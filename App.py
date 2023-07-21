import os
import time
import random
import mysql.connector

connection = mysql.connector.connect(
    host='sql6.freesqldatabase.com',
    user='sql6634238',
    password='3ISy8lQSuI',
    database='sql6634238'
)

cursor = connection.cursor()


def clear_terminal():
    # Clear the terminal screen based on the operating system
    if os.name == "posix":  # For Unix/Linux/MacOS
        os.system("clear")
    elif os.name == "nt":   # For Windows
        os.system("cls")
    else:
        # If the operating system is not recognized, print a message
        print("Unable to clear terminal. Unsupported operating system.")

class customer:
    def __init__(self,name,age,sex,address,room):
        self.name = name
        self.age = age
        self.sex = sex
        self.address = address
        self.room_number = room

class Room:
    amount = 0
    def __init__(self,number,customer):
        self.room_number = number
        self.customer_name = customer
        self.amount = 0

class Hotel:
    total_rooms = 100
    assigned_rooms = 0    

    def welcome(self):
        print("                                                               ")
        print("                                                               ")
        print("+++++++++++++++++    Welcome to the Hotel     +++++++++++++++++")
        print("                                                               ")
        print("                                                               ")
        time.sleep(2)
        clear_terminal()
        self.select_member()

    def __init__(self):
        self.welcome()

    def select_member(self):
        print("                                                               ")
        print("                  Choose The Option                            ")
        print("                     1.Customer                                ")
        print("                     2.Staff                                   ")
        print("                                                               ")
        option = int(input("Enter the option : "))
        if option == 1:
            clear_terminal()
            self.customer_login()
        elif option ==2 :
            clear_terminal()
            self.staff_login()
        else:
            print("Enter a valid Option")
            clear_terminal()
            self.select_member()

    def staff_login(self):
        username = str(input("Enter the Username : "))
        password = str(input("Enter the Password : "))
        if(username == 'admin' and password == 'admin'):
            self.display_staff_options()
        else:
            print("Password Incorrect")
            time.sleep(1)
            clear_terminal()
            self.select_member()
    
    def display_staff_options(self):
        print("                                                               ")
        print("                  Choose The Option                            ")
        print("                     1.Generate Bill                           ")
        print("                     2.Customer Details                        ")
        print("                                                               ")
        option = int(input("Enter the option : "))
        if option == 1:
            clear_terminal()
            self.generate_bill()
        elif option ==2 :
            clear_terminal()
            self.customer_details()
        else:
            print("Enter a valid Option")
            clear_terminal()
            self.display_staff_options()
    
    def generate_bill(self):
        room_number = input("Enter the Room Number : ")
        sql_query = 'select * from rent where room_number = %s'
        cursor.execute(sql_query,(room_number,))
        result = cursor.fetchall()
        customer_name = result[0][1]
        amount_to_pay = result[0][2]
        sql_query = 'select * from customer where name = %s'
        cursor.execute(sql_query,(customer_name,))
        result = cursor.fetchall()
        print('Room Number : '+ str(room_number))
        print('\n\n')
        print('Customer Details : ')
        print('Name : '+ result[0][0])
        print("Age : " + str(result[0][1]))
        print('Sex : ' + result[0][2])
        print('Address : ' + result[0][3])
        print('\n\n')
        print('Total Amount to pay : '+ str(amount_to_pay))
        print('\n\n')
        print('Thank you visit again')
        time.sleep(5)
        clear_terminal()
    
    def customer_details(self):
        sql_query = 'select room_number,customer from rent;'
        cursor.execute(sql_query)
        result = cursor.fetchall()
        for row in result:
            print('Room Number : '+str(row[0])+"       Customer Name : "+str(row[1]))
        time.sleep(4)
        clear_terminal()
        self.display_staff_options()

    def customer_login(self):
        print("                                                               ")
        print("                  Choose The Option                            ")
        print("                     1.Login                                   ")
        print("                     2.SignUp                                  ")
        print("                                                               ")
        option = int(input("Enter the option : "))
        if option == 1:
            clear_terminal()
            self.login_customer()
        elif option ==2 :
            clear_terminal()
            self.new_login_customer()
        else:
            print("Enter a valid Option")
            clear_terminal()
            self.customer_login()

    def new_login_customer(self):
        customer_name = str(input("Enter the Name : "))
        sql_query = "select name from customer"
        cursor.excute(sql_query)
        for row in cursor.fetchall():
            if row[0] == customer_name:
                print("Username is already in use. Try a different one ! ")
                time.sleep(1)
                clear_terminal()
                self.new_login_customer()
        customer_age = str(input("Enter the Age : "))
        customer_sex = str(input("Enter the sex : "))
        customer_address = str(input("Enter the Address : "))
        self.sai = customer(customer_name,customer_age,customer_sex,customer_address,-1)
        password = str(input("Create a New Password : "))
        sql_query = "INSERT INTO customer (name,age,sex,address,password) VALUES (%s,%s,%s,%s,%s)"
        data_to_insert = (customer_name,customer_age,customer_sex,customer_address,password)
        cursor.execute(sql_query,data_to_insert)
        connection.commit()
        clear_terminal()
        self.login_customer()


    def login_customer(self):
        username = str(input("Enter the Username : "))
        password = str(input("Enter the Password : "))
        sql_query = "select * from customer where name = %s"
        cursor.execute(sql_query,(username,))
        result = cursor.fetchall()
        if len(result) == 0:
            print("Username Incorrect")
            time.sleep(1)
            clear_terminal()
            self.customer_login()
        else:
            if password == result[0][4]:
                clear_terminal()
                print("Welcome ",result[0][0])
                self.show_options(result[0][0])
            else:
                print("Password Incorrect")
                time.sleep(1)
                clear_terminal()
                self.customer_login()
    
    def show_options(self,username):
        print("Hi "+str(username)+" ! great to have you here")
        print("                                                               ")
        print("                  Choose The Option                            ")
        print("                     1.Book Room                               ")
        print("                     2.Order Food                              ")
        print("                                                               ")
        option = int(input("Enter the option : "))
        if option == 1:
            clear_terminal()
            self.book_room(username)
        elif option ==2 :
            clear_terminal()
            self.order_food(username)
        else:
            print("Enter a valid Option")
            clear_terminal()
            self.show_options(username)

    def book_room(self,username):
        if(self.total_rooms < self.assigned_rooms):
            print("No Rooms are available")
            print("Thanks for the Visit")
            clear_terminal()
            self.welcome()
        else:
            self.assigned_rooms = self.assigned_rooms + 1
            room_set = set(range(1,101))
            sql_query = "select room_number from rent;"
            cursor.execute(sql_query)
            result = cursor.fetchall()
            for row in result:
                room_set.discard(row[0])
            room_number = random.choice(list(room_set))
            sql_query = "INSERT INTO rent (room_number,customer,amount) VALUES (%s,%s,%s)"
            data_to_insert = (room_number,username,0)
            cursor.execute(sql_query,data_to_insert)
            connection.commit() 
            print("Room Assigned to you is "+str(room_number))
            print("Enjoy the Stay in the Hotel")
            time.sleep(2)
            clear_terminal()
            self.welcome()

    def order_food(self,username):
        print("Order the Food from the List")
        sql_query = "select * from food;"
        cursor.execute(sql_query)
        result = cursor.fetchall()
        for row in result:
            print(row[0],end='    ')
            print(row[1],end='        ')
            print(row[2],end='\n')
        print("Enter the Items Numbers with spaces in between")
        food = str(input("Enter the List of Items : "))
        food_items = food.split(' ')
        sql_query = 'select cost from food;'
        cursor.execute(sql_query)
        result = cursor.fetchall()
        total_food_cost = 0
        for i in range(len(food_items)):
            total_food_cost = total_food_cost + int(result[int(food_items[i])-1][0])
        print("Total Cost for the Food is " + str(total_food_cost))
        sql_query = "select room_number from rent where customer = %s"
        cursor.execute(sql_query,(username,))
        result = cursor.fetchall()
        room_number = result[0][0]
        sql_query = 'UPDATE rent SET amount = %s where room_number = %s'
        data_to_insert = (total_food_cost,room_number)
        cursor.execute(sql_query,data_to_insert)
        connection.commit()

def main():
    h = Hotel()

if __name__ == "__main__":
    main()