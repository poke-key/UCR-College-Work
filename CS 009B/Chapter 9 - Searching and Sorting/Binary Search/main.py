# TODO: Declare global variables here.
recursions = 0
comparisons = 0
def binary_search(nums, target, lower, upper):
    global recursions, comparisons
    recursions += 1
    
    index = (lower + upper)//2 #floor division is used to get an int instead of a float.
    comparisons += 1
    if target == nums[index]:
        return index
    
    if lower == upper:
        return -1

    comparisons += 1
    if nums[index] < target:
        return binary_search(nums, target, index + 1, upper)
    if nums[index] > target:
        return binary_search(nums, target, 0, index - 1)
if __name__ == '__main__':
    # Input a list of nums from the first line of input
    nums = [int(n) for n in input().split()]
    
    # Input a target value
    target = int(input())

    # Start off with default values: full range of list indices
    index = binary_search(nums, target, 0, len(nums) - 1)

    # Output the index where target was found in nums, and the
    # number of recursions and comparisons performed
    print(f'index: {index}, recursions: {recursions}, comparisons: {comparisons}')
