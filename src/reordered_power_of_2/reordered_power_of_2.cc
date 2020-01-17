#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int N);
};

long counter(int N) {
    long res = 0;
    for (; N; N /= 10) {
        res += pow(10, N % 10);
    }
    return res;
}

bool Solution::reorderedPowerOf2(int N) {
    long c = counter(N);
    for (int i = 0; i < 32; i++) {
        if (counter(1 << i) == c) {
            return true;
        }
    }
    return false;
}


int main() {
    Solution s;

    cout << s.reorderedPowerOf2(1) << endl;
    cout << s.reorderedPowerOf2(10) << endl;
    cout << s.reorderedPowerOf2(16) << endl;
    cout << s.reorderedPowerOf2(24) << endl;
    cout << s.reorderedPowerOf2(46) << endl;

    return 0;
}
