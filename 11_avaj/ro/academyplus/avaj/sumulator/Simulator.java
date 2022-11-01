package ro.academyplus.avaj.sumulator;

import java.io.*; 

public class Simulator {
	public static void main(String[] args) {

		if (args.length != 1) {
			System.out.println("Incorrect number of args, should be one - name of file");
			System.exit(1);			
		}

		try (FileOutputStream f = new FileOutputStream("simulation.txt");) {
			System.setOut(new PrintStream(f));

			WeatherTower weatherTower = new WeatherTower();
			WeatherProvider weatherProvider = WeatherProvider.getProvider();
			int weatherChangeNumb = 0;

			try (Parser parser = new Parser(args[0])) {
				weatherChangeNumb = parser.weatherChangeNumb;
				while (parser.parseLine() != null) {
					IFlyable flyable = AircraftFactory.newAircraft(parser.type, parser.name, parser.longitude, parser.latitude, parser.height);
					flyable.registerTower(weatherTower);
				}
			} catch (Exception e) {
				System.out.printf("%s %s\n", "Uncorrect income data", e.toString());
				System.exit(1);
			}

			for (int i = 0; i < weatherChangeNumb; i++) {
				weatherTower.changeWeather();
			}

		} catch (Exception e) {
			System.out.printf("%s %s\n", "Incorrect output file", e.toString());
			System.exit(1);
		}

	
	}
}