package app;

import java.util.InputMismatchException;
import java.util.Scanner;

public class PetShop {

	Scanner input = new Scanner(System.in);

	private Stock<Toy> stockToys;
	private Stock<Clothe> stockClothes;
	private Stock<Food> stockFoods;
	private int amountToys = 5;
	private int amountClothes = 7;
	private int amountFoods = 10;

	// Usuario
	User loggedUser;

	// Juguetes
	Toy toy1 = new Toy("Pelota De Goma Caucho Maciza Para Perros 7.5 Cm", 1099.99);
	Toy toy2 = new Toy("Cuerda con nudos Perros", 1099.99);
	Toy toy3 = new Toy("Puzzle para perros comedero", 6590.00);
	Toy toy4 = new Toy("Juguete Perro Cuerda Circular", 3000);
	Toy toy5 = new Toy("Pescado Interactivo con Carga Micro USB", 5490.69);
	Toy toy6 = new Toy("Pelota Porfiada, Ratón y Plumas", 1200.50);

	// Ropas
	Clothe clothe1 = new Clothe("Poncho Capa Buzo Abrigo Polar Para Mascotas Talles Varios", 1445.99);
	Clothe clothe2 = new Clothe("Campera abrigo mascota para perro cachorro", 2962.00);
	Clothe clothe3 = new Clothe("Polar rosa talle 2 Perro", 1599.00);
	Clothe clothe4 = new Clothe("Polar naranja talle 3", 1599.00);

	// Comidas
	Food food1 = new Food("Royal Canin Urinary Care", 17490.00);
	Food food2 = new Food("Royal Canin Ageing 12+ Feline", 23990.00);
	Food food3 = new Food("Royal Canin Urinary Care", 17490.00);
	Food food4 = new Food("Royal Canin Hepatic Feline 1.5 kg", 19990.00);
	Food food5 = new Food("Royal Canin Mother & Babycat", 12990.00);
	Food food6 = new Food("Royal Canin Gastrointestinal Canine", 17090.00);
	Food food7 = new Food("Hill´s L/D Canine 7.98 kg", 78500.00);
	Food food8 = new Food("Hill’s Science Diet Puppy", 17990.00);
	Food food9 = new Food("Hill´s Natural Training Treat", 4990.00);
	Food food10 = new Food("Royal Canin Puppy X-Small", 11490.00);

	public PetShop(User loggedUser) {
		this.loggedUser = loggedUser;
		stockToys = new Stock<Toy>();
		stockClothes = new Stock<Clothe>();
		stockFoods = new Stock<Food>();
	}

	public void cargarProductos() {

		// Cargamos 30 productos "Toy" de cada uno
		for (int i = 0; i < amountToys; i++) {
			stockToys.addProduct(toy1);
			stockToys.addProduct(toy2);
			stockToys.addProduct(toy3);
			stockToys.addProduct(toy4);
			stockToys.addProduct(toy5);
			stockToys.addProduct(toy6);
		}

		// Cargamos 28 productos "Clothe" de cada uno
		for (int i = 0; i < amountClothes; i++) {
			stockClothes.addProduct(clothe1);
			stockClothes.addProduct(clothe2);
			stockClothes.addProduct(clothe3);
			stockClothes.addProduct(clothe4);
		}

		// Cargamos 100 productos "Food" de cada uno
		for (int i = 0; i < amountFoods; i++) {
			stockFoods.addProduct(food1);
			stockFoods.addProduct(food2);
			stockFoods.addProduct(food3);
			stockFoods.addProduct(food4);
			stockFoods.addProduct(food5);
			stockFoods.addProduct(food6);
			stockFoods.addProduct(food7);
			stockFoods.addProduct(food8);
			stockFoods.addProduct(food9);
			stockFoods.addProduct(food10);
		}

	}

	public void shopMenu() {

		int option = 0;
		boolean next = false;

		do {
			try {
				option = 0;
				next = false;
				System.out.println("\n[SHOP - TIENDA]\n");

				System.out.println("1) Juguetes");
				System.out.println("2) Ropa");
				System.out.println("3) Alimentos");
				System.out.println("0) Salir");

				System.out.println();
				System.out.print("Opcion: ");

				option = input.nextInt();

				switch (option) {

				case 1:
					shopMenu_toys();
					break;

				case 2:
					shopMenu_clothes();
					break;

				case 3:
					shopMenu_foods();
					break;

				case 0:
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
			
		} while ((option >= 1 || option >= 3) || next == true);
	}

	public void shopMenu_toys() {

		boolean next = false;
		int option = 0;

		do {
			
			try {
				
				option = 0;
				next = false;

				System.out.println("\nStock actual de Juguetes: " + stockToys.getQuantity());
				System.out.println("Stock actual de Ropa: " + stockClothes.getQuantity());
				System.out.println("Stock actual de Alimentos: " + stockFoods.getQuantity() + "\n");

				stockToys.showProducts(amountToys);
				System.out.println("[!] Para volver al menu principal ingrese: 0 (cero)\n");

				System.out.print("[!] Ingrese indice del producto que desea comprar: ");
				option = input.nextInt();

				System.out.println("\nSALDO: " + loggedUser.getMyWallet().getAmount());

				switch (option) {

				case 0:
					break;
				
				case 1:
					purchaseOperationToy(toy1);
					break;

				case 2:
					purchaseOperationToy(toy2);
					break;

				case 3:
					purchaseOperationToy(toy3);
					break;

				case 4:
					purchaseOperationToy(toy4);
					break;

				case 5:
					purchaseOperationToy(toy5);
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

		} while ((option >= 1 || option >= 5) || next == true);
	}

	public void shopMenu_clothes() {

		int option = 0;
		boolean next = false;

		do {
			try {
				option = 0;
				next = false;

				System.out.println("\nStock actual de Ropa: " + stockClothes.getQuantity());
				System.out.println("Stock actual de Juguetes: " + stockToys.getQuantity());
				System.out.println("Stock actual de Alimentos: " + stockFoods.getQuantity() + "\n");

				stockClothes.showProducts(amountToys);
				System.out.println("[!] Para volver al menu principal ingrese: 0 (cero)\n");

				System.out.print("[!] Ingrese indice del producto que desea comprar: ");
				option = input.nextInt();

				System.out.println("\nSALDO: " + loggedUser.getMyWallet().getAmount());

				switch (option) {

				case 0:
					break;
				
				case 1:
					purchaseOperationClothe(clothe1);
					break;

				case 2:
					purchaseOperationClothe(clothe2);
					break;

				case 3:
					purchaseOperationClothe(clothe3);
					break;

				case 4:
					purchaseOperationClothe(clothe4);
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

		} while ((option >= 1 || option >= 4) || next == true);

	}

	public void shopMenu_foods() {

		int option = 0;
		boolean next = false;
		
		do {
			try {
				option = 0;
				next = false;

				System.out.println("\nStock actual de Alimentos: " + stockFoods.getQuantity());
				System.out.println("Stock actual de Juguetes: " + stockToys.getQuantity());
				System.out.println("Stock actual de Ropa: " + stockClothes.getQuantity() + "\n");

				stockFoods.showProducts(amountFoods);
				System.out.println("[!] Para volver al menu principal ingrese: 0 (cero)\n");

				System.out.print("[!] Ingrese indice del producto que desea comprar: ");
				option = input.nextInt();

				System.out.println("\nSALDO: " + loggedUser.getMyWallet().getAmount());

				switch (option) {

				case 0:
					break;
				
				case 1:
					purchaseOperationFood(food1);
					break;

				case 2:
					purchaseOperationFood(food2);
					break;

				case 3:
					purchaseOperationFood(food3);
					break;

				case 4:
					purchaseOperationFood(food4);
					break;

				case 5:
					purchaseOperationFood(food5);
					break;

				case 6:
					purchaseOperationFood(food6);
					break;

				case 7:
					purchaseOperationFood(food7);
					break;

				case 8:
					purchaseOperationFood(food8);
					break;

				case 9:
					purchaseOperationFood(food9);
					break;

				case 10:
					purchaseOperationFood(food10);
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

		} while ((option >= 1 || option >= 10) || next == true);
	}

	public void purchaseOperationToy(Toy product) {
		
		int confirmPurchase = 0;
		
		System.out.println(product.toString());

		System.out.println("[?] ¿Desea confirmar la compra?\n 1- Si | 2- No\n");

		System.out.print("Opcion: ");
		confirmPurchase = input.nextInt();
		
		if(confirmPurchase == 1) {
		
			if (loggedUser.getMyWallet().getAmount() > product.getPrice()) {
				loggedUser.getMyWallet().subtractionCash(product.getPrice());
				stockToys.removeProductPerPurchase(product);
	
				System.out.println("[!] Compra confirmada");
				System.out.println("Su saldo actual es de: $" + loggedUser.getMyWallet().getAmount());
				
			} else {
				System.out.println("No dispone de suficiente saldo para realizar la operacion.");
				System.out
						.println("Te faltan: $" + (product.getPrice() - loggedUser.getMyWallet().getAmount()));
			}
		}
	}
	
	public void purchaseOperationClothe(Clothe product) {
		
		int confirmPurchase = 0;
		
		System.out.println(product.toString());

		System.out.println("[?] ¿Desea confirmar la compra?\n 1- Si | 2- No\n");

		System.out.print("Opcion: ");
		confirmPurchase = input.nextInt();
		
		if(confirmPurchase == 1) {
			
			if (loggedUser.getMyWallet().getAmount() > product.getPrice()) {
				loggedUser.getMyWallet().subtractionCash(product.getPrice());
				stockClothes.removeProductPerPurchase(product);
				
				System.out.println("[!] Compra confirmada");
				System.out.println("Su saldo actual es de: $" + loggedUser.getMyWallet().getAmount());
				
			} else {
				System.out.println("No dispone de suficiente saldo para realizar la operacion.");
				System.out
				.println("Te faltan: $" + (product.getPrice() - loggedUser.getMyWallet().getAmount()));
			}
		}
	}
	
	public void purchaseOperationFood(Food product) {
		
		int confirmPurchase = 0;
		
		System.out.println(product.toString());

		System.out.println("[?] ¿Desea confirmar la compra?\n 1- Si | 2- No\n");

		System.out.print("Opcion: ");
		confirmPurchase = input.nextInt();
		
		if(confirmPurchase == 1) {
			
			if (loggedUser.getMyWallet().getAmount() > product.getPrice()) {
				loggedUser.getMyWallet().subtractionCash(product.getPrice());
				stockFoods.removeProductPerPurchase(product);
				
				System.out.println("[!] Compra confirmada");
				System.out.println("Su saldo actual es de: $" + loggedUser.getMyWallet().getAmount());
				
			} else {
				System.out.println("No dispone de suficiente saldo para realizar la operacion.");
				System.out
				.println("Te faltan: $" + (product.getPrice() - loggedUser.getMyWallet().getAmount()));
			}
		}
	}
}