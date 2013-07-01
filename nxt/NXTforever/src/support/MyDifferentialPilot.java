package support;
import lejos.nxt.Motor;
import lejos.robotics.navigation.DifferentialPilot;


public class MyDifferentialPilot {
	
	private static MyDifferentialPilot instance = new MyDifferentialPilot();
	
	//Variablen
	private DifferentialPilot pilot  = new DifferentialPilot(56, 110, Motor.A, Motor.B);
	private boolean isStop = true;
	

	//Motor Parameter
	private int speed = 200;
	
	private MyDifferentialPilot() {
		pilot.setTravelSpeed(speed);
	}
	
	public static MyDifferentialPilot getInstance() {
        return instance;
    }
	
	public void forward(){
		isStop = false;
	}
	
	public void stop(){
		isStop = true;
		pilot.stop();
	}
	
	public void Turn(int turn){
		if(!isStop) {
				pilot.steer(-turn);
		}
		
	}

	public void toggleStartStop() {
		if(isStop)
			forward();
		else
			stop();
		
	}
	
	public void steer(){
		pilot.arc(0,90);
		
	}
	
	public void travel() {
		pilot.travel(120);
		pilot.steer(0);
	}

}
