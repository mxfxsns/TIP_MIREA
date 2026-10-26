#include <iostream>

using namespace std;

long long gcd_recursive(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd_recursive(b, a % b);
}
 
int main() {
    long long a, b;
    if (cin >> a >> b) {
        cout << gcd_recursive(a, b) << endl;
    }
    return 0;
}