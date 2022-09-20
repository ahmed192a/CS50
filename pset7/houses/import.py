# TODO
from cs50 import SQL
import csv
import sys

db = SQL("sqlite:///students.db")

#db.execute("CREATE TABLE students (first TEXT,middle TEXT,last TEXT, house TEXT, birth NUMERIC)")
#while(sys.argc != 2):
#    exit(1)


with open(f"{sys.argv[1]}","r") as file:
    read = csv.DictReader(file)

    for row in read:
        name = row ["name"]
        name = name.split( )
        house = row ["house"]
        birth = row ["birth"]
        #print(len(name))
        if(len(name) == 2):
            first = name[0]
            middle = None
            last = name[1]
        elif(len(name) == 3):
            first = name[0]
            middle = name[1]
            last = name[2]

        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?,?,?,?,?)",first,middle,last,house,birth)




