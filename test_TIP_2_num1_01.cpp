#include <iostream>

using namespace std;

long long fast_pow(long long base, long long exp) {
    if (exp == 0) return 1;

    if (exp % 2 == 0) {
        long long half = fast_pow(base, exp / 2);
        return half * half;
    } 
   
    else {
        return base * fast_pow(base, exp - 1);
    }
}

int main() {
    long long x, y;
    if (cin >> x >> y) {
        cout << fast_pow(x, y) << endl;
    }
    return 0;
}


