package main;

import support.Task;
import behavior.*;

import lejos.robotics.subsumption.Behavior;

public class Status {
	
	//alle Behaviors anlegen :D
	public Behavior Initialisierung = new Initialisierung(this);
	public Behavior Parking = new Parking(this);
	public Behavior Follow = new Follow(this);
	public Behavior Connection = new Connection(this);
	
	private Behavior behaviorStatus;
	private Behavior lastBehaviorStatus;
	
	//Auftrag
	private Task mTask;
	
	//Position
	private int PositionMark = -1;
	private int Position;
	
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
				Connection
		};
		
		return bArray;		
	}

	public void setTask(Task newTask) {
		this.mTask = newTask;		
	}

	public int getPosition() {
		return Position;
	}

	public void setPosition(int position) {
		Position = position;
	}

	public int getPositionMark() {
		return PositionMark;
	}

	public void setPositionMark(int positionMark) {
		PositionMark = positionMark;
	}
}
