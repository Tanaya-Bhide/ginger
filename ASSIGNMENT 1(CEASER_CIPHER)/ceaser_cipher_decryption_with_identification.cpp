#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;
set<string> loadCommonWords(const string &filename)
{
    set<string> commonWords;
    ifstream file(filename);
    string word;
    while (file >> word)
    {
        commonWords.insert(word);
    }

    return commonWords;
}

bool containsMoreThanHalfValidWords(const string &text, const set<string> &commonWords)
{
    istringstream iss(text);
    string word;
    int validWordCount = 0;
    int totalWordCount = 0;

    while (iss >> word)
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        if (commonWords.count(word) > 0)
        {
            validWordCount++;
        }
        totalWordCount++;
    }

    return (validWordCount * 2 > totalWordCount);
}

string decryptShiftCipher(const string &ciphertext, int shift)
{
    string decryptedText = "";

    for (char c : ciphertext)
    {
        if (isalpha(c))
        {
            bool isUpper = isupper(c);
            c = tolower(c);
            char decryptedChar = ((c - 'a' + shift + 26) % 26) + 'a';
            if (isUpper)
            {
                decryptedChar = toupper(decryptedChar);
            }
            decryptedText += decryptedChar;
        }
        else
        {
            decryptedText += c;
        }
    }
    return decryptedText;
}

int main()
{   
    string ciphertext = " M eq xerece erh y evi ? ";
   // string ciphertext = "Bfqhmfsi Htqqjlj Tk Jslnsjjwnsl";
    string commonWordsFilename = "common_english_words.txt";
    set<string> commonWords = loadCommonWords(commonWordsFilename);

    for (int shift = 0; shift < 26; ++shift)
    {
        string decryptedText = decryptShiftCipher(ciphertext, shift);

        if (containsMoreThanHalfValidWords(decryptedText, commonWords))
        {
            cout << "Shift " << 26 - shift << ": " << decryptedText << endl;
        }
    }

    return 0;
}
