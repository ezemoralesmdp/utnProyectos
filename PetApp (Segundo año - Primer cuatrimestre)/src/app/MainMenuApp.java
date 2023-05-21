package app;

import java.io.IOException;
import java.io.StreamCorruptedException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;

public class MainMenuApp {
	
	//private HashMap<String, User> users = FileManager.readAndUploadUsersFileToHashmap(); //Recibe el hashmap temporal creado con los usuarios del archivo
	
	Scanner input = new Scanner(System.in);
	
	public HashMap<String, User> getHashMap() {
		
		HashMap<String, User> users = null;
		
		try {
			
			//Recibe el HashMap temporal cargado con los usuarios del archivo
			users = FileManager.readAndUploadUsersFileToHashmap();
			
		} catch (StreamCorruptedException e) {
	
			//e.printStackTrace();
		}  
		
		return users;
	}
	
	//Menu interactivo para el usuario
	public void menu() {
		
		int option = 0;
		//boolean goSingUp = false; 
		
		do {
			
			System.out.println("Bienvenido a Pet App!");
			
			System.out.println("1- Sign up"); //Registrarse
			System.out.println("2- Sign in"); //Iniciar de sesion
			System.out.println("3- Close app"); //Cerrar la aplicación
			
			option = input.nextInt();
			
			switch(option) {
			
				case 1:
					singUp(); //El usuario se registra
					//singIn(); //Lo redireccionamos directamente a iniciar sesion
					break;
					
				case 2:
					singIn();
					break;
					
				case 3:
					System.out.println("Vuelva pronto!");
					break;
					
				default:
					System.out.println("Error. Número de operación incorrecta, por favor vuelva a ingresar la opción");
					break;
			}
			
		} while(option < 1 || option > 3);
	}
	
	//Registro
	//Una vez que se crea el nuevo usuario, se carga al archivo
	public void singUp() {
		
		User temporary = new User(); //Usuario temporal para setear datos
		
		//Recorrer el HashMap y verificar los datos que necesitamos en cada instancia
		//Iterator<Map.Entry<String,User>> rows = users.entrySet().iterator();
		
		//try {
			
			//input.nextLine(); //Limpiamos el buffer
			
			boolean find = false; //Si encontro alguna coincidencia en el HashMap
	
			do {
					
					input.nextLine(); //Limpiamos el buffer
					
					System.out.println("Ingrese el nombre de usuario: ");
					String key = input.nextLine();
										
					//Contemplar cuando el archivo no existe
					if(getHashMap().containsKey(key)) //Busca en el HashMap (por clave) si el username ya existe
					{
						System.out.println("El usuario ya existe, por favor registre uno nuevo username o inicie sesión");
						find = true;
					}
					else
					{
						temporary.setUser(key); //Guardamos el username
						find = false;
					}
					
				} while(find == true);
			
//			input.nextLine();
//			
//			System.out.println("Ingrese el nombre de usuario: ");
//			String key = input.nextLine();
//			temporary.setUser(key);

			System.out.println("Ingrese la contraseña: ");
			temporary.setPassword(input.nextLine());
			
			System.out.println("Ingrese el correo electrónico: ");
			temporary.setEmail(input.nextLine());
			
			System.out.println("Ingrese su nombre: ");
			temporary.setName(input.nextLine()); 
			
			System.out.println("Ingrese su edad: ");
			temporary.setAge(input.nextInt());
			
			System.out.println("¿Esta dispuesto a dar tránsito a animales? 1- Si || 2- No");
			int response = input.nextInt();
			
			if(response == 1) {
				temporary.setEnabledForFostering(true);
			}else {
				temporary.setEnabledForFostering(false);
			}
			
			FileManager.saveAnUserInFile(temporary); //Mandamos el usuario creado a la función que lo guarda en el archivo
			
			System.out.println(temporary.getUser() + " fue registrado exitosamente!");
			
		//}catch(Exception e) {
			
		//}
	}
	
	//Inicio de sesión
	//Primero se carga el archivo a un HashMap y se busca en él al usuario, por clave.
	public void singIn() {
		
		String name;
		String password;
		
		try {
			
			System.out.println("Ingrese el nombre de usuario: ");
			name = input.nextLine();
			
			input.nextLine();
			
			System.out.println("Ingrese la contraseña: ");
			password = input.nextLine();
			
			//mandar al menu interno de user
			
		}catch(Exception e) {
			
		}
	}
	
}
