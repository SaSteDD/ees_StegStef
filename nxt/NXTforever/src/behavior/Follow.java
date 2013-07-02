package behavior;

import java.util.List;

import support.MyBTSend;
import support.MyBTconnection;
import support.MyDifferentialPilot;
import support.MyLightSensors;
import support.Position;
import lejos.nxt.LCD;
import lejos.nxt.Sound;
import lejos.robotics.subsumption.Behavior;
import main.Status;

public class Follow implements Behavior {

	// Globale Klassen
	private Status mStatus;
	private MyLightSensors mLightSensors = MyLightSensors.getInstance();
	private MyDifferentialPilot mDifferentialPilot = MyDifferentialPilot
			.getInstance();
	private MyBTconnection mBTconnection = MyBTconnection.getInstance();

	// Klassen
	private MyBTSend mBTSend;

	// Behavior
	private boolean suppressed = false;

	// Senosren
	private int linkerSensor;
	private int rechterSensor;

	// Position
	private int maxcureve = 0;
	private int curve = 0;
	private int mark = 0;

	public Follow(Status status) {
		this.mStatus = status;
	}

	@Override
	public boolean takeControl() {
		return (mStatus.getBehaviorStatus() == this);
	}

	@Override
		public void action() {
			suppressed = false;
	
			mDifferentialPilot.forward();
			Sound.beep();
			
			//Anzahl der Kurven der LongLange setzen
			if(mStatus.getlastPosition() == Position.parkingSpace.ordinal()) 
				maxcureve=2;
			else
				maxcureve=3;
			
			
			while (!suppressed && (mStatus.getBehaviorStatus() == this)) {
				
				LCD.clear();
				
				if(!mDifferentialPilot.followLine(2)) {					
				
					if(mStatus.getPosition() == Position.longLane.ordinal()) {
						if(curve < maxcureve) {
							mDifferentialPilot.steer(1);
							curve++;
						}
						else
						{
							mStatus.setPosition(Position.mark1.ordinal());
							mStatus.setBehaviorStatus(mStatus.AskParameter);
						}
					}
					
					if(mStatus.getPosition() == Position.station1to2.ordinal() || 
					   mStatus.getPosition() == Position.station2to3.ordinal() || 
					   mStatus.getPosition() == Position.station3to4.ordinal()  ) {
						
						mStatus.setPosition();
						mStatus.setBehaviorStatus(mStatus.AskParameter);	
					}
					
					if(mStatus.getPosition() == Position.station4ToParkingSpace.ordinal()) {
						mDifferentialPilot.stop();
					}
						
				}	
				
				LCD.drawString("Folge Bahn", 1, 1);
				LCD.drawString("Cureve: " + curve, 1, 2);
				LCD.drawString("Mark: " + mark, 1, 3);
				
				//Kommunikation
//				if(mBTconnection.checkConnection())
//					readConnection();	
				
				try {
					Thread.yield();
					Thread.sleep(10);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				
				LCD.clear(); 
			}
			
			mDifferentialPilot.stop();

		}

	@Override
	public void suppress() {
		suppressed = true;
	}

	private void readConnection() {

		List<Byte> temp;
		Sound.beep();
		temp = mBTconnection.readConnection();

		if (temp.get(0) == 97)
			mDifferentialPilot.toggleStartStop();

	}

}
