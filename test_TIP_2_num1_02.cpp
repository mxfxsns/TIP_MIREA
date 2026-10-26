#include <iostream>

using namespace std;


long long fast_pow_iterative(long long a, long long n) {
    long long result = 1;
    while (n > 0) {
        if (n % 2 != 0) {
            result *= a;
        }
        a *= a;
        n /= 2; 
    }
    return result;
}

int main() {
    long long a, n;
    if (cin >> a >> n) {
        cout << fast_pow_iterative(a, n) << endl;
    }
    return 0;
}