package support;

public class followLine {
	
	//PID Regler Parameter
	private int Kp = 1;	
	
	private int offset = 10;
	
	//Temporäre Variablen
	private Turn mturn = new Turn();
	
	private int error = 0;
	private int turn = 0;
	private int integral = 0;
	private int lastError = 0;
	private int derivative = 0;
	private int max = 80;
	
	private int lastRightValue = 0;
	private int result = 0;
	
	//Farben
	private int grauLeft;
	private int grauRight;
	
	public followLine(int graulinks, int graurechts){
		this.grauLeft = graulinks;
		this.grauRight = graurechts;
		
	}
	
	public Turn getFollowLine(int rechterSensor, int linkerSensor) {
		
		if(linkerSensor < 10 && rechterSensor > 10)
			mturn.setTurn(-rechterSensor);
		
		if(linkerSensor > 10 && rechterSensor < 10 )
			mturn.setTurn(linkerSensor);
		
		if(linkerSensor < 10 && rechterSensor < 10 ) {
			mturn.setTurn(0);
			mturn.setobjallowed(true);
		}
		
		if(linkerSensor > 30 && rechterSensor >30 ) 
			mturn.setObjectal(true);
		
		return mturn;
	}


	
}
