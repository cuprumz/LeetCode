#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int M = mat.size();
        int N = mat[0].size();
        vector<vector<int>> ans(M, vector<int>(N, 0));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                int rLower = ((i - K) < 0 ? 0 : (i - K));
                int rUpper = (i + K) >= mat.size() ? (mat.size() - 1) : (i + K);
                int cLower = ((j - K) < 0 ? 0 : (j - K));
                int cUpper = (j + K) >= mat[i].size() ? (mat[i].size() - 1) : (j + K);
                getRangeSum(mat, rLower, rUpper, cLower, cUpper, i, j, ans);
            }
        }
        return ans;
    }

    void getRangeSum(vector<vector<int>> &mat, int rL, int rU, int cL, int cU, int i, int j, vector<vector<int>>& ans) {
        int sum = 0;
        for (int r = rL; r <= rU; r++) {
            for (int c = cL; c <= cU; c++) {
                sum += mat[r][c];
            }
        }
        ans[i][j] += sum;
    }
};

template<typename T>
void printMatrix(vector<vector<T>> &matrix) {
    int i_max = matrix.size();
    int j_max = matrix[0].size();
    for (int i = 0; i < i_max; i++) {
        for (int j = 0; j < j_max; j++) {
            printf("%3d ", matrix[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char **argv) {

    Solution s;

    int n = 3;
    if (argc > 1) {
        n = atoi(argv[1]);
    }

    vector<vector<int>> matrix;
    for (int i = 1; i <= n; i++) {
        vector<int> v;
        for (int j = 1; j <= n; j++) {
            v.push_back((i - 1) * n + j);
        }
        matrix.push_back(v);
    }

    printMatrix(matrix);
    matrix = s.matrixBlockSum(matrix, 2);
    printMatrix(matrix);

    return 0;
}
