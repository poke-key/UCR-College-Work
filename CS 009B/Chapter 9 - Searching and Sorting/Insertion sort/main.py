comparisons = 0
swaps = 0 
def read_nums():
    """Read numbers from input and return them in a list"""
    return [int(num) for num in input().split()]

def print_nums(nums):
    """Output numbers, separating each item by a spaces;
    no space or newline before the first number or after the last."""
    print(' '.join([str(n) for n in nums]), end='')

def swap(nums, n, m):
    """Exchange nums[n] and nums[m]"""
    nums[n], nums[m] = nums[m], nums[n]

def insertion_sort(numbers):
    """Sort the list numbers using insertion sort"""
    # TODO: Count comparisons and swaps. Output the array at the end of each iteration.
    global comparisons
    global swaps
    for i in range(1, len(numbers)):
        j = i
        # Insert numbers[i] into sorted part
        # stopping once numbers[i] is in correct position
        while j > 0: 
            comparisons += 1
            if numbers[j] < numbers[j - 1]: 
                swap(numbers, j, j - 1)
                swaps += 1
                j -= 1
            else:
                break
        print(*numbers)
if __name__ == '__main__':
    # Step 1: Read numbers into a list
    numbers = read_nums()

    # Step 2: Output the numbers list
    print_nums(numbers);
    print(end='\n\n')

    # Step 3: Sort the numbers list
    insertion_sort(numbers)
    print()
    
    # Step 4: TODO: Output the number of comparisons and swaps performed
    print(f'comparisons: {comparisons}')
    print(f'swaps: {swaps}')