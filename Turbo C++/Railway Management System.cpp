
/*****************************************************************************
**************************** COMPUTER PROJECT ********************************
******************************************************************************
*************************RAILWAY MANAGEMENT SYSTEM****************************
******************************************************************************/

//HEADER FILES

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>



int i=-1,j=-1;//j-account,i-ticket; global variables for handling objects.

/*****************************************************************************
		     CLASS DEFINITION OF ACCOUNT CLASS
******************************************************************************/
class account
{
 char name[20];
 long int accno;
 public:
  void getacc(int a)           //TAKES ACCOUNT DETAILS
 {
  cout<<"\n\t  ENTER USERNAME - ";
  gets(name);
  accno=a;
  }
  void update(int t)            //UPDATES ACCOUNT DETAILS
 {
  accno=t;
  cout<<"\n\t ENTER NEW USERNAME - ";
  gets(name);
  cout<<"\n\n\tAccount Updated!";
 }
 long int ano()                 //RETURNS ACCOUNT NUMBER
 {
  return accno;
 }
 void showacc()                 //SHOWS ACCOUNT DETAILS
 {
  cout<<"\n\n\n\n\tUSERNAME       : ";
  puts(name);
  cout<<"\n\tACCOUNT NUMBER : ";
  cout<<accno;
 }
};

account a[10]; //j

/*****************************************************************************
			CLASS DEFINITION OF TICKET CLASS
******************************************************************************/

class ticket
{
 private:
 char tname[20];
 char pname[10];
 char dtime[15];
 char date[18];
 char gender;
 int dplace;
 int clas;
 int mode;
 int age;
 int fare;
 long int tno;

 public:
 long int ptr;
 int getticket();
 void showticket();
};

ticket t[10]; //i

/***MEMBER FUNCTION TO BOOK TICKET***/

int ticket::getticket()
 {

  int choice=-1;
   dplace=-1;
    clas=-1;
  while((choice<0)||(choice>4))
   {
    clrscr();
    while((dplace>4)||(dplace<0))
    {
     cout<<"\n  Enter your station ";
     cout<<"\n  1.MADRAS\t2.RAIPUR\t3.HYDERABAD\t4.INDORE\n  ";
     cin>>dplace;
     if((dplace>4)||(dplace<0))
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
    cin>>choice;
   if((choice<0)||(choice>5))
     {
      cout<<"\n  INVALID ENTRY \n  ENTER AGAIN... ";
      getch();
      continue;
     }
   else if(choice==5)
    {
     cout<<"\n Exiting...";
     getch();
     return 0;
     break;
    }
   else
   {
   cout<<"\n  Enter passenger name ";
   gets(pname);
   cout<<"\n  Enter age of the passenger ";
   cin>>age;
   cout<<"\n  Enter gender of the passenger(M/F) ";
   cin>>gender;
    while((gender!='M')&&(gender!='m')&&(gender!='F')&&(gender!='f'))
    {
     cout<<"\n INVALID ENTRY \n ENTER AGAIN...\n";
     cin>>gender;
    }
    while((clas>3)||(clas<0))
    {
     cout<<"\n  Enter compartment type ";
     cout<<"\n  1.SLEEPER CLASS\t2.3 A/C\t  3.2 A/C\n  ";
     cin>>clas;
     if((clas>4)||(clas<0))
     cout<<"\n Invalid entry \n Enter again";
    }
   }
    mode=-1;
    while((mode>4)||(mode<0))
    {
     cout<<"\n  Enter mode of payment ";
     cout<<"\n  1.Cash\t2.Debit card\t3.Cheque\n  ";
     cin>>mode;
     if((mode>4)||(mode<0))
     cout<<"\n INVALID ENTRY \n ENTER AGAIN...\n";
    }

   switch(choice)
   {
    case 1:
	   strcpy(tname,"Mumbai Express");
	   tno=1234;
	   strcpy(dtime,"00:10");
	   strcpy(date,"13/10/12");
	   fare=3000;
	   break;
    case 2:
	   strcpy(tname,"Delhi Express");
	   tno=1235;
	   strcpy(dtime,"20:10");
	   strcpy(date,"13/12/12");
	   fare=2500;
	   break;
    case 3:
	   strcpy(tname,"Kolkata Express");
	   tno=5678;
	   strcpy(dtime,"10:10");
	   strcpy(date,"12/09/12");
	   fare=2700;
	   break;
    case 4:
	   strcpy(tname,"Chennai Express");
	   tno=5679;
	   strcpy(dtime,"12:10");
	   strcpy(date,"11/08/12");
	   fare=2100;
	   break;

     }
     return 1;
    }
  }

 /*** MEMBER FUNCTION TO DISPLAY BOOKED TICKETS ***/

 void ticket::showticket()
 {

  cout<<"\n\n\t\t\tINDIAN RAILWAYS";
  cout<<"\n\t\t\t---------------";
  cout<<"\n\n\n\tPASSENGER NAME: ";  cout<<pname;
  cout<<"\n\tAGE: "<<age;
  cout<<"\t\tGENDER: "<<gender;
  cout<<"\n\n\tTRAIN NO.: "<<tno;
  cout<<"\t    TRAIN NAME: "; puts(tname);
  cout<<"\n\tCLASS: ";
  if(clas==1) cout<<"SLEEPER";
  else if(clas==2) cout<<"3AC";
  else if(clas==3) cout<<"2AC";
  cout<<"\tFARE: "<<fare;
  cout<<"\tDATE: "<<date;
  cout<<"\n\n\tDEPARTURE: ";
  if(dplace==1) cout<<"MADRAS";
  else if(dplace==2) cout<<"RAIPUR";
  else if(dplace==3) cout<<"HYDERABAD";
  else if(dplace==4) cout<<"INDORE";
  cout<<"\tDEPARTURE TIME: "<<dtime;
  cout<<"\n\n\tPAYMENT BY	: ";
  if(mode==1) cout<<"CASH ";
  else if(mode==2) cout<<"DEBIT CARD";
  else if(mode==3) cout<<"CHEQUE";

 }

/***************************************************************************
****************************** MAIN PROGRAM ********************************
****************************************************************************/


void main()
{
 //Reading existing data from files
 ifstream ifile("acc.dat",ios::in|ios::binary|ios::app);
  while(!ifile.eof())
  {
   j++;
   ifile.read((char*)&a[j],sizeof(a[j]));
  }
 j--;
 ifile.close();
 ifile.open("ticket.dat",ios::in|ios::binary|ios::app);
 while(!ifile.eof())
  {
   i++;
   ifile.read((char*)&t[i],sizeof(t[i]));
  }
 i--;
 clrscr();
 int choice1;
 cout<<"\n\n\n\t\t\t     COMPUTER PROJECT ";
 cout<<"\n\t\t\t     ================ ";
 cout<<"\n\n\t\t\t RAILWAY MANAGEMENT SYSTEM";
 cout<<"\n\t\t\t -------------------------";
 gotoxy(27,14);
 cout<<"-SURAJ P MANIYAR";
 gotoxy(27,15);
 cout<<"  *ROLL NO.20";
 gotoxy(27,17);
 cout<<"-SWAPNESH KUMAR SAHOO";
 gotoxy(27,18);
 cout<<"  *ROLL NO.21";
 gotoxy(27,20);
 cout<<"-CLASS : XII A";

 getch();
 clrscr();
 do
{clrscr();

 /******** WELCOME SCREEN ***********/

 cout<<"\n\n\t\tINDIAN RAILWAYS";
 cout<<"\n\t\t===============";
 cout<<"\n\n\t-> ENTER 1  to  CREATE AN ACCOUNT";
 cout<<"\n\n\t-> ENTER 2  to  LOG IN AND ACCESS YOUR ACCOUNT";
 cout<<"\n\n\t-> ENTER 3  to  DELETE YOUR ACCOUNT";
 cout<<"\n\n\t-> ENTER ANY OTHER NUMBER TO EXIT";
 cout<<"\n\n\t\tEnter your choice... ";
 cin>>choice1;
 int x,y;
 int flag2;

 switch(choice1)
 {
  case 1: //THIS CASE CREATES ACCOUNTS
	  ofstream ofile("acc.dat",ios::binary|ios::app);
	  clrscr();
	  cout<<"\n\t  CREATING ACCOUNT";
	  cout<<"\n\t  ----------------";
	  cout<<"\n\n\tPlease enter account details...";
	  int temp1;
	  cout<<"\n\n\t  ENTER ACCOUNT NUMBER";
	  cout<<"\n\t  (should consist only numbers, max. 5 digits) - ";
	  cin>>temp1;
	  flag2=-1;
	  if(j==-1)
	  {
	   j++;
	  a[j].getacc(temp1);
	  cout<<"\n\tAccount created!";
	  ofile.write((char*)&a[j],sizeof(a[j]));
	  }
	  else
	  {                     //Check for existng accounts
	   for(x=0;x<=j;x++)
	    if(a[x].ano()==temp1)
	    {
	     cout<<"\n\t ACCOUNT ALREADY EXISTS! ";
	     flag2=0;
	     break;
	    }
	    if(flag2==-1)
	    {
	     j=j+1;
	     a[j].getacc(temp1);
	     cout<<"\n\tAccount created!";
	     ofile.write((char*)&a[j],sizeof(a[j]));
	    }
	   }
	  getch();
	  break;

  case 2: //THIS CASE HELPS TO ACCESS ACCOUNT
	  clrscr();
	  int flag=-1;
	  long int tempno;
	  cout<<"\n\n\tENTER ACCOUNT NUMBER: ";
	  cin>>tempno;
	  for(x=0;x<=j;x++)
	   if(a[x].ano()==tempno)
	    {
	     flag=x;
	    }
	   x=flag;

	  if(flag==-1)       //Check if account exists
	   {
	    cout<<"\n\tAccount does not exist!";
	    getch();
	   }

	 else
	 {
	  int choice2;
	  do
	  {
	   clrscr();
	   cout<<"\n\n\t... logged in succesfully!";
	   cout<<"\n\n\t-> ENTER 1  to  UPDATE YOUR ACCOUNT ";
	   cout<<"\n\n\t-> ENTER 2  to  BOOK TICKETS ";
	   cout<<"\n\n\t-> ENTER 3  to  VIEW BOOKED TICKETS";
	   cout<<"\n\n\t-> ENTER 4  to  VIEW ACCOUNT DETAILS";
	   cout<<"\n\n\t-> ENTER ANY OTHER NUMBER TO LOGOUT";
	   cout<<"\n\n\t Enter your choice...";
	   cin>>choice2;
	   switch(choice2)
	   {
	    case 1://THIS CASE HELPS TO UPDATE ACCOUNT
		   clrscr();
		   ofstream file("temp1.dat",ios::binary);
		   int flag3=-1;
		   int temp2;
		   cout<<"\n\n\n\t ENTER (NEW) ACCOUNT NUMBER: ";
		   cin>>temp2;
		   for(y=0;y<=j;y++)
		   if(a[y].ano()==temp2)
		   {
		    cout<<"\n\t ACCOUNT ALREADY EXISTS! ";
		    flag3=0;
		    break;
		   }

		 if(flag3==-1)
		 {
		  for(int k=0;k<=j;k++)
		  {
		   if(t[k].ptr==a[x].ano())
		    t[k].ptr=temp2;
		  }
		  a[x].update(temp2);
		 }

		 for(y=0;y<=j;y++)
		  file.write((char*)&a[y],sizeof(a[y]));
		  file.close();
		 remove("acc.dat");
		 rename("temp1.dat","acc.dat");
		  file.open("temp2.dat",ios::binary);

		 for(y=0;y<=i;y++)
		  file.write((char*)&t[y],sizeof(t[y]));
		  file.close();
		 remove("ticket.dat");
		 rename("temp2.dat","ticket.dat");

		 getch();
		 break;
	   case 2://THIS CASE HELPS TO BOOK TICKETS
		  clrscr();
		  ofstream tfile("ticket.dat",ios::binary|ios::app);
		  i=i+1;
		  if(t[i].getticket()==1)
		  {
		   t[i].ptr=a[x].ano();
		   tfile.write((char*)&t[i],sizeof(t[i]));
		   tfile.close();
		  }
		  break;
	   case 3: //THIS CASE HELPS TO VIEW BOOKED TICKETS
		   clrscr();
		   int flag=-1;
		   for(int y=0;y<=i;y++)
		   {
		    if((t[y].ptr)==(a[x].ano()))
		      {clrscr();
		       t[y].showticket();
		       flag+=2;
		       getch();
		      }
		   }
		   if(flag==-1)
		    {
		     cout<<"\n\n\tNo tickets booked!";
		     getch();
		    }
		  break;
	    case 4://THIS CASE HELPS TO VIEW ACCOUNT DETAILS
		   clrscr();
		   a[x].showacc();
		   getch();
	   }
	  }while(choice2<5);
	 }
	  break;
  case 3: //THIS CASE DELETES SPECIFIED ACCOUNT
	  clrscr();
	  int temp3,w=-2;
	  cout<<"\n\n  ENTER ACCOUNT NUMBER(to be deleted): ";
	  cin>>temp3;
	  ofstream newfile("temp1.dat",ios::binary);
	  for(int y=0;y<=j;y++)
	   {
	    if(temp3!=a[y].ano())
	    newfile.write((char*)&a[y],sizeof(a[y]));
	   }
	    for(y=0;y<=j;y++)
	     if(temp3==a[y].ano())
	      for(w=y;w<=j ;w++)
	       a[w]=a[w+1];
	 newfile.close();
	 remove("acc.dat");
	 rename("temp1.dat","acc.dat");
	 if(w<0)
	 cout<<"\n  Account does not exist! ";
	 else
	  cout<<"\n  ACCOUNT (Account number:"<<temp3<<") IS DELETED... ";
	 newfile.open("temp1.dat",ios::binary);

	 for(int l=0;l<=j;l++)
	 {
	  if(t[l].ptr!=temp3)
	   newfile.write((char*)&t[l],sizeof(t[l]));
	 }
	 for(l=0;l<=j;l++)
	     if(temp3==t[l].ptr)
	      for(w=l;w<=j ;w++)
	       t[w]=t[w+1];
	 newfile.close();

	 remove("ticket.dat");
	 rename("temp1.dat","ticket.dat");
	 getch();
	 break;
  }
 }while(choice1<4);
}




