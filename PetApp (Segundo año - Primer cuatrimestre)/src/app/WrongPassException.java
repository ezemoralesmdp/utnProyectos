package app;

public class WrongPassException extends Exception{
	
	public WrongPassException(String message) {
		super(message);
	}


	@Override
	public String getMessage() {
		// TODO Auto-generated method stub
		return super.getMessage();
	}
}
