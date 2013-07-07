package behavior;

import lejos.nxt.Button;
import lejos.nxt.LCD;
import lejos.robotics.subsumption.Behavior;
import main.Status;
import support.MyDifferentialPilot;
import support.MyLightSensors;
import support.Step;

public class UseStation implements Behavior {
	
	 private static MyLightSensors mLightSensors = MyLightSensors.getInstance();
	    private MyDifferentialPilot mDifferentialPilot = MyDifferentialPilot.getInstance();
		
		private Status mStatus;
		private boolean suppressed = false;
		
		private Step mStep;
		
		public UseStation(Status status){
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
			
			mDifferentialPilot.forward();
			
			mDifferentialPilot.steerRight();
			
			while(!suppressed && (mStatus.getBehaviorStatus() == this) && mDifferentialPilot.followLine()) {}
			
			mDifferentialPilot.stop();
			try {
					Thread.yield();
					Thread.sleep(1000 * mStatus.getTask().getStep().getTime());
			} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
			}
			mDifferentialPilot.forward();
				
			mDifferentialPilot.turn();
			
			while(!suppressed && (mStatus.getBehaviorStatus() == this) && mDifferentialPilot.followLine()) {}
				
			mDifferentialPilot.steerRight();
			
			mStatus.setPosition();
			mStatus.setBehaviorStatus(mStatus.Follow);
			
			//Schritt aus der Kette löschen :D
			mStatus.getTask().removeStep();

		}

		@Override
		public void suppress() {
			suppressed = true;
		}

	
	
}
