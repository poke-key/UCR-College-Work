# Type your code here. 
filename = input()
str1 = input()
str2 = input()

with open(filename, 'r') as f:
    lines = f.readlines()
for line in lines:
    mline = line.strip()
    if (mline < str1) or (mline > str2):
        print(f'{mline} - not in range')
    else: 
        print(f'{mline} - in range')