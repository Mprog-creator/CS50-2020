from cs50 import SQL
from sys import argv
import csv


if len(argv) != 2:
    print("Usage: python import.py characters.csv")
    exit(0)

db=SQL("sqlite:///students.db")
with open(argv[1], "r") as file:
    Dreader = list(csv.DictReader(file))
    for person in Dreader:
        names=person["name"].split()
        if(len(names)==3):
          db.execute("INSERT INTO students (first,middle,last,house,birth) VALUES (?,?,?,?,?)",names[0],names[1],names[2],person['house'],person['birth'])
        elif(len(names)==2):
          db.execute("INSERT INTO students (first,middle,last,house,birth) VALUES (?,?,?,?,?)",names[0],'None',names[1],person['house'],person['birth'])
        