#include <bits/stdc++.h>
using namespace std;

// Function for extended Euclidean Algorithm
int S, T;
int extendedGCD(int r1, int r2, int s1, int s2, int t1, int t2){
    // Base Case
    if (r2 == 0){
        S = s1;
        T = t1;
        return r1;
    }

    int q = r1 / r2;
    int r = r1 % r2;
    int s = s1 - q * s2;
    int t = t1 - q * t2;

    cout << q <<"\t" << r1 <<"\t" << r2 <<"\t" << r <<"\t" << s1 <<"\t" << s2 <<"\t" << s <<"\t" << t1 <<"\t" << t2 <<"\t"<< t << endl;
    return extendedGCD(r2, r, s2, s, t2, t);
}


int modInverse(int A, int M){
    int x, y;
    int g = extendedGCD(A, M, 1, 0, 0, 1);
    if (g != 1) {
        cout << "Inverse doesn't exist";
        return 0;
    }
    else {
        int res = (S % M + M) % M;
        cout << "inverse is" << res << endl;
        return res;
    }
}

long long powM(long long a, long long b, long long n){
    if (b == 1){
        return a % n;
    }
    long long x = powM(a, b / 2, n);
    x = (x * x) % n;
    if (b % 2){
        x = (x * a) % n;
    }
    return x;
}

int GCD(int num1, int num2){
    if (num1 == 0){
        return num2;
    }
    return GCD(num2 % num1, num1);
}


int main(){
    long long p, q, e, msg;
    //17 31 7 2

    cout << "Please enter 2 prime number and e and Message to Encrypt" << endl;
    cin >> p >> q >> e >> msg;

    cout << "2 random prime numbers selected are " << p << " " << q << endl;

    // First part of public key:
    long long n = p * q;
    cout << "Product of two prime number n is " << n << endl;

    cout << "Taken e is " << e << endl;

    long long phi = (p - 1) * (q - 1);
    cout << "phi is " << phi << endl;

    while (e < phi) {
        if (GCD(e, phi) == 1)
            break;
        else
            e++;
    }
    cout << "Final e value is " << e << endl;

    // Private key (d stands for decrypt)
    long long d = modInverse(e, phi);
    cout << "d is " << d << endl;

    cout << "\nso now our public key is " << "<" << e << "," << n << ">" << endl;
    cout << "\nso now our private key is " << "<" << d << "," << n << ">" << endl << endl;
    // Message to be encrypted
    cout << "Message date is " << msg << endl;

    // Encryption c = (msg ^ e) % n
    long long c = powM(msg, e, n);
    cout << "Encripted Message is " << c << endl;

    // Decryption m = (c ^ d) % n
    long long m = powM(c, d, n);
    cout << "original Message is " << m << endl;

    return 0;
}