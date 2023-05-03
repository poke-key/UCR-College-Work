def print_all_permutations(permList, names):
    # TODO: Implement method to create and output all permutations of the list of names.
    if len(names) == 1:
        print(", ".join(permList + [names[0]]))
    else:
        for i in range(len(names)):
            print_all_permutations(permList + [names[i]], names[:i] + names[i+1:])
            
if __name__ == "__main__": 
    nameList = input().split(' ')
    permList = []
    #print(nameList)
    print_all_permutations(permList, nameList)
    #print(permList)