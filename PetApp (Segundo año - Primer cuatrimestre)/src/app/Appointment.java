package app;

public class Appointment {

	private int id;
	private String time;
	private String date;
	private boolean castration;
	private boolean deparasitization;
	private boolean adoption;
	private boolean groomer;
	private String userAssigned;
	private Animal usersPetAssigned;
	
	public Appointment(int id, String time, String date, String userAssigned) {
		super();
		this.id= id;
		this.time = time;
		this.date = date;
		this.castration = false;
		this.deparasitization = false;
		this.adoption = false;
		this.groomer = false;
		this.userAssigned=userAssigned;
	}

	public Appointment() { 
	}

	public String getTime() {
		return time;
	}

	public void setTime(String time) {
		this.time = time;
	}

	public String getDate() {
		return date;
	}

	public void setDate(String date) {
		this.date = date;
	}

	public boolean isCastration() {
		return castration;
	}

	public void setCastration(boolean castration) {
		this.castration = castration;
	}

	public boolean isDeparasitization() {
		return deparasitization;
	}

	public void setDeparasitization(boolean deparasitization) {
		this.deparasitization = deparasitization;
	}

	public boolean isAdoption() {
		return adoption;
	}

	public void setAdoption(boolean adoption) {
		this.adoption = adoption;
	}

	public boolean isGroomer() {
		return groomer;
	}

	public void setGroomer(boolean groomer) {
		this.groomer = groomer;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getUserAssigned() {
		return userAssigned;
	}

	public void setUserAssigned(String userAssigned) {
		this.userAssigned = userAssigned;
	}

	public Animal getUsersPetAssigned() {
		return usersPetAssigned;
	}

	public void setUsersPetAssigned(Animal usersPetAssigned) {
		this.usersPetAssigned = usersPetAssigned;
	}

	@Override
	public String toString() {
		return "Turno [ID: " + id + ", Horario: " + time + ", Dia: " + date + "]\n";
	}
	
	
}
