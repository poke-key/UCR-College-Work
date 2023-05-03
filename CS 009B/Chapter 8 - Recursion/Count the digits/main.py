# TODO: Write recursive digit_count() function here.
def digit_count(num):
    count = 1
    if(num < 10):
        return count
    else:
        return(count + digit_count(num/10)) 

if __name__ == '__main__':
    num = int(input())
    digit = digit_count(num)
    print(digit)