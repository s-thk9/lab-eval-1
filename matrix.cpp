#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> readMatrix(int n);
int calculateDeterminant(const vector<vector<int>>& matrix);
vector<vector<int>> getMinor(const vector<vector<int>>& matrix, int row, int col);
int calculateDeterminantRec(const vector<vector<int>>& matrix, int n);


vector<vector<int>> readMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the elements of the " << n << "x" << n << " matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

int calculateDeterminant(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    return calculateDeterminantRec(matrix, n);
}

vector<vector<int>> getMinor(const vector<vector<int>>& matrix, int row, int col) {
    int n = matrix.size();
    vector<vector<int>> minor(n - 1, vector<int>(n - 1));
    int r = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        if (i == row) continue;
        c = 0;
        for (int j = 0; j < n; ++j) {
            if (j == col) continue;
            minor[r][c++] = matrix[i][j];
        }
        ++r;
    }
    return minor;
}

int calculateDeterminantRec(const vector<vector<int>>& matrix, int n) {
    int determinant = 0;
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    for (int j = 0; j < n; ++j) {
        vector<vector<int>> minor = getMinor(matrix, 0, j);
        int cofactor = (j % 2 == 0 ? 1 : -1) * matrix[0][j] * calculateDeterminantRec(minor, n - 1);
        determinant += cofactor;
    }
    return determinant;
}

int main() {
    int n;

    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Matrix size must be a positive integer." << endl;
        return 1;
    }

    vector<vector<int>> matrix = readMatrix(n);
    int determinant = calculateDeterminant(matrix);

    cout << "The determinant of the matrix is: " << determinant << endl;

    return 0;
}

