# Type your code here
fileName = input()
file = open(fileName)
contents = file.readlines()  
for line in contents:
    nline = line.strip() #used to get rid of the \n at the end of the line
    items = nline.split("\t")
    if(items[3] == "Available"):
        print(f'{items[1]} ({items[0]}) -- {items[2]}')
file.close()  
