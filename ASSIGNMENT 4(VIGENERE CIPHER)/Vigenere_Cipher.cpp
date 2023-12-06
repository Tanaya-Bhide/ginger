#include <iostream>
#include <string>

using namespace std;

string generateKey(const string& str, const string& key) {
    int x = str.size();
    string modifiedKey = key;

    for (int i = 0; ; i++) {
        if (x == i)
            i = 0;
        if (modifiedKey.size() == str.size())
            break;
        modifiedKey.push_back(modifiedKey[i]);
    }
    return modifiedKey;
}

string cipherText(const string& str, const string& key) {
    string cipher_text;

    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) {
            char x = (toupper(str[i]) + toupper(key[i])) % 26;
            x += 'A';
            cipher_text.push_back(x);
        } else {
            cipher_text.push_back(str[i]);
        }
    }
    return cipher_text;
}

string originalText(const string& cipher_text, const string& key) {
    string orig_text;

    for (int i = 0; i < cipher_text.size(); i++) {
        if (isalpha(cipher_text[i])) {
            char x = (toupper(cipher_text[i]) - toupper(key[i]) + 26) % 26;
            x += 'A';
            orig_text.push_back(x);
        } else {
            orig_text.push_back(cipher_text[i]);
        }
    }
    return orig_text;
}

int main() {
    string str, keyword;

    cout << "Enter the plaintext: ";
    getline(cin, str);

    cout << "Enter the keyword: ";
    getline(cin, keyword);

    string key = generateKey(str, keyword);
    string cipher_text = cipherText(str, key);

    cout << "Ciphertext: " << cipher_text << "\n";

    string decrypted_text = originalText(cipher_text, key);
    cout << "Original/Decrypted Text: " << decrypted_text << "\n";

    return 0;
}
