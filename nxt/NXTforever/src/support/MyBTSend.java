package support;

import java.io.DataOutputStream;
import java.io.IOException;
import java.util.LinkedList;

import lejos.nxt.LCD;

public class MyBTSend extends Thread {
	
	private MyBTconnection mBTconnection = MyBTconnection.getInstance();
	
	private DataOutputStream dataOut = mBTconnection.getOutputStream();
	
	//Schlange was gesendet werden muss
	LinkedList<byte[]> queue = new LinkedList<byte[]>();
	
	public MyBTSend() {
	}
	
	public void run() {
		
		if(!queue.isEmpty()) {
			try {
				dataOut.write(queue.get(0),0,queue.get(0).length);
				dataOut.flush();
			} catch (IOException e) {
				e.printStackTrace();
			}

			queue.remove(0);
		}
		
		try {
			Thread.yield();
			Thread.sleep(100);
		} catch (InterruptedException e) {
			LCD.clear();
			LCD.drawString("Fehler beim Senden.", 0, 0);
			LCD.drawString(e.getMessage(), 0,1);
		}
		
	}

	public synchronized void send(byte[] out) {
		queue.add(out);
	}
	
	
}
