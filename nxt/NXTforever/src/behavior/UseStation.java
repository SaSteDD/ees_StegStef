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
			
			LCD.clear();
			LCD.drawString("forward", 0, 0);
			mDifferentialPilot.forward();
			
			LCD.clear();
			LCD.drawString("Einlenk", 0, 0);
			mDifferentialPilot.steerRight();
			
			
			LCD.clear();
			LCD.drawString("Gerade aus 1", 0, 0);
			while(!suppressed && (mStatus.getBehaviorStatus() == this) && mDifferentialPilot.followLine(2))
		
			
			LCD.clear();
			LCD.drawString("Umdrehen", 0, 0);
			mDifferentialPilot.turn();
			
			LCD.clear();
			LCD.drawString("Gerade aus 2", 0, 0);
			while(!suppressed && (mStatus.getBehaviorStatus() == this) && mDifferentialPilot.followLine(2))
				
			LCD.clear();
			LCD.drawString("Einlenken", 0, 0);
			mDifferentialPilot.steerRight();
			
			mStatus.setPosition();
			mStatus.setBehaviorStatus(mStatus.Follow);
			
			//Schritt aus der Kette löschen :D
			mStatus.getTask().removeStep();
				
			LCD.clear();
		}

		@Override
		public void suppress() {
			suppressed = true;
		}

	
	
}
