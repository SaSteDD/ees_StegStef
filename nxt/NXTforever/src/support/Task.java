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
	
	public List<Step> getSteps(){
		return Steps;
	}
	
	/**
	 * Gibt den aktuellen Schritt zurück
	 * 
	 * @return Step
	 */
	public Step getStep(){
		return Steps.get(0);
	}
	
	/**
	 * Löscht den aktuellen Schritt
	 */
	public void removeStep(){
		Steps.remove(0);
	}
	/**
	 * Gibt zurück ob der Auftrag noch Schritte zu Verfügung hat
	 * 
	 * @return true, wenn Schritte da sind
	 */
	public boolean hasSteps(){
		return !Steps.isEmpty();
	}
	
	/**
	 *  Gibt zurück an wieviel Stationen schon angefragt wurde
	 * 
	 * @return 1..4 true, false
	 */
	public boolean hasTrys(){
		return Steps.get(0).getTrys() < 4 ;
	}
	
	/**
	 * 
	 * @return Schrittnumber, wenn alle Schritte abgearbeitet sind dann wird 99 zurüch gegeben
	 */
	public int getNumber(){
		if (Steps.size() > 0)
			return Steps.get(0).getNumber();
		
		return 99;
	}
}
