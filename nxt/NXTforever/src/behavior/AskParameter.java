package behavior;

import support.MyDifferentialPilot;
import support.MyLightSensors;
import support.Position;
import lejos.nxt.LCD;
import lejos.nxt.Sound;
import lejos.robotics.subsumption.Behavior;
import main.Status;

public class AskParameter implements Behavior {

    private MyDifferentialPilot mDifferentialPilot = MyDifferentialPilot.getInstance();
	
	private Status mStatus;
	private boolean suppressed = false;
	
	private boolean ParameterOK = true;
	
	public AskParameter(Status status){
		this.mStatus = status;
	}
	
	@Override
	public boolean takeControl() {
		return (mStatus.getBehaviorStatus()==this);
	}

	@Override
	public void action() {
		LCD.clear();
		
		if(ParameterOK) {
			
			mStatus.setPosition();
			mStatus.setBehaviorStatus(mStatus.UseStation);
		}

	}

	@Override
	public void suppress() {
		suppressed = true;

	}

}
