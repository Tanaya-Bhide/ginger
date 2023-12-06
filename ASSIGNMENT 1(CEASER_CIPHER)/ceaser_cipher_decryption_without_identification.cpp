#include <iostream>
#include <string>

using namespace std;

string decryptShiftCipher(const string& ciphertext, int shift) {
    string decryptedText = "";

    for (char c : ciphertext) {
        if (isalpha(c)) {
            bool isUpper = isupper(c);
            c = tolower(c);
            char decryptedChar = ((c - 'a' - shift + 26) % 26) + 'a';
            if (isUpper) {
                decryptedChar = toupper(decryptedChar);
            }
            decryptedText += decryptedChar;
        } else {
            decryptedText += c;
        }
    }

    return decryptedText;
}

int main() {
    string ciphertext = " M eq xerece erh y evi ? ";

    for (int shift = 0; shift < 26; ++shift) {
        string decryptedText = decryptShiftCipher(ciphertext, shift);
        cout << "Shift " << shift << ": " << decryptedText << endl;
    }

    return 0;
}