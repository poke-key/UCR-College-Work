# TODO: Write recursive print_num_pattern() function
def print_num_pattern(num1, num2):
    if num1 < 0:
        print(num1, end=' ')
        return
    print(num1, end=' ')
    print_num_pattern(num1 - num2, num2)
    print(num1, end=' ')
    
if __name__ == "__main__":
    num1 = int(input())
    num2 = int(input())
    print_num_pattern(num1, num2)