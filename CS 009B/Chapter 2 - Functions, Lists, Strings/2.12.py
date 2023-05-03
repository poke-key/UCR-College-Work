# Define your function here
def jiffies_to_seconds(user_jiffies):
    return (user_jiffies / 100)
    
if __name__ == '__main__':
    # Type your code here. Your code must call the function.
    #user_jiffies = input()
    #seconds = jiffies_to_seconds(float(input()))
    print(f'{jiffies_to_seconds(float(input())):.3f}')