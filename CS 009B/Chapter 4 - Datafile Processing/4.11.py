import csv

# Type your code here. 
filename = input()
my_dict = {}
with open(filename, 'r') as csvfile:
    csvstuff = csv.reader(csvfile) 
    for line in csvstuff: 
        for word in line:
            if word in my_dict:
                num = my_dict[word]
                num += 1
                my_dict[word] = num
            else: 
                my_dict[word] = 1
for x in my_dict: 
    print(f'{x} - {my_dict[x]}')
        