package main;

import behavior.*;

import lejos.robotics.subsumption.Behavior;

public class Status {
	
	//alle Behaviors anlegen :D
	public Behavior Initialisierung = new Initialisierung(this);
	public Behavior Parken = new Parken(this);
	public Behavior Follow = new behavior.Follow(this);
	
	private Behavior behaviorStatus;
	private Behavior lastBehaviorStatus;

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
				Parken,
				Follow
		};
		
		return bArray;		
	}
}
