package ro.academyplus.avaj.sumulator;

public abstract class Aircraft {
	protected long id;
	protected String name;
	protected Coordinates coordinates;
	private static long idCounter = 1;

	protected Aircraft(String name, Coordinates coordinates) {
		this.name = name;
		this.coordinates = coordinates;
		id = nextId();
	}

	private long nextId() {
		return idCounter++;
	}
}