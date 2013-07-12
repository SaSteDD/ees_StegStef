package behavior;

import support.MyBTconnection;
import support.MyDifferentialPilot;
import support.MyLightSensors;
import support.Position;
import support.Step;
import lejos.nxt.LCD;
import lejos.robotics.subsumption.Behavior;
import main.Status;

public class PullInParking implements Behavior {

	 private static MyLightSensors mLightSensors = MyLightSensors.getInstance();
	    private MyDifferentialPilot mDifferentialPilot = MyDifferentialPilot.getInstance();
	    private MyBTconnection mBTconnection = MyBTconnection.getInstance();
		
		private Status mStatus;
		private boolean suppressed = false;
		
		private Step mStep;
		
		public PullInParking(Status status){
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
			
			mDifferentialPilot.steerRight();
			
			mStatus.setBehaviorStatus(mStatus.Parking);
			
			while(!suppressed && (mStatus.getBehaviorStatus() == this) && mDifferentialPilot.followLine()) {}
				
			mDifferentialPilot.turn();
			
			mDifferentialPilot.stop();
		
		}

		@Override
		public void suppress() {
			suppressed = true;
		}

	
	
}
