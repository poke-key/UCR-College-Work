def calc_average(nums):
    # Type your code here.
    return float(sum(nums)/len(nums))
if __name__ == '__main__':
    nums = [1, 2, 3, 4, 5]
    print(calc_average(nums))   # calc_average() should return 3.0