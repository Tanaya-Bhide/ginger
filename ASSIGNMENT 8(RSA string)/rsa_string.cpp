#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <random>
using namespace std;
// Function for extended Euclidean Algorithm
int S, T;
int extendedGCD(int r1, int r2, int s1, int s2, int t1, int t2)
{
    // Base Case
    if (r2 == 0)
    {
        S = s1;
        T = t1;
        return r1;
    }

    int q = r1 / r2;
    int r = r1 % r2;
    int s = s1 - q * s2;
    int t = t1 - q * t2;

    cout << q << "\t" << r1 << "\t" << r2 << "\t" << r << "\t" << s1 << "\t" << s2 << "\t" << s << "\t" << t1 << "\t" << t2 << "\t" << t << endl;
    return extendedGCD(r2, r, s2, s, t2, t);
}

int modInverse(int A, int M)
{
    int x, y;
    int g = extendedGCD(A, M, 1, 0, 0, 1);
    if (g != 1)
    {
        cout << "Inverse doesn't exist";
        return 0;
    }
    else
    {
        int res = (S % M + M) % M;
        cout << "inverse is" << res << endl;
        return res;
    }
}

long long powM(long long a, long long b, long long n)
{
    if (b == 1)
    {
        return a % n;
    }
    long long x = powM(a, b / 2, n);
    x = (x * x) % n;
    if (b % 2)
    {
        x = (x * a) % n;
    }
    return x;
}

int GCD(int num1, int num2)
{
    if (num1 == 0)
    {
        return num2;
    }
    return GCD(num2 % num1, num1);
}

// Function to convert text to a numerical representation
vector<int> textToNumbers(const string &str)
{
    vector<int> nums;
    for (char c : str)
    {
        nums.push_back((int)c);
    }
    return nums;
}

// Function to convert numerical representation to text
string numbersToText(const vector<int> &nums)
{
    string str;
    for (int num : nums)
    {
        str.push_back((char)num);
    }
    return str;
}

int main()
{
    long long p, q;
    cout << "Enter two prime numbers (p and q): ";
    cin >> p >> q;
    cout << "2 random prime numbers selected are " << p << " " << q << endl;
    // First part of public key: n = p * q
    long long n = p * q;

    // Finding other part of public key (e stands for encrypt)
    long long e;
    cout << "Enter the public exponent (e): ";
    cin >> e;
    cout << "Taken e is " << e << endl;

    long long phi = (p - 1) * (q - 1);
    cout << "phi is " << phi << endl;

    while (e < phi)
    {
        if (GCD(e, phi) == 1)
            break;
        else
            e++;
    }
    cout << "Final e value is " << e << endl;

    // Private key (d stands for decrypt)
    long long d = modInverse(e, (p - 1) * (q - 1));

    // Display public and private keys
    cout << "\nso now our public key is <" << e << "," << n << ">" << endl;
    cout << "\nso now our private key is <" << d << "," << n << ">" << endl;

    // Message to be encrypted
    string message;
    cout << "Enter the message to encrypt: ";
    cin.ignore(); // Ignore any previous newline character
    getline(cin, message);

    // Convert message to numbers
    vector<int> nums = textToNumbers(message);

    // Encrypt the message
    vector<int> encryptedMessage;
    for (int num : nums)
    {
        long long c = powM(num, e, n);
        encryptedMessage.push_back((int)c);
    }

    cout << "Encrypted Message: ";
    for (int num : encryptedMessage)
    {
        cout << num << " ";
    }
    cout << endl;

    // Decrypt the message
    vector<int> decryptedNums;
    for (int num : encryptedMessage)
    {
        long long m = powM(num, d, n);
        decryptedNums.push_back((char)m);
    }

    string decryptedMessage = numbersToText(decryptedNums);
    cout << "Decrypted Message is : " << decryptedMessage << endl;

    return 0;
}