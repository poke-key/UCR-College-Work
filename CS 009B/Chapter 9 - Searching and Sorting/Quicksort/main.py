# Global variable
num_calls = 0

# TODO: Write the partitioning algorithm - pick the middle element as the 
#       pivot, compare the values using two index variables l and h (low and high), 
#       initialized to the left and right sides of the current elements being sorted,
#       and determine if a swap is necessary
def partition(user_ids, i, k):
    # Pick middle value as pivot
    midpoint = i + (k - i) // 2
    pivot = user_ids[midpoint]
    done = False    
    low = i
    high = k
    while not done:
        while user_ids[low] < pivot:
            low += 1
        while pivot < user_ids[high]:
            high -= 1
        if low >= high:
            done = True
        else:
            temp = user_ids[low]
            user_ids[low] = user_ids[high]
            user_ids[high] = temp
            low += 1
            high -= 1
    return high
    
# TODO: Write the quicksort algorithm that recursively sorts the low and 
#       high partitions. Add 1 to num_calls each time quicksort() is called
def quicksort(user_ids, i, k):
    global num_calls
    num_calls += 1
    
    if i >= k:
       return
   
    j = partition(user_ids, i, k)
    
    quicksort(user_ids, i, j)
    
    quicksort(user_ids, j + 1, k)
    
    return


if __name__ == "__main__":
    user_ids = []
    user_id = input()
    while user_id != "-1":
        user_ids.append(user_id)
        user_id = input()
        
    # Initial call to quicksort 
    quicksort(user_ids, 0, len(user_ids) - 1)
    
    # Print number of calls to quicksort
    print(num_calls)
    
    # Print sorted user ids
    for user_id in user_ids:
        print(user_id)
