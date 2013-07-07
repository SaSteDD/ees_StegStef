package behavior;

import java.util.List;

import support.MyBTconnection;
import support.MyDifferentialPilot;
import support.MyLightSensors;
import support.Position;
import java.util.List;
import lejos.nxt.LCD;
import lejos.nxt.Motor;
import lejos.nxt.Sound;
import lejos.robotics.subsumption.Behavior;
import main.Status;
import behavior.*;
import support.*;

public class AskParameter implements Behavior {

    private MyDifferentialPilot mDifferentialPilot = MyDifferentialPilot.getInstance();
    private MyBTconnection mBTconnection = MyBTconnection.getInstance();
	
	private Status mStatus;
	private boolean suppressed = false;
	
	private boolean ParameterOK = false;
	private int Station;
	private List<Byte> temp;
	private Step mStep;
	
	
	public AskParameter(Status status){
		this.mStatus = status;
	}
	
	@Override
	public boolean takeControl() {
		return (mStatus.getBehaviorStatus()==this);
	}

	@Override
	public void action() {
				
				//Setzen von Parameter, da ich nicht weis was hier vorgeht
				ParameterOK = false;
				temp = null;
		
				LCD.drawInt(4, 0, 4);
				mDifferentialPilot.stop();
			   //nächsten Schritt holen
			    mStep = mStatus.getTask().getStep();
				
				LCD.drawInt(5, 0, 4);
				/*
				 *Format for Message of nxt(Receive):
				 *     [qualityChar]  [Station-Nr (1-4)]
				 *BNr.      1                 2
				 *Example:  q                  1
				 * Stationsnummer: mark1=4;mark2=7;mark3=10;mark4=13;
				 * 
				 */
				switch(mStatus.getPosition()) { case 4: Station=1; break; case 7: Station=2; break; case 10: Station=3; break; case 13: Station=4; break; }
				byte[] out = new byte[] {113,(byte) Station } ;
				try {
				mBTconnection.sendConnection(out);
				}
				catch (Exception e) {
					LCD.clear();
					LCD.drawString("Fehler Send", 0, 0);
					LCD.drawString(e.getMessage(), 0, 1);
				}
				LCD.drawInt(6, 0, 4);
				//solange Warten, bis Antwort kommt
				while(!suppressed && (mStatus.getBehaviorStatus() == this) && !mBTconnection.checkConnection())
				/*Mitteilung auswerten
				 * *Format for Message of RasPi (send):
				 *     [qualityChar] [StationType]  [Quality]
				 *BNr:           1           2              3
				 *Example:       q           2              4
				 */
	
				LCD.drawInt(7, 0, 4);		
				temp = mBTconnection.readConnection();
				
				LCD.drawInt(8, 0, 4);
				if(temp.get(0) == 113)
				{
					if(temp.get(2) >= mStep.getQuality() )
						ParameterOK = true;
				}
				else {
					mStep.setTrys();
					ParameterOK= false;
				}
			
		LCD.drawInt(9, 0, 4);
			
		if(ParameterOK) {
			
			mStatus.setPosition();
			mStatus.setBehaviorStatus(mStatus.UseStation);
		}
		else
		{	
			mDifferentialPilot.forward();
			mDifferentialPilot.goStraight();
			mStatus.setPosition(mStatus.getPosition() + 2);
			mStatus.setBehaviorStatus(mStatus.Follow);
		}

	}

	@Override
	public void suppress() {
		suppressed = true;

	}

}
