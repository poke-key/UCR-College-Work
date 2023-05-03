import random

retries = 0

def unique_random_ints(how_many, max_num):
    """Return a list of how_many unique randomly generated numbers from
    0 to max_num (inclusive) using seed to initialize the random module"""
    # Type your code here. #
    global retries
    listrand = []
    for i in range(how_many):
        rand = random.randint(0, max_num)
        while (rand in listrand):
            rand = random.randint(0, max_num)
            retries += 1
        listrand.append(rand)
    return listrand
    
if __name__ == '__main__':
    seed = int(input())
    how_many = int(input())
    max_num = int(input())
    # Type your code here. #
    random.seed(seed)
    listrand = unique_random_ints(how_many, max_num)
    #print(f'{listrand} retries={retries}')
    #gets rid of the brackets and commas in the list, end= allows no new line to form and print all on one line.
    print(*listrand, sep=' ', end=' ') 
    print(f'retries={retries}')
    