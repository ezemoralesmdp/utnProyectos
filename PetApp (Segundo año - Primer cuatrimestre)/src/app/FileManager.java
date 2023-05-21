package app;

import java.io.BufferedWriter;
import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.NotSerializableException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.StreamCorruptedException;
import java.util.HashMap;
import java.util.Map;


public class FileManager {

	public static void saveAnUserInFile(User temporary) {
		
		//Aca guardamos el usuario en el archivo
		FileOutputStream fileOutputStream = null;
		ObjectOutputStream objectOutputStream = null;
		MyObjectOutputStream myObjectOutputStream = null;
		
		File file = new File("users.bin");
		
		try {
			
			if(!file.exists()) {
				
				fileOutputStream = new FileOutputStream(file);
				objectOutputStream = new MyObjectOutputStream(fileOutputStream);
				objectOutputStream.writeObject(temporary);
				
			} else {
				
				fileOutputStream = new FileOutputStream(file, true);
				myObjectOutputStream = new MyObjectOutputStream(fileOutputStream);
				myObjectOutputStream.writeObject(temporary);
			}
		
		} catch (IOException e) {
			
			e.printStackTrace();
			
		} finally {
			
			if(objectOutputStream != null) {
				try {
					objectOutputStream.close();
					
				} catch(IOException e) {
					System.out.println("Error al cerrar el achivo");
				}
			}
			
			if(fileOutputStream != null) {
				try {
					fileOutputStream.close();
				} catch(IOException e) {
					System.out.println("Error al cerrar el achivo");
				}
			}
		}
	}
	
	public static HashMap<String, User> readAndUploadUsersFileToHashmap() throws StreamCorruptedException
	{
		 
		HashMap<String, User> temporaryHM = new HashMap<>(); //HashMap temporal
		
		
		try 
		{
			
			FileInputStream fileInputStream = new FileInputStream("users.bin");
			ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);
			
			int lecture = 1;
			
			while(lecture == 1)
			{
				
				User aux = (User)objectInputStream.readObject();
				//System.out.println(aux);
				temporaryHM.put(aux.getUser(), aux);
				
			}
			
			objectInputStream.close();
			//fileInputStream.close();

		} catch (EOFException e) {
			
			System.out.println("Fin archivo");
			
		} catch(FileNotFoundException e) {
			e.printStackTrace();
			
		}catch (NotSerializableException e) {
            e.printStackTrace();
            
		}catch (IOException e) {
			e.printStackTrace();
			System.out.println("Error");
			
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
			
		} catch (Exception e) {
			
            e.printStackTrace();
        }
		
		
		return temporaryHM;
	}
}
