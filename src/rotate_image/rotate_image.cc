#include <iostream>
#include <vector>


using namespace std;

template<typename T>
void rotate(vector<vector<T>> &matrix) {
    int n = matrix.size();

    for (int i = 0; i < n / 2; i++) {
        int low = i, high = n - i - 1;
        for (int j = low; j < high; j++) {
            T tmp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = tmp;
        }
    }
}

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
    rotate(matrix);
    printMatrix(matrix);


    return 0;
}