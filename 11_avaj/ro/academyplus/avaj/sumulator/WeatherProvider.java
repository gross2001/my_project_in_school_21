package ro.academyplus.avaj.sumulator;
 

public class WeatherProvider {
	private static WeatherProvider weatherProvider = new WeatherProvider();
	private static String[] weather = {"RAIN", "FOG", "SUN", "SNOW"};

	private WeatherProvider() {
	}

	public static WeatherProvider getProvider() {
		return weatherProvider;
	}

	public String getCurrentWeather(Coordinates coordinates) {
		int sum = coordinates.getLongitude() + coordinates.getLatitude() + coordinates.getHeight();
		
		long timestamp = System.currentTimeMillis() / 1000;

		if (sum < 50)
			return weather[(int) (timestamp + 0) % 4];
		if (sum < 100)
			return weather[(int) (timestamp + 1) % 4];
		if (sum < 150)
			return weather[(int) (timestamp + 2) % 4];
		return weather[(int)(timestamp + 3) % 4];
	}
}