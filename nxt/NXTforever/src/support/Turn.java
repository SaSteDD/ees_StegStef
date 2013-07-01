package support;

public class Turn {
	
	private int turn = 0;
	private boolean objectal = false;
	private boolean objallowed = false;
	
	public int getTurn() {
		return turn;
	}
	
	public void setTurn(int turn) {
		this.turn = turn;
	}
	

	public void setobjallowed(boolean obj) {
		this.objallowed = obj;
	}
	
	public boolean isobjallowed() {
		return this.objallowed;
	}

	public boolean isObjectal() {
		return objectal;
	}

	public void setObjectal(boolean objectal) {
		this.objectal = objectal;
	}

}
