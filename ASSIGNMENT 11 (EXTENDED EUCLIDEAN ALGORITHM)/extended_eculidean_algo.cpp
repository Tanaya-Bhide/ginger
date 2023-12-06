#include <iostream>
#include <iomanip>
using namespace std;

int ansS, ansT;

void printHeader() {
    cout << setw(6) << "Step" << setw(6) << "q" << setw(13) << "r1" << setw(13) << "r2"
         << setw(13) << "r" << setw(13) << "s1" << setw(13) << "s2"
         << setw(13) << "s" << setw(13) << "t1" << setw(13) << "t2" << setw(13) << "t" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void printStep(int step, int q, int r1, int r2, int r, int s1, int s2, int s, int t1, int t2, int t) {
    cout << setw(6) << step << setw(6) << q << setw(13) << r1 << setw(13) << r2
         << setw(13) << r << setw(13) << s1 << setw(13) << s2
         << setw(13) << s << setw(13) << t1 << setw(13) << t2 << setw(13) << t << endl;
}

int findGcdExtended(int r1, int r2, int s1, int s2, int t1, int t2, int step) {
    if (r2 == 0) {
        ansS = s1;
        ansT = t1;
        return r1;
    }

    int q = r1 / r2;
    int r = r1 % r2;
    int s = s1 - q * s2;
    int t = t1 - q * t2;

    if (step == 1) {
        printHeader();
    }
    printStep(step, q, r1, r2, r, s1, s2, s, t1, t2, t);

    return findGcdExtended(r2, r, s2, s, t2, t, step + 1);
}

int main() {
    int num1, num2, s, t;
    cout << "Enter the first number  : ";
    cin >> num1;
    cout << "Enter the second number : ";
    cin >> num2;

    int gcd = findGcdExtended(num1, num2, 1, 0, 0, 1, 1);

    cout << "\nFinal Result:" << endl;
    cout << "GCD = " << gcd << endl;
    cout << "S = " << ansS << endl;
    cout << "T = " << ansT << endl;

    return 0;
}
