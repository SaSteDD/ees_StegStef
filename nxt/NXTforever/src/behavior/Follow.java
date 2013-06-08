package behavior;

import support.MyDifferentialPilot;
import support.MyLightSensors;
import support.followLine;
import lejos.nxt.LCD;
import lejos.robotics.subsumption.Behavior;
import main.Status;

public class Follow implements Behavior {

	    //Globale Klassen
		private Status mStatus;
		private MyLightSensors mLightSensors = MyLightSensors.getInstance();
		private MyDifferentialPilot mDifferentialPilot = MyDifferentialPilot.getInstance();
		
		//Klassen
		private followLine  mfollowLine;
		
		private boolean suppressed = false;
		
		private int linkerSensor;
		private int rechterSensor;
		private int turn = 0;
		
		public Follow(Status status){
			this.mStatus = status;
		}
		
		@Override
		public boolean takeControl() {
			return (mStatus.getBehaviorStatus() == this);
		}

		@Override
		public void action() {
			suppressed = false;
			
			mfollowLine = new followLine();
			
			mDifferentialPilot.forward();
			
			while (!suppressed && (mStatus.getBehaviorStatus() == this)) {
				
				//Eingänge holen
 				linkerSensor = mLightSensors.getSensorLeft();
				rechterSensor = mLightSensors.getSensorRight();
				
				turn = mfollowLine.getFollowLine(linkerSensor, rechterSensor);
				
				LCD.drawString("Li: " + linkerSensor + " : " + mLightSensors.getSensorLeftRaw(), 0, 1);
				LCD.drawString("Re: " + rechterSensor + " : " + mLightSensors.getSensorRightRaw(), 0, 2);
				
				LCD.drawString("Pos: " + turn,0,3 );
				
				mDifferentialPilot.Turn(turn);
				
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

}
