package app;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class MainMenuApp2 {

	Scanner input = new Scanner(System.in);
	private ArrayList<User> users;

	public MainMenuApp2() {
		users = new ArrayList<User>();
	}

	public void menu() {

		int option = 0;
		boolean next = false;
		
		do {
			try {
				next=false;
				boolean error = true;
				users = JSONManager.JSONtoUsersArray();
			
			System.out.println("Bienvenido a Pet App!");

			System.out.println("1- Sign up"); // Registrarse
			System.out.println("2- Sign in"); // Iniciar de sesion
			System.out.println("3- Close app"); // Cerrar la aplicación

			option = input.nextInt();

			switch (option) {

			case 1:
				while (error == true) {
					try {
						signUp();
						error = false;
						option = 0;
					} catch (userAlredyExists e) {
						System.out.println(e.getMessage());
					}
				}
				break;

			case 2:
				input.nextLine();
				// error = true;
				while (error == true) {

					if (users.size() == 0) {
						System.out.println("No hay usuarios registrados, registrese primero");
						option = 0;
					} else {
						try {
							signIn();
							error = false;
						} catch (WrongUserException e) {
							System.out.println(e.getMessage());
						} catch (WrongPassException e) {
							System.out.println(e.getMessage());
						}
					}
				}
				break;

			case 3:
				System.out.println("Vuelva pronto!");
				break;

			default:
				System.out.println("Error. Número de operación incorrecta, por favor vuelva a ingresar la opción");
				break;
			}
		} catch (InputMismatchException e) {

			input.next();
			System.out.println("\n[!] Debe ingresar obligatoriamente un número entero.");
			next = true;
		}

		} while ((option < 1 || option > 3) || next == true);
	}

	public void signUp() throws userAlredyExists {

		User aux = new User();
		boolean fileExists = false;
		boolean wrongUser = true;
		boolean newUser = false;

		input.nextLine();

		while (wrongUser) {
			System.out.println("Ingrese el nombre de usuario: ");
			aux.setUser(input.nextLine());

			if (users.size() == 0) {
				System.out.println("No existen usuarios registrados, se creara una nueva base de datos...");
				wrongUser = false;
				fileExists = false;
			} else {
				for (int i = 0; i < users.size(); i++) {
					if (aux.equals(users.get(i))) {
						wrongUser = true;
						break;
					} else {
						newUser = true;
						wrongUser = false;
					}
				}
				fileExists = true;
			}
			if (wrongUser) {
				throw new userAlredyExists("El usuario: ", aux.getUser());
			}
		}

		if (wrongUser == false) {
			System.out.println("Ingrese la contraseña: ");
			aux.setPassword(input.nextLine());
			System.out.println("Ingrese el correo electrónico: ");
			aux.setEmail(input.nextLine());
			System.out.println("Ingrese su nombre: ");
			aux.setName(input.nextLine());
			System.out.println("Ingrese su edad: ");
			aux.setAge(input.nextInt());
			System.out.println("¿Esta dispuesto a dar tránsito a animales? 1- Si || 2- No");
			int response = input.nextInt();

			if (response == 1) {
				aux.setEnabledForFostering(true);
			} else {
				aux.setEnabledForFostering(false);
			}
		}

		if (fileExists == false) {
			JSONManager.createJSON(aux);
			System.out.println(aux.getUser() + " fue registrado exitosamente!");
		}
		if (newUser == true) {
			JSONManager.newUser(aux);
			System.out.println(aux.getUser() + " fue registrado exitosamente!");
		}
	}

	public void signIn() throws WrongUserException, WrongPassException {

		System.out.println("Ingrese el nombre de usuario: ");
		String userName = input.nextLine();
		boolean userError = false;
		boolean wrongPass = true;

		for (int i = 0; i < users.size(); i++) {
			if (users.get(i).getUser().equals(userName)) {
				userError = false;
				while (wrongPass == true) {
					System.out.println("Ingrese la contraseña: ");
					String password = input.nextLine();
					if (users.get(i).getPassword().equals(password)) {
						UserMenuApp userOperation=new UserMenuApp(users.get(i),new PetShop(users.get(i)), new PetAppointment());
						userOperation.menu(users);
						wrongPass = false;
					} else {
						throw new WrongPassException("Contraseña incorrecta, vuelva a intentar");
					}
				}
				break;
			} else {
				userError = true;
			}
		}
		if (userError) {
			throw new WrongUserException("El usuario:", userName);
		}

	}
}
