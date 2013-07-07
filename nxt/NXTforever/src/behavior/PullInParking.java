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
			
			while(!suppressed && (mStatus.getBehaviorStatus() == this) && mDifferentialPilot.followLine()) {}
				
			mDifferentialPilot.steer();
			
			mDifferentialPilot.stop();
			
			
			byte[] out;
			
			if(mStatus.getTask().hasSteps())
				out = new byte[] {'f'} ;
			else
				out = new byte[] {'F'} ;
			
			try {
			mBTconnection.sendConnection(out);
			}
			catch (Exception e) {
				LCD.clear();
				LCD.drawString("Fehler Send", 0, 0);
				LCD.drawString(e.getMessage(), 0, 1);
			}
			
			mStatus.setBehaviorStatus(mStatus.Parking);

		}

		@Override
		public void suppress() {
			suppressed = true;
		}

	
	
}
