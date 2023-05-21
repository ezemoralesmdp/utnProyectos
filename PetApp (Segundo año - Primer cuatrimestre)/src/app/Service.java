package app;

public class Service {

	boolean castration;
	boolean deparasitization;
	boolean adoption;
	boolean groomer;
	boolean isShop;
	
	public Service(boolean castration, boolean deparasitization, boolean adoption, boolean groomer, boolean isShop) {
		super();
		this.castration = castration;
		this.deparasitization = deparasitization;
		this.adoption = adoption;
		this.groomer = groomer;
		this.isShop = isShop;
	}

	public boolean isCastration() {
		return castration;
	}

	public boolean isDeparasitization() {
		return deparasitization;
	}

	public boolean isAdoption() {
		return adoption;
	}

	public boolean isGroomer() {
		return groomer;
	}

	public boolean isShop() {
		return isShop;
	}	
	
	@Override
	public String toString() {
		return "Castracion: " + castration + "\n" +
				"Desparacitacion: " + deparasitization + "\n" + 
				"Adopcion: " + adoption + "\n" + 
				"Peluqueria: " + groomer + "\n" +
				"Tienda: " + isShop + "\n";
	}
}
