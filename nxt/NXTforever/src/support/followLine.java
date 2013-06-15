package support;

public class followLine {
	
	//PID Regler Parameter
	private int Kp = 100;			//mal 1000
	private int Ki = 0;			//mal 1000
	private int Kd = 0;			//mal 1000
	
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
	
	public int getFollowLine(int rechterSensor) {
		error = rechterSensor - offset;
		integral = integral + error;
		
		if (Math.abs(integral) > 30)
			integral = (int) (30 * Math.signum(integral));
		
		derivative = derivative - lastError;
		turn = Kp*error + Ki*integral + Kd*derivative;
		turn = turn/100;
		lastError = error;
		
		return turn;
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
		
		if (Math.abs(integral) > 30)
			integral = (int) (30 * Math.signum(integral));
		
		derivative = derivative - lastError;
		turn = Kp*error + Ki*integral + Kd*derivative;
		turn = turn/100;
		lastError = error;
		
		return turn;
		
	}
	
}
