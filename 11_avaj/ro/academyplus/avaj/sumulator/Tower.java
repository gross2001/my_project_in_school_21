package ro.academyplus.avaj.sumulator;

import java.util.ArrayList;
import java.util.List;

public abstract class Tower {
	private	List<IFlyable> observers;

	public Tower() {
		this.observers = new ArrayList<>();
	}

	public void register(IFlyable flyable) {
		if (flyable == null)
			throw new NullPointerException("Null Observer");
		if (!observers.contains(flyable)) 
			observers.add(flyable);
	}

	public void unregister(IFlyable flyable) {
		observers.remove(flyable);
	}

	protected void conditionsChanged() {
		List<IFlyable> observersLocal = null;
		observersLocal = new ArrayList<>(this.observers);
		for (IFlyable obj : observersLocal) {
			obj.updateConditions();
		}
	}
}