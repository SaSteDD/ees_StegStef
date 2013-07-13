package main;


import support.MyBTconnection;
import support.Task;
import behavior.*;
import support.*;

import lejos.nxt.LCD;
import lejos.robotics.subsumption.Behavior;

public class Status {
	
	//alle Behaviors anlegen :D
	public final Behavior Initialisierung = new Initialisierung(this);
	public final Behavior Parking = new Parking(this);
	public final Behavior Follow = new Follow(this);
	public final Behavior Connection = new Connection(this);
	public final Behavior DEBUG = new DEBUG(this);
	public final Behavior AskParameter = new AskParameter(this);
	public final Behavior UseStation = new UseStation(this);
	public final Behavior PullInParking = new PullInParking(this);
	
	//Kommunikation
	private boolean commAllowed = true;
	private MyBTconnection mBTconnection = MyBTconnection.getInstance();
	
	private int currentPosition;
	private int lastPosition;
	
	private Behavior behaviorStatus;
	
	//Auftrag
	private Task mTask;
		
	public Behavior getBehaviorStatus() {
		return behaviorStatus;
	}

	public void setBehaviorStatus(Behavior behaviorStat) {
		this.behaviorStatus = behaviorStat;
	}
	
	public Behavior[] getAllBeBehavior(){
		
		Behavior[] bArray = {
				Initialisierung,
				Parking,
				Follow,
				Connection,
				DEBUG,
				AskParameter,
				UseStation,
				PullInParking
		};
		
		return bArray;		
	}

	public void setTask(Task newTask) {
		this.mTask = newTask;		
	}

	public int getPosition() {
		
		return currentPosition;
	}
	

	
	private void commPosition(){
		if(commAllowed) {
			drawLCD();
			byte b1 = (byte) ((mTask.getNumber() >> 24) & 0xFF);
		    byte b2 = (byte) ((mTask.getNumber() >> 16) & 0xFF);
		    byte b3 = (byte) ((mTask.getNumber() >> 8) & 0xFF);
		    byte b4 = (byte) ( mTask.getNumber()  & 0xFF);
			byte[] out = new byte[] {(byte)'s',(byte) currentPosition,b4,b3,b2,b1} ;
			mBTconnection.sendConnection(out);
		}
	}
	
	public int getlastPosition() {
		return lastPosition;
	}
	
	public void steered() {
		if(currentPosition == Position.parkingSpace.ordinal() )
			currentPosition = Position.longLane.ordinal();
		
	}
	
	public void setPosition(int position) {
		lastPosition = currentPosition;
		currentPosition = position;
		commPosition();
	}
	
	public void setPosition() {
		lastPosition = currentPosition;
		currentPosition++;
		commPosition();
	}

	public void drawLCD() {
		int lv = 2;
		LCD.clear();
		LCD.drawString("Status", 0, 0);
		LCD.drawString("Position: " + this.getNamePosition(this.getPosition()), 0, 1);
		for(Step tm : mTask.getSteps()){
			LCD.drawString("Nr : " + tm.getNumber() + "  " + getNameTyp(tm.getType()), 0, lv);
			lv++;
		}
	}

	private String getNamePosition(int i){
		String temp = null;
		
		switch(i) {
		case 0:  temp="parkingSpace"; break;
		case 1:  temp="mark5"; break;
		case 2:  temp="parkingSpaceTSection"; break;
		case 3:  temp="longLane"; break;
		case 4:  temp="mark1"; break;
		case 5:  temp="station1"; break;
		case 6:  temp="station1to2"; break;
		case 7:  temp="mark2"; break;
		case 8:  temp="station2"; break;
		case 9:  temp="station2to3"; break;
		case 10: temp="mark3"; break;
		case 11: temp="station3"; break;
		case 12: temp="station3to4"; break;
		case 13: temp="mark4"; break;
		case 14: temp="station4"; break;
		case 15: temp="station4ToParkingSpace"; break;
		}
		
		return temp;
	}
	
	private String getNameTyp(int i){
		String temp = null;
		
		switch(i) {
		case 0: temp="Bohren"; break;
		case 1: temp="Drehen"; break;
		case 2: temp="Fräsen"; break;
		default: temp="Fehler";
		}
		
		return temp;
	}
	
	public Task getTask(){
		return mTask;
		
	}
	
}
