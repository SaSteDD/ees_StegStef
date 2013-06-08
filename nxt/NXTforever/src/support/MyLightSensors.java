package support;
import lejos.nxt.LightSensor;
import lejos.nxt.SensorPort;


public class MyLightSensors {

private static MyLightSensors instance = new MyLightSensors();
	
	private MyLightSensors() {}
	
	//Sensoren
	private LightSensor SensorLeft = new LightSensor(SensorPort.S1);
	private LightSensor SensorRight = new LightSensor(SensorPort.S2);

	
	public static MyLightSensors getInstance() {
        return instance;
    }
	
	public void setBlack(){
		SensorLeft.setLow(SensorLeft.getNormalizedLightValue());
		SensorRight.setLow(SensorRight.getNormalizedLightValue());
	}
	
	public void setWhite(){
		SensorLeft.setHigh(SensorLeft.getNormalizedLightValue());
		SensorRight.setHigh(SensorRight.getNormalizedLightValue());
	}
	
	public int getSensorLeft(){
		return SensorLeft.getLightValue();
	}
	
	public int getSensorRight(){
		return SensorRight.getLightValue();
	}
	
	public int getSensorLeftRaw(){
		return SensorLeft.getNormalizedLightValue();
	}
	
	public int getSensorRightRaw(){
		return SensorRight.getNormalizedLightValue();
	}
	
}
