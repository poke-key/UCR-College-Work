''' Type your code here. '''
str_sentence1 = input()
str_sentence2 = input()

sentence1 = str_sentence1.split()
sentence2 = str_sentence2.split()

for i in range(len(sentence1)):
    if (sentence1[i] != sentence2[i]):
        print(sentence1[i], sentence2[i])
#print(str_sentence1, str_sentence2)
#print(sentence1, sentence2) 