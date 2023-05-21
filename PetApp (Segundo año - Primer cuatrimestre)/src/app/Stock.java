package app;

import java.util.ArrayList;

public class Stock <E> {

	private ArrayList<E> stock;
	private int quantity;

	public Stock() {
		stock = new ArrayList<E>();
	}
	
	public void addProduct(E product) {
		stock.add(product);
		quantity++;
	}
	
	public void showProducts(int eachProduct) {
		
		for (int i = 0; i < eachProduct; i++) {
			
			System.out.print(i + 1 + ") ");
			System.out.println(stock.get(i).toString());
		}
	}
	
	public int removeProductPerPurchase(E product) {
		
//		System.out.println("este producto es: " + product.toString());
		
		boolean find = false;
		
		//Existencia inicial
//		for(int i = 0; i < stock.size(); i++) {
//			System.out.println(stock.get(i).toString());
//		}
		
//		System.out.println("------------------------------------------------------------------------------------------------------");
		
		for(int i = 0; i < stock.size(); i++) {
			
			if(stock.get(i).equals(product) && find == false) {
				
				stock.remove(i);
				quantity--;
				find = true;
			}
		}
		
//		System.out.println("------------------------------------------------------------------------------------------------------");
		
//		//Existencia posterior
//		for(int i = 0; i < stock.size(); i++) {
//			System.out.println(stock.get(i).toString());
//		}
		
		return quantity;
	}
	
	public int getQuantity() {
		return quantity;
	}
	
	
	
	
}
