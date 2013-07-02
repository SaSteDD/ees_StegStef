package main;

import java.io.DataOutputStream;
import java.io.IOException;

import support.MyBTSend;
import support.MyBTconnection;
import support.Task;
import behavior.*;
import support.*;

import lejos.nxt.Sound;
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
			Sound.beep();
			byte[] out = new byte[] {(byte)'s',(byte) currentPosition,1,0,0,0 } ;
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
		currentPosition = position;
		commPosition();
	}
	
	public void setPosition() {
		currentPosition++;
		commPosition();
	}

	public int getPositionMark() {
		return PositionMark;
	}

	public void setPositionMark(int positionMark) {
		PositionMark = positionMark;
	}

	
}
