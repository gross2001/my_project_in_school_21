package ro.academyplus.avaj.sumulator;

import java.io.*;
import java.util.*;

public class Parser  implements AutoCloseable {

	public int weatherChangeNumb;
	public String type;
	public String name;
	public int longitude;
	public int latitude;
	public int height;

	private String line;
	private String fileName;
	private BufferedReader br;

	public Parser(String fileName) throws Exception {
		this.fileName = fileName;
		br = new BufferedReader(new FileReader(fileName));
		parseFirstLine();
	}

	private void parseFirstLine() throws Exception {
		line = br.readLine();
		weatherChangeNumb = Integer.parseInt(line);
	}

	public String parseLine() throws Exception {
		line = br.readLine();
		while (line != null && line.trim().isEmpty())
			line = br.readLine();
		if (line != null) {
			parseLine(line);
		}
		return line;
	}

	private void parseLine(String newLine) throws Exception {
		Scanner sc = new Scanner(newLine);
		while (sc.hasNext()) {
			type = sc.next();
			name = sc.next();
			longitude = sc.nextInt();
			latitude = sc.nextInt();
			height = sc.nextInt();
		}
		sc.close();
	}

    public void close() throws Exception {
        br.close();
    }
}