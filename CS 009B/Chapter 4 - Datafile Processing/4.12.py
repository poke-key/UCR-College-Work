import csv
# TODO: Declare any necessary variables here. 
m1_total = 0
m2_total = 0
final_total = 0
numstudents = 0

      
# TODO: Read a file name from the user and read the tsv file here. 
fileName = input()
with open(fileName, 'r') as csvfile:
    with open('report.txt', 'w') as outfile:
        csvreader = csv.reader(csvfile, delimiter='\t')
        for line in csvreader:
            m1_total += int(line[2])
            m2_total += int(line[3])
            final_total += int(line[4])
            numstudents += 1
            #A: 90 =< x B: 80 =< x < 90 C: 70 =< x < 80 D: 60 =< x < 70 F: x < 60
            finalgrade = (int(line[2]) + int(line[3]) + int(line[4]))/3
            if (finalgrade >= 90):
                lettergrade = 'A'
            if (finalgrade < 90) and (finalgrade >= 80):
                lettergrade = 'B'
            if (finalgrade < 80) and (finalgrade >= 70):
                lettergrade = 'C'
            if (finalgrade < 70) and (finalgrade >= 60):
                lettergrade = 'D'
            if (finalgrade < 60):
                lettergrade = 'F'
            outfile.write(f'{line[0]}\t{line[1]}\t{line[2]}\t{line[3]}\t{line[4]}\t{lettergrade}')
            outfile.write('\n')
        outfile.write('\n')
        outfile.write(f'Averages: midterm1 {m1_total/numstudents:.2f}, midterm2 {m2_total/numstudents:.2f}, final {final_total/numstudents:.2f}')
        outfile.write('\n')
# TODO: Compute student grades and exam averages, then output results to a text file here. 
            