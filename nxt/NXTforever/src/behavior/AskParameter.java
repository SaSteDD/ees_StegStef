package behavior;

import java.util.List;

import support.MyBTconnection;
import support.MyDifferentialPilot;
import support.MyLightSensors;
import support.Position;
import java.util.List;
import lejos.nxt.LCD;
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
		LCD.clear();
		Sound.beep();
		//nächsten Schritt holen
		mStep = mStatus.getStep();
		
			/*
			 *Format for Message of nxt(Receive):
			 *     [qualityChar]  [Station-Nr (1-4)]
			 *BNr.      1                 2
			 *
			 *Example:  q                  1
			 * 
			 * Stationsnummer: mark1=4;mark2=7;mark3=10;mark4=13;
			 * 
			 */
			switch(mStatus.getPosition()) {
			case 4: Station=1; break;
			case 7: Station=2; break;
			case 10: Station=3; break;
			case 13: Station=4; break;
			}
			Sound.beep();
			byte[] out = new byte[] {113,(byte) Station } ;
			mBTconnection.sendConnection(out);
			Sound.beep();
			//solange Warten, bis Antwort kommt
			while(!suppressed && (mStatus.getBehaviorStatus() == this) && !mBTconnection.checkConnection())
				Sound.beep();
			/*Mitteilung auswerten
			 * *Format for Message of RasPi (send):
			 *     [qualityChar] [StationType]  [Quality]
			 *
			 *BNr:           1           2              3
			 *Example:       q           2              4
			 */
			temp = mBTconnection.readConnection();
			Sound.beep();
			if(temp.get(0) == 113)
			{
				if(temp.get(1) == mStep.getType() && temp.get(2) >= mStep.getQuality() )
					ParameterOK = true;
			}
			else {
				ParameterOK= false;
			}

		
		if(ParameterOK) {
			
			mStatus.setPosition();
			mStatus.setBehaviorStatus(mStatus.UseStation);
		}
		else
		{
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
