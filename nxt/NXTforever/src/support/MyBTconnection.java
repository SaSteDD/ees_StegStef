package support;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import lejos.nxt.LCD;
import lejos.nxt.comm.Bluetooth;
import lejos.nxt.comm.NXTConnection;

public class MyBTconnection {
	
	private static MyBTconnection instance = new MyBTconnection();
	private MyBTconnection() {}
	
	private DataOutputStream dataOut;
	private DataInputStream dataIn;
	
	
	public static MyBTconnection getInstance() {
        return instance;
    }
	
	private NXTConnection connection;	
	
	public void openConnection()
		{
			connection = Bluetooth.waitForConnection();
			connection.setIOMode(NXTConnection.RAW);
			dataOut = connection.openDataOutputStream();
		    dataIn = connection.openDataInputStream();
		    
		    //Sendenthread laufen lassen
		//    mSend.start();
		}
	
	public boolean checkConnection() {
		try{
			if(dataIn.available() > 0)
				return true;
		} catch (IOException e) {
			e.printStackTrace();
		}
		return false;
	}
	
	public List<Byte> readConnection() {	
		
		List<Byte> temp = new ArrayList<Byte>();
		
		try{
			while(dataIn.available() > 0)
				temp.add(dataIn.readByte());		
		} catch (IOException e) {
			LCD.clear();
			LCD.drawString("Fehler", 0, 0);
			LCD.drawString(e.getMessage(), 0, 1);
		}
		
		return temp;
	
	}
	
	public DataOutputStream getOutputStream(){
		return dataOut;		
	}
	
	public void sendConnection(byte[] out) {
			
			try {
				dataOut.write(out,0,out.length);
				dataOut.flush();
			} catch (IOException e) {
				e.printStackTrace();
			}
	}
		
}
