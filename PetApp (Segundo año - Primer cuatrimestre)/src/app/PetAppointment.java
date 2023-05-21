package app;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.Scanner;

public class PetAppointment {
	
	Scanner input = new Scanner(System.in);
	ArrayList<Veterinary> veterinaries;
	
	//Veterinarias
	public void availableShiftLoad(User loggedUser) {
		
		//Creo una lista doblemente enlazada que contrá los turnos
		LinkedList<Appointment> globalListAppointment = new LinkedList<>();
		
		//Turnos mañana
		Appointment mañana1 = new Appointment(1, "08:00", "28/06/2022", loggedUser.getName());
		Appointment mañana2 = new Appointment(2, "09:00", "28/06/2022", loggedUser.getName());
		Appointment mañana3 = new Appointment(3, "10:00", "28/06/2022", loggedUser.getName());
		Appointment mañana4 = new Appointment(4, "11:00", "28/06/2022", loggedUser.getName());
		Appointment mañana5 = new Appointment(5, "12:00", "28/06/2022", loggedUser.getName()); 
		
		//Turnos tarde
		Appointment tarde1 = new Appointment(6, "15:00", "28/06/2022", loggedUser.getName());
		Appointment tarde2 = new Appointment(7, "16:00", "28/06/2022", loggedUser.getName());
		Appointment tarde3 = new Appointment(8, "17:00", "28/06/2022", loggedUser.getName());
		Appointment tarde4 = new Appointment(9, "18:00", "28/06/2022", loggedUser.getName());
		Appointment tarde5 = new Appointment(10, "19:00", "28/06/2022", loggedUser.getName());
		
		//Turnos noche
		Appointment noche1 = new Appointment(11, "20:00","28/06/2022", loggedUser.getName());
		Appointment noche2 = new Appointment(12, "21:00","28/06/2022", loggedUser.getName());
		Appointment noche3 = new Appointment(13, "22:00","28/06/2022", loggedUser.getName());
		Appointment noche4 = new Appointment(14, "23:00","28/06/2022", loggedUser.getName()); 
		
		//Inserto turnos en la lista doblemente enlazada
		globalListAppointment.add(mañana1);
		globalListAppointment.add(mañana2);
		globalListAppointment.add(mañana3);
		globalListAppointment.add(mañana4);
		globalListAppointment.add(mañana5);
		
		globalListAppointment.add(tarde1);
		globalListAppointment.add(tarde2);
		globalListAppointment.add(tarde3);
		globalListAppointment.add(tarde4);
		globalListAppointment.add(tarde5);
		
		globalListAppointment.add(noche1);
		globalListAppointment.add(noche2);
		globalListAppointment.add(noche3);
		globalListAppointment.add(noche4);
		
		for (Veterinary veterinary : veterinaries) {
			
			//A todas las veterinarias les seteo la misma lista de turnos
			veterinary.setListOfAppointments(globalListAppointment);
		}
	}
	
	//----------------------------------------------------------------------------------------------------------------------------------
	
	public void petAppointmentMenu(User loggedUser, ArrayList<Veterinary> veterinaries) {
		
		boolean next = false;
		
		try {
		this.veterinaries = veterinaries;
		availableShiftLoad(loggedUser); //Cargo turnos en veterinarias
		selectPetUser(loggedUser);
		
		} catch (InputMismatchException e) {

			input.next();
			System.out.println("\n[!] Debe ingresar obligatoriamente un número entero.");
			next = true;
		}
	}
	
	//----------------------------------------------------------------------------------------------------------------------------------
	
	public void selectPetUser(User loggedUser)
	{
		String petsName = "";
		boolean flag = false;
		
		if(loggedUser.getAnimals() != null) {
			
			System.out.println("\n[!] Estas son tus mascotas actuales: ");
			loggedUser.showListOfAnimals(); //Muestra lista de animales
			System.out.print("\nIngrese el nombre de la mascota a la que desea sacarle un turno: ");
			petsName = input.nextLine();
			
			//Recorremos lista de animales del usuario
			for(int i = 0; i < loggedUser.getAnimals().size(); i++) {
				
				if(loggedUser.getAnimals().get(i).getName().equals(petsName)) {
					
					flag = true;
					//Mostrar turnos
					showAppoinmentsToUser();
					
					//Reservar y asignar turno
					appointmentMaking(loggedUser.getAnimals().get(i), loggedUser);
					
				} 
			}
			
			if(flag == false) {
				System.out.println("\n[!] " + petsName + " no existe ! Volviendo al menu principal...\n");
			}
			
		} else {
			System.out.println("\n[!] Usted no posee mascotas cargadas. Volviendo al menu principal...");
		}
		
	}
	
	public void appointmentMaking(Animal aPet, User loggedUser) {
		
		int chosenId = 0;
		int appointmentChoose = 0;
		int confirmShift = 0;
		Veterinary aux = null;
		
		do {
			
			System.out.print("[!] Seleccione una Veterinaria: ");
			chosenId = input.nextInt();
			
			if(chosenId < 1 || chosenId > 5) {
				
				System.out.println("\n[!] Error. Ingrese una opcion correcta.\n");
			}
			
		}while(chosenId < 1 || chosenId > 5);
		
		chosenId--;
			
		aux = veterinaries.get(chosenId);
			
		System.out.println(aux.toString());	
		
		System.out.println();
		
		LinkedList<Appointment> appointmentAux = null;
		appointmentAux = aux.getListOfAppointments();

		System.out.println("[TURNOS DISPONIBLES]:");
		System.out.println(appointmentAux.toString());
		
		System.out.print("\n[!] Ingrese el ID del turno que quiere escoger: ");
		appointmentChoose = input.nextInt();
		
		appointmentChoose--;
		
		Appointment appinChoose = null;
		appinChoose = appointmentAux.get(appointmentChoose);
		appointmentAux.remove(appointmentChoose);
		
		System.out.println("TURNO ESCOGIDO: " + appinChoose.toString());
		System.out.println("[?] Desea confirmar el turno? 1- Si | 2- No");
		confirmShift = input.nextInt();
		
		if(confirmShift == 1) {
			
			loggedUser.addAppointment(appinChoose);
		}
		
	}
	
	public void showAppoinmentsToUser() {
		
		int numberVeterinary = 0;

			for (Veterinary veterinary : veterinaries) {
				
				System.out.println(numberVeterinary+1 + ") VETERINARIA: " + veterinary.getName());
				numberVeterinary++;
			}
			
			System.out.println();
	}
}
