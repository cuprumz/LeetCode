#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings);
};

int Solution::candy(vector<int> &ratings) {
    int size_ = ratings.size();
    vector<int> candy_cnt(size_);
    candy_cnt[0] = 1;
    for (int i = 1; i < size_; i++) {
        candy_cnt[i] = ratings[i] > ratings[i - 1] ? candy_cnt[i - 1] + 1 : 1;
    }

    int total_candy = candy_cnt[size_ - 1];
    for (int i = size_ - 2; i >= 0; i--) {
        candy_cnt[i] = (ratings[i] > ratings[i + 1] && candy_cnt[i + 1] + 1 > candy_cnt[i]) ? candy_cnt[i + 1] + 1 : candy_cnt[i];
        total_candy += candy_cnt[i];
    }

    return total_candy;
}

void generateRatings(vector<int> &ratings, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        ratings.push_back(rand() % 10);
    }
}

void printVector(vector<int> &v) {
    int size_ = v.size();
    for (int i = 0; i < size_; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main(int argc, char** argv) {

    int n = 10;
    if (argc > 1) {
        n = atoi(argv[1]);
    }
    vector<int> ratings;
    generateRatings(ratings, n);
    printVector(ratings);

    Solution s;
    cout << s.candy(ratings) << endl;

    cout << "--------------------" << endl;
    int r[] = { 5, 6, 7, 4, 1, 2, 3, 2, 1, 7 };
    vector<int> ra(r, r+sizeof(r)/sizeof(r[0]));
    printVector(ra);
    cout << s.candy(ra) << endl;

    cout << "--------------------" << endl;
    int r1[] = { 1, 0, 2 };
    vector<int> ra1(r1, r1+sizeof(r1)/sizeof(r1[0]));
    printVector(ra1);
    cout << s.candy(ra1) << endl;


    return 0;
}
