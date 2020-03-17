#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k);
};

int Solution::subarraySum(vector<int> &nums, int k) {
    int count = 0;
    map<int, int> rec;
    int cumulated = 0;
    rec[0]++;
    for (int & num : nums) {
        cumulated += num;
        count += rec[cumulated - k];
        rec[cumulated]++;
    }
    return count;
}

int main(int argc, char **argv) {

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    Solution s;
    int res = s.subarraySum(v, 3);
    printf("%d", res);


    return 0;
}
