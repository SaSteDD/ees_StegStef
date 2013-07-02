package support;

import java.io.DataOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class MyBTSend extends Thread {
	
	private MyBTconnection mBTconnection = MyBTconnection.getInstance();
	
	private DataOutputStream dataOut = mBTconnection.getOutputStream();;
	private byte[] out;
	
	public MyBTSend(byte[] output) {
		
		this.out = output;
	}
	
	public void run() {
		try {
			dataOut.write(out,0,out.length);
			dataOut.flush();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	
}
