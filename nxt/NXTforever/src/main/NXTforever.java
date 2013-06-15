package main;

import behavior.Initialisierung;
import lejos.nxt.Button;
import lejos.nxt.ButtonListener;
import lejos.nxt.LCD;
import lejos.robotics.subsumption.Arbitrator;
import lejos.robotics.subsumption.Behavior;

public class NXTforever {
	
	private static Status mStatus;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		Button.ESCAPE.addButtonListener(new ButtonListener() {
			
			@Override
			public void buttonReleased(Button b) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void buttonPressed(Button b) {
				exitProgram();
				
			}
		});
		
		mStatus = new Status();
		
		LCD.drawString("Los gehts", 1, 2);
		
		Arbitrator arby = new Arbitrator(mStatus.getAllBeBehavior());
		mStatus.setBehaviorStatus(mStatus.Connection);
	    arby.start();

	}
	
	private static void exitProgram() {
		LCD.clear();
		LCD.drawString("Progarm beendet!", 0, 0);
		System.exit(0);
	}

}
