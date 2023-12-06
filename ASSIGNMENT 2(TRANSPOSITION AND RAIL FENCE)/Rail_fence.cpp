#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

string encryptRailFence(string text, int key)
{
    char railMatrix[key][text.length()];

    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < text.length(); j++)
        {
            railMatrix[i][j] = '\n';
        }
    }

    bool moveDown = false;
    int row = 0, col = 0;

    for (int i = 0; i < text.length(); i++)
    {
        if (row == 0 || row == key - 1)
        {
            moveDown = !moveDown;
        }

        railMatrix[row][col++] = text[i];
        moveDown ? row++ : row--;
    }

    string result;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < text.length(); j++)
        {
            if (railMatrix[i][j] != '\n')
            {
                result.push_back(railMatrix[i][j]);
            }
        }
    }

    return result;
}

string decryptRailFence(string cipher, int key)
{
    char railMatrix[key][cipher.length()];

    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < cipher.length(); j++)
        {
            railMatrix[i][j] = '\n';
        }
    }

    bool moveDown;
    int row = 0, col = 0;

    for (int i = 0; i < cipher.length(); i++)
    {
        if (row == 0)
        {
            moveDown = true;
        }
        if (row == key - 1)
        {
            moveDown = false;
        }

        railMatrix[row][col++] = '*';
        moveDown ? row++ : row--;
    }

    int index = 0;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < cipher.length(); j++)
        {
            if (railMatrix[i][j] == '*' && index < cipher.length())
            {
                railMatrix[i][j] = cipher[index++];
            }
        }
    }

    string result;

    row = 0, col = 0;
    for (int i = 0; i < cipher.length(); i++)
    {
        if (row == 0)
        {
            moveDown = true;
        }
        if (row == key - 1)
        {
            moveDown = false;
        }

        if (railMatrix[row][col] != '*')
        {
            result.push_back(railMatrix[row][col++]);
        }

        moveDown ? row++ : row--;
    }

    return result;
}

int main()
{
    string plaintext;
    int key;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the key: ";
    cin >> key;

    string ciphertext = encryptRailFence(plaintext, key);
    cout << "Encrypted: " << ciphertext << endl;

    string decryptedText = decryptRailFence(ciphertext, key);
    cout << "Decrypted: " << decryptedText << endl;

    return 0;
}
