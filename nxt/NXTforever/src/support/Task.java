package support;

import java.util.ArrayList;
import java.util.List;

public class Task {
	
	private List<Step> Steps;
	
	private int taskNumber;
	
	public Task(int TaskNumber) {
		this.taskNumber = TaskNumber;
		
		Steps = new ArrayList<Step>();
	}
	
	public void addStep(int type, int quality, int time) {
		Steps.add(new Step(Steps.size(), type, quality, time));
	}
	
}
