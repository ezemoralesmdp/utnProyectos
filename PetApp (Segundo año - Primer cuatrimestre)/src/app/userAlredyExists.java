package app;

public class userAlredyExists extends Exception{

	private String userName;
	
	public userAlredyExists(String message,String userName) {
		super(message);
		this.userName=userName;
	}

	
	
	public String getUserName() {
		return userName;
	}



	public void setUserName(String userName) {
		this.userName = userName;
	}



	@Override
	public String getMessage() {
		return super.getMessage()+ getUserName()+" ya esta registrado, ingrese otro usuario.";
	}

	
	
	
}
