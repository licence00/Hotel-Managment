import mysql.connector

connection = mysql.connector.connect(
    host='sql6.freesqldatabase.com',
    user='sql6634238',
    password='3ISy8lQSuI',
    database='sql6634238'
)

cursor = connection.cursor()

sql_query = 'select * from food;'
cursor.execute(sql_query)
result = cursor.fetchall()
count = len(result)


food_item = input("Enter Food Item Name : ")
amount_item = int(input("Enter the Amount of "+ str(food_item) +" : "))

sql_query = "INSERT INTO food(sno,food_item,cost) VALUES (%s,%s,%s)"
data_to_insert = (count+1,food_item,amount_item)
cursor.execute(sql_query,data_to_insert)
connection.commit()
print("Item Added Successfully into Database")

