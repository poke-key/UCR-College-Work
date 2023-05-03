# TODO: Write recursive draw_triangle() function here.
def draw_triangle(length):
    if ( length != 1):
        draw_triangle(length - 2)
    print(' ' * int((19-length)/2), end='')
    print('*' * length)
    return
if __name__ == '__main__':
    base_length = int(input())
    draw_triangle(base_length)