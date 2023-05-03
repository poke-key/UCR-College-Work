# Define your function here.
def days_in_feb(user_year):
    if (user_year % 400 == 0):
        return 29
        #print(f'{user_year} has 29 days in February')
    else:
        if (user_year % 100 == 0):
            return 28
        else:
            if (user_year % 4 == 0):
                return 29 
            else:
                return 28   
                
if __name__ == '__main__':
    # Type your code here. Your code must call the function.
   user_year = int(input())
   days = days_in_feb(user_year)
   print("%d has %d days in February." %(user_year, days))
   #print(f'{user_year} has {days} days in February.')