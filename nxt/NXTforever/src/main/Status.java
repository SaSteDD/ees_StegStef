package main;

import support.Task;
import behavior.*;
import support.*;

import lejos.robotics.subsumption.Behavior;

public class Status {
	
	//alle Behaviors anlegen :D
	public Behavior Initialisierung = new Initialisierung(this);
	public Behavior Parking = new Parking(this);
	public Behavior Follow = new Follow(this);
	public Behavior Connection = new Connection(this);
	public Behavior DEBUG = new behavior.DEBUG(this);
	
//	private int currentPosition;
	
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
				DEBUG
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
	}
	
	public void changePosition(int position) {
		lastPosition = currentPosition;
		currentPosition = position;
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
	}

	public int getPositionMark() {
		return PositionMark;
	}

	public void setPositionMark(int positionMark) {
		PositionMark = positionMark;
	}
}
