# TODO
from cs50 import SQL
import sys

db = SQL("sqlite:///students.db")
lis = db.execute("SELECT first,middle,last,birth FROM students WHERE house = ? ORDER BY last, first", sys.argv[1])
#print (lis)
#print(len(lis))

for i in range(len(lis)):
    if(lis[i]['middle'] == None):
        print(lis[i]['first'],lis[i]['last'],end="")
        print(", born",lis[i]['birth'])
    else:
        print(lis[i]['first'],lis[i]['middle'],lis[i]['last'],end="")
        print(", born",lis[i]['birth'])