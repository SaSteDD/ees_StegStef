package support;
import lejos.nxt.Motor;
import lejos.robotics.navigation.DifferentialPilot;


public class MyDifferentialPilot {
	
	private static MyDifferentialPilot instance = new MyDifferentialPilot();
	private MyLightSensors mLightSensors = MyLightSensors.getInstance();
	
	//Variablen
//	private DifferentialPilot pilot  = new DifferentialPilot(56, 110, Motor.A, Motor.B);
	private boolean isStop = true;
	

	//Motor Parameter
	private int speed = 200;
	
	private MyDifferentialPilot() {
		Motor.A.setSpeed(200);// 2 RPM
		Motor.B.setSpeed(200);
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
	
	public void steer(){
		Motor.B.setSpeed(300);
		Motor.B.backward();
		while(!followLine());
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
	
	
	public void travel() {
		Motor.A.setSpeed(400);
		Motor.B.setSpeed(400);
		while(!followLine());
		
	}

	public boolean followLine() {
		float rechterSensor = mLightSensors.getSensorRight();
		float linkerSensor = mLightSensors.getSensorLeft();
		
		float turn = 0;
		
		if(linkerSensor < 10 && rechterSensor > 10)
			turn = (float) (rechterSensor * 2);
		
		if(linkerSensor > 10 && rechterSensor < 10 )
			turn = (float) (-linkerSensor * 2);
		
		if(linkerSensor < 10 && rechterSensor < 10 ) {
			turn = 0;
		}
		
		if(linkerSensor > 30 && rechterSensor >30 ) 
			return false;
		
		Turn(turn);
		return true;
		
	}
	
	public void Turn(float turn){
		Motor.A.setSpeed(400 - turn);
		Motor.B.setSpeed(400 + turn);	
	}

}
