package ro.academyplus.avaj.sumulator;

public class Baloon extends Aircraft implements IFlyable {

	private WeatherTower weatherTower;

	Baloon(String name, Coordinates coordinates) {
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
				longitude += 2;
				height += 4;
				message = "SUN";
				break;
			case "RAIN":
				height -= 5;
				message = "RAIN";
				break;
			case "FOG":
				height -= 3;
				message = "FOG";
				break;
			case "SNOW":
				height -= 15;
				message = "SNOW";
		}

		super.coordinates = new Coordinates(longitude, latitude, height);
		System.out.printf("%s%s%s%d%s%s%s", "Baloon#", super.name, "(", super.id, "): ",  message, "\n");

		if (height <= 0) {
			System.out.printf("%s%s%s%d%s", "Baloon#", super.name, "(", super.id, ") landing\n");
			weatherTower.unregister(this);
			System.out.printf("%s %s %s", "Tower says:", "Baloon" + "#" + this.name + "(" + this.id + ")", "unregistered from weather tower.\n");

		}
	}

	public void registerTower(WeatherTower weatherTower) {
		this.weatherTower = weatherTower;
		weatherTower.register(this);
		System.out.printf("%s %s %s", "Tower says:", "Baloon" + "#" + this.name + "(" + this.id + ")", "registered to weather tower.\n");
	}
}