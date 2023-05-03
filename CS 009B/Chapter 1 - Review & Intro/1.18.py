# TODO: Write recursive draw_triangle() function here.
def draw_triangle(length):
    space = int((19 - length)/2)
    for num in range(space):
        print(' ', end='')
    for num in range(length):
        print('*', end='')
    print("")
    if(length == 1):
        return 
    else: 
        draw_triangle(length - 2)
        

if __name__ == '__main__':
    base_length = int(input())
    draw_triangle(base_length)