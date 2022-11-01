package ro.academyplus.avaj.sumulator;

public class AircraftFactory {
	public static IFlyable newAircraft(String type, String name, int longitude, int latitude, int height) throws Exception {
		
		if (height > 100)
			height = 100;
		if (height < 0)
			height = 0;
		if (longitude < 0 || latitude < 0)
			throw new Exception("Coordinates should be positive number");
		Coordinates coordinates = new Coordinates(longitude, latitude, height);

		if ("helicopter".equalsIgnoreCase(type))
			return new Helicopter(name, coordinates);
		if ("baloon".equalsIgnoreCase(type))
			return new Baloon(name, coordinates);
		return new JetPlane(name, coordinates);
	} 
}