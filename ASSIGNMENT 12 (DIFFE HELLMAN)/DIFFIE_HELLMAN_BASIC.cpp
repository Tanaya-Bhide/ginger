#include <iostream>
#include <map>
using namespace std;

// Function to calculate modular exponentiation (a^b % n)
long long powM(long long a, long long b, long long n) {
    if (b == 1)
        return a % n;
    long long x = powM(a, b / 2, n);
    x = (x * x) % n;
    if (b % 2)
        x = (x * a) % n;
    return x;
}

// Function to check if alpha is a primitive root of q
bool checkPrimitiveRoot(long long alpha, long long q) {
    map<long long, int> m;
    for (long long i = 1; i < q; i++) {
        long long x = powM(alpha, i, q);
        if (m.find(x) != m.end())
            return false;  // If there's a repeated value, alpha is not a primitive root
        m[x] = 1;
    }
    return true; // If no repeated values found, alpha is a primitive root
}

int main() {
    long long q, alpha, xa, xb;

    // Input the prime number q
    cout << "Enter a prime number (q): ";
    cin >> q;

    // Input the primitive root alpha
    cout << "Enter a primitive root of q (alpha): ";
    cin >> alpha;

    // Check if alpha is a primitive root of q
    if (!checkPrimitiveRoot(alpha, q)) {
        cout << "alpha is not a primitive root of q";
        return 0;
    } else {
        cout << alpha << " is a primitive root of " << q << endl;
    }

    // Input Alice's private key (xa)
    cout << "Enter Alice's private key (xa): ";
    cin >> xa;

    // Calculate Alice's public key (ya)
    long long ya = powM(alpha, xa, q);
    cout << "Private key of Alice is " << xa << endl;
    cout << "Public key of Alice is " << ya << endl << endl;

    // Input Bob's private key (xb)
    cout << "Enter Bob's private key (xb): ";
    cin >> xb;

    // Calculate Bob's public key (yb)
    long long yb = powM(alpha, xb, q);
    cout << "Private key of Bob is " << xb << endl;
    cout << "Public key of Bob is " << yb << endl << endl;

    // Generate the shared secret key for both Alice and Bob
    long long k1 = powM(yb, xa, q); // Secret key for Alice
    long long k2 = powM(ya, xb, q); // Secret key for Bob

    // Output the generated shared secret keys
    cout << "Generated key by Alice is " << k1 << endl;
    cout << "Generated key by Bob is " << k2 << endl << endl;

    return 0;
}
