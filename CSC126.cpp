#include <iostream>
#include <iomanip>
using namespace std;

void PrintOrderDetails(int,int,int,int,int);		//Function Prototype Declaration
float CalculateOrderCost(int, int, int, int);

void PrintOrderDetails(int orderNumber, int noodle, int soup, int addons, int quantity)	//Function Definition for receipt
{
    cout << "|   " << orderNumber << "   |";

    if (noodle == 1)
    {
        cout << " Noodle: Instant noodle    |           |           |"<<endl;
    }
    else
    {
        cout << " Noodle: Vermicelli noodle |           |           |"<<endl;
    }

    if (soup == 1)
    {
        cout << "|       | Soup: Tomyam              |           |           |"<<endl;
    } 
    else
    {
        cout << "|       | Soup: Curry Laksa         |           |           |"<<endl;
    }

    if (addons == 1)
    {
        cout << "|       | Add-ons: Giant Crab Stick |";
    }
    else
    {
        cout << "|       | Add-ons: Cheese Sausage   |";
    }

    cout << "     " << quantity << "     |";
}

float CalculateOrderCost(int noodle, int soup, int addons, int quantity)  //Function Definition
{
    float cost = 0.0;

    // Define prices
    const float instantNoodlePrice = 1.50;
    const float vermicelliNoodlePrice = 1.50;
    const float tomyamSoupPrice = 2.00;
    const float curryLaksaSoupPrice = 2.00;
    const float giantCrabStickPrice = 3.00;
    const float cheeseSausagePrice = 3.00;

    // Calculate cost based on user choices
    if (noodle == 1)
    {
        cost += instantNoodlePrice;
    }
    else
    {
        cost += vermicelliNoodlePrice;
    }

    if (soup == 1)
    {
        cost += tomyamSoupPrice;
    }
    else
    {
        cost += curryLaksaSoupPrice;
    }

    if (addons == 1)
    {
        cost += giantCrabStickPrice;
    }
    else
    {
        cost += cheeseSausagePrice;
    }

    // Multiply by quantity
    cost *= quantity;

    return cost;
}

int main()
{
	int inputNoodle, inputSoup, inputQuantity, inputAddons;
	int orderNumber = 0, noodle, soup, addons, quantity;
    char code, addmore;
    float orderCost;
   
    do
    {
    	cout << "  ____________________" << endl;
   	    cout << " | Oden self-service |" << endl;
   	    cout << " |___________________|" << endl;

    	cout << "____________________________________________" << endl;
    	cout << "| Types of  |   Instant noodle    |        |" << endl;
    	cout << "|  noodle   |  Vermicelli noodle  | RM1.50 |" << endl;
    	cout << "|___________|_____________________|________|" << endl;
    	cout << "| Types of  |     Tomyam Soup     |        |" << endl;
    	cout << "|   soup    |  Curry Laksa Soup   | RM2.00 |" << endl;
    	cout << "|___________|_____________________|________|" << endl;
    	cout << "| Types of  |  Giant Crab Stick   |        |" << endl;
    	cout << "|  add-ons  |   Cheese Sausage    | RM3.00 |" << endl;
    	cout << "|___________|_____________________|________|" << endl;

  
        // User input for noodle
       do {
    		cout << "\nChoose your types of noodle (1-instant noodle | 2-vermicelli noodle): ";
   			cin >> inputNoodle;

    		if (inputNoodle != 1 && inputNoodle != 2)
			{
        	cout << "\nInvalid number. Please try again." << endl;
    	    }

	   } while (inputNoodle != 1 && inputNoodle != 2);

        // User input for soup
       do {
    		cout << "Choose your types of soup (1-tomyam | 2-curry laksa): ";
    		cin >> inputSoup;

 		   if (inputSoup != 1 && inputSoup != 2) 
			{
        		cout << "\nInvalid number. Please try again." << endl;
   			}

	   } while (inputSoup != 1 && inputSoup != 2);

        // User input for add-ons
       do {
    		cout << "Do you want add-ons? (Y-Yes/N-No): ";
    		cin >> code;

  			if (toupper(code) != 'Y' && toupper(code) != 'N') 
			{
        		cout << "\nInvalid answer. Please try again." << endl;
    		}

	   } while (toupper(code) != 'Y' && toupper(code) != 'N');

       if (toupper(code) == 'Y') 
	   {
    	  do {
           		cout << "Choose add-ons (1-giant crab stick | 2-cheese sausage): ";
        		cin >> inputAddons;

        		if (inputAddons == 1 || inputAddons == 2)
				{
            	break; 
        	    }
				else
				{
            	cout << "\nInvalid option. Please choose 1 or 2." << endl;
        		}
    	  } while (inputAddons != 1 && inputAddons != 2);
       }

	   // User input for quantity
	   do {
   			 cout << "Choose quantity for this order (1-5): ";
   			 cin >> inputQuantity;

    		 if (inputQuantity < 1 || inputQuantity > 5)
			 {
       			 cout << "\nInvalid quantity. Please try again." << endl;
    	     }

	   } while (inputQuantity < 1 || inputQuantity > 5);
 
        // Store user inputs in arrays 
   		noodle = inputNoodle;
        soup = inputSoup;
        addons = inputAddons;
        quantity= inputQuantity;
        
        // Increment the order number for the next order
        orderNumber++;
	
	   do {
        	 cout << "\nDo you want to add more order? (Y-Yes|N-No): ";
      		 cin >> addmore;

        	 if (toupper(addmore) != 'Y' && toupper(addmore) != 'N')
			 {	
            	 cout << "Invalid answer. Please try again\n";
        	 }

       } while (toupper(addmore) != 'Y' && toupper(addmore) != 'N');

    } while (toupper(addmore) == 'Y');

    // Display the receipt with all the orders and total cost
    float totalCost = 0.0;

    cout << "____________________________________________________________" << endl;
    cout << "|INVOICE                                                    |" << endl;
    cout << "|___________________________________________________________|" << endl;
    cout << "| order |                           | Quantity  | Price(RM) |" << endl;
    cout << "|_______|___________________________|___________|___________|" << endl;

    for (int i = 0; i < orderNumber; i++)
    {
    PrintOrderDetails(i + 1, noodle, soup, addons, quantity);               //Function Call
    orderCost = CalculateOrderCost(noodle, soup, addons, quantity);         //Function Call
    cout << "   " <<fixed<< setprecision(2) << orderCost << "   |" << endl;
    cout << "|_______|___________________________|___________|___________|" << endl;
    totalCost += orderCost;
    }

    cout << "|                                               |           |" << endl;
    cout << "| TOTAL COST :                                  |   " <<fixed<< setprecision(2) << totalCost << "   |" << endl;
    cout << "|_______________________________________________|___________|" << endl;
    cout << "|                                                           |" << endl;
    cout << "| MEMO : Please bring this invoice to the counter.          |" << endl;
    cout << "|___________________________________________________________|" << endl;

    return 0;
}
