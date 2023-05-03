''' Type your code here. '''
def minimum(numberList):
    minimum = int(numberList[0])
    #print(minimum) 
    min1 = min([int(num) for num in numberList])
    min2 = min([int(num) for num in numberList if int(num) != min1])
    return min1, min2
    
if __name__ == '__main__':
    str_numbers = input()
    numberList = str_numbers.split()
    num = minimum(numberList)
    print(f'{num[0]} and {num[1]}')
         