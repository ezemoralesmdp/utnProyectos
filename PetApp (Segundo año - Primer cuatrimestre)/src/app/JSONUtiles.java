package app;

import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import org.json.JSONArray;
import org.json.JSONObject;

	public class JSONUtiles {
		
	public static void grabar(JSONArray array) {
		
		try {
			FileWriter file = new FileWriter("users.json");
			file.write(array.toString());
			file.flush();
			file.close();

		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void grabar(JSONObject myPersonalInfo) {
		
		try {
			FileWriter file = new FileWriter("myPersonalInfo.json");
			file.write(myPersonalInfo.toString());
			file.flush();
			file.close();

		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static String leer(String archivo) 
	{
		String contenido = "";
		
		try 
		{
			contenido = new String(Files.readAllBytes(Paths.get(archivo + ".json")));
		} 
		catch (IOException e) 
		{
			e.printStackTrace();
		}
		
		return contenido;
	}
}