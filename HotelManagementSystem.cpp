#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
using namespace std;
int sta_room, exe_room;
int sta_meal, exe_meal;
string username = "Hello", password;
void read_rates()
{
	fstream rates, admin;
	rates.open("Rates.txt");
	if (rates.is_open())
	{
		rates >> sta_room >> exe_room >> sta_meal >> exe_meal;
	}
	else
		cout << "Shit";
	rates.close();
	admin.open("Admin.txt");
	if (admin.is_open())
	{
		admin >> username;
		admin >> password;
	}
	admin.close();
}
void change_username()
{

	fstream admin;
	admin.open("Admin.txt");
	if (admin.is_open())
	{
		cout << "Enter New Username: ";
		cout << "\x1B[94m";
		cin >> username;
		cout << "\x1B[37m";
		admin << username << endl;
		cout << "Enter New Password: ";
		cout << "\x1B[94m";
		cin >> password;
		cout << "\x1B[37m";
		admin << password << endl;
	}
	cout << "\x1B[33m"<<"Username and password updated....." << "\x1B[37m";
	admin.close();

}
void change_rates()
{
	ofstream rates("Rates.txt");
	cout << "Enter new rent of Standard Room: ";
	cout << "\x1B[94m";
	cin >> sta_room;
	cout << "\x1B[37m";
	cout << "Enter new rent of Executive Room: ";
	cout << "\x1B[94m";
	cin >> exe_room;
	cout << "\x1B[37m";
	cout << "Enter new rent of Standard Meal: ";
	cout << "\x1B[94m";
	cin >> sta_meal;
	cout << "\x1B[37m";
	cout << "Enter new rent of Executive Meal: ";
	cout << "\x1B[94m";
	cin >> exe_meal;
	cout << "\x1B[37m";
	rates << sta_room << endl << exe_room << endl << sta_meal << endl << exe_meal << endl;
	cout << "\x1B[33m"<< "Rates have been successfully updated : "<<"\x1B[37m";
	rates.close();

}
void standard_room()
{
	cout << "Your " << "\x1B[33m" << "standard" << "\x1B[37m" << " room has:                  " << endl;
	cout << "\x1B[92m";
	cout << "\tNo Wifi                                " << endl;
	cout << "\tFree room service                      " << endl;
	cout << "\tLocker                                 " << endl;
	cout << "\tMini Bar                               " << endl;
	cout << "\tAir Conditioner                        " << endl;
	cout << "\x1B[37m";
}
void executive_room()
{
	cout << "Your " << "\x1B[33m"<<"Executive" << "\x1B[37m" << " room has : " << endl;
	cout << "\x1B[92m";
	cout << "\tFire place                             " << endl;
	cout << "\tFree Wifi                              " << endl;
	cout << "\tFree room service                      " << endl;
	cout << "\tLocker                                 " << endl;
	cout << "\tMini Bar                               " << endl;
	cout << "\tBalcony with Beautiful views           " << endl;
	cout << "\tLavish bathrooms                       " << endl;
	cout << "\x1B[37m";
}

void standard_menu()
{
	cout << "Standard" << "\x1B[33m" << " Breakfast" << "\x1B[37m" << " Includes: " << "\x1B[92m" << "\n";
	cout << "\tBaccon egg & cheese biscuit.\n";
	cout << "\tEgg Muffin\n";
	cout << "\tSausage Muffin with egg\n";
	cout << "\tFrench Toast\n";
	cout << "\x1B[37m"<<"Standard" << "\x1B[33m" << " Dinner" << "\x1B[37m" << " Includes:" << "\x1B[92m" << "\n";
	cout << "\tMalai Boti\n";
	cout << "\tChicken Karahi\n";
	cout << "\tMutton Karahi\n";
	cout << "\tBBQ Platter\n";
	cout << "\x1B[33m" << "Sweets:" << "\x1B[92m" << " \n";
	cout << "\tGajreela" << "\x1B[37m" << " \n";
}
void executive_menu()
{
	cout << "\x1B[37m" << "Executive " << "\x1B[33m" << "Breakfast" << "\x1B[37m" << " includes:  " << "\x1B[92m" << endl;
	cout << "\tFreshly baked croissants & muffins                " << endl;
	cout << "\tJam and Butter                                    " << endl;
	cout << "\tFresh bagels with Egg                             " << endl;
	cout << "\tSmoked Salmon                                     " << endl;
	cout << "\tFresh fruit platter                               " << endl;
	cout << "\tArabic cold and hot corner                        " << endl;
	cout << "\tAsian cold and hot corner                         " << endl;
	cout << "\x1B[37m" << "Executive " << "\x1B[33m" << " Dinner" << "\x1B[37m" << " includes:  " << "\x1B[92m" << "                        " << endl;
	cout << "\tMutton Tikka                                      " << endl;
	cout << "\tMalai Boti                                        " << endl;
	cout << "\tMutton Chaanp                                     " << endl;
	cout << "\tGola Kabab                                        " << endl;
	cout << "\tMutton Karahi                                     " << endl;
	cout << "\tChicken Jalfrezi                                  " << endl;
	cout << "\tSalud                                             " << endl;
	cout  << "\x1B[33m" << "Sweets:" << "\x1B[92m" << "                                             " << endl;
	cout << "\tCustard                                           " << endl;
	cout << "\tRas Malae  "<<"\x1B[37m" << "                                       " << endl;
}
bool search(string name_check)
{
	string temp;
	ifstream fout;
	fout.open("Customers.txt");
	if (fout.is_open())
	{
		while (fout >> temp)
		{
			if (name_check == temp)
			{
				fout.close();
				return true;
			}
		}
	}
	else
		cout <<  "\x1B[33m"<<" Can't open file\n" << "\x1B[37m ";
	fout.close();
	return false;
}
void deletee(string name_check)
{
	// int x;
	// char arr_name[40][20];
	string temp;
	bool check = search(name_check);
	if (check)
	{
		fstream fout, f1out, temp_file;
		temp_file.open("temp.txt", ios::out);
		fout.open("Customers.txt", ios::in);
		int k = 0;
		if (temp_file.is_open() && fout.is_open())
		{
			while (fout >> temp)
			{
				if (temp != name_check)
				{
					temp_file << temp << endl;
				}
			}

			temp_file.close();
			fout.close();
			remove("Customers.txt");
			rename("temp.txt", "Customers.txt");
			cout << "Customer successfully deleted. " << endl;
		}

	}
	else
		cout <<  "\x1B[33m"<<"File not deleted(not found) : " << "\x1B[37m";
}

void add_customer()
{
	string name, input;
	ofstream fout;
	cout << "Enter Customer's First Name: " ;
	cout << "\x1B[94m";
	cin >> name;
	cout << "\x1B[37m";
	fout.open("Customers.txt", ios::app);
	fout << endl << name << endl;
	fout.close();
	fout.open(name, ios::out);
	if (fout.is_open())
	{
		cout << "Enter Customer's Second name: ";
		cout << "\x1B[94m";
		cin >> input;
		cout << "\x1B[37m";
		fout << input << endl;
		cout << "Enter Customer's contact number: ";
		cout << "\x1B[94m";
		cin >> input;
		cout << "\x1B[37m";
		fout << input << endl;
		cout << "Enter Customer's occupation: ";
		cout << "\x1B[94m";
		cin >> input;
		cout << "\x1B[37m";
		fout << input << endl;
		cout << "Enter Customer's age: ";
		cout << "\x1B[94m";
		cin >> input;
		cout << "\x1B[37m";
		fout << input << endl;
		cout << "Enter number of days Customer wants to stay: ";
		cout << "\x1B[94m";
		cin >> input;
		cout << "\x1B[37m";
		fout << input << endl;
	q:	cout << "Enter chosen room package" << "\x1B[32m"<< " (1.Standard / 2.Executive) : ";
		cout << "\x1B[92m";
		cin >> input;
		cout << "\x1B[37m";
		if (input != "1" && input != "2")
		{
			cout << "\x1b[A\b\b\b\b\b\b";
			cout << "\33[2K\r";
			goto q;
		}
		fout << input << endl;
	c:	cout << "Enter chosen Meal package" << "\x1B[32m" <<" (1.None / 2.Standard / 3.Executive) : ";
		cout << "\x1B[92m";
		cin >> input;
		cout << "\x1B[37m";
		if (input != "1" && input != "2" && input != "3")
		{
			cout << "\x1b[A\b\b\b\b\b\b";
			cout << "\33[2K\r";
			goto c;
		}
		fout << input << endl;
		cout << "\x1B[33m";
		cout <<  "\x1B[33m"<<"Customer has been successfully added... " << "\x1B[37m" << endl;
		cout << "\x1B[37m";
		fout.close();
	}
}
int bill(string name)
{
	fstream fout;
	int bill = 0, temp, x;
	string name1;
	fout.open(name);
	if (fout.is_open())
	{
		int i = 0;
		while (fout >> name1)
		{
			if (i == 3)
			{
				fout >> bill;
				temp = bill;
				fout >> x;
				if (x == 1)
					bill *= sta_room;
				else
					bill *= exe_room;
				fout >> x;
				if (x == 2)
					bill += (temp * sta_meal);
				else if (x == 3)
					bill += (temp * exe_meal);
			}
			i++;
		}

	}
	return bill;
}
void display()
{
	cout << "Enter First name of customer you want to check details: " << endl;
	cout << "\x1B[94m";

	fstream fout;
	string x, name;
	cin >> name;
	cout << "\x1B[37m";

	fout.open(name);
	if (fout.is_open())
	{
		int i = 0;
		while (fout >> x)
		{
			if (i == 0)
				cout << "Customer name is: "<<  "\x1B[94m" << name << " " << x <<  "\x1B[37m"<< endl;
			else if (i == 1)
				cout << "Customer's Contact number is: " << "\x1B[94m"<<x << "\x1B[37m" << endl;
			else if (i == 2)
				cout << "Customer's Occupation is: " << "\x1B[94m" << x<<  "\x1B[37m" << endl;
			else if (i == 3)
				cout << "Customer's Age is: " << "\x1B[94m" << x << "\x1B[37m" << " years " << endl;
			else if (i == 4)
				cout << "Customer wants to stay " << "\x1B[94m" << x << "\x1B[37m" << " days" << endl;
			else if (i == 5)
			{
				cout << "Customer's room package is: ";
				cout << "\x1B[94m";
				if (x == "1")
					cout << "Standard " << endl;
				else
				{
					cout << "Executive " << endl;
				}
				cout<< "\x1B[37m";
			}
			else if (i == 6)
			{
				if (x == "1")
					cout << "Chosen Meal Package: "<< "\x1B[94m" << "None\n" ;
				else if (x == "2")
					cout << "Chosen Meal Package: " << "\x1B[94m" << "Standard\n";
				else if (x == "3")
					cout << "Chosen Meal Package: " << "\x1B[94m" << "Executive\n";
				cout << "\x1B[37m";
				cout << "Customers's Due bill is: Rs." << "\x1B[94m" << bill(name) << "\x1B[31m" << endl;
			}

			i++;
		}
	}
	else
		cout << "\x1B[33m" << "Customer not found... " << "\x1B[37m" << endl;
	fout.close();

}
void view_Bill(string name)
{
	fstream fout;
	int x, bill, temp;
	string name1, y;
	fout.open(name);
	if (fout.is_open())
	{
		int i = 0;
		while (fout >> name1)
		{
			if (i == 0)
			{
				cout << "Customer name is: " << "\x1B[33m" << name << " " << name1 << "\x1B[37m" << endl;
			}
			if (i == 3)
			{
				fout >> temp;
				bill = temp;
				cout << "Total Days Stayed: " << "\x1B[33m" << temp << "\x1B[37m";
				cout << "\nCustomer's bill for ";
				fout >> x;
				if (x == 1)
				{
					cout << "Standard room Package is: Rs." << "\x1B[33m" ;
					bill *= sta_room;
					cout << bill << endl;
					cout << "\x1B[37m";
				}
				else
				{
					cout << "Executive room Package is: Rs." << "\x1B[33m";
					bill *= exe_room;
					cout << bill << endl;
					cout << "\x1B[37m";
				}
				fout >> x;
				cout << "Customer's bill for ";
				if (x == 1)
					cout << "no Package:" << "\x1B[33m" << " Rs.0\n " << "\x1B[37m"<< endl;
				else if (x == 2)
				{
					bill += (temp * sta_meal);
					cout << "Standard meal Package: Rs." << "\x1B[33m"<< (temp * sta_meal) << "\x1B[37m"<< endl;
				}
				else if (x == 3)
				{
					bill += (temp * exe_meal);
					cout << "Executive meal Package: Rs." << "\x1B[33m" << (temp * exe_meal) << "\x1B[37m" << endl;
				}
				cout << "Customer's due amount is: Rs." << "\x1B[33m" << bill << "\x1B[37m" << endl;
			}
			i++;
		}
	}
	else
		cout << "\x1B[33m" << "Customer not found... " << "\x1B[37m" << endl;

	fout.close();
}
void Customer(string name)
{


	ifstream fout;
	string x;
	fout.open(name);
	if (fout.is_open())
	{
		int i = 0;
		while (fout >> x)
		{
			if (i == 0)
				cout << "Your name is: " << "\x1B[33m" << name << " " << x << "\x1B[37m" << endl;
			else if (i == 1)
				cout << "Your Contact number is: " << "\x1B[33m" << x << "\x1B[37m" << endl;
			else if (i == 2)
				cout << "Your Occupation is: " << "\x1B[33m" << x << "\x1B[37m" << endl;
			else if (i == 3)
				cout << "Your Age is: " << "\x1B[33m" << x << " years " << "\x1B[37m" << endl;
			else if (i == 4)
				cout << "You want to stay " << "\x1B[33m" << x << " days" << "\x1B[37m" << endl;
			else if (i == 5)
			{
				cout << "Your room package is: ";
				cout << "\x1B[33m";
				if (x == "1")
				{
					cout << "Standard " << "\x1B[37m" << endl;
					standard_room();
				}
				else
				{
					cout << "\x1B[33m"<< "Executive " << "\x1B[37m" << endl;
					executive_room();
				}
			}
			else if (i == 6)
			{
				if (x == "1")
					cout << "\nChosen Meal Package:" << "\x1B[33m"<< "None" << "\x1B[37m" <<"\n\n";
				else if (x == "2")
				{
					cout << "\nChosen Meal Package:" << "\x1B[33m "<<" Standard" << "\x1B[37m \n\n";
					cout << "Menu Details are: " << "\x1B[37m " << endl;
					standard_menu();
				}
				else if (x == "3")
				{
					cout << "\nChosen Meal Package: " << "\x1B[33m"<< " Executive\n\n" << "\x1B[37m";
					executive_menu();
				}
			}
			
			
				
			
			i++;
		}
		cout << "\n Your due bill is: " << "\x1B[33m" << bill(name);

	}
	else
		cout << "\x1B[33m" << "Customer not found... " << "\x1B[37m" << endl;
	fout.close();

}
void check_out()
{
	string z;
	cout << "Enter Name of Customer: ";
	cin >> z;
	view_Bill(z);
	getchar();
	deletee(z);
}
int main()
{
	read_rates();
	string username1, n, password1;
	int  q;
	string choice = "0";
	int wick = 0;       //Signature
	cout << "\x1B[33m";
l:	cout << "                                            ***************************\n";
	cout << "                                            *       WELCOME To        *\n\n";
	cout << "                                            *  GYMKHANA Club SARGODHA *\n";
	cout << "                                            ***************************\n"                                               ;
	cout << endl;
	cout << endl;
	cout << "\x1B[37m";
j:
	cout << "\t\tpress 1 for " << "\x1B[36m" <<"Admin" << "\x1B[37m" " login : " << endl;
	
	cout << "\t\tpress 2 for "<< "\x1B[36m"  <<" Customer " << "\x1B[37m" <<"login : " << endl;
	cout << "\t\tpress 3 for" << "\x1B[91m"<<" Exit : " << "\x1B[37m"<< endl;
	cin >> choice;
	if (choice == "1")
	{
		system("cls");
		cout << "\x1B[33m";
		cout << "                                            ***************************\n";
		cout << "                                            *       WELCOME To        *\n\n";
		cout << "                                            *  GYMKHANA Club SARGODHA *\n";
		cout << "                                            ***************************\n";
		cout << endl;
		cout << endl;
		cout << "\x1b[37m";
	q:			cout << "\t\tEnter"<< "\x1B[36m" <<" username : ";
		cout << "\x1B[33m";
		cin >> username1;
		cout << "\x1b[37m";
	P:		cout << "\t\tEnter "<< "\x1B[36m"<< "password: ";
		cout << "\x1B[33m";
		cin >> password1;
		cout << "\x1b[37m";
		if (username == username1 && password == password1)
		{

			cout << endl << "sucessfully login" << endl;
			system("cls");
		a:	
			cout << "\x1B[33m";
			cout << "                                            ***************************\n";
			cout << "                                            *       WELCOME To        *\n\n";
			cout << "                                            *  GYMKHANA Club SARGODHA *\n";
			cout << "                                            ***************************\n";
			cout << endl;
			cout << endl;
			cout << "\x1B[37m";
			cout << "\tPress" << "\x1B[36m" << " 1" << "\x1B[37m " << "to" << "\x1B[36m" << " add" << "\x1B[37m" << " customer:" << endl;
			cout << "\tPress" << "\x1B[36m" << " 2" << "\x1B[37m " << "to" << "\x1B[36m" << " display" << "\x1B[37m" << " customer:" << endl;
			cout << "\tPress" << "\x1B[36m" << " 3" << "\x1B[37m " << "to" << "\x1B[36m" << " search" << "\x1B[37m" << " customer:" << endl;
			cout << "\tPress" << "\x1B[36m" << " 4" << "\x1B[37m " << "to" << "\x1B[36m" << " delete" << "\x1B[37m" << " customer:" << endl;
			cout << "\tPress" << "\x1B[36m" << " 5" << "\x1B[37m " << "to" << "\x1B[36m" << " check-out" << "\x1B[37m" << " customer:" << endl;
			cout << "\tPress" << "\x1B[36m" << " 6" << "\x1B[37m " << "to" << "\x1B[36m" << " review-bill" << "\x1B[37m" << " of a customer:" << endl;
			cout << "\tPress" << "\x1B[36m" << " 7" << "\x1B[37m " << "to" << "\x1B[36m" << " change rates" << "\x1B[37m" << " of a customer:" << endl;
			cout << "\tPress" << "\x1B[36m" << " 8" << "\x1B[37m " << "to" << "\x1B[36m" << " change id/pass" << "\x1B[37m"  << endl;
			cout << "\tPress" << "\x1B[31m" << " 9" << "\x1B[37m " << "to" << "\x1B[31m" << " exit" << "\x1B[37m" << endl;
			cin >> wick;
			if (wick == 1)
			{

				system("cls");
				cout << "\x1B[33m";
				cout << "                                            ***************************\n";
				cout << "                                            *       WELCOME To        *\n\n";
				cout << "                                            *  GYMKHANA Club SARGODHA *\n";
				cout << "                                            ***************************\n";
				cout << endl;
				cout << endl;
				cout << "\x1B[37m";
				add_customer();
				getchar();
				system("cls");
				goto a;
			}
			else if (wick == 2)
			{
				system("cls");
				cout << "\x1B[33m";
				cout << "                                            ***************************\n";
				cout << "                                            *       WELCOME To        *\n\n";
				cout << "                                            *  GYMKHANA Club SARGODHA *\n";
				cout << "                                            ***************************\n";
				cout << endl;
				cout << endl;
				cout << "\x1B[37m";
				display();
				getchar();
				system("cls");
				goto a;
			}
			else if (wick == 3)
			{
				bool salud;
				system("cls");
				cout << "\x1B[33m";
				cout << "                                            ***************************\n";
				cout << "                                            *       WELCOME To        *\n\n";
				cout << "                                            *  GYMKHANA Club SARGODHA *\n";
				cout << "                                            ***************************\n";
				cout << endl;
				cout << endl;
				cout << "\x1B[37m";
				cout << "Enter Customer's First Name: " << endl;
				cout << "\x1B[94m";
				cin >> n;
				cout << "\x1B[37m";
				salud = search(n);
				if (salud)
					cout <<  "\x1B[33m"<<"Customer is found... \n" << "\x1B[37m";
				else
					cout << "\x1B[33m" << "Customer not found... \n" << "\x1B[37m";
				getchar();
				system("cls");
				goto a;
			}
			else if (wick == 4)
			{
				system("cls");
				cout << "\x1B[33m";
				cout << "                                            ***************************\n";
				cout << "                                            *       WELCOME To        *\n\n";
				cout << "                                            *  GYMKHANA Club SARGODHA *\n";
				cout << "                                            ***************************\n";
				cout << endl;
				cout << endl;
				cout << "\x1B[37m";
				cout << "Enter Customer's First Name: " << endl;
				cout << "\x1B[94m";
				cin >> n;
				cout << "\x1B[37m";
				deletee(n);
				getchar();
				system("cls");
				goto a;
			}
			else if (wick == 5)
			{
				system("cls");
				cout << "\x1B[33m";
				cout << "                                            ***************************\n";
				cout << "                                            *       WELCOME To        *\n\n";
				cout << "                                            *  GYMKHANA Club SARGODHA *\n";
				cout << "                                            ***************************\n";
				cout << endl;
				cout << endl;
				cout << "\x1B[37m";
				check_out();
				getchar();
				system("cls");
				goto a;
			}
			else if (wick == 6)
			{
				string z;
				system("cls");
				cout << "\x1B[33m";
				cout << "                                            ***************************\n";
				cout << "                                            *       WELCOME To        *\n\n";
				cout << "                                            *  GYMKHANA Club SARGODHA *\n";
				cout << "                                            ***************************\n";
				cout << endl;
				cout << endl;
				cout << "\x1B[37m";
				cout << "Enter customers Name: ";
				cout << "\x1B[33m";
				cin >> z;
				cout << "\x1B[37m";
				view_Bill(z);
				getchar();
				system("cls");
				goto a;
			}
			else if (wick == 7)
			{
				system("cls");
				cout << "\x1B[33m";
				cout << "                                            ***************************\n";
				cout << "                                            *       WELCOME To        *\n\n";
				cout << "                                            *  GYMKHANA Club SARGODHA *\n";
				cout << "                                            ***************************\n";
				cout << endl;
				cout << endl;
				cout << "\x1B[37m";
				change_rates();
				getchar();
				system("cls");
				goto a;
			}
			else if (wick == 8)
			{
				system("cls");
				cout << "\x1B[33m";
				cout << "                                            ***************************\n";
				cout << "                                            *       WELCOME To        *\n\n";
				cout << "                                            *  GYMKHANA Club SARGODHA *\n";
				cout << "                                            ***************************\n";
				cout << endl;
				cout << endl;
				cout << "\x1B[37m";
				change_username();
				getchar();
				system("cls");
				goto a;
			}
			else if (wick == 9)
			{
				system("cls");
				cout << "\x1B[33m";
				cout << "                                            ***************************\n";
				cout << "                                            *       WELCOME To        *\n\n";
				cout << "                                            *  GYMKHANA Club SARGODHA *\n";
				cout << "                                            ***************************\n";
				cout << endl;
				cout << endl;
				cout << "\x1B[37m";
				goto j;
			}

			else
			{
			cout << "\x1B[33m" << "Please enter a valid option: " << "\x1B[37m";
				for (int i = 0; i < 18; i++)
				{
					cout << "\x1b[A\b\b\b\b\b\b";
					cout << "\33[2K\r";
				}
				goto a;
			}
			
		}

		else if (username != username1 && password == password1)
		{

			for (int i = 0; i < 2; i++)
			{
				cout << "\x1b[A\b\b\b\b\b\b";
				cout << "\33[2K\r";
			}
			goto q;
		}

		else if (username == username1 && password != password1)
		{
			for (int i = 0; i < 1; i++)
			{
				cout << "\x1b[A\b\b\b\b\b\b";
				cout << "\33[2K\r";
			}
			goto P;
		}
		else {
		cout << "\x1B[33m" << "Access failed... \n" << "\x1B[37m";
			exit(1);
		}
	}
	else if (choice == "2")
	{
	system("cls");
	cout << "\x1B[33m";
	cout << "                                            ***************************\n";
	cout << "                                            *       WELCOME To        *\n\n";
	cout << "                                            *  GYMKHANA Club SARGODHA *\n";
	cout << "                                            ***************************\n";
	cout << endl;
	cout << endl;
	cout << "\x1B[37m";
		string z;
		bool capice;
		cout << "Enter your First Name: ";
		cin >> z;
		capice = search(z);
		if (capice)
		{
			system("cls");
			Customer(z);
		}
		else
		{
			cout << "\x1B[33m" << "You are not registered.GET OUT!!!!!!!  \n" << "\x1B[37m";
			return 0;
		}
		getchar();
		system("cls");
		goto l;
	}
	else if (choice == "3")
	{
	return 0;
	}
	else
	{
	cout << "\x1B[33m" << "Please choose a correct option:  \n" << "\x1B[37m";
		for (int i = 0; i < 5; i++)
		{
			cout << "\x1b[A\b\b\b\b\b";
			cout << "\33[2K\r";
		}
		goto j;
	}

}