#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

string const key = "HACK";
map<int, int> keyMap;

void setPermutationOrder() {
    for (int i = 0; i < key.length(); i++) {
        keyMap[key[i]] = i;
    }
}

string encryptMessage(string msg) {
    int row, col, j;
    string cipher = "";
    col = key.length();
    row = msg.length() / col;

    if (msg.length() % col)
        row += 1;

    char matrix[row][col];

    for (int i = 0, k = 0; i < row; i++) {
        for (int j = 0; j < col;) {
            if (k >= msg.length()) {
                matrix[i][j] = '_';
                j++;
            }

            if (isalnum(msg[k]) || msg[k] == ' ' || msg[k] == '_' || ispunct(msg[k])) {
                matrix[i][j] = msg[k];
                j++;
            }
            k++;
        }
    }

    for (map<int, int>::iterator ii = keyMap.begin(); ii != keyMap.end(); ++ii) {
        j = ii->second;
        for (int i = 0; i < row; i++) {
            if (isalnum(matrix[i][j]) || matrix[i][j] == ' ' || matrix[i][j] == '_' || ispunct(matrix[i][j]))
                cipher += matrix[i][j];
        }
    }

    return cipher;
}

string decryptMessage(string cipher) {
    int col = key.length();
    int row = cipher.length() / col;
    char cipherMat[row][col];

    for (int j = 0, k = 0; j < col; j++)
        for (int i = 0; i < row; i++)
            cipherMat[i][j] = cipher[k++];

    int index = 0;
    for (map<int, int>::iterator ii = keyMap.begin(); ii != keyMap.end(); ++ii)
        ii->second = index++;

    char decCipher[row][col];
    map<int, int>::iterator ii = keyMap.begin();
    int k = 0;

    for (int l = 0, j; key[l] != '\0'; k++) {
        j = keyMap[key[l++]];
        for (int i = 0; i < row; i++) {
            decCipher[i][k] = cipherMat[i][j];
        }
    }

    string msg = "";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (decCipher[i][j] != '_') {
                msg += decCipher[i][j];
            } else {
                break;   
            }
        }
    }

    return msg;
}

int main(void) {
    string msg;
    cout << "Enter a message to encrypt: ";
    getline(cin, msg);

    setPermutationOrder();

    string cipher = encryptMessage(msg);
    cout << "Encrypted Message: " << cipher << endl;

    string decryptedMsg = decryptMessage(cipher);
    cout << "Decrypted Message: " << decryptedMsg << endl;

    return 0;
}
