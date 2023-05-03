# TODO: Write recursive fibonacci() function
def fibonacci(num):
    if num == 0: 
        return 0
    if num == 1 or num == 2:
        return 1
    if num < 0:
        return -1
    else:
        return (fibonacci(num - 1) + fibonacci(num-2))
if __name__ == "__main__":
    start_num = int(input())
    print(f'fibonacci({start_num}) is {fibonacci(start_num)}')