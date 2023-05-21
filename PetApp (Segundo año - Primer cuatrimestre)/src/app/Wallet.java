package app;

import java.io.*;

public class Wallet implements Serializable {
	
	private double amount;

	public Wallet() {
		
	}

	public void setAmount(double amount) {
		this.amount = amount;
	}
	
	public double getAmount() {
		return amount;
	}
	
	public void addCash(double cash) {
		amount+=cash;
	}
	
	public void subtractionCash(double cash) {
		amount-=cash;
	}
}
