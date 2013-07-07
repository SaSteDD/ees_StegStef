package behavior;

import java.util.List;

import support.MyBTconnection;
import support.MyDifferentialPilot;
import support.Position;
import lejos.nxt.LCD;
import lejos.robotics.subsumption.Behavior;
import main.Status;

public class Follow implements Behavior {

	// Globale Klassen
	private Status mStatus;
	private MyDifferentialPilot mDifferentialPilot = MyDifferentialPilot
			.getInstance();
	private MyBTconnection mBTconnection = MyBTconnection.getInstance();

	// Behavior
	private boolean suppressed = false;
	
	// Position
	private int maxcureve = 2;
	private int curve = 0;

	public Follow(Status status) {
		this.mStatus = status;
	}

	@Override
	public boolean takeControl() {
		return (mStatus.getBehaviorStatus() == this);
	}

	@Override
		public void action() {
			suppressed = false;
	
			mDifferentialPilot.forward();
			
			while (!suppressed && (mStatus.getBehaviorStatus() == this)) {
				
				/**
				 * followLine gibt false zurück, wenn es auf ein Hinterniss trifft.
				 * Es wird anhand der Position entschieden, was gemacht werden soll
				 */
				if(!mDifferentialPilot.followLine()) {					
					
					//wenn der NXT sich auf der Gerade befindet, dann muss er entweder eine Kurve fahren oder die erste Station abfragen
					if(mStatus.getPosition() == Position.longLane.ordinal()) {
						// sollte er noch nicht alle Kruven erreicht haben, denn fährt er die Kurve
						if(curve < maxcureve) {
							//Kurve fahren
							mDifferentialPilot.steer();
							//Anzahl der Kurven nach oben zählen
							curve++;
						}
						//Wenn alle Kurven erreicht, dann befindet sich der nxt an der ersten Station
						else
						{
							//Wenn noch Schritte zu bearbieten sind, dann Frag Parameter ab
							if(mStatus.getTask().hasSteps() &&  mStatus.getTask().hasTrys()){
								//wechselt Position, hier von longLane -> mark1
								mStatus.setPosition();
								//State wecheln
								mStatus.setBehaviorStatus(mStatus.AskParameter);
							}
							else
							{
								//wenn die Station nicht mehr angefahren werden muss dann einfach gerade ausfahren
								mDifferentialPilot.goStraight();
								//wechselt Position, hier von longLane -> station1to2
								mStatus.setPosition(mStatus.getPosition() + 3);
							}
							break;
						}
					}
					
					//wenn der NXT sich auf einem zwichenStück befindet, dann soll er die Station anfahren
					else if(mStatus.getPosition() == Position.station1to2.ordinal() || 
							mStatus.getPosition() == Position.station2to3.ordinal() || 
							mStatus.getPosition() == Position.station3to4.ordinal()  ) {
						
						//Wenn noch Schritte zu bearbieten sind, dann Frag Parameter ab
						if(mStatus.getTask().hasSteps() &&  mStatus.getTask().hasTrys()) {
							//wechselt Position, hier von station?toX -> markX
							mStatus.setPosition();
							//State wecheln
							mStatus.setBehaviorStatus(mStatus.AskParameter);
						}
						else
						{
							//wenn die Station nicht mehr angefahren werden muss dann einfach gerade ausfahren
							mDifferentialPilot.goStraight();
							//wechselt Position, hier von station?toX -> stationXto?
							mStatus.setPosition(mStatus.getPosition() + 3);
						}
						break;
					}
					
					//nach der letzen Station wird entschieden ob der NXT Praken soll
					else if(mStatus.getPosition() == Position.station4ToParkingSpace.ordinal()) {
						// wenn er sich noch auf der Bahn befindet, dann muss zu erst noch mal Gelenkt werden
						if(curve==maxcureve) {
							mDifferentialPilot.steer();
							curve++;
						}
						//Entscheidung on geparkt werden soll
						else {
							if(mStatus.getTask().hasSteps() &&  mStatus.getTask().hasTrys()){
								mStatus.setPosition(Position.mark5.ordinal());
								mDifferentialPilot.goStraight();
								mStatus.setPosition(Position.parkingSpaceTSection.ordinal());
							}
							else
							{
								mStatus.setPosition(Position.mark5.ordinal());
								//State wechseln, Parkstate
								curve=0;
							//	maxcureve=3;
								mStatus.setBehaviorStatus(mStatus.PullInParking);
							}
							break;
						}
					}
					
					//wenn der nxt sich auf dem T Stück befindet, dann beginnt die ganze Runde wieder von vorne
					else if(mStatus.getPosition() == Position.parkingSpaceTSection.ordinal()) {
						mDifferentialPilot.steer();
						mStatus.setPosition(Position.longLane.ordinal());
						//alle Warte wieder auf anfang setzen
				//		maxcureve=2;
						curve=0;
					}
						
						
					
					
				}	
//
//				//Kommunikation
//				if(mBTconnection.checkConnection())
//					readConnection();	
				
				try {
					Thread.yield();
					Thread.sleep(10);
				} catch (InterruptedException e) {
					LCD.clear();
					LCD.drawString("Fehler hier", 0, 0);
					LCD.drawString(e.getMessage(), 0,1);
				}
				
			}
			LCD.drawInt(3, 0, 4);
	//		mDifferentialPilot.stop();

		}

	@Override
	public void suppress() {
		suppressed = true;
	}

	@SuppressWarnings("unused")
	private void readConnection() {

		List<Byte> temp;
		temp = mBTconnection.readConnection();

		if (temp.get(0) == 97)
			mDifferentialPilot.toggleStartStop();

	}

}
