package app;

import java.util.*;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class JSONManager {
	
	public static void createJSON(User aux) {
		JSONArray jsonArrayUsers = new JSONArray();
		JSONObject firstUser = new JSONObject();
		
		try {
			firstUser.put("user", aux.getUser());
			firstUser.put("password", aux.getPassword());
			firstUser.put("email", aux.getEmail());
			firstUser.put("name", aux.getName());
			firstUser.put("age", aux.getAge());
			firstUser.put("enabledForFostering", aux.isEnabledForFostering());
			JSONArray jsonAnimals=new JSONArray();
			JSONObject jsonAnimal=new JSONObject();
			jsonAnimal.put("name", "");
			jsonAnimal.put("specie", "");
			jsonAnimal.put("gender", "");
			jsonAnimal.put("healthStatus", "");
			jsonAnimal.put("age", 0);
			jsonAnimal.put("breed", "");
			jsonAnimal.put("castrate", false);
			jsonAnimals.put(jsonAnimal);
			firstUser.put("animals", jsonAnimals);
			JSONArray jsonAppointments=new JSONArray();
			JSONObject jsonAppointment=new JSONObject();
			jsonAppointment.put("id", 0);
			jsonAppointment.put("time", "");
			jsonAppointment.put("date", "");
			jsonAppointment.put("castration", false);
			jsonAppointment.put("desparasitization", false);
			jsonAppointment.put("adoption", false);
			jsonAppointment.put("groomer", false);
			jsonAppointment.put("userAssigned", "");
			JSONObject jsonAppointmentAnimal=new JSONObject();
			jsonAppointmentAnimal.put("name", "");
			jsonAppointmentAnimal.put("specie", "");
			jsonAppointmentAnimal.put("gender", "");
			jsonAppointmentAnimal.put("healthStatus", "");
			jsonAppointmentAnimal.put("age", 0);
			jsonAppointmentAnimal.put("breed", "");
			jsonAppointmentAnimal.put("castrate", false);
			jsonAppointment.put("animal", jsonAppointmentAnimal);
			jsonAppointments.put(jsonAppointment);
			firstUser.put("appointments", jsonAppointments);
			JSONObject jsonWallet=new JSONObject();
			jsonWallet.put("amount", 0);
			firstUser.put("wallet", jsonWallet);
			jsonArrayUsers.put(firstUser);
			JSONUtiles.grabar(jsonArrayUsers);
		} catch (JSONException e) {
			e.printStackTrace();
		}
		
	}

	public static void newUser(User newUser) {
		String source=JSONUtiles.leer("users");
		try {
			JSONArray jsonArrayUsers=new JSONArray(source);
			JSONObject jsonUser = new JSONObject();
			jsonUser.put("user", newUser.getUser());
			jsonUser.put("password", newUser.getPassword());
			jsonUser.put("email", newUser.getEmail());
			jsonUser.put("name", newUser.getName());
			jsonUser.put("age", newUser.getAge());
			jsonUser.put("enabledForFostering", newUser.isEnabledForFostering());
			JSONArray jsonAnimals=new JSONArray();
			JSONObject jsonAnimal=new JSONObject();
			jsonAnimal.put("name", "");
			jsonAnimal.put("specie", "");
			jsonAnimal.put("gender", "");
			jsonAnimal.put("healthStatus", "");
			jsonAnimal.put("age", 0);
			jsonAnimal.put("breed", "");
			jsonAnimal.put("castrate", false);
			jsonAnimals.put(jsonAnimal);
			jsonUser.put("animals", jsonAnimals);
			JSONArray jsonAppointments=new JSONArray();
			JSONObject jsonAppointment=new JSONObject();
			jsonAppointment.put("id", 0);
			jsonAppointment.put("time", "");
			jsonAppointment.put("date", "");
			jsonAppointment.put("castration", false);
			jsonAppointment.put("desparasitization", false);
			jsonAppointment.put("adoption", false);
			jsonAppointment.put("groomer", false);
			jsonAppointment.put("userAssigned", "");
			JSONObject jsonAppointmentAnimal=new JSONObject();
			jsonAppointmentAnimal.put("name", "");
			jsonAppointmentAnimal.put("specie", "");
			jsonAppointmentAnimal.put("gender", "");
			jsonAppointmentAnimal.put("healthStatus", "");
			jsonAppointmentAnimal.put("age", 0);
			jsonAppointmentAnimal.put("breed", "");
			jsonAppointmentAnimal.put("castrate", false);
			jsonAppointment.put("animal", jsonAppointmentAnimal);
			jsonAppointments.put(jsonAppointment);
			jsonUser.put("appointments", jsonAppointments);
			JSONObject jsonWallet=new JSONObject();
			jsonWallet.put("amount", 0);
			jsonUser.put("wallet", jsonWallet);
			jsonArrayUsers.put(jsonUser);
			
			JSONUtiles.grabar(jsonArrayUsers);
		} catch (JSONException e) {
			e.printStackTrace();
		}
	}

	public static ArrayList<User> JSONtoUsersArray() {

		String source = JSONUtiles.leer("users");

		ArrayList<User> arrayUsers = new ArrayList<>();

		try {
			JSONArray jsonArrayUsers = new JSONArray(source);
			for (int i = 0; i < jsonArrayUsers.length(); i++) {
				User auxUser = new User();
				JSONObject jsonUser = jsonArrayUsers.getJSONObject(i);
				auxUser.setUser(jsonUser.getString("user"));
				auxUser.setPassword(jsonUser.getString("password"));
				auxUser.setEmail(jsonUser.getString("email"));
				auxUser.setName(jsonUser.getString("name"));
				auxUser.setAge(jsonUser.getInt("age"));

				JSONArray jsonArrayAnimals = jsonUser.getJSONArray("animals");
				ArrayList<Animal> arrayAnimals = new ArrayList<>();

				for (int j = 0; j < jsonArrayAnimals.length(); j++) {

					JSONObject jsonAnimal = jsonArrayAnimals.getJSONObject(j);
					Animal auxAnimal = new Animal();

					auxAnimal.setName(jsonAnimal.getString("name"));
					auxAnimal.setSpecie(jsonAnimal.getString("specie"));
					auxAnimal.setGender(jsonAnimal.getString("gender"));
					auxAnimal.setHealthStatus(jsonAnimal.getString("healthStatus"));
					auxAnimal.setAge(jsonAnimal.getInt("age"));
					auxAnimal.setBreed(jsonAnimal.getString("breed"));
					auxAnimal.setCastrate(jsonAnimal.getBoolean("castrate"));

					arrayAnimals.add(auxAnimal);
				}
				auxUser.setAnimals(arrayAnimals);

				JSONArray jsonArrayAppointments = jsonUser.getJSONArray("appointments");
				LinkedList<Appointment> arrayAppointments = new LinkedList<>();

				for (int j = 0; j < jsonArrayAppointments.length(); j++) {
					JSONObject jsonAppointment = jsonArrayAppointments.getJSONObject(j);
					Appointment auxAppointment = new Appointment();

					auxAppointment.setId(jsonAppointment.getInt("id"));
					auxAppointment.setTime(jsonAppointment.getString("time"));
					auxAppointment.setDate(jsonAppointment.getString("date"));
					auxAppointment.setCastration(jsonAppointment.getBoolean("castration"));
					auxAppointment.setDeparasitization(jsonAppointment.getBoolean("desparasitization"));
					auxAppointment.setAdoption(jsonAppointment.getBoolean("adoption"));
					auxAppointment.setGroomer(jsonAppointment.getBoolean("groomer"));
					auxAppointment.setUserAssigned(jsonAppointment.getString("userAssigned"));
					JSONObject jsonAnimal = jsonAppointment.getJSONObject("animal");
					Animal auxAnimal = new Animal();
					auxAnimal.setName(jsonAnimal.getString("name"));
					auxAnimal.setSpecie(jsonAnimal.getString("specie"));
					auxAnimal.setGender(jsonAnimal.getString("gender"));
					auxAnimal.setHealthStatus(jsonAnimal.getString("healthStatus"));
					auxAnimal.setAge(jsonAnimal.getInt("age"));
					auxAnimal.setBreed(jsonAnimal.getString("breed"));
					auxAnimal.setCastrate(jsonAnimal.getBoolean("castrate"));
					auxAppointment.setUsersPetAssigned(auxAnimal);
					arrayAppointments.add(auxAppointment);
				}
				auxUser.setListOfAssignedAppointments(arrayAppointments);
				auxUser.setEnabledForFostering(jsonUser.getBoolean("enabledForFostering"));

				JSONObject jsonWallet = jsonUser.getJSONObject("wallet");
				Wallet auxWallet = new Wallet();

				auxWallet.setAmount(jsonWallet.getDouble("amount"));

				auxUser.setMyWallet(auxWallet);

				arrayUsers.add(auxUser);
			}
		} catch (JSONException e) {

			System.out.println("Parece que sos el primer usuario en registrarse, bienvenido!");
		}

		return arrayUsers;
	}

	public static void userArrayToJSONFile(ArrayList<User> users) {
		JSONArray jsonArrayUsers = new JSONArray();
		
		try {
			for (int i = 0; i < users.size(); i++) {
				JSONObject jsonUser = new JSONObject();
				User auxUser= users.get(i);
				jsonUser.put("user", auxUser.getUser());
				jsonUser.put("password", auxUser.getPassword());
				jsonUser.put("email", auxUser.getEmail());
				jsonUser.put("name", auxUser.getName());
				jsonUser.put("age", auxUser.getAge());
				jsonUser.put("enabledForFostering", auxUser.isEnabledForFostering());
				JSONArray jsonAnimals=new JSONArray();
				ArrayList<Animal> auxArrayAnimals=auxUser.getAnimals();
				for (int j = 0; j < auxArrayAnimals.size(); j++) {
					Animal auxAnimal=auxArrayAnimals.get(j);
					JSONObject jsonAnimal=new JSONObject();
					jsonAnimal.put("name", auxAnimal.getName());
					jsonAnimal.put("specie", auxAnimal.getSpecie());
					jsonAnimal.put("gender", auxAnimal.getGender());
					jsonAnimal.put("healthStatus",auxAnimal.getHealthStatus());
					jsonAnimal.put("age", auxAnimal.getAge());
					jsonAnimal.put("breed",auxAnimal.getBreed());
					jsonAnimal.put("castrate", auxAnimal.isCastrate());
					jsonAnimals.put(jsonAnimal);
				}
				jsonUser.put("animals", jsonAnimals);
				
				JSONArray jsonAppointments=new JSONArray();
				ArrayList<Appointment> auxArrayAppointments=new ArrayList<>();
				
				for (int j = 0; j < auxArrayAppointments.size(); j++) {
					JSONObject jsonAppointment=new JSONObject();
					Appointment aux=auxArrayAppointments.get(j);
					jsonAppointment.put("id", aux.getId());
					jsonAppointment.put("time", aux.getTime());
					jsonAppointment.put("date", aux.getDate());
					jsonAppointment.put("castration", aux.isCastration());
					jsonAppointment.put("desparasitization", aux.isDeparasitization());
					jsonAppointment.put("adoption",aux.isAdoption());
					jsonAppointment.put("groomer", aux.isGroomer());
					jsonAppointment.put("userAssigned",aux.getUserAssigned());
					Animal auxAnimal=aux.getUsersPetAssigned();
					JSONObject jsonAppointmentAnimal=new JSONObject();
					jsonAppointmentAnimal.put("name", auxAnimal.getName());
					jsonAppointmentAnimal.put("specie", auxAnimal.getSpecie());
					jsonAppointmentAnimal.put("gender", auxAnimal.getGender());
					jsonAppointmentAnimal.put("healthStatus", auxAnimal.getHealthStatus());
					jsonAppointmentAnimal.put("age", auxAnimal.getAge());
					jsonAppointmentAnimal.put("breed", auxAnimal.getBreed());
					jsonAppointmentAnimal.put("castrate", auxAnimal.isCastrate());
					jsonAppointment.put("animal", jsonAppointmentAnimal);
					jsonAppointments.put(jsonAppointment);
				}
				jsonUser.put("appointments", jsonAppointments);
				JSONObject jsonWallet=new JSONObject();
				Wallet auxWallet=auxUser.getMyWallet();
				jsonWallet.put("amount", auxWallet.getAmount());
				jsonUser.put("wallet", jsonWallet);
				jsonArrayUsers.put(jsonUser);
			}
			
		} catch (JSONException e) {
			e.printStackTrace();
		}
		
		JSONUtiles.grabar(jsonArrayUsers);
	}

	public static ArrayList<Veterinary> readJson() {

		String source = JSONUtiles.leer("veterinarias");

		ArrayList<Veterinary> arrayVeterinary = new ArrayList<>();
		Veterinary aux = null;

		try {

			JSONArray array = new JSONArray(source);

			for (int i = 0; i < array.length(); i++) {

				JSONObject obj = array.getJSONObject(i);

				String name = obj.getString("nombre");
				String openingHours = obj.getString("horarios");
				String address = obj.getString("direccion");
				String neighborhood = obj.getString("barrio");
				String description = obj.getString("descripcion");

				JSONObject obj_services = obj.getJSONObject("servicios");

				Service services_veterinary = null;

				services_veterinary = new Service(obj_services.getBoolean("castracion"),
						obj_services.getBoolean("desparacitacion"), obj_services.getBoolean("adopcion"),
						obj_services.getBoolean("peluqueria"), obj_services.getBoolean("isTienda"));

				aux = new Veterinary(name, openingHours, address, neighborhood, description, services_veterinary);

				arrayVeterinary.add(aux);
			}

		} catch (JSONException e) {

			e.printStackTrace();
		}

		return arrayVeterinary;

	}
	
	public static void createPersonalJSON(User loggedUser) {
		
		JSONObject myPersonalInfo = new JSONObject();
		
		try {
			myPersonalInfo.put("user", loggedUser.getUser());
			myPersonalInfo.put("email", loggedUser.getEmail());
			myPersonalInfo.put("name", loggedUser.getName());
			myPersonalInfo.put("age", loggedUser.getAge());
			myPersonalInfo.put("enabledForFostering", loggedUser.isEnabledForFostering());
			
			JSONArray arrayAnimals = new JSONArray();
			ArrayList<Animal> animals = null;
			
			if(loggedUser.getAnimals() != null) {
				
				animals = loggedUser.getAnimals();
				
				for(int i = 0; i < animals.size(); i++) {
					
					JSONObject animal = new JSONObject();
					Animal aux = new Animal();
					
					aux = animals.get(i);
					
					animal.put("name", aux.getName());
					animal.put("specie", aux.getSpecie());
					animal.put("gender", aux.getGender());
					animal.put("healthStatus", aux.getHealthStatus());
					animal.put("age", aux.getAge());
					animal.put("age", aux.getBreed());
					animal.put("castrate", aux.isCastrate());
					
					arrayAnimals.put(animal);
				}
				
				myPersonalInfo.put("animals", arrayAnimals);
				
			} else {
				
				JSONObject animal = new JSONObject();
				
				animal.put("name", "");
				animal.put("specie", "");
				animal.put("gender", "");
				animal.put("healthStatus", "");
				animal.put("age", "");
				animal.put("age", "");
				animal.put("castrate", "");
				
				arrayAnimals.put(animal);
				
				myPersonalInfo.put("animals", arrayAnimals);
			}
			
			//------------------------------------------------------------------------------------------------------------------
			
			JSONArray arrayAppointment = new JSONArray();
			LinkedList<Appointment> appointments = null;
			
			if(loggedUser.getListOfAssignedAppointments() != null) {
				
				appointments = loggedUser.getListOfAssignedAppointments();
				
				for(int i = 0; i < appointments.size(); i++) {
					
					JSONObject appointment = new JSONObject();
					Appointment aux = new Appointment();
					
					aux = appointments.get(i);
					
					appointment.put("id", aux.getId());
					appointment.put("time", aux.getTime());
					appointment.put("date", aux.getDate());
					appointment.put("castration", aux.isCastration());
					appointment.put("desparasitization", aux.isDeparasitization());
					appointment.put("adoption", aux.isAdoption());
					appointment.put("groomer", aux.isGroomer());
					appointment.put("userAssigned", aux.getUserAssigned());
					
					JSONObject myAnimal = new JSONObject();
					Animal aux2 = aux.getUsersPetAssigned();
					
					myAnimal.put("name", aux2.getName());
					myAnimal.put("specie", aux2.getSpecie());
					myAnimal.put("gender", aux2.getGender());
					myAnimal.put("healthStatus", aux2.getHealthStatus());
					myAnimal.put("age", aux2.getAge());
					myAnimal.put("breed", aux2.getBreed());
					myAnimal.put("castrate", aux2.isCastrate());
					
					appointment.put("animal", myAnimal);
					
					arrayAppointment.put(appointment);
				}
				
				myPersonalInfo.put("appointments", arrayAppointment);
				
			} else {
				
				JSONObject appointment = new JSONObject();
				
				appointment.put("id", "");
				appointment.put("time", "");
				appointment.put("date", "");
				appointment.put("castration", "");
				appointment.put("desparasitization", "");
				appointment.put("adoption", "");
				appointment.put("groomer", "");
				appointment.put("userAssigned", "");
				
				JSONObject myAnimal = new JSONObject();
				myAnimal.put("name", "");
				myAnimal.put("specie", "");
				myAnimal.put("gender", "");
				myAnimal.put("healthStatus", "");
				myAnimal.put("age", "");
				myAnimal.put("breed", "");
				myAnimal.put("castrate", "");
				
				appointment.put("animal", myAnimal);
				
				arrayAppointment.put(appointment);
				
				myPersonalInfo.put("appointments", arrayAppointment);
			}
			
			JSONUtiles.grabar(myPersonalInfo);
			
		} catch (JSONException e) {
			e.printStackTrace();
		}
	}
}