package behavior;

import lejos.nxt.LCD;
import lejos.robotics.subsumption.Behavior;
import main.Status;

public class Parken implements Behavior {
	
	private Status mStatus;
	private boolean suppressed = false;
	
	public Parken(Status status){
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
		
		LCD.drawString("Es geht", 1, 2);

	}

	@Override
	public void suppress() {
		suppressed = true;
	}

}
