package behavior;

import support.MyDifferentialPilot;
import support.MyLightSensors;
import support.Position;
import lejos.nxt.Button;
import lejos.nxt.LCD;
import lejos.robotics.subsumption.Behavior;
import main.Status;

public class DEBUG implements Behavior {
	
    private static MyLightSensors mLightSensors = MyLightSensors.getInstance();
    private MyDifferentialPilot mDifferentialPilot = MyDifferentialPilot.getInstance();
	
	private Status mStatus;
	private boolean suppressed = false;
	
	public DEBUG(Status status){
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
		
		mLightSensors.setColor(310, 336, 538, 581);
		
		while(!suppressed && (mStatus.getBehaviorStatus()==this)){		
			int offset = 0;
			
			LCD.drawString("Plazierung", 1, 2);
			offset = mLightSensors.getSensorRight() - 50;
			LCD.drawString("0 = "  + offset, 1, 3);
			
			if(Button.ENTER.isDown()){
			break;
			}
		
				
			try {
				Thread.yield();
				Thread.sleep(10);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}	
		
		mDifferentialPilot.forward();
		
		mStatus.setPosition(Position.parkingSpace.ordinal());
		mStatus.setBehaviorStatus(mStatus.Parking);
			
		LCD.clear();
		LCD.drawString("Fahren", 0, 0);
//			while (!suppressed && (mStatus.getBehaviorStatus() == this)) {
//				
//				if(!mDifferentialPilot.followLine(2)) {	
//					mStatus.setPosition(Position.mark1.ordinal());
//					mStatus.setBehaviorStatus(mStatus.AskParameter);
//				}
//				
//				try {
//					Thread.yield();
//					Thread.sleep(10);
//				} catch (InterruptedException e) {
//					// TODO Auto-generated catch block
//					e.printStackTrace();
//				}
//				
//			}
			
		
			
		LCD.clear();
	}

	@Override
	public void suppress() {
		suppressed = true;
	}

}
