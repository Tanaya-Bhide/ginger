#include <iostream>

int gcd(int a, int b) {
    // Base case: If the second number is 0, GCD is the first number
    if (b == 0)
        return a;
    // Recursively call gcd with b and the remainder of a divided by b
    return gcd(b, a % b);
}
int main() {
    int num1, num2;

    std::cout << "\nEnter first number  : ";
    std::cin >> num1;

    std::cout << "\nEnter second number : ";
    std::cin >> num2;

    int result = gcd(num1, num2);
    std::cout << "\nGCD of " << num1 << " and " << num2 << " is: " << result << std::endl<<std::endl;

    return 0;
}
