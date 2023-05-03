# The words parameter is a list of strings.
def build_dictionary(words):
    # The frequencies dictionary will be built with your code below.
    # Each key is a word string and the corresponding value is an integer 
    # indicating that word's frequency.
    
    ''' Type your code here (remove the "pass" statement below) '''
    mydict = {}
    for word in words:
        if word in mydict:
            value = int(mydict[word])
            value += 1
            mydict[word] = value
        else: 
            mydict[word] = 1
    return mydict

# The following code asks for input, splits the input into a word list, 
# calls build_dictionary(), and displays the contents sorted by key.
if __name__ == '__main__':
    words = input().split()
    your_dictionary = build_dictionary(words)
    sorted_keys = sorted(your_dictionary.keys())
    for key in sorted_keys:
        print(f'{ key } - { str(your_dictionary[key]) }')