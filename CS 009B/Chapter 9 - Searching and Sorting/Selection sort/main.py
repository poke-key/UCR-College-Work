# Type your code here.
str_num = input().split()

numbers = [int(num) for num in str_num]

for i in range(len(numbers) - 1):
   # Find index of smallest remaining element
    index_largest = i
    for j in range(i + 1, len(numbers)):
        if numbers[j] > numbers[index_largest]:
            index_largest = j
   # Swap numbers[i] and numbers[index_largest]
    temp = numbers[i]
    numbers[i] = numbers[index_largest]
    numbers[index_largest] = temp
    print(numbers)

