package app;

public class WrongUserException extends Exception{

	private String userName;
	
	public WrongUserException(String message,String userName) {
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
		// TODO Auto-generated method stub
		return super.getMessage()+getUserName()+" no existe.";
	}
	
	

}
