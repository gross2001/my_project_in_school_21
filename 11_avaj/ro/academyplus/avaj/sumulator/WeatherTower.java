package ro.academyplus.avaj.sumulator;

public class WeatherTower extends Tower {

	public String getWeather(Coordinates coordinates) {
		WeatherProvider weatherProvider = WeatherProvider.getProvider();
		return weatherProvider.getCurrentWeather(coordinates);
	}

	void changeWeather() {
		super.conditionsChanged();
	}
}