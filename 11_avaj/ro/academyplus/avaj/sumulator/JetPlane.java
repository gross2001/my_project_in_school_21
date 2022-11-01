package ro.academyplus.avaj.sumulator;

public class JetPlane extends Aircraft implements IFlyable {
	
	private WeatherTower weatherTower;

	JetPlane(String name, Coordinates coordinates) {
		super(name, coordinates);
		weatherTower = new WeatherTower();
	}

	public void updateConditions() {
		String weather = weatherTower.getWeather(super.coordinates);

		int longitude = super.coordinates.getLongitude();
		int latitude = super.coordinates.getLatitude();
		int height = super.coordinates.getHeight();
		String message = "";

		switch(weather) {
			case "SUN":
				latitude += 10;
				height += 2;
				message = "SUN";
				break;
			case "RAIN":
				latitude += 5;
				message = "RAIN";
				break;
			case "FOG":
				latitude += 1;
				message = "FOG";
				break;
			case "SNOW":
				height -= 7;
				message = "SNOW";
			}

		super.coordinates = new Coordinates(longitude, latitude, height);	
		System.out.printf("%s%s%s%d%s%s%s", "JetPlane#", super.name, "(", super.id, "): ",  message, "\n");

		if (height <= 0) {
			System.out.printf("%s%s%s%d%s", "JetPlane#", super.name, "(", super.id, "): landing\n");
			weatherTower.unregister(this);
			System.out.printf("%s %s %s", "Tower says:", "JetPlane" + "#" + this.name + "(" + this.id + ")", "unregistered from weather tower.\n");
		}
	}

	public void registerTower(WeatherTower weatherTower) {
		this.weatherTower = weatherTower;
		weatherTower.register(this);
		System.out.printf("%s %s %s", "Tower says:", "JetPlane" + "#" + this.name + "(" + this.id + ")", "registered to weather tower.\n");
	}
}