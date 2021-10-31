from cs50 import SQL
from sys import argv
import csv

db=SQL("sqlite:///students.db")

if len(argv) != 2:
    print("Usage: python import.py characters.csv")
    exit(0)
    
house=argv[1]
info=db.execute("SELECT first,middle,last,birth FROM students WHERE house=? ORDER BY last,first",house)
for person in info:
    if(person['middle']=="None"):
        print(person['first']+" "+person['last']+", born "+str(person['birth']))
    else:
        print(person['first']+" "+person['middle']+" "+person['last']+", born "+str(person['birth']))