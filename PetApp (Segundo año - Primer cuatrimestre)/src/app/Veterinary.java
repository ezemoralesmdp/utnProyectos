package app;

import java.util.*;

public class Veterinary {

	//Atributes
	private String name;
	private String openingHours;
	private String address;
	private String neighborhood;
	private String description;
	
	private Service services;
	private LinkedList<Appointment> listOfAppointments;
	
	public Veterinary(String name, String openingHours, String address, String neighborhood, String description,
			Service services) {
		super();
		this.name = name;
		this.openingHours = openingHours;
		this.address = address;
		this.neighborhood = neighborhood;
		this.description = description;
		this.services = services;
		listOfAppointments = new LinkedList<>();
	}
	
	public Service getServices() {
		return services;
	}
	
	public LinkedList<Appointment> getListOfAppointments() {
		return listOfAppointments;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getOpeningHours() {
		return openingHours;
	}

	public void setOpeningHours(String openingHours) {
		this.openingHours = openingHours;
	}

	public String getAddress() {
		return address;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public String getNeighborhood() {
		return neighborhood;
	}

	public void setNeighborhood(String neighborhood) {
		this.neighborhood = neighborhood;
	}

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description;
	}

	public void setServices(Service services) {
		this.services = services;
	}

	public void setListOfAppointments(LinkedList<Appointment> listOfAppointments) {
		this.listOfAppointments = listOfAppointments;
	}

	@Override
	public String toString() {
		return "\nVeterinaria: " + name + "\n" + 
				"Horarios: " + openingHours + "\n" + 
				"Direccion: " + address + "\n" + 
				"Barrio: " + neighborhood + "\n" + 
				"Descripcion: " + description + "\n" +
				"Servicios: \n" + services;
	}
}
