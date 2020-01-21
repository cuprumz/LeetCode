#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2);
};

vector<int> Solution::intersect(vector<int> &nums1, vector<int> &nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> solution;
    int index = 0;
    bool finished = false;
    for (int i = 0; i < nums1.size() && !finished; i++) {
        while (index < nums2.size() && nums1[i] > nums2[index]) index++;
        if (index == nums2.size()) finished = true;
        else if (nums1[i] == nums2[index]) {
            solution.push_back(nums1[i]);
            index++;
        }
    }
    return solution;
}

template<typename T>
void printVector(vector<T> &v) {
    for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char **argv) {

    Solution s;
    vector<int> nums1(4,2), nums2(2, 2);
    nums1[0] = 1;
    nums1[3] = 1;

    vector<int> res = s.intersect(nums1, nums2);
    printVector(res);

    nums1.resize(3);
    nums2.resize(5);
    nums1[0] = 4;
    nums1[1] = 9;
    nums1[2] = 5;
    nums2[0] = 9;
    nums2[1] = 4;
    nums2[2] = 9;
    nums2[3] = 8;
    nums2[4] = 4;
    res = s.intersect(nums1, nums2);
    printVector(res);

    return 0;
}
