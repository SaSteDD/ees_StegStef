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
		Motor.A.stop();
		Motor.B.stop();
	}

	public void toggleStartStop() {
		if(isStop)
			forward();
		else
			stop();
		
	}
	
	public void turn(){
		Motor.A.setSpeed(speed/2);
		Motor.B.setSpeed(speed/2);
		Motor.B.backward();
		while(!findLine());
		Motor.B.forward();
		Motor.B.setSpeed(speed*2);
		
		try {
			Thread.yield();
			Thread.sleep(100);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		Motor.A.setSpeed(speed);
		Motor.B.setSpeed(speed);
		Motor.A.forward();
		Motor.B.forward();
	}
	
	public void steer(int force){
		Motor.B.backward();
		while(!findLine());
		Motor.B.forward();
		Motor.B.setSpeed(600);

		try {
		Thread.yield();
		Thread.sleep(100);
		} catch (InterruptedException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
		}
	}
	
	public void steerRight(){
		Motor.A.setSpeed(0);
		Motor.B.setSpeed(speed);
		Motor.A.backward();
		Sound.beep();
		while(!findLine()) {
			
			try {
				Thread.yield();
				Thread.sleep(100);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		Sound.beep();
		Motor.A.forward();
		Motor.A.setSpeed(speed);
		Motor.B.setSpeed(speed);
		Motor.A.forward();
		Motor.B.forward();
	}

	public boolean followLine(int force) {
		float rechterSensor = mLightSensors.getSensorRight();
		float linkerSensor = mLightSensors.getSensorLeft();
		
		float turn = 0;
		
		if(linkerSensor < 10 && rechterSensor > 10)
			turn = (float) (rechterSensor * force);
		
		if(linkerSensor > 10 && rechterSensor < 10 )
			turn = (float) (-linkerSensor * force);
		
		if(linkerSensor < 10 && rechterSensor < 10 ) {
			turn = 0;
		}
		
		if(linkerSensor > 30 && rechterSensor >30 ) 
			return false;
		
		Turn(turn);
		return true;
		
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
		Motor.A.setSpeed(speed - turn);
		Motor.B.setSpeed(speed + turn);	
	}

}
