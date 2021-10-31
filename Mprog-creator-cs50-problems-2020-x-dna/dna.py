from sys import argv
import csv
import re
if len(argv) != 3:
    print('Usage: python dna.py data.csv sequence.txt')

# data.csv
with open(argv[1], "r") as file:
    Dreader = list(csv.DictReader(file))

with open(argv[1], "r") as file:
    Header = list(csv.reader(file))[0]
    # Ignore the first element from the header
    Header = Header[1:]
# sequence.txt
with open(argv[2], "r") as Input:
    Itext = Input.read()
    Count = {}
for column in Header:
    temp=''
    occurences = re.findall(f"(?:{column})+", Itext)
    for word in occurences:
        if len(word)>len(temp):
            temp=word
    Count[column] = temp.count(column)
for person in Dreader:
    name = person["name"]
    del person["name"]
    if all(Count[gene] == int(amount) for gene, amount in person.items()):
        print(name)
        exit()
print('No Match')