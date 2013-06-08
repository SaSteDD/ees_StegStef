package behavior;

import lejos.nxt.Button;
import lejos.nxt.LCD;
import lejos.robotics.subsumption.Behavior;
import main.*;
import support.*;

public class Initialisierung implements Behavior {
	
	private static MyLightSensors mLightSensors = MyLightSensors.getInstance();
	
	private Status mStatus;
	private boolean suppressed = false;
	
	public Initialisierung(Status status){
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
		
		//Farbe Weiﬂ einlesen
		while(true){
			LCD.drawString("Weis setzen", 1, 1);
			LCD.drawString("Li:  "  + mLightSensors.getSensorLeftRaw(), 1, 2);
			LCD.drawString("Re: "  + mLightSensors.getSensorRightRaw(), 1, 3);
			
			if(Button.ENTER.isDown()){
				mLightSensors.setWhite();	
				break;
			}
			try {
				Thread.sleep(10);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			LCD.clear();
		}
		
		while(!Button.ENTER.isUp())
			try {
				Thread.sleep(10);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
				
		//Farbe Weiﬂ einlesen
		while(true){
			LCD.drawString("Schwarz setzen", 1, 1);
			LCD.drawString("Li:  "  + mLightSensors.getSensorLeftRaw(), 1, 2);
			LCD.drawString("Re: "  + mLightSensors.getSensorRightRaw(), 1, 3);
					
			if(Button.ENTER.isDown()){
				mLightSensors.setBlack();	
				break;
			}
			try {
				Thread.sleep(10);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			LCD.clear();
		}
		
		while(!Button.ENTER.isUp())
			try {
				Thread.sleep(10);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		
		while(!suppressed && (mStatus.getBehaviorStatus()==this)){		
			int offset = 0;
			
			LCD.drawString("Plazierung", 1, 2);
			offset = mLightSensors.getSensorRight() - 50;
			LCD.drawString("0 = "  + offset, 1, 3);
			
			
			if(Button.ENTER.isDown()){
				mStatus.setBehaviorStatus(mStatus.Follow);
			}
				
			try {
				Thread.yield();
				Thread.sleep(10);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			LCD.clear();
			
		}

	}

	@Override
	public void suppress() {
		suppressed = true;
	}

}
