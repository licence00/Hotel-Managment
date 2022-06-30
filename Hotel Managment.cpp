#include<bits/stdc++.h>
#include <time.h> 
using namespace std;
int choice;
int custchoice;
string hotelcode="sidda";
class Room
{
  public:
  int cust_id;
  string Roomowner;
  int age;
  string checkintime;
  int bill;
  int roomtype;
  int roomcharge;
   bool roomstatus;
  Room(int x)
  {
    time_t timetodayonly;
    time(&timetodayonly);
    roomstatus=false;
    checkintime=asctime(localtime(&timetodayonly));
    if(x==1)
    {
        this->roomcharge=20000;
    }
    else if(x==2)
    {
        this->roomcharge=10000; 
    }
    else if(x==3)
    {
        this->roomcharge=5000; 
    }
  }
};
class Hotel
{
  private:
  
  int Hotel_Occupied;
  vector<Room*>hotel;
  unordered_map<string,string>uspass;  
  public:
  Hotel()
  {
    hotel.resize(5,nullptr);
    Hotel_Occupied=0;
    hotelcode="sidda";
  }
  void Userinterface()
  {
    cout<<"-------------------------------------------------------------------------------------\n";
    cout<<"                                Welcome to Hotel                                     \n";
    cout<<"-------------------------------------------------------------------------------------\n";
  }
  void LoginPage()
  {
    time_t timetoday;
    time(&timetoday);
    cout<<"-------------------------------------------------------------"<<asctime(localtime(&timetoday))<<"\n";
    cout<<"                                                                                     \n";
    cout<<"                                                                                     \n";
    cout<<"                                                                                     \n";
    cout<<"---------------------------------LOGIN SCREEN----------------------------------------\n";
    cout<<"-------------------------------------------------------------------------------------\n";
    cout<<"                               1.Customer Login                                      \n";
    cout<<"                               2.Admin Login                                         \n";
    cout<<"                               3.Exit                                                \n";
    
  }
  void cust_page()
  {
    cout<<"------------------------------CUSTOMER LOGIN-----------------------------------------\n";
    cout<<"-------------------------------------------------------------------------------------\n";
    cout<<"                               1.Login                                               \n";
    cout<<"                               2.Signup                                              \n";
  }
  void Signup_cust()
  {
    string username; string password;
    cout<<"                            Enter Username                                          \n";
    cin>>username;
    cout<<"                            Enter New password                                      \n";
    cin>>password;
    uspass[username]=password;
    cout<<"                            Succesfully Registered                                  \n";
  }
  void admin_page()
  {
    cout<<"------------------------------ADMIN LOGIN--------------------------------------------\n";
    cout<<"-------------------------------------------------------------------------------------\n";
    cout<<"                               1.Check Availability                                  \n";
    cout<<"                               2.Get Details                                         \n";
  }
  void Book_room()
  {
    if(Hotel_Occupied<5)
    {
    cout<<"                          Please Choose Roomtype                                   \n";
    cout<<"                          1.Super Luxury                                           \n";
    cout<<"                          2.Luxury                                                 \n";
    cout<<"                          3.Delux                                                  \n";
    int num; cin>>num;
    Room r(num);
    cout<<"                           Please Enter Room ID                                    \n";
    cin>>r.cust_id;
    cout<<"                           Please Enter your Name                                  \n";
    cin>>r.Roomowner;
    cout<<"                           Please Enter your Age                                   \n";
    cin>>r.age;
    
    Room*ptr=&r; 
    hotel[r.cust_id]=ptr; Hotel_Occupied++;
    cout<<"                           Successfully Booked                                    \n";
    
    }
    else
    {
      cout<<"                        Hotel is Completely Occupied                            \n";  
      cout<<"                            Sorry,Visit Again                                   \n";
      return;  
    }
    }
  void login_cust()
  {
    string username; string password;
    cout<<"                            Enter Username                                          \n";
    cin>>username;
    if(uspass.find(username)!=uspass.end())
    {
      cout<<"                            Enter Password                                        \n";
      cin>>password;
      if(uspass[username]==password)
      {
        Book_room();
        cout<<"                                 Thankyou                                            \n";
        cout<<"                         Room was booked Successfully                                \n";
        cout<<"                                                                                     \n";
        cout<<"                                                                                     \n";
        cout<<"                                                                                     \n";
        cout<<"                                                                                     \n";
        if(cin.get()=='\n')
        {
           LoginPage();
        }
   
      }
      else
      {
        cout<<"                            Password Incorrect                                 \n";
        login_cust(); 
      }
    }
    else
    {
      cout<<"                            Please enter a Valid Username                         \n"; 
      login_cust(); 
    }
  }
  void avaliabilty()
  {
    for(int i=0;i<5;i++)
    {
        if(hotel[i]->roomstatus==true)
        {
           cout<<"         Room ID  "<<i<<":            Occupied                                     \n";
        }
        else
        {
           cout<<"         Room ID  "<<i<<":            UnOccupied                                   \n";
        }
    }
  }
  void Display_Customer()
  {  
      cout<<"                           Please Enter Room ID                                    \n";
      int room_id; cin>>room_id;
      Room*ptr=hotel[room_id];
      if(ptr->roomstatus==false)
      {
        cout<<"                          Room is Empty                                        \n";
      }
      else
      {
      cout<<"\t\t\t\tName:"<<"\t\t\t"<<ptr->Roomowner<<"\t\t\t\n";
      cout<<"\t\t\t\tAge:"<<"\t\t\t"<<ptr->age<<"\t\t\t\n";
      cout<<"\t\t\t\tRoom Type:"<<"\t\t\t"<<ptr->roomtype<<"\t\t\t\n";
      cout<<"\t\t\t\tCheckIn Time&Date:"<<"\t\t\t"<<ptr->checkintime<<"\t\t\t\n";
      }
  }
  void GenerateBill()
  {
    cout<<"                           Please Enter Room ID                                    \n";
    int room_id; cin>>room_id;
    Room*ptr=hotel[room_id];
    if(ptr->roomstatus=false)
      {
        cout<<"                  Enter Valid Room ID                                        \n";
      }
      else
      {
        cout<<"\t\t\t\tTotal Bill:"<<"\t\t\t"<<ptr->roomcharge<<"\t\t\t\n";
        cout<<"                 Please Pay above mentioned Amount                          \n";
      }
  }
  void deleteCustomer()
  {
    cout<<"                           Please Enter Room ID                                    \n";
    int room_id; cin>>room_id;
    Room*ptr=hotel[room_id];
    if(ptr->roomstatus=false)
      {
        cout<<"                  Enter Valid Room ID                                        \n";
      }
      else
      {
        ptr->roomstatus=false;
        hotel[room_id]=nullptr;
      }
  }
};


int main()
{
   Hotel l;
   l.Userinterface();
   if(cin.get()=='\n')
   {
     l.LoginPage();
     cout<<"Enter choice:"<<endl; cin>>choice;
     if(choice==1)
     {
       l.cust_page(); 
       cout<<"Enter choice:"<<endl; cin>>custchoice;
       if(custchoice==1)
       {
         l.login_cust();
       }
       else if(custchoice==2)
       {
         l.Signup_cust();
         l.login_cust();
       }

     }
     else if(choice==2)
     {
        cout<<"                    Please Enter Hotel's Administrator Code                          \n";
        string adminchoice; cin>>adminchoice;
        if(adminchoice==hotelcode)
        {
          l.admin_page();
          int adminchoice; cin>>adminchoice;
          if(adminchoice==1)
          {
            l.avaliabilty(); return 0;
          }
          else if(adminchoice==2)
          {
            l.Display_Customer(); return 0;
          }
        }
        else
        {
           cout<<"                    Wrong Code,Please enter Again                                 \n"; 
        }
     }
     else if(choice==3)
     {
       l.GenerateBill();
       cout<<"Please enter Payment Status------------paid/not paid:"<<endl;
       string status; cin>>status;
       if(status=="paid")
       {
         l.deleteCustomer();
         cout<<"Thanks Visit Again"<<endl;
       }
       else
       {
        cout<<"F*ck off"<<endl;
       }
     }
   }
   
}
