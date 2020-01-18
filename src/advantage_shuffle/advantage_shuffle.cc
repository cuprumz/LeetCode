#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int> &A, vector<int> &B);
};

vector<int> Solution::advantageCount(vector<int> &A, vector<int> &B) {
    multiset<int> s(begin(A), end(A));
    for (auto i = 0; i < B.size(); i++) {
        auto p = s.upper_bound(B[i]);
        if (p == s.end()) p = s.begin();
        A[i] = *p;
        s.erase(p);
    }
    return A;
}

template<typename T>
void printVector(vector<T> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char **argv) {

    Solution s;
    vector<int> A(0), B(0);
    A.push_back(2);
    A.push_back(7);
    A.push_back(11);
    A.push_back(15);
    B.push_back(1);
    B.push_back(10);
    B.push_back(4);
    B.push_back(11);

    printVector(A);
    s.advantageCount(A, B);
    printVector(A);

    cout << endl;

    vector<int> C(0), D(0);
    C.push_back(12);
    C.push_back(24);
    C.push_back(8);
    C.push_back(32);
    D.push_back(13);
    D.push_back(25);
    D.push_back(32);
    D.push_back(11);
    printVector(C);
    s.advantageCount(C, D);
    printVector(C);

    return 0;
}
