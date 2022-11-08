
import java.util.*;
import java.io.*;
import java.nio.*;

public class Customer implements MyFileIO{
    private String code;
    private String name;
    private String address;
    private String phone;
    
	public Customer() {
        code = "";
        name = "";
        address = "";
        phone = "";	
	}
	
    public Customer(String code, String name, String add, String ph) {
        this.code = code;
        this.name = name;
        address =add;
        phone = ph;
		
    }
    
    
    public String getCode() { return code; }
	
	public String getName() { return name; }
	
	public String getAddress() { return address; }
	
	public String getPhone() { return phone; }
	
	
	public void setCode(String code) { this.code = code; }
	
	public void setName(String name) { this.name = name; }
	
	public void setAddress(String add) { address = add; }
	
	public void setPhone(String ph) { phone = ph; }

    
	public void readData(Scanner input) { 
		//Read data from the input
		try {
			code = input.next();
			name = input.next();
			address = input.next();
			phone = input.next();
			
		}
		catch (InputMismatchException e) {
				System.out.println("Wrong input type. " + e);
				input.next(); //Jump over the string
		}
	}
	
	public void writeData(Formatter output) {
		output.format("%s\n", toString());
	}
	
	public String toString() {
		String s = code + "," + name + "," + address + "," + phone;
		
		return s;
	}
	
	public String displayString() {
		String s = "Customer Code: " + code + "\nName: " + name + "\nAddress: " + address + "\nPhone: " + phone;
		
		return s;
	}
}
