package main;

import support.MyBTSend;
import support.MyBTconnection;
import support.Task;
import behavior.*;
import support.*;

import lejos.nxt.LCD;
import lejos.nxt.Sound;
import lejos.nxt.comm.BTConnection;
import lejos.robotics.subsumption.Behavior;

public class Status {
	
	//alle Behaviors anlegen :D
	public Behavior Initialisierung = new Initialisierung(this);
	public Behavior Parking = new Parking(this);
	public Behavior Follow = new Follow(this);
	public Behavior Connection = new Connection(this);
	public Behavior DEBUG = new behavior.DEBUG(this);
	public Behavior AskParameter = new behavior.AskParameter(this);
	public Behavior UseStation = new behavior.UseStation(this);
	
	//Kommunikation
	private boolean commAllowed = true;
	private MyBTSend mBTSend;
	private MyBTconnection mBTconnection = MyBTconnection.getInstance();

	
	private int currentPosition;
	private int lastPosition;
	
	private Behavior behaviorStatus;
	private Behavior lastBehaviorStatus;
	
	//Auftrag
	private Task mTask;
	
	//Position
	private int PositionMark = -1;
	private int Pos;
	
	public Behavior getBehaviorStatus() {
		return behaviorStatus;
	}

	public void setBehaviorStatus(Behavior behaviorStat) {
		lastBehaviorStatus = this.behaviorStatus;
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
				UseStation
		};
		
		return bArray;		
	}

	public void setTask(Task newTask) {
		this.mTask = newTask;		
	}

	public int getPosition() {
		
		return currentPosition;
	}
	
	public void changePosition() {
		lastPosition = currentPosition;
		currentPosition++;
		commPosition();
	}
	
	public void changePosition(int position) {
		lastPosition = currentPosition;
		currentPosition = position;
		commPosition();
	}
	
	private void commPosition(){
		if(commAllowed) {
			drawLCD();
			byte b1 = (byte) ((mTask.getNumber() >> 24) & 0xFF);
		    byte b2 = (byte) ((mTask.getNumber() >> 16) & 0xFF);
		    byte b3 = (byte) ((mTask.getNumber() >> 8) & 0xFF);
		    byte b4 = (byte) ( mTask.getNumber()  & 0xFF);
			byte[] out = new byte[] {(byte)'s',(byte) currentPosition,b4,b3,b2,b1} ;
			//mBTconnection.sendConnection(out);
			mBTSend = new MyBTSend(out);
			mBTSend.run();
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
		currentPosition = position;
		commPosition();
	}
	
	public void setPosition() {
		currentPosition++;
		commPosition();
	}

	public void drawLCD() {
		LCD.clear();
		LCD.drawString("Status", 0, 0);
		LCD.drawString("Position: " + currentPosition, 0, 1);
	}

	public Task getTask(){
		return mTask;
		
	}
	
}
