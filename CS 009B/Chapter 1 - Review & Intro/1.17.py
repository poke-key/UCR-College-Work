def max_magnitude(user_val1, user_val2, user_val3):
    if(abs(user_val1) > abs(user_val2)):
        if(abs(user_val1) > abs(user_val3)):
            return user_val1
        else:
            return user_val3
    else: 
        if(abs(user_val2) > abs(user_val3)):
            return user_val2
        else:
            return user_val3
if __name__ == '__main__':
    print(max_magnitude(int(input()), int(input()), int(input())))
