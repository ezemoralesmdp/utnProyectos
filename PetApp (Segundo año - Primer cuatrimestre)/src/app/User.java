package app;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Objects;

public class User implements Serializable {
	
	//Atributes
	private String user;
	private String password;
	private String email;
	private String name;
	private int age;
	private ArrayList <Animal> animals;
	private LinkedList <Appointment> listOfAssignedAppointments;
	private boolean isEnabledForFostering;
	private Wallet myWallet;
	
	//Constructor
	public User() {
		//Constructor vacio porque seteamos todos los atributos desde el registro (PetApp.java)
		animals = new ArrayList<Animal>(); //Inicializamos la lista de animales del usuario vacia para luego utilizar metodos
		myWallet = new Wallet();
		listOfAssignedAppointments = new LinkedList<>();
	}

	//Getters & Setters
	public String getUser() {
		return user;
	}

	public void setUser(String user) {
		this.user = user;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public void addAnimal(Animal animal) {
		animals.add(animal);
	}
	
	public void removeAnimal(int animal) {
		animals.remove(animal);
	}
	
	public void addAnimalAfterEdit(int index, Animal animal) {
		animals.add(index, animal);
	}

	public boolean isEnabledForFostering() {
		return isEnabledForFostering;
	}

	public void setEnabledForFostering(boolean isEnabledForFostering) {
		this.isEnabledForFostering = isEnabledForFostering;
	}	
	
	public String getEmail() {
		return email;
	}
	
	public void setEmail(String email) {
		this.email = email;
	}
	
	public Wallet getMyWallet() {
		return myWallet;
	}
	
	public void setMyWallet(Wallet myWallet) {
		this.myWallet = myWallet;
	}
	
	public LinkedList<Appointment> getListOfAssignedAppointments() {
		
		if(listOfAssignedAppointments.size() > 0) {
			return listOfAssignedAppointments;
		}else {
			return null;
		}
	}
	
	public ArrayList<Animal> getAnimals() {
		
		if(animals.size() > 0) {
			return animals;
		} else{
			return null;
		}		
	}
	
	public void showListOfAnimals() {
        
        for (Animal animal : animals) {
        	System.out.println(animal.getName());
		}
    }
	
	public void setAnimals(ArrayList<Animal> animals) {
		this.animals = animals;
	}
	
	public void setListOfAssignedAppointments(LinkedList<Appointment> listOfAssignedAppointments) {
		this.listOfAssignedAppointments = listOfAssignedAppointments;
	}

	@Override
	public int hashCode() {
		return Objects.hash(user);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (!(obj instanceof User))
			return false;
		User other = (User) obj;
		return Objects.equals(user, other.user);
	}
	
	public void addAppointment(Appointment appointment) {
		
		listOfAssignedAppointments.addLast(appointment);
		
	}	
	
	@Override
	public String toString() {
		
		String aux = "";
		
		aux = "Usuario: " + user + "\n" + 
			  "Nombre: " + name + "\n" + 
			  "Correo electronico: " + email + "\n" +
			  "Edad: " + age + "\n" + 
			  "Transito: " + isEnabledForFostering + "\n" +
			  "Mascotas: " + animals + "\n" +
			  "Turnos: " + listOfAssignedAppointments;
		
		return aux;
	}
}