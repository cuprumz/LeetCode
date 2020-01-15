#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> CountBits(int num);
};


vector<int> Solution::CountBits(int num) {
    vector<int> bits_cnt(num + 1, 0);

    for (int i = 1; i <= num; i++) {
        bits_cnt[i] = 1 + bits_cnt[i & (i - 1)];
    }

    return bits_cnt;
}

template<typename T>
void printVector(vector<T> v) {
    for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main () {

    Solution s;

    vector<int> v = s.CountBits(2);
    printVector(v);

    cout << "------" << endl;
    v = s.CountBits(5);
    printVector(v);


    return 0;
}