package behavior;

import support.MyBTconnection;
import lejos.nxt.Button;
import lejos.nxt.LCD;
import lejos.robotics.subsumption.Behavior;
import main.Status;

public class Connection implements Behavior {
	
	private Status mStatus;
	private boolean suppressed = false;
	
	private MyBTconnection mBTconnection = MyBTconnection.getInstance();
	
	public Connection(Status status){
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
		LCD.drawString("waiting for BT",0 ,1 );
		
		// Verbindung öffnen
		mBTconnection.openConnection();
		
		LCD.drawString("..connected",0 ,2 );
		
		try {
			Thread.yield();
			Thread.sleep(1000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		mStatus.setBehaviorStatus(mStatus.Initialisierung);
		
	}

	@Override
	public void suppress() {
		suppressed = true;
	}

}
