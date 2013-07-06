package support;

public class Step {
	
	private byte number;
	private byte type;
	private byte quality;
	private byte time;
	private byte trys = 0;
	
	public Step(byte nummer, byte typ, byte qualit�t, byte zeit) {
		this.number = nummer;
		this.type = typ;
		this.quality = qualit�t;
		this.time = zeit;
	}
	
	public int getTrys(){
		return trys;
	}
	
	public void setTrys(){
		trys++;
	}

	public byte getQuality() {
		return  quality;
	}

	public byte getType() {
		return  type;
	}

	public byte getNumber() {
		return  number;
	}

	public int getTime() {
		return time;
	}
	
}
