package app;

import java.util.*;

public class UserMenuApp implements I_Administration {

	Scanner input = new Scanner(System.in);
	PetShop shop;
	PetAppointment appointment;
	User loggedUser;
	ArrayList<Veterinary> veterinaries = JSONManager.readJson();

	// Constructor
	public UserMenuApp(User loggedUser, PetShop aPetShop, PetAppointment appointment) {
		this.loggedUser = loggedUser;
		this.shop = aPetShop;
		this.appointment = appointment;
	}

	public void menu(ArrayList<User> users) {

		int option = 0;
		boolean next = false;
		
		do {

			try {

				next = false;
				option = 0;

				System.out.println("\nBienvenido " + loggedUser.getName() + "!");
				System.out.println("SALDO ACTUAL: $" + loggedUser.getMyWallet().getAmount() + "\n");

				System.out.println("1) Reserva un Turno"); // x
				System.out.println("2) Ver veterinarias"); // x
				System.out.println("3) Agrega tu mascota"); // x
				System.out.println("4) Poner en adopcion (No disponible)"); // --
				System.out.println("5) Ver mascotas en adopcion (No disponible)"); // --
				System.out.println("6) Ir a la tienda"); // x Ver mensajes que se invierten
				System.out.println("7) Opciones de usuario"); // x
				System.out.println("8) Cargar / Ver saldo"); // x
				System.out.println("9) Exportar datos de usuario"); // x
				
				System.out.println("\n0) Guardar y salir del programa");
				
				//Nombre, edad, los animales, turnos
				
				System.out.println();
				System.out.print("Opcion: ");
				option = input.nextInt();

				switch (option) {
				
				case 0:
					
					JSONManager.userArrayToJSONFile(users);
					System.out.println("Guardando datos y saliendo, Hasta Pronto!");
					
					break;

				// Reserva un Turno
				case 1:
					appointment.petAppointmentMenu(loggedUser, veterinaries);
					break;

				// Ver veterinarias
				case 2:
					menuVeterinaries();
					break;

				// Agrega tu mascota
				case 3:
					addAnimal();
					break;

				// Poner en adopcion
				case 4:
					break;

				// Ver mascotas en adopcion
				case 5:
					break;

				// Ir a la tienda
				case 6:
					shop.shopMenu();
					break;

				// Opciones de usuario
				case 7:
					editUser();
					break;

				//Cargar y mostrar billetar
				case 8:
					loadAndViewMoneyInMyWallet();
					break;
					
				//Exportar información personal
				case 9:
					exportPersonalInfo();
					break;

				default:
					System.out.println("\n[!] Error. Numero de operacion incorrecta, por favor vuelva a ingresar la opcion.");
					break;
				}
				
			} catch (InputMismatchException e) {

				input.next();
				System.out.println("\n[!] Debe ingresar obligatoriamente un número entero.");
				next = true;
			}

		} while ((option >= 1 || option >= 8) || next == true);
	}
	
	public void addAnimal() {

		int option = 0;
		boolean next = false;

		do {
			try {
				option=0;
				next=false;
				System.out.println("\n[ADMINISTRAR TUS MASCOTAS]\n");

				System.out.println("1) Agregar mascota");
				System.out.println("2) Editar mascota");
				System.out.println("3) Eliminar mascota");
				System.out.println("4) Ver todas tus mascotas");

				System.out.println();
				System.out.println("0) Salir");

				System.out.print("\nOpcion: ");
				option = input.nextInt();

				switch (option) {

				case 0:
					break;

				case 1:
					System.out.println("\n[AGREGAR MASCOTA]");
					add();
					break;

				case 2:
					System.out.println("\n[EDITAR MASCOTA]");
					edit();
					break;

				case 3:
					System.out.println("\n[REMOVER MASCOTA]");
					remove();
					break;

				case 4:
					System.out.println("\n[VER TODAS LAS MASCOTAS]");
					seeAll();
					break;
					
				default:
					System.out.println("\n[!] Error. Número de operación incorrecta, por favor vuelva a ingresar la opción");
					break;

				}
			} catch (InputMismatchException e) {

				input.next();
				System.out.println("\n[!] Debe ingresar obligatoriamente un número entero.");
				next = true;
			}

		} while ((option >= 1 || option >= 4) || next == true);

	}

	public void menuVeterinaries() {

		int option = 0;
		boolean next = false;

		do {

			try {
				next = false;
				option = 0;

				System.out.println("\n[VETERINARIAS DISPONIBLES]\n");

				System.out.println("Filtrar por: ");
				System.out.println("1) Castracion");
				System.out.println("2) Desparacitacion");
				System.out.println("3) Adopcion");
				System.out.println("4) Peluqueria");
				System.out.println("5) Venta de Articulos");
				System.out.println("6) Ver todas las veterinarias disponibles");

				System.out.println();
				System.out.println("0) Volver al menu principal");

				System.out.println();
				System.out.print("Opcion: ");

				option = input.nextInt();

				System.out.println();

				switch (option) {

					case 0:
						break;
	
					case 1:
						System.out.println("[FILTRADO POR CASTRACION]\n");
						filterByOption(option);
						break;
	
					case 2:
						System.out.println("[FILTRADO POR DESPARACITACIï¿½N]\n");
						filterByOption(option);
						break;
	
					case 3:
						System.out.println("[FILTRADO POR ADOPCION]\n");
						filterByOption(option);
						break;
	
					case 4:
						System.out.println("[FILTRADO POR PELUQUERIA]\n");
						filterByOption(option);
						break;
	
					case 5:
						System.out.println("[FILTRADO POR TIENDA - SHOP]\n");
						filterByOption(option);
						break;
	
					case 6:
						System.out.println("[MOSTRANDO TODAS LAS VETERINARIAS]\n");
						filterByOption(option);
						break;
	
					default: {
						System.out.println("[!] La opcion " + option + " es inexistente, por favor vuelva a intentarlo.");
						break;
					}
				}

			} catch (InputMismatchException e) {

				input.next();
				System.out.println("\n[!] Debe ingresar obligatoriamente un número entero.");
				next = true;
			}

		} while ((option >= 1 || option >= 6) || next == true);

	}

	public void filterByOption(int selectionCase) {

		if(selectionCase == 1) {
			for (Veterinary veterinary : veterinaries) {
				if(veterinary.getServices().isCastration() == true) {
					System.out.println(veterinary.toString());
				}
			}
		} else if (selectionCase == 2) {
			for (Veterinary veterinary : veterinaries) {
				if(veterinary.getServices().isDeparasitization() == true) {
					System.out.println(veterinary.toString());
				}
			}
		} else if(selectionCase == 3) {
			for (Veterinary veterinary : veterinaries) {
				if(veterinary.getServices().isAdoption() == true) {
					System.out.println(veterinary.toString());
				}
			}
		} else if(selectionCase == 4) {
			for (Veterinary veterinary : veterinaries) {
				if(veterinary.getServices().isGroomer() == true) {
					System.out.println(veterinary.toString());
				}
			}
		} else if(selectionCase == 5) {
			for (Veterinary veterinary : veterinaries) {
				if(veterinary.getServices().isShop == true) {
					System.out.println(veterinary.toString());
				}
			}
		} else if(selectionCase == 6) {
			for (Veterinary veterinary : veterinaries) {
				System.out.println(veterinary.toString());
			}
		}
	}

	public void loadAndViewMoneyInMyWallet() {

		int loadMoney = 0;
		double addCash = 0;

		do {
			
			System.out.println("\nTu saldo actual es de: $" + loggedUser.getMyWallet().getAmount());
			System.out.println("Desea cargar saldo?\n 1 - Si | 2 - No\n");
	
			System.out.print("Opcion: ");
	
			loadMoney = input.nextInt();
	
			if (loadMoney == 1) {
	
				System.out.print("Ingrese un monto: $");
	
				addCash = input.nextDouble();
	
				loggedUser.getMyWallet().addCash(addCash);
	
				System.out.println("\nFelicitaciones, se han cargado $" + addCash + ". Su saldo actual es de: $"
						+ loggedUser.getMyWallet().getAmount());
	
			}
			
			if(loadMoney != 1 && loadMoney != 2) {
				
				System.out.println("\n[!] Opcion incorrecta. Vuelva a intentarlo.");
				
			}
			
		}while(loadMoney != 1 && loadMoney != 2);
		
		System.out.println("\nVolviendo al menu principal...");
	}

	public void editUser() {

		int option = 0;
		int optionFostering = 0;
		boolean next = false;

		do {
			try {

				boolean isEnabledForFostering;

				System.out.println("\n[EDITAR USUARIO]");
				System.out.println("1) Ver informacion de usuario");
				System.out.println("2) Cambiar contrasenia");
				System.out.println("3) Cambiar direccion de correo electronico");
				System.out.println("4) Cambiar nombre");
				System.out.println("5) Cambiar edad");
				System.out.println("6) Cambiar disposicion a dar transito");

				System.out.println("\n0) Salir");

				System.out.println("\nOpcion: ");

				option = input.nextInt();
				input.nextLine();

				switch (option) {
				
				case 1:
					System.out.println(loggedUser.toString());
					break;

				case 2:
					System.out.print("Ingrese su nueva contraseÃ±a: ");
					loggedUser.setPassword(input.nextLine());
					System.out.println("La contrasenia ha sido modificada exitosamente !");
					break;

				case 3:
					System.out.print("Ingrese su nueva direccion de correo electronico: ");
					loggedUser.setEmail(input.nextLine());
					System.out.println("La direccion de correo electronico ha sido modificada exitosamente !");
					break;

				case 4:
					System.out.print("Ingrese su nuevo nombre: ");
					loggedUser.setName(input.nextLine());
					System.out.println("El nombre de usuario ha sido modificado exitosamente !");
					break;

				case 5:
					System.out.print("Ingrese su nueva edad: ");
					loggedUser.setAge(input.nextInt());
					System.out.println("La edad ha sido modificada exitosamente !");
					break;

				case 6:
					
					do {
		
						System.out.println(
								"\nActualmente su disposicion a dar transito es: " + loggedUser.isEnabledForFostering());
						System.out.println("Desea modificarlo? 1- Si | 2- No");
						System.out.print("Opcion: ");
						
						optionFostering = input.nextInt();
								
						if(optionFostering == 1) {
							
							isEnabledForFostering = (loggedUser.isEnabledForFostering() == true) ? false : true;
							loggedUser.setEnabledForFostering(isEnabledForFostering);
							System.out.println("La disposicion a dar transido ha sido modificada exitosamente !");
						}
						
						if(optionFostering != 1 && optionFostering != 2) {
							System.out.println("\n[!] Opcion incorrecta. Vuelva a intentarlo.");
						}
						
					}while(optionFostering != 1 && optionFostering != 2);
					
					break;
				}

				System.out.println();
			} catch (InputMismatchException e) {

				input.next();
				System.out.println("\n[!] Debe ingresar obligatoriamente un número entero.");
				next = true;
			}

		} while ((option >= 1 || option >= 6) || next==true);

	}

	@Override
	public void add() {

		String name = "";

		int optionSpecie = 0;

		String gender = "";
		int optionGender = 0;

		String healthStatus = "";
		int optionHealthStatus = 0;

		int age = 0;

		String breed = "";

		boolean isCastrate = false;
		int optionisCastrate = 0;
		
		boolean pasa = true;

		// Tipo de mascota
		
		do {
			
			System.out.println("Seleccione el tipo de mascota que desea agregar:\n");
			System.out.println("1- Perro");
			System.out.println("2- Gato");
			System.out.print("\nOpcion: ");
			optionSpecie = input.nextInt();
			
		}while(optionSpecie != 1 && optionSpecie != 2); //Contemplar ingreso de Strings para que se repita solo este menu

		// Nombre mascota
		System.out.println();
		input.nextLine();
		System.out.print("Ingrese el nombre de su mascota: ");
		name = input.nextLine();

		// Genero mascota
		System.out.println("\nIngrese el genero de su mascota:\n");
		System.out.println("1- Macho");
		System.out.println("2- Hembra");
		System.out.print("\nOpcion: ");

		optionGender = input.nextInt();

		if (optionGender == 1) {
			gender = "Macho";
		} else if (optionGender == 2) {
			gender = "Hembra";
		}

		// Estado de salud mascota
		System.out.println("\nIngrese el estado de su mascota:\n");
		System.out.println("1- Saludable");
		System.out.println("2- Reservado");
		System.out.println("3- Malo");
		System.out.print("\nOpcion: ");
		optionHealthStatus = input.nextInt();

		if (optionHealthStatus == 1) {
			healthStatus = "Saludable";
		} else if (optionHealthStatus == 2) {
			healthStatus = "Reservado";
		} else if (optionHealthStatus == 3) {
			healthStatus = "Malo";
		}

		// Edad
		System.out.print("\nIngrese la edad de su mascota: ");
		age = input.nextInt();

		// Raza
		input.nextLine();
		System.out.print("\nIngrese la raza de su mascota (Si no es de raza aclararlo): ");
		breed = input.nextLine();

		// Castracion
		System.out.println("\nConfirme si su mascota se encuentra castrada o no");
		System.out.println();
		System.out.println("1- Se encuentra castrada");
		System.out.println("2- No se encuentra castrada");
		optionisCastrate = input.nextInt();

		if (optionisCastrate == 1) {
			isCastrate = true;
		} else if (optionisCastrate == 2) {
			isCastrate = false;
		}

		if (optionSpecie == 1) {

			Dog aux = new Dog(name, "Canino", gender, healthStatus, age, breed, isCastrate);
			loggedUser.addAnimal(aux);
			System.out.println(aux.getName() + " ha sido agregado con exito !");

		} else if (optionSpecie == 2) {

			Cat aux = new Cat(name, "Felino", gender, healthStatus, age, breed, isCastrate);
			loggedUser.addAnimal(aux);
			System.out.println(aux.getName() + " ha sido agregado con exito !");
		}
	}

	@Override
	public void remove() {
		
		String name = "";
		int index = 0;
		System.out.print("Ingrese el nombre de la mascota que quiere eliminar: ");
		input.nextLine();
		name = input.nextLine();

		try {
			
			for (int i = 0; i < loggedUser.getAnimals().size(); i++) {
				
				if (loggedUser.getAnimals().get(i).getName().equals(name)) {
					name = loggedUser.getAnimals().get(i).getName();
					index = i;
					loggedUser.removeAnimal(index);
					System.out.println("\n[!] '" + name + "' ha sido eliminado exitosamente !");
					
				}else {
					System.out.println("\n[!] '" + name + "' no existe !");
				}
					
			}
			
		} catch (NullPointerException e) {
			
		}
	}

	@Override
	public void edit() {
		String name;
		int index;
		Animal aux = null;
		boolean find = false;

		String newName = "";

		int optionSpecie = 0;

		String gender = "";
		int optionGender = 0;

		String healthStatus = "";
		int optionHealthStatus = 0;

		int age = 0;

		String breed = "";

		boolean isCastrate = false;

		int optionisCastrate = 0;

		System.out.print("Ingrese el nombre de la mascota que quiere editar: ");
		input.nextLine();
		name = input.nextLine();

		for (int i = 0; i < loggedUser.getAnimals().size(); i++) {
			if (loggedUser.getAnimals().get(i).getName().equals(name)) {
				index = i;
				aux = loggedUser.getAnimals().get(index);
				find = true;

				// Nombre mascota
				System.out.println();
				System.out.print("Ingrese el nombre de su mascota: ");
				newName = input.nextLine();

				// Genero mascota
				System.out.println("\nIngrese el genero de su mascota:\n");
				System.out.println("1- Macho");
				System.out.println("2- Hembra");
				System.out.print("\nOpcion: ");

				optionGender = input.nextInt();

				if (optionGender == 1) {
					gender = "Macho";
				} else if (optionGender == 2) {
					gender = "Hembra";
				}

				// Estado de salud mascota
				System.out.println("\nIngrese el estado de su mascota:\n");
				System.out.println("1- Saludable");
				System.out.println("2- Reservado");
				System.out.println("3- Malo");
				System.out.print("\nOpcion: ");
				optionHealthStatus = input.nextInt();

				if (optionHealthStatus == 1) {
					healthStatus = "Saludable";
				} else if (optionHealthStatus == 2) {
					healthStatus = "Reservado";
				} else if (optionHealthStatus == 3) {
					healthStatus = "Malo";
				}

				// Edad
				System.out.print("\nIngrese la edad de su mascota: ");
				age = input.nextInt();

				// Raza
				input.nextLine();
				System.out.print("\nIngrese la raza de su mascota (Si no es de raza aclararlo): ");
				breed = input.nextLine();

				// Castracion
				System.out.println("\nConfirme si su mascota se encuentra castrada o no");
				System.out.println();
				System.out.println("1- Se encuentra castrada");
				System.out.println("2- No se encuentra castrada");
				optionisCastrate = input.nextInt();

				if (optionisCastrate == 1) {
					isCastrate = true;
				} else if (optionisCastrate == 2) {
					isCastrate = false;
				}

				aux.setName(newName);
				aux.setGender(gender);
				aux.setHealthStatus(healthStatus);
				aux.setAge(age);
				aux.setBreed(breed);
				aux.setCastrate(isCastrate);

				System.out.println(aux.getName() + " ha sido modificado con exito !");
			}
		}

		if (find == false) {
			System.out.println("La mascota con el nombre " + name + " no existe.");
		}
	}

	@Override
	public void seeAll() {
		
		ArrayList<Animal> animals = loggedUser.getAnimals();

		if(loggedUser.getAnimals() != null) {
			
			for(int i = 1; i < loggedUser.getAnimals().size(); i++) {
				
				System.out.println(animals.get(i).toString());
			}
			
		} else {
			System.out.println("\n[!] Usted no posee mascotas añadidas.");
		}
	}
	
	public void exportPersonalInfo() {
		
		JSONManager.createPersonalJSON(loggedUser);
		System.out.println("[!] 'myPersonalInfo.json' ha sido creado exitosamente !\n");
	}
}