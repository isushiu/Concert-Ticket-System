 #include <iostream>
#include <iomanip>
#include <string.h>
using namespace std ;
int main ()
{
	//variables declaration
	int people, age, sumAge  = 0;
	int count = 0;
	float price, totalVIP, totalCAT1, totalCAT2, totalCAT3, totalCAT4, totalPrice, discount, tax, newPrice, avg = 0.0;
	string type, code, method, firstName, secondName, banner, typeNameMin, typeNameMax ;
	char confirmation, ticketconfirmation ;
	
	
	//function declaration
	float calcDiscount ();
	float calcTax(float);
	float calcPrice(float,float,float);
	string ticketName(int,int,int);
	void displayReceipt(string, string, float, float, float, float);
	void displayClosing();
	
	//array declaration
	//VIP, CAT1, CAT2, CAT3, CAT4
	int stock [5] = {810, 600, 750, 550, 400} ;
	int countType [5] = { 0, 0, 0, 0, 0};
	
	do
	{
		cout<<"\n\t\t***CONCERT TICKET SYSTEM***"<<endl;
		
		cout<<"\nFIRST NAME\t: ";
		cin>>firstName;
		cout<<"SECOND NAME\t: ";
		cin>>secondName;
		cout<<"Age\t\t: ";
		cin>>age;
		
		cout<<"\n___________________________________________________________________"<<endl;
		
		cout<<"\n\nWELCOME "<<firstName<<" "<<secondName<<endl;
		cout<<"\n\tTICKET TYPE\t\tSTOCK"<<endl;
		cout<<"\tVIP\t\t\t"<<stock[0]<<endl;
		cout<<"\tCAT1\t\t\t"<<stock[1]<<endl;
		cout<<"\tCAT2\t\t\t"<<stock[2]<<endl;
		cout<<"\tCAT3\t\t\t"<<stock[3]<<endl;
		cout<<"\tCAT4\t\t\t"<<stock[4]<<endl;
		
		//do-while loop for ticket types if user want to buy more than one type of ticket
		do 
		{
			cout<<"\nENTER TICKET TYPE\t: ";
			cin>>type;
			cout<<"AMOUNT OF PEOPLE\t: ";
			cin>>people;
			
			if ((type == "VIP") || (type == "vip"))
			{
				//comparing user demand with stock
				if (people > stock[0])  
				{
					cout<<"OUT OF STOCK CHOOSE OTHER TYPE"<<endl;
				}
				else
				{
					price = 1888;
					totalVIP = people*price;
					countType[0]= countType[0] + people;
					
					//update amount of stock
					stock[0] = stock[0] - people;
				}
			}
	
			else if ((type == "CAT1") || (type == "cat1"))
			{
				//comparing user demand with stock
				if (people > stock[1])  
				{
					cout<<"OUT OF STOCK CHOOSE OTHER TYPE"<<endl;
				}
				else
				{
					price = 1588;
					totalCAT1 = people*price;
					countType[1]= countType[1] + people;
					//update amount of stock
					stock[1] = stock[1] - people ;			
				}
				

					
			}
	
			else if ((type == "CAT2") || (type == "cat2") )
			{
				
				//comparing user demand with stock
				if (people > stock[2])  
				{
					cout<<"OUT OF STOCK CHOOSE OTHER TYPE"<<endl;
				}
				else
				{
					price = 988;
					totalCAT2 = people*price;
					countType[2]= countType[2] + people;
					//update amount of stock
					stock[2] = stock[2] - people ;
				}
			
				
			}
	
			else if ((type =="CAT3") || (type =="cat3"))
			{	
				//comparing user demand with stock
				if (people > stock[3]) 
				{
					cout<<"OUT OF STOCK CHOOSE OTHER TYPE"<<endl;
				}
				else
				{
					price = 588;
					totalCAT3 = people*price;
					countType[3]= countType[3] + people;
					//update amount of stock
					stock[3] = stock[3] - people;
				}
			}
		
			else if ((type == "CAT4") || (type == "cat4"))
			{		
			
				//comparing user demand with stock
				if (people > stock[4])  
				{
					cout<<"OUT OF STOCK CHOOSE OTHER TYPE"<<endl; 
				}
				else
				{
					price = 400;
					totalCAT4 = people*price;
					countType[4]= countType[4] + people;
					//update amount of stock
					stock[4] = stock[4] - people;
				}
			}
			
			else
			{
				cout<<"INVALID TICKET TYPE"<<endl;
			}
			
			
			cout<<"\nWould you like to buy others type of ticket (Y/N)\t: ";
			cin>>ticketconfirmation;

		} while ((ticketconfirmation == 'Y') || (ticketconfirmation == 'y')) ;
			
		cout<<"\n___________________________________________________________________"<<endl;
	
	
		//process to calculate total prices
		totalPrice = totalVIP + totalCAT1 + totalCAT2 + totalCAT3 + totalCAT4;
			
		//function call
		discount = calcDiscount ()*totalPrice;
		tax =  calcTax(totalPrice);
		newPrice = calcPrice(totalPrice,discount,tax);
			
		//set decimal places to 2 places
		cout<<fixed<<setprecision(2);
		
		//output function not return value + parameter, use &
		displayReceipt(firstName, secondName, totalPrice, discount, tax, newPrice);
		
		cout<<"\nPayment Method (CARD/CASH)\t: ";
		cin>>method;
		
		cout<<"PRESS 'Y' FOR THE NEXT CUSTOMER\t: ";
		cin>>confirmation;
		
		//function call to display closing statement
		displayClosing();
		
		//update total people, sum of buyer's age
		sumAge = sumAge + age;
		count++;		
			
	} while ((confirmation == 'Y') || (confirmation == 'y'));

	//to determine ticket with maximum amount of sold tickets
	
	int max = countType[0];
	
	for ( int i = 0 ; i<5 ; i++)
	{
		if (countType[i] > max)
			max = countType[i];
	}
	
	if (max == countType[0])
	{
		typeNameMax = "VIP";
	}
	else if ( max == countType[1])
	{
		typeNameMax = "CAT1";
	}
	else if (max == countType[2])
	{
		typeNameMax = "CAT2";
	}
	else if (max == countType[3])
	{
		typeNameMax = "CAT3";
	}
	else
	{
		typeNameMax = "CAT4";
	}

	//to determine the Less seller tickets
	
	int min = countType[0];
	
	for ( int i = 0 ; i<5 ; i++)
	{
		if (countType[i] < min)
			min = countType[i];
	}
	
	if (min == countType[0])
	{
		typeNameMin = "VIP";
	}
	else if ( min == countType[1])
	{
		typeNameMin = "CAT1";
	}
	else if (min == countType[2])
	{
		typeNameMin = "CAT2";
	}
	else if (min == countType[3])
	{
		typeNameMin = "CAT3";
	}
	else
	{
		typeNameMin = "CAT4";
	}
			
	//average age buying tickets
	avg = sumAge/count;
	
	//display at the end of the program
	cout<<"\nThe average age of buyer\t: "<<avg<<endl;
	cout <<"Best sold tickets\t\t: "<<typeNameMax<<endl;
	cout<<"Less seller tickets\t\t: "<<typeNameMin<<endl;
	
	return 0;
}



	//function with parameter and not return value
	void displayReceipt(string firstName, string secondName, float totalPrice, float discount, float tax, float newPrice)
	{
			cout<<"\nName\t\t\t: "<<firstName<<" "<<secondName<<endl;
			cout<<"Prices\t\t\t: RM"<<totalPrice<<endl; 
			cout<<"Discount\t\t: RM"<<discount<<endl;
			cout<<"Tax\t\t\t: RM"<<tax<<endl;
			cout<<"Total Prices\t\t: RM"<<newPrice<<endl;
	}
	
	
	//function with parameter and return value
	float calcTax(float totalPrice)
	{
			float tax = 0.06*totalPrice;

			return tax;			
	}
	
	float calcPrice(float totalPrice,float discount,float tax)
	{
		float newPrice;
		newPrice = (totalPrice - discount)+ tax;	
		
		return newPrice;
	}
	

	//function without parameter and not return value
    void displayClosing()
    {
    	cout<<"\n___________________________________________________________________"<<endl;
    	cout<<"\n\t\tTHANK YOU FOR USING THIS SYSTEM"<<endl;
	}
	
	
	//function without parameter and return value
	float calcDiscount ()
	{
		float discount;
		string code;
		
		cout<<"\nDiscount Code\t\t: ";
		cin>>code ;
			
		if ( code == "DIS12")
		{
			discount = 0.15;
		}
		else
		{
			discount = 0;
		}
			
		return discount;
	}
	
