import nltk
nltk.download('words')

from nltk.corpus import words
word_list = words.words()

with open('common_english_words.txt', 'w') as f:
    f.write('\n'.join(word_list))
