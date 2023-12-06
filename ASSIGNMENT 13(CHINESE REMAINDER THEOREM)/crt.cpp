#include <iostream>
#include <vector>

int extendedGCD(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extendedGCD(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int gcd = extendedGCD(a, m, x, y);
    if (gcd != 1) {
        std::cerr << "\nModular inverse does not exist.\n";
        return -1; // Error case
    } else {
        return (x % m + m) % m;
    }
}

long long chineseRemainderTheorem(const std::vector<int>& num, const std::vector<int>& rem) {
    long long product = 1;
    long long result = 0;

    for (int n : num)
        product *= n;

    for (size_t i = 0; i < num.size(); ++i) {
        long long pp = product / num[i];
        long long inv = modInverse(pp, num[i]);
        if (inv == -1) {
            std::cerr << "No solution due to non-coprime moduli.\n";
            return -1; // No solution
        }
        result = (result + (long long)rem[i] * pp * inv) % product;
    }

    return result;
}

int main() {
    int numOfEquations;
    std::cout << "Enter the number of equations: ";
    std::cin >> numOfEquations;

    std::vector<int> num, rem;

    for (int i = 0; i < numOfEquations; ++i) {
        int n, r;
        std::cout << "\nEnter the modulus for equation " << i + 1 << ": ";
        std::cin >> n;
        std::cout << "\nEnter the remainder for equation " << i + 1 << ": ";
        std::cin >> r;
        num.push_back(n);
        rem.push_back(r);
    }

    std::cout << "\nEquations entered:\n";
    for (int i = 0; i < numOfEquations; ++i) {
        std::cout << "x = " << rem[i] << " (mod " << num[i] << ")\n";
    }

    bool coprime = true;
    for (size_t i = 0; i < num.size(); ++i) {
        for (size_t j = i + 1; j < num.size(); ++j) {
            int temp1, temp2; // Create variables to pass to extendedGCD
            if (extendedGCD(num[i], num[j], temp1, temp2) != 1) {
                coprime = false;
                break;
            }
        }
    }

    if (!coprime) {
        std::cerr << "No solution due to non-coprime moduli.\n";
        return 1;
    }

    int result = chineseRemainderTheorem(num, rem);

    if (result != -1) {
        std::cout << "\nThe solution for the system of congruences is: " << result << std::endl;
    }

    return 0;
}
