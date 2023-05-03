#filename = input()
gdpAverage = 0

with open("GDP.csv", 'r') as f:
    lines = f.readlines()
    numreadings = len(lines) - 1
    for line in lines[1:] :   # note we write line[1:] so we skip header in the file. 
        date , gdp = line.split(",")
        gdpAverage += float(gdp)
    gdpAverage /= numreadings
    print(f'Average GDP: ${gdpAverage} billion')