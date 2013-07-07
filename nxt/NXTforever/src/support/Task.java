package support;

import java.util.ArrayList;
import java.util.List;

public class Task {
	
	public List<Step> Steps;
	
	private int taskNumber;
	
	public Task(int TaskNumber) {
		this.taskNumber = TaskNumber;
		
		Steps = new ArrayList<Step>();
	}
	
	public void addStep(byte type, byte quality, byte time) {
		Steps.add(new Step((byte)(Steps.size()+1), type, quality, time));
	}
	
	/**
	 * Gibt den aktuellen Schritt zur�ck
	 * 
	 * @return Step
	 */
	public Step getStep(){
		return Steps.get(0);
	}
	
	/**
	 * L�scht den aktuellen Schritt
	 */
	public void removeStep(){
		Steps.remove(0);
	}
	/**
	 * Gibt zur�ck ob der Auftrag noch Schritte zu Verf�gung hat
	 * 
	 * @return true, wenn Schritte da sind
	 */
	public boolean hasSteps(){
		return !Steps.isEmpty();
	}
	
	/**
	 *  Gibt zur�ck an wieviel Stationen schon angefragt wurde
	 * 
	 * @return 1..4 true, false
	 */
	public boolean hasTrys(){
		return Steps.get(0).getTrys() < 4 ;
	}
	
	/**
	 * 
	 * @return Schrittnumber, wenn alle Schritte abgearbeitet sind dann wird 99 zur�ch gegeben
	 */
	public int getNumber(){
		if (Steps.size() > 0)
			return Steps.get(0).getNumber();
		
		return 99;
	}
}
