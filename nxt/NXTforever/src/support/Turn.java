package support;

public class Turn {
	
	private int turn = 0;
	private boolean iscurve = false;
	private boolean isgrau = false;
	private boolean grauallowed = true;
	
	public int getTurn() {
		return turn;
	}
	
	public void setTurn(int turn) {
		this.turn = turn;
	}
	
	public boolean getiscurve() {
		return iscurve;
	}
	
	public void setiscurve(boolean iscurve) {
		this.iscurve = iscurve;
	}

	public boolean getisgrau() {
		return isgrau;
	}

	public void setisgrau(boolean isgrau) {
		this.isgrau = isgrau;
	}

	public boolean getGrauallowed() {
		return grauallowed;
	}

	public void setGrauallowed(boolean grauallowed) {
		this.grauallowed = grauallowed;
	}

}
