# Type your code here.
filename = input()

with open(filename, 'r') as photo:
  contents = photo.readlines()
  for jpg in contents:
    line = jpg.strip()
    text = line.split('_')
    newstr = text[0] + '_info.txt'
    print(newstr)