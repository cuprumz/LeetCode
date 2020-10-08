#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d);
};

int main(int argc, char **argv) {
    Solution s;

    vector<int> arr1 = {4, 5, 8},
            arr2 = {10, 9, 1, 8};
    int d = 2;
    cout << s.findTheDistanceValue(arr1, arr2, d) << endl;

    arr1 = {1, 4, 2, 3};
    arr2 = {-4, -3, 6, 10, 20, 30};
    d = 3;
    cout << s.findTheDistanceValue(arr1, arr2, d) << endl;

    arr1 = {2, 1, 100, 3};
    arr2 = {-5, -2, 10, -3, 7};
    d = 6;
    cout << s.findTheDistanceValue(arr1, arr2, d) << endl;

    return 0;
}

int Solution::findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
    sort(begin(arr2), end(arr2));
    int ans = 0;
    for (int n : arr1) {
        if (upper_bound(begin(arr2), end(arr2), n + d) == lower_bound(begin(arr2), end(arr2), n - d))
            ++ans;
    }
    return ans;
}