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
		Steps.add(new Step((byte)Steps.size(), type, quality, time));
	}
	
	public Step getStep(){
		return Steps.get(0);
	}
	
	public void removeStep(){
		Steps.remove(0);
	}
	
	public boolean hasSteps(){
		return Steps.size() > 0;
	}
}
