package support;

public class followLine {
	
	//PID Regler Parameter
	private int Kp = 100;			//mal 1000
	private int Ki = 0;			//mal 1000
	private int Kd = 0;			//mal 1000
	private int Tp = 50;			//mal 1000
	
	private int offset = 50;        //offset um den Geregelt wird
	
	//Temporäre Variablen
	private int error = 0;
	private int turn = 0;
	private int integral = 0;
	private int lastError = 0;
	private int derivative = 0;
	private int max = 80;
	
	private int lastRightValue = 0;
	private int result = 0;
	
	public followLine(){
		//mhh, hier werde ich wohl noch nen bissel was machen
	}
	
	public int getFollowLine(int linkerSensor, int rechterSensor) {
		if( rechterSensor > 20 )
			result = FollowEdgeMiss(rechterSensor);
		else
			result = -175;
		
		return result;
	}
	
	/**
	 * PID Regler, gibt Sollwert zum Lenken zurück. Kalibriert um auf der Linie zu fahren.
	 * 
	 * @param LightValue - Lichtwert (1 ... 100)
	 * @return
	 */
	public int FollowEdgeMiss(int LightValue){
		
		error = LightValue - offset;
		integral = integral + error;
		derivative = derivative - lastError;
		turn = Kp*error + Ki*integral + Kd*derivative;
		turn = turn/100;
		lastError = error;
		
		if(turn > max)
			return 80;
		else
			return turn;
		
	}
	
}
