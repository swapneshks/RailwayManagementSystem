
/*****************************************************************************
**************************** COMPUTER PROJECT ********************************
******************************************************************************
*************************RAILWAY MANAGEMENT SYSTEM****************************
******************************************************************************/

//added source for trains
//renamed variables
//using vector instead of arrays for accounts and tickets
//replaced getch with cin.get
//replaced clrscr with system("clear")
//using overloaded operators instead of eof method for files

//HEADER FILES

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

int i=-1,j=-1;//j-account,i-ticket; global variables for handling objects.

/*****************************************************************************
		     CLASS DEFINITION OF ACCOUNT CLASS
******************************************************************************/

class Account
{
	 string name;
	 long accno;

	 public:

	 Account() {
        name="";
        accno=0;
     }

	 void setacc(int a)           //TAKES ACCOUNT DETAILS
	 {
		  cout<<"\n\t  ENTER USERNAME - ";
		  cin.ignore();
		  getline(cin,name);
		  accno=a;
	 }

	 void update(int t)            //UPDATES ACCOUNT DETAILS
	 {
		  accno=t;
		  cout<<"\n\t ENTER NEW USERNAME - ";
		  cin.ignore();
		  getline(cin,name);
		  cout<<"\n\n\tAccount Updated!";
	 }

	 long getAccNo()                 //RETURNS ACCOUNT NUMBER
	 {
		 return accno;
	 }

	 void showacc()                 //SHOWS ACCOUNT DETAILS
	 {
		  cout<<"\n\n\n\n\tUSERNAME       : ";
		  cout<<name;
		  cout<<"\n\tACCOUNT NUMBER : ";
		  cout<<accno;
	 }

	 friend std::ostream& operator<< (std::ostream&, const Account&);
     friend std::istream& operator>> (std::istream&, Account&);
};

istream& operator>>(istream& in, Account& a)
{
    getline(in, a.name, ',');
    in >> a.accno;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
}

ostream& operator<<(ostream& out, const Account& a)
{
    out << a.name  << ',' << a.accno << endl;
    return out;
}

/*****************************************************************************
			CLASS DEFINITION OF TICKET CLASS
******************************************************************************/

class Ticket
{
	 string trainName;
	 string passengerName;
	 string trainTime;
	 string date;
	 char gender;
	 int source;
	 int destination;
	 int classCode;
	 int paymentMode;
	 int age;
	 int fare;
	 long ticketNumber;
	 long accno;

	 public:

	 int bookTicket();
	 void showticket();

     long getAccNo() {
        return accno;
     }

	 void setAccNo(long accno) {
        this->accno = accno;
	 };

	 friend std::ostream& operator<< (std::ostream&, const Ticket&);
     friend std::istream& operator>> (std::istream&, Ticket&);
};


/***MEMBER FUNCTION TO BOOK TICKET***/

int Ticket::bookTicket()
{
	destination=-1;
	source=-1;
	classCode=-1;
	paymentMode=-1;

    int trainChoice=-1;

    while((trainChoice<0)||(trainChoice>4))
	{
		system("clear");

        while((source>4)||(source<0))
		{
			cout<<"\n  Enter your station ";
			cout<<"\n  1.MADRAS\t2.RAIPUR\t3.HYDERABAD\t4.INDORE\n  ";
			cin>>source;
			if((source>4)||(source<0))
				cout<<"\n Invalid entry \n Enter again";
		}

		while((destination>4)||(destination<0)||(destination==source))
		{
			cout<<"\n  Enter your destination ";
			cout<<"\n  1.MADRAS\t2.RAIPUR\t3.HYDERABAD\t4.INDORE\n  ";
			cin>>destination;
			if((destination>4)||(destination<0)||(destination==source))
				cout<<"\n Invalid entry \n Enter again";
		}

		cout<<"\n\n  Available trains are:";
		cout<<"\n    TRAIN \t\t DATE   \tTIME \tFARE(Rs) ";
		cout<<"\n    1.MUMBAI EXPRESS \t 13/10/12 \t00:10 \t5000";
		cout<<"\n    2.DELHI EXPRESS \t 13/12/12 \t20:10 \t3000";
		cout<<"\n    3.KOLKATA EXPRESS \t 12/09/12 \t10:10 \t2000";
		cout<<"\n    4.CHENNAI EXPRESS \t 11/08/12 \t12:10 \t4000";
		cout<<"\n    5.EXIT";
		cout<<"\n\n  Enter your choice...";
		cin>>trainChoice;

		if((trainChoice<0)||(trainChoice>5))
		{
			cout<<"\n  INVALID ENTRY \n  ENTER AGAIN... ";
			cin.get();cin.ignore();
			continue;
		}
		else if(trainChoice==5)
		{
			cout<<"\n Exiting...";
			cin.get();cin.ignore();
			return 0;
			break;
		}
		else
		{
			cout<<"\n  Enter passenger name ";
			cin.ignore();
			getline(cin, passengerName);
			cout<<"\n  Enter age of the passenger ";
			cin>>age;
			cout<<"\n  Enter gender of the passenger(M/F) ";
			cin>>gender;
			while((gender!='M')&&(gender!='m')&&(gender!='F')&&(gender!='f'))
			{
				cout<<"\n INVALID ENTRY \n ENTER AGAIN...\n";
				cin>>gender;
			}
			while((classCode>3)||(classCode<0))
			{
				cout<<"\n  Enter compartment type ";
				cout<<"\n  1.SLEEPER CLASS\t2.3 A/C\t  3.2 A/C\n  ";
				cin>>classCode;
				if((classCode>4)||(classCode<0))
					cout<<"\n Invalid entry \n Enter again";
			}
		}

		while((paymentMode>4)||(paymentMode<0))
		{
			cout<<"\n  Enter mode of payment ";
			cout<<"\n  1.Cash\t2.Debit card\t3.Cheque\n  ";
			cin>>paymentMode;
			if((paymentMode>4)||(paymentMode<0))
				cout<<"\n INVALID ENTRY \n ENTER AGAIN...\n";
		}

		switch(trainChoice)
		{
		case 1:
			trainName="Mumbai Express";
			ticketNumber=1234;
			trainTime="00:10";
			date="13/10/12";
			fare=3000;
			break;
		case 2:
			trainName="Delhi Express";
			ticketNumber=1235;
			trainTime="20:10";
			date="13/12/12";
			fare=2500;
			break;
		case 3:
			trainName="Kolkata Express";
			ticketNumber=5678;
			trainTime="10:10";
			date="12/09/12";
			fare=2700;
			break;
		case 4:
			trainName="Chennai Express";
			ticketNumber=5679;
			trainTime="12:10";
			date="11/08/12";
			fare=2100;
			break;

		}
		return 1;
	}
}

 /*** MEMBER FUNCTION TO DISPLAY BOOKED TICKETS ***/

void Ticket::showticket()
{

	cout<<"\n\n\t\t\tINDIAN RAILWAYS";
	cout<<"\n\t\t\t---------------";
	cout<<"\n\n\n\tPASSENGER NAME: ";  cout<<passengerName;
	cout<<"\n\tAGE: "<<age;
	cout<<"\t\tGENDER: "<<gender;
	cout<<"\n\n\tTRAIN NO.: "<<ticketNumber;
	cout<<"\t    TRAIN NAME: "; cout<<trainName;
	cout<<"\n\tCLASS: ";
	if(classCode==1) cout<<"SLEEPER";
	else if(classCode==2) cout<<"3AC";
	else if(classCode==3) cout<<"2AC";
	cout<<"\tFARE: "<<fare;
	cout<<"\tDATE: "<<date;
	cout<<"\n\n\tDEPARTURE: ";
	if(source==1) cout<<"MADRAS";
	else if(source==2) cout<<"RAIPUR";
	else if(source==3) cout<<"HYDERABAD";
	else if(source==4) cout<<"INDORE";
	cout<<"\tARRIVAL: ";
	if(destination==1) cout<<"MADRAS";
	else if(destination==2) cout<<"RAIPUR";
	else if(destination==3) cout<<"HYDERABAD";
	else if(destination==4) cout<<"INDORE";
	cout<<"\n\n\tDEPARTURE TIME: "<<trainTime;
	cout<<"\n\n\tPAYMENT BY	: ";
	if(paymentMode==1) cout<<"CASH ";
	else if(paymentMode==2) cout<<"DEBIT CARD";
	else if(paymentMode==3) cout<<"CHEQUE";
}

istream& operator>> (istream& in, Ticket& t)
{
    string input;
    getline(in, t.passengerName, ',');
    getline(in, t.trainName, ',');
    getline(in, t.date, ',');
    getline(in, input, ',');
    istringstream(input)>>t.gender;
    getline(in, input, ',');
    istringstream(input)>>t.source;
    getline(in, input, ',');
    istringstream(input)>>t.destination;
    getline(in, input, ',');
    istringstream(input)>>t.classCode;
    getline(in, input, ',');
    istringstream(input)>>t.paymentMode;
    getline(in, input, ',');
    istringstream(input)>>t.age;
    getline(in, input, ',');
    istringstream(input)>>t.fare;
    getline(in, input, ',');
    istringstream(input)>>t.ticketNumber;
    getline(in, input);
    istringstream(input)>>t.accno;
    return in;
}

ostream& operator<<(ostream& out, const Ticket& t)
{
    out << t.passengerName << ','
        << t.trainName << ','
        << t.date << ','
        << t.gender << ','
        << t.source << ','
        << t.destination << ','
        << t.classCode << ','
        << t.paymentMode << ','
        << t.age << ','
        << t.fare << ','
        << t.ticketNumber << ','
        << t.accno << endl;
    return out;
}

/***************************************************************************
****************************** MAIN PROGRAM ********************************
****************************************************************************/

int main()
{
    vector<Account> accounts;
    vector<Ticket> tickets;

    Account dummyAccount;
    Ticket dummyTicket;

	//Reading existing data from files
	ifstream ifile("acc.dat",ios::in);

	while(ifile >> dummyAccount)
		accounts.push_back(dummyAccount);

    ifile.close();

    ifile.clear();
	ifile.open("ticket.dat",ios::in);

	while(ifile >> dummyTicket) {
        tickets.push_back(dummyTicket);
    }

    ifile.close();

	system("clear");

	int menuChoice;

	cout<<"\n\n\t\t\t RAILWAY MANAGEMENT SYSTEM";
	cout<<"\n\t\t\t =========================";

	cin.ignore();
	do
	{
		system("clear");

 /******** WELCOME SCREEN ***********/

		cout<<"\n\n\t\tINDIAN RAILWAYS";
		cout<<"\n\t\t===============";
		cout<<"\n\n\t-> ENTER 1  to  CREATE AN ACCOUNT";
		cout<<"\n\n\t-> ENTER 2  to  LOG IN AND ACCESS YOUR ACCOUNT";
		cout<<"\n\n\t-> ENTER 3  to  DELETE YOUR ACCOUNT";
		cout<<"\n\n\t-> ENTER ANY OTHER NUMBER TO EXIT";
		cout<<"\n\n\t\tEnter your choice... ";
		cin>>menuChoice;

		int flag_account_exist;

		switch(menuChoice)
		{
		case 1: {//THIS CASE CREATES ACCOUNTS
			ofstream ofile("acc.dat",ios::binary|ios::app);

			system("clear");

			cout<<"\n\t  CREATING ACCOUNT";
			cout<<"\n\t  ----------------";
			cout<<"\n\n\tPlease enter account details...";

			int tempAccNo;
			cout<<"\n\n\t  ENTER ACCOUNT NUMBER";
			cout<<"\n\t  (should consist only numbers, max. 5 digits) - ";
			cin>>tempAccNo;

			flag_account_exist=-1;
			if(accounts.empty())
			{
				dummyAccount.setacc(tempAccNo);
				cout<<"\n\tAccount created!";
				accounts.push_back(dummyAccount);
				ofile<<dummyAccount;
			}
			else
			{                     //Check for existng accounts
				for(vector<Account>::iterator it = accounts.begin(); it != accounts.end(); it++)
					if(it->getAccNo()==tempAccNo)
					{
						cout<<"\n\t ACCOUNT ALREADY EXISTS! ";
						flag_account_exist=0;
						cin.ignore();
						break;
					}
				if(flag_account_exist==-1)
				{
					dummyAccount.setacc(tempAccNo);
					cout<<"\n\tAccount created!";
					accounts.push_back(dummyAccount);
					ofile<<dummyAccount;
				}
			}
			cin.ignore();
			break;
        }
		case 2: { //THIS CASE HELPS TO ACCESS ACCOUNT
            long accnoLoggedIn;
			system("clear");
			int flag_account_found=-1;
			long tempAccNo;
			cout<<"\n\n\tENTER ACCOUNT NUMBER: ";
			cin>>tempAccNo;
			for(vector<Account>::iterator it = accounts.begin(); it != accounts.end(); it++)
				if(it->getAccNo()==tempAccNo)
				{
					flag_account_found=0;
					accnoLoggedIn = it->getAccNo();
				}

			if(flag_account_found==-1)       //Check if account exists
			{
				cout<<"\n\tAccount does not exist!";
				cin.get();cin.ignore();
			}
			else
			{
				int loginChoice;
				do
				{
					system("clear");
					cout<<"\n\n\t... logged in succesfully!";
					cout<<"\n\n\t-> ENTER 1  to  UPDATE YOUR ACCOUNT ";
					cout<<"\n\n\t-> ENTER 2  to  BOOK TICKETS ";
					cout<<"\n\n\t-> ENTER 3  to  VIEW BOOKED TICKETS";
					cout<<"\n\n\t-> ENTER 4  to  VIEW ACCOUNT DETAILS";
					cout<<"\n\n\t-> ENTER ANY OTHER NUMBER TO LOGOUT";
					cout<<"\n\n\t Enter your choice...";
					cin>>loginChoice;
					switch(loginChoice)
					{
					case 1: {//THIS CASE HELPS TO UPDATE ACCOUNT
						system("clear");

						ofstream file("tempacc.dat",ios::binary);
						int flag_account_update=-1;

						int tempNewAccNo;
						cout<<"\n\n\n\t ENTER (NEW) ACCOUNT NUMBER: ";
						cin>>tempNewAccNo;

						for(vector<Account>::iterator it = accounts.begin(); it != accounts.end(); it++)
							if(it->getAccNo()==tempNewAccNo)
							{
								cout<<"\n\t ACCOUNT NUMBER ALREADY EXISTS! ";
								flag_account_update=0;
								break;
							}

						if(flag_account_update==-1)
						{
							for(vector<Ticket>::iterator it = tickets.begin(); it != tickets.end(); it++)
							{
								if(it->getAccNo()==accnoLoggedIn)
									it->setAccNo(tempNewAccNo);
							}

							for(vector<Account>::iterator it = accounts.begin(); it != accounts.end(); it++) {
                                if(it->getAccNo()==accnoLoggedIn)
                                    it->update(tempNewAccNo);
                            }

                            accnoLoggedIn=tempNewAccNo;
						}

						for(vector<Account>::iterator it = accounts.begin(); it != accounts.end(); it++) {
							dummyAccount = *it;
							file<<dummyAccount;
                        }
						file.close();
						remove("acc.dat");
						rename("tempacc.dat","acc.dat");

						file.open("tempticket.dat",ios::binary);

						for(vector<Ticket>::iterator it = tickets.begin(); it != tickets.end(); it++) {
                            dummyTicket = *it;
                            file<<dummyTicket;
						}
						file.close();
						remove("ticket.dat");
						rename("tempticket.dat","ticket.dat");

						cin.ignore();
						break;
                    }
					case 2: {//THIS CASE HELPS TO BOOK TICKETS
						system("clear");

						ofstream tfile("ticket.dat", ios::app);
						if(dummyTicket.bookTicket()==1)
						{
                            cout<<"\n\tTicket booked!"<< endl
                                <<"\n\tComplete the payment through our payment"<< endl
                                <<"\tportal to validate your ticket...";
                            cin.get();
                            cin.ignore();
							dummyTicket.setAccNo(accnoLoggedIn);
							tickets.push_back(dummyTicket);
							tfile<<dummyTicket;
							tfile.close();
						}
						break;
                    }

					case 3: { //THIS CASE HELPS TO VIEW BOOKED TICKETS
						system("clear");
						int flag_tickets_booked=-1;
						for(vector<Ticket>::iterator it = tickets.begin(); it != tickets.end(); it++)
						{
							if(it->getAccNo() == accnoLoggedIn)
							{
                                system("clear");
                                it->showticket();
                                flag_tickets_booked = 1;
                                cin.get();cin.ignore();
							}
						}
						if(flag_tickets_booked==-1)
						{
							cout<<"\n\n\tNo tickets booked!";
							cin.get();cin.ignore();
						}
						break;
                    }
					case 4://THIS CASE HELPS TO VIEW ACCOUNT DETAILS
						system("clear");
						for(vector<Account>::iterator it = accounts.begin(); it != accounts.end(); it++) {
                                if(it->getAccNo()==accnoLoggedIn) {
                                    it->showacc();
                                    cin.get();cin.ignore();
                                }
                        }
					}
				}while(loginChoice<5);
			}
			break;
        }
		case 3: //THIS CASE DELETES SPECIFIED ACCOUNT
			system("clear");

			int tempDelAccNo;
			int flag_account_delete=-1;
			cout<<"\n\n  ENTER ACCOUNT NUMBER(to be deleted): ";
			cin>>tempDelAccNo;

			ofstream newfile("tempacc.dat",ios::binary);

            vector<Account>::iterator a_it = accounts.begin();
			while(a_it != accounts.end())
			{
				if(tempDelAccNo==a_it->getAccNo()) {
                    accounts.erase(a_it);
                    flag_account_delete=1;
				}
				else {
                    dummyAccount = *a_it;
                    newfile<<dummyAccount;
                    a_it++;
				}
			}

			newfile.close();
			remove("acc.dat");
			rename("tempacc.dat","acc.dat");

			if(flag_account_delete == -1)
				cout<<"\n  Account does not exist! ";
			else
				cout<<"\n  ACCOUNT (Account number:"<<tempDelAccNo<<") IS DELETED... ";

			newfile.open("tempticket.dat",ios::binary);

            vector<Ticket>::iterator t_it = tickets.begin();
			while(t_it != tickets.end())
			{
				if(tempDelAccNo==t_it->getAccNo()) {
                    tickets.erase(t_it);
				}
				else {
                    dummyTicket = *t_it;
                    newfile<<dummyTicket;
                    t_it++;
				}
			}

			newfile.close();

			remove("ticket.dat");
			rename("tempticket.dat","ticket.dat");
			cin.get();cin.ignore();
			break;
		}
	}while(menuChoice<4);
}



