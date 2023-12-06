#include <iostream>
#include <string>
using namespace std;
string encryptCaesarCipher(const string& text, int shift) {
    string encryptedText = "";

    for (char c : text) {
        if (isalpha(c)) {
            char base = (isupper(c)) ? 'A' : 'a';
            encryptedText += static_cast<char>((c - base + shift) % 26 + base);
        } else {
            encryptedText += c;
        }
    }
    return encryptedText;
}
int main() {
    string plaintext;
    int shift;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the shift value: ";
    cin >> shift;

    string encryptedText = encryptCaesarCipher(plaintext, shift);
    cout << "Encrypted text: " << encryptedText << endl;

    return 0;
}
