#include<bits/stdc++.h>
using namespace std;



cout<<"\nEnter customer Checkin Date: ";
START:
cout<<"\n----------------------------------";
cout<<"\nYear: ":
cin>>check_inyear;
cout<<"\nMonth: ";
cin>>check_inmonth; 
cout<<"\nDate";
cin>>check_indate:
cout<<"\nEnter Room Type: ";
cin>>roomtype;
cout<<"\nEnter Room Charge: ";
cin>>room charge; 
if((check_inmonth==2) && (check_indate>29))
{
  cout<<"wrong input!!!\n";
  cout<<<<"\nenter the date again....\n"; 
  goto START;
}

if((check_inmonth>12)||(check_indate>31))
{
  cout<<"wrong input!!!\n"; 
  cout<<"\nenter the date again....\n";
  goto START;
}

if((check_inmonth==4||check_inmonth==6||check_inmonth=-9||check_inmonth==11) && (check_indate>30))
{
  cout<<"wrong input!!!\n";
  cout<<"\nenter the date again....\n";
  goto START;
}

if((check_inyear%4)!=0 && (check_inmonth==2) && (check_indate>28)) 
{
  cout<<"wrong input!!!\n"; 
  cout<<"\nenter the date again....\n";
  goto START:
}

//We had use the validation in the adminstration login while entering the wrong user name & password it show the popup menu,

cout<<"\t\t\User Name = ";
cin>>username:
if(strcmp(username, "admin")==0)
{
  string pass="";
  char ch;
  cout<<"\n\t\t\t\tPassword = ";
  ch= getch();
  while(ch!= 13)
  {
    pass.push_back(ch):
    cout <<'*';
    ch= getch();
  }
  if(pass=="admin")
  {
    cout<<"\n\t\t"<<"Access granted";
    do{}
  }

}


//WELCOME SCREEN
void customer::welcomescreen()
{
    system("cls");
  cout<<endl<<endl<<endl<< endl; 
  cout<<"                COMPUTERISED MANAGEMENT SYSTEM"<<endl;
  cout<<"                APIIT SD INDIA, PANIPAT "<< endl;
  cout<<"                INDIVIDUAL ASSINGMENT "<<endl;
  cout<<"              ON                    "<<endl;
  cout<<"             Further Programming Concepts in C++ "<<endl;
  cout<<"            (CE00314-2)                        "<<endl;
  cout<<"                         
  _______________________________________________________________"<<endl;
 cout<<endl<<endl<<endl<< endl;
 cout<<"                  SUBMITTED BY:         SUBMITTED TO:
 "<<endl;
 cout<<"                 Rudra laxmi kanth and sidhart"<<endl;
 cout<<"                 CS20B066               CS20b059"<<endl;
 cout<<endl<<endl;
 cout<<"                  Press Enter to continue...."<<endl<<endl<<endl<<endl;
 getch();
}

//LOGIN SCREEN
void customer::login_screen()
{
  time_t t;
  system("cls");
  t=time(NULL); 
  cout<<"\n                                  "<<ctime(&t);
  customer c
  t-=24L*60L*60L;
  char choice;
  cout<<endl<<endl<<endl<<endl;
  cout<<"                                LOGIN SCREEN\n";
  cout<<"
  ________________________________________________________________________"<<endl;
  cout<<"               1.Administrator Login\n";
  cout<<"               2.customer Login\n"; 
  cout<<"               3.Exit\n";
  cout<<"\n\n\n";
  cout<<"Enter Choice:: ":
  cin>>choice;
  switch(choice)
  {
   case'1':
          system("cls");
          c.main_screen(); break;

   case'2':
          search_customer();
          break;

   case'3':
          exit(0); 
          break;
   default:
          cout<<"wrong choice entered";
  }
}
//ADD CUSTOMER

void customer::add_customer()
{

    customer c;
    ofstream outf
  outf.open("customer.txt",ios::outlios::applios::binary);
  c.getdata();
  outf.write((char*)&c,sizeof(c));
  outf.close();
  _getch();
}
//SEARCH CUSTOMER

void customer::search_customer()
{

   fstream file:
  customer c:
  int i=1;
  char nam[25];
  file.open("customer.txt",ios::in);
       cout<<"\t\t\t\t customer Detail \n"; 
  cout<<"\t\t\t____________________________________\n\n";
  cout<<"\n Enter name to Search: ":
  cin>>nam;
  file.seekg(0,ios::beg);
  while(file.read((char *) &c, sizeof(customer)))
  {
      if(c.compare(nam))
      {

          cout<<"\t\t\t\t custm id"<<"        "<<e.custm_id<<"custm_name \n"<<endl;
          cout<<"            "<<c.custm_id<<"                    "<<c.custm_name;
          cout<<"\n\t\t\t_______________________________________________";
          cout<<"\n\t\t\t ...Thank you for using ^_^ ...";
          i=0; break;
      }
  }
  file.close():
  if(i)
  {
    cout<<"Sorry!!!Record Not found";
  }
  getch()
}


//DELETE CUSTOMER

void customer::delete_customer()
{
   fstream file;
   fstream temp:
   temp.open("tempdata.txt" ios::out);
   customer c;
   int i=1;
   char nam[25];
   file.open("customer.txt",ios::in);
   cout<<"\t\t\t\t All customer Detail \n";
   cout<<"\t\t\t\t\n Enter name to Search: ";
   cin>>nam;
   file.seekg(0,ios::beg);
   while(file.read((char *) &c, sizeof(customer)))
   {
    if(!e.compare(nam))
    {
    cout<<"\t\t\t\t custm id"<<"          "<<"custum_name\n<<endl;"
    cout<<"                  "<<c.custm_id<<" "<<c.custm_name; 
    i=0;
    temp.write((char *)&c,sizeof(customer));
    }
   }
   file.close():
   temp.close(); remove("customer.txt");
   rename("tempfile.txt","customer.txt");
   getch(); 
}
//CHECKOUT CUSTOMER
   void customer::checkout customer()
   {
    system("cls"); 
    cout<<"\n"<<endl;
    cout<<"\n\t\t\t\t HOTEL MANAGEMENT SYSTEM "<<<endl; dl;
    cout<<"\t\t\t\t All customer Detail\n";
   }

//ROOM DETAIL

{
    system("cls");
    cout<<"\n\t\t\t\tHOTEL MANAGEMENT SYSTEM "<<endl;
    cout<<"\t\t\t\t All customer Detail \n";
    cout<<left<<setw(10)<<"roomtype"<<<<left<<setw(15)<<"room_charge"<<endl;
}

//Generate Bill

#include"customer.h"

class Generatebill:public customer
{
  public:
  int rcharge; 
  char custm_name[25];
  char b:

public:
   void calculate()
   {
    system("els");
    cout<<"\n Enter Room type:";
    cout<<"\n Select 1 for Super Luxary \n Select 2 for Luxary In Select 3 for Delux \n";
    cin>>b; 
    if(b=1)
    {
         r charge=4000;
    }
    else if(b=2)
    {
       r charge=3000;
    }
    else if(b=3)
    {
        r_charge=2000;
    }
    else{
    cout<<"\nWrong choice...";
    cout<<"\n ERROR: Room is not allocated.";
    cout<<"\n Bill cannot be created";
    }
    cout<<"n Enter the bill amount of restaurant:";
    cin>>food;
    cout<<"\n Enter other charges:";
    cin>>oc;
    cout<<"\n Enter customer name:";
    cin>>custm_name;
    cout<<"\n Enter number of days:";
    cin>>r_day;
    room=r_charger_day: t=(int) room + food + oc;
    ser=(int)(0.05*t);
    total=t+ser;
    }


  void display bill()
  {
  system("CLS");
  cout<<"\n";
  cout<<"\n Customer name: "<<custm_name; 
  cout<<"\n Stayed for"<<r_day<<"days";

  cout<<"\n Room charges :"<<r_charge<<"(Per day)"; 
  cout<<"\n Room charges:"<<room<<<"(total)";
  cout<<"\n Restaurant bill: "<<food;
  cout<<"\n Other charges :"<<<oc:

  cout<<"\n Ser.tax = 5%";
  cout<<"\n Bill Amount >>>>>> Rs "<<total;
  cout<<"\n THANK YOU !!!!!";
  cout<<"\n Visit Again !";

 }
};

void customer::generate_bill()
{
    Generatebill b;
    b.calculate();
    b.display_bill();
}

int main()
{
    
}
