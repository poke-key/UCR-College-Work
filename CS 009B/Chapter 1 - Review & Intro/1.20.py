''' Type your code here. '''
str_numbers = input()
#print(str_numbers)
lnumbers = str_numbers.split()
numbers = list(map(float, lnumbers))
#print(numbers)

max_num = 0

for num in numbers:
    if (num > max_num):
        max_num = num
#print(max_num)
for num in numbers:    
    print('%.2f' %(num/max_num), end=' ')
print("")