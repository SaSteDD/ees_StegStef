package behavior;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import support.MyBTconnection;
import support.MyDifferentialPilot;
import support.MyLightSensors;
import support.Task;
import support.followLine;
import lejos.nxt.LCD;
import lejos.robotics.subsumption.Behavior;
import main.Status;

public class Parking implements Behavior {
	
	private Status mStatus;
	private MyLightSensors mLightSensors = MyLightSensors.getInstance();
	private MyDifferentialPilot mDifferentialPilot = MyDifferentialPilot.getInstance();
	
	private boolean suppressed = false;
	
	private MyBTconnection mBTconnection = MyBTconnection.getInstance();
	
	//interne Variable, legt fest ob Parkplatz verlassen werden darf
	private boolean leaveParkingPosition = true;
	
	//iV, hält Wert für den rechten Sensor
	private int rechterSensor;
	
	public Parking(Status status){
		this.mStatus = status;
	}
	
	@Override
	public boolean takeControl() {
		return (mStatus.getBehaviorStatus()==this);
	}

	@Override
	public void action() {
		suppressed = false;
		LCD.clear();		
		LCD.drawString("Warte auf",0 ,2 );
		LCD.drawString("      Auftrag",0 ,3 );
		
		// Variablen, die zm Fahren benötigt wird
		int turn = 0;
		
		// Variablen, zählt die Kurven
		int curve = 0;
		// PID-Regler, zum folgen der Linie
		followLine mfollowLine = new followLine();
	
		
		while (!suppressed && (mStatus.getBehaviorStatus() == this)) {
			
			if(leaveParkingPosition == false) {
				// Abfragen ob Daten an der Verbindung anliegen
				if(mBTconnection.checkConnection())				
					askforTask();	
			}
			else {
				
				LCD.clear();
				
				
				mDifferentialPilot.forward();
				
				//Eingänge lesen
				rechterSensor = mLightSensors.getSensorRight();
				
				turn = mfollowLine.FollowEdgeMiss(rechterSensor);
				
				LCD.drawString("Se: " + turn, 0, 2);
				
//				if( rechterSensor > 70 ) {
//					turn = mfollowLine.FollowEdgeMiss(rechterSensor);
//				}
//				else {
//					turn = -175;			
//				}
					
				mDifferentialPilot.Turn(turn);
				
			}
			
			try {
				Thread.yield();
				Thread.sleep(10);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			
		}	

	}

	private void askforTask() {
		List<Byte> temp;
		Task newTask;
		int countSteps;
		
		// Alle Bytes von rfcomn abfragen
		temp = mBTconnection.readConnection();

			
		if(temp.get(0) == 116){							// wenn 1. Byte = T -> Auftrag
			countSteps = temp.get(1);					// 2. Byte: Anzahl der Schritte
			newTask = new Task(temp.get(5));			// neuen Auftrag anlegen
			
			//alle Schritte nacheinander Ablegen
			for (int i = 0;i<countSteps;i++) {
				newTask.addStep(temp.get(6 + i*3), temp.get(7 + i*3), temp.get(8 + i*3));
			}
			
			// Auftrag an die Statusklasse übergeben
			mStatus.setTask(newTask);
			
			leaveParkingPosition = true;
		}
		else {
			System.out.print("Fehler!!!!");
		}
	}

	@Override
	public void suppress() {
		suppressed = true;
	}

}
