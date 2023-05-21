package app;

import java.io.Serializable;

public class Animal implements Serializable {

	//Atributes
	private String name;
	private String specie;
	private String gender;
	private String healthStatus;
	private int age;
	private String breed;
	private boolean isCastrate;
	
	//Constructor
	public Animal() {
		
	}
	
	public Animal(String name, String specie, String gender, String healthStatus, int age, String breed, boolean isCastrate) {
		this.name = name;
		this.specie = specie;
		this.gender = gender;
		this.healthStatus = healthStatus;
		this.age = age;
		this.breed = breed;
		this.isCastrate = isCastrate;
	}

	//Getters & Setters
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getSpecie() {
		return specie;
	}

	public void setSpecie(String specie) {
		this.specie = specie;
	}

	public String getGender() {
		return gender;
	}

	public void setGender(String gender) {
		this.gender = gender;
	}

	public String getHealthStatus() {
		return healthStatus;
	}

	public void setHealthStatus(String healthStatus) {
		this.healthStatus = healthStatus;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public String getBreed() {
		return breed;
	}
	
	public void setBreed(String breed) {
		this.breed = breed;
	}
	
	public void setCastrate(boolean isCastrate) {
		this.isCastrate = isCastrate;
	}
	public boolean isCastrate() {
		return isCastrate;
	}
	
	@Override
	public String toString() {
		
		String data = "";
		
		data = "Especie: " + getSpecie() + 
				"\nNombre: " + getName() + 
				"\nGenero: " + getGender() + 
				"\nEdad: " + getAge() + 
				"\nEstado de salud: " + getHealthStatus() + 
				"\nRaza: " + getBreed() + 
				"\nCastrado: " + isCastrate() +
				"\n";
		
		return data;
	}
}
