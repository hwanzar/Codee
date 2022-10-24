import java.util.*;
import java.io.EOFException;
import java.io.IOException;
import java.nio.file.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.event.ListSelectionEvent;
import java.awt.*;
import javax.swing.*;

public class OrderSystem extends JFrame implements ActionListener, ListSelectionListener {
	private ArrayList<Customer> customers;
	private int currentIdx;
	private Customer currentCustomer;
	private JTextArea customerDetails;
	private JButton updateButton, addButton;
	private JList<String> customerList;
	private DefaultListModel<String> customerCodeList;
	private JTextField messages;
	private Container container;
	private BorderLayout layout;
	
	//Create the GUI
    public OrderSystem() {
		super("Order System");
		
		//Load customer data
		customers = new ArrayList<Customer>();		
		loadCustomers();
		
		//Set current customer index
		if(customers.size() > 0) { 
			currentIdx = 0;
			currentCustomer = customers.get(currentIdx);
		}
		else {
			currentIdx = -1;
			currentCustomer = null;
		}
			
		
		//Set BorderLayout for the container
		container = getContentPane();
		layout = new BorderLayout();
		container.setLayout(layout);
		container.setComponentOrientation(ComponentOrientation.LEFT_TO_RIGHT);
		
		//Add customer components
		addCustomerComponents();
		
		//Add buttons
		addButtons();
		
		//Add messages
		addMessages();
		
		//Show the current customer
		showCustomer();
		
		
    }
     //Add the GUI components for the customer
  	 //Include customer code list and text area of details
  	private void addCustomerComponents() {
  		//Use flow lay out for the components
  		JPanel pan = new JPanel(new GridLayout(1,2));
  		
  		//Add the label
  		JLabel label = new JLabel(" Customer code ");
  		pan.add(label);
  		
  	    //Add the detail label
  		label = new JLabel("Customer details ");
  		pan.add(label);
  		

  		//Add the panel to the center
  		container.add(pan, BorderLayout.NORTH);
  		
  		
  		
  		JPanel pan2 = new JPanel(new FlowLayout());
  		//Add the customer code list
  		customerCodeList = new DefaultListModel<>();
  		for(Customer c:customers)
  			customerCodeList.addElement(c.getCode());
  		customerList = new JList<>(customerCodeList);
  		customerList.setVisibleRowCount(10);
  		customerList.setFixedCellWidth(30);
  					
  		customerList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
  		customerList.addListSelectionListener(this);
  		pan2.add(new JScrollPane(customerList));
  		
  		container.add(pan2, BorderLayout.WEST);
  		
  		
  		JPanel pan3 = new JPanel(new FlowLayout());
  		//Add the text area		
  		customerDetails = new JTextArea("", 20, 20);
  		customerDetails.setLineWrap(false);
  		customerDetails.setWrapStyleWord(true);
  		pan3.add(customerDetails);
  		
  
  		container.add(pan3, BorderLayout.EAST);
  	}
  	
    //Add the GUI buttons
  	//Include previous, next, update, add and delete
  	private void addButtons() {
  		
  		//Create buttons, and add actionListener
  		JPanel panel = new JPanel(new FlowLayout());
  		
  		addButton = new JButton("New Order");
		addButton.addActionListener(this);
		panel.add(addButton);
		
		updateButton = new JButton("Save Order");
		updateButton.addActionListener(this);
		panel.add(updateButton);
		
		//Add the panel to the center
		container.add(panel, BorderLayout.CENTER);
		
  	}
  	
     //Add the GUI messages
  	 private void addMessages() {
  		
  		//Create buttons, and add actionListener
  		JPanel panel = new JPanel(new FlowLayout());
  		
  		JLabel label = new JLabel("Message:");
  		messages = new JTextField(50);

  		panel.add(label);
  		panel.add(messages);
  		
  		//Add the panel to the south
  		container.add(panel, BorderLayout.SOUTH);
  		
  	 }
  	
  	
   //Display current customer information on GUI
  	private void showCustomer() {
  		if(currentCustomer != null) {
  			String c = currentCustomer.displayString();
  			customerDetails.setText(c);
  		}
  		else {
  			messages.setText("No customer selected.");
  		}
  	}
  	
  	//Override
  	public void valueChanged(ListSelectionEvent event) {
  		int i = customerList.getSelectedIndex();
  		messages.setText("");
  		if(i >= 0) {	
  			//Display the subject details
  			currentIdx = i;
  			currentCustomer = customers.get(currentIdx);
  			showCustomer();
  		}
  	}
  	

	public void actionPerformed(ActionEvent event) {
		messages.setText("");
		if(event.getSource() == updateButton) { //Save the current order
			
				saveOrders();
				messages.setText("Orders are saved.");
		}
		else if (event.getSource() == addButton) { //Add a new order
			//Add an order
			AddOrder addord = new AddOrder();		
		}
	}
	
	public static void main(String[] args) {
        OrderSystem os = new OrderSystem();
        
        os.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		os.setSize(900, 900);
		os.setVisible(true);
    }

	//Return true if a customer exists, else return false
	public boolean customerExists(String code) {
		boolean found = false;
		
		for(Customer c:customers) {
			if(code.equals(c.getCode())) {
				found = true;
				break;
			}
		}
		return found;		
	}

	
	public Customer getCurrentCustomer() {
		return currentCustomer;
	}
	
	public void loadCustomers() {
		String filename = "customers.txt";
		Path path = Paths.get(filename);
		int cnt = 0;
		try {
			if(Files.exists(path)) {
				//System.out.printf("%s exists", path.getFileName());
			
				if(!Files.isDirectory(path)) { //Not a directory, read data
					Scanner fin = new Scanner(path);
					fin.useDelimiter(",|\r\n|\t|\n");
					//Clear the container
					customers.clear();
					while(fin.hasNext()) {
						Customer aCustomer = new Customer();
						aCustomer.readData(fin);
						customers.add(aCustomer);
						cnt ++;
					}
					fin.close();
				}
				else
					System.out.printf("File %s does not exist", path);
			}
		}
		catch (IOException err) {
			System.out.println("IO exception error");
		}
		
		if(cnt > 1)
			System.out.println("" + cnt + " Customers have been loaded.");
		else
			System.out.println("No customer loaded.");
		
	}
	//save orders into a text file
	public void saveOrders() {
		String filename = "customers.txt";
		
		try {
			//Open an output file
			Formatter fout = new Formatter(filename);
			for(Customer c:customers) {
				fout.format("%s\n", c.toString());
			}
			fout.close();
		}
		catch (IOException err) {
			System.out.println("IO exception error");
		}		
	}
	
	
			
  	


}
