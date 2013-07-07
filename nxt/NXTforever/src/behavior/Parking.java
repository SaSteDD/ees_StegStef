package behavior;

import java.util.List;

import support.MyBTconnection;
import support.MyDifferentialPilot;
import support.Position;
import support.Task;
import lejos.nxt.LCD;
import lejos.nxt.Sound;
import lejos.robotics.subsumption.Behavior;
import main.Status;

public class Parking implements Behavior {
	
	private Status mStatus;
	private MyDifferentialPilot mDifferentialPilot = MyDifferentialPilot.getInstance();

	private boolean suppressed = false;
	
	private MyBTconnection mBTconnection = MyBTconnection.getInstance();
	
	//interne Variable, legt fest ob Parkplatz verlassen werden darf
	private boolean leaveParkingPosition = false;
	
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
		
		leaveParkingPosition = false;
		
		while (!suppressed && (mStatus.getBehaviorStatus() == this)) {
			
			if(leaveParkingPosition == false) {
				// Abfragen ob Daten an der Verbindung anliegen
				if(mBTconnection.checkConnection())				
					askforTask();
			}
			else {
				
				LCD.clear();
				
				if(!mDifferentialPilot.followLine()) {
					mDifferentialPilot.steer();
					mStatus.setPosition(Position.longLane.ordinal());
					mStatus.setBehaviorStatus(mStatus.Follow);
				}		
			
////				//Kommunikation
////				if(mBTconnection.checkConnection())
////					readConnection();

				
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

	private void readConnection() {
		
		List<Byte> temp;
		Sound.beep();
		temp = mBTconnection.readConnection();
		
		if(temp.get(0) == 97)
			mDifferentialPilot.toggleStartStop();
		
	}

	private void askforTask() {
		List<Byte> temp;
		Task newTask;
		int countSteps;
		
		// Alle Bytes von rfcomn abfragen
		temp = mBTconnection.readConnection();

			
		if(temp.get(0) == 't'){							// wenn 1. Byte = T -> Auftrag
			countSteps = (temp.get(5) << 24) + (temp.get(4) << 16) + (temp.get(3) << 8) + temp.get(2);
			newTask = new Task(temp.get(1));			// neuen Auftrag anlegen
			
			//alle Schritte nacheinander Ablegen
			for (int i = 0;i<countSteps;i++) {
				newTask.addStep(temp.get(6 + i*3), temp.get(7 + i*3), temp.get(8 + i*3));
				Sound.beep();
			}
			
			// Auftrag an die Statusklasse übergeben
			mStatus.setTask(newTask);
			
			leaveParkingPosition = true;
			mDifferentialPilot.forward();
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
