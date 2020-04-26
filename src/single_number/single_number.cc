#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums);
};

int Solution::singleNumber(vector<int> &nums) {
    int res = 0;
    for (auto it = nums.begin(); it != nums.end(); it++) {
        res ^= *it;
    }
    return res;
}


int main(int argc, char **argv) {

    Solution s;

    vector<int> ex1 = {2, 2, 1};

    cout << s.singleNumber(ex1) << endl;

    vector<int> ex2 = {4, 1, 2, 1, 2};

    cout << s.singleNumber(ex2) << endl;


    return 0;
}
