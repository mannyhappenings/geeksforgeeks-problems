#include<iostream>

using namespace std;

bool is_odd(long n) {
    return n % 2 == 1;
}

long pow(long a, long n) {
    if (n == 0) {
        return 1;
    }

    long p = pow(a, n / 2);
    
    cout << "pow(" << a << ", " << n/2 << ") = " << p << endl;

    return is_odd(n) ? (a * p * p) : (p * p);
}

void test_pow(long a, long n) {
    cout << "--------------------" << endl;
    long p = pow(a, n);
    cout << "pow(" << a << ", " << n << ") = " << p << endl;
}

int main() {
    test_pow(5, 2);
    test_pow(4, 3);
    test_pow(2, 5);
    test_pow(2, 20);
    test_pow(2, 60);

    return 0;
}