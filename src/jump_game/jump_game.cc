#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums);
};


bool Solution::canJump(vector<int> &nums) {
    int reach = 0, len = nums.size();
    for (int i = 0; i < len && i <= reach; i++) {
        reach = max(i + nums[i], reach);
    }
    return reach > len;
}

int main(int argc, char **argv) {

    Solution s;

    vector<int> v1{2, 3, 1, 1, 4};
    cout << "v1: " << s.canJump(v1);


    return 0;
}
