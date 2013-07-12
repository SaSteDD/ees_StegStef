package support;
import lejos.nxt.LCD;
import lejos.nxt.Motor;
import lejos.nxt.Sound;
import lejos.robotics.navigation.DifferentialPilot;


public class MyDifferentialPilot {
	
	private static MyDifferentialPilot instance = new MyDifferentialPilot();
	private MyLightSensors mLightSensors = MyLightSensors.getInstance();
	
	//Variablen
//	private DifferentialPilot pilot  = new DifferentialPilot(56, 110, Motor.A, Motor.B);
	private boolean isStop = true;
	

	//Motor Parameter
	private int speed = 400;
	
	private MyDifferentialPilot() {
		Motor.A.setSpeed(400);// 2 RPM
		Motor.B.setSpeed(400);
		Motor.A.setAcceleration(24000);
		Motor.B.setAcceleration(24000);
	}
	
	public static MyDifferentialPilot getInstance() {
        return instance;
    }
	
	public void forward(){
		isStop = false;
		Motor.A.forward();
		Motor.B.forward();
	}
	
	public void stop(){
		isStop = true;
		Motor.A.stop(true);
	    Motor.B.stop();
	}

	public void toggleStartStop() {
		if(isStop)
			forward();
		else
			stop();
		
	}
	
	public void goStraight(){
		Motor.A.setSpeed(speed);
		Motor.B.setSpeed(speed);
		forward();
		while(followGrau());
	}
	
	public void turn(){
		Motor.A.setSpeed(speed/2);
		Motor.B.setSpeed(speed/2);
		Motor.B.backward();
		while(!findLine());
		Motor.B.forward();

		
		Motor.A.setSpeed(speed);
		Motor.B.setSpeed(speed);
		Motor.A.forward();
		Motor.B.forward();
	}
	
	public void steer(){
		Motor.A.setSpeed(200);
		Motor.B.setSpeed(400);
		Motor.B.backward();
		while(!findLineAfterCurve());
		Motor.B.forward();
		
		
	}
	
	public void steerRight(){
		Motor.A.setSpeed(0);
		Motor.A.backward();
		Motor.A.setSpeed(50);
		Motor.B.setSpeed(speed);
		while(!findLine()) {}
		Motor.A.setSpeed(speed);
		Motor.B.setSpeed(speed);
		Motor.A.forward();
		Motor.B.forward();
	}
	
	public boolean followGrau() {
		float rechterSensor = mLightSensors.getSensorRight();
		float linkerSensor = mLightSensors.getSensorLeft();
		
		
		float turn = 0;
		
		if(Math.abs(linkerSensor - rechterSensor) < 10)
			turn = 0;
		else
			turn = (rechterSensor - linkerSensor) / 2;
		
		
				
		if(linkerSensor < 20 || rechterSensor < 20 ) 
			return false;
		
//	Turn(turn);
		return true;
		
	}
	
	public boolean followLine() {
		float rechterSensor = mLightSensors.getSensorRight();
		float linkerSensor = mLightSensors.getSensorLeft();
		
		float turn = 0;
		
		if( rechterSensor > 10 )
		    if(linkerSensor < 10)
		    	turn = (float) (rechterSensor * 2);
		    else
		    	turn = (float) (rechterSensor * 2.5);
		
		if(linkerSensor > 10)
			if(rechterSensor < 10 )
				turn = (float) -(linkerSensor * 2);
			else
				turn = (float) -(linkerSensor * 2.5 );
		
		if(linkerSensor < 10 && rechterSensor < 10 ) {
			turn = 0;
		}
		
		if(linkerSensor > 30 && rechterSensor >30 ) 
			return false;
		
		Turn(turn);
		return true;
		
	}
	
	public boolean findLineAfterCurve() {
		
		float rechterSensor = mLightSensors.getSensorRight();
		float linkerSensor = mLightSensors.getSensorLeft();
		
		if(linkerSensor < 10 ) {
			return true;
		}
		
		return false;
	}
	
	public boolean findLine() {
		
		float rechterSensor = mLightSensors.getSensorRight();
		float linkerSensor = mLightSensors.getSensorLeft();
		
		if(linkerSensor < 10 && rechterSensor < 10 ) {
			return true;
		}
		
		return false;
	}
	
	public void Turn(float turn){
		if(!isStop) {
			Motor.A.setSpeed(speed - turn);
			Motor.B.setSpeed(speed + turn);	
		}
	}

}
