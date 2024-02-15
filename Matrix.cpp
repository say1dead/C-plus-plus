//
// Created by kochu on 15.02.2024.
//
#include <iostream>
#include <utility>
#include <vector>
#include <iomanip>
using namespace std;

class Matrix{
private:
    vector<vector<float>> data;
public:
    Matrix(){
        data.resize(3, vector<float>(3, 0));
    }

    Matrix(vector<vector<float>> m){
        data = std::move(m);
    }

    Matrix operator+(Matrix& other){
        Matrix result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(Matrix& other){
        Matrix result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(Matrix& other){
        Matrix result;
        float sum = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {

                for (int k = 0; k < 3; k++) {
                    sum += data[i][k] * other.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }
        return result;
    }

    Matrix operator*(float scalar){
        Matrix result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    bool operator==(Matrix& other) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(Matrix& other) {
        return !(*this == other);
    }

    bool operator>(Matrix& other){
        float sum1 = 0, sum2 = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                sum1 += data[i][j] * data[i][j];
                sum2 += other.data[i][j] * other.data[i][j];
            }
        }
        return sum1 > sum2;
    }

    bool operator<(Matrix& other){
        float sum1 = 0, sum2 = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                sum1 += data[i][j] * data[i][j];
                sum2 += other.data[i][j] * other.data[i][j];
            }
        }
        return sum1 < sum2;
    }

    void Show(Matrix& other){
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << setw(4) << other.data[i][j];
            }
            cout << "\n";
        }
    }
};

void StartMatrix(){
    vector<vector<float>> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<float>> m2 = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    float scalar = 2.0;

    Matrix matrix1(m1);
    Matrix matrix2(m2);
    Matrix matrix3 = matrix1 + matrix2;
    Matrix matrix4 = matrix1 - matrix2;
    Matrix matrix5 = matrix1 * matrix2;
    Matrix matrix6 = matrix1 * scalar;

    cout << "Matrix 1:" << "\n";
    matrix6.Show(matrix1);
    cout << "\n";

    cout << "Matrix 2:" << "\n";
    matrix6.Show(matrix2);
    cout << "\n";

    cout << "Matrix 1 + Matrix 2:" << "\n";
    matrix6.Show(matrix3);
    cout << "\n";

    cout << "Matrix 1 - Matrix 2:" << "\n";
    matrix6.Show(matrix4);
    cout << "\n";

    cout << "Matrix 1 * Matrix 2:" << "\n";
    matrix6.Show(matrix5);
    cout << "\n";

    cout << "Matrix 1 * scalar" << ":" << "\n";
    matrix6.Show(matrix6);
    cout << "\n";

    cout << "Matrix 1 == Matrix 2: " << (matrix1 == matrix2 ? "True" : "False") << "\n";
    cout << "Matrix 1 > Matrix 2: " << (matrix1 > matrix2 ? "True" : "False") << "\n";
    cout << "Matrix 1 < Matrix 2: " << (matrix1 < matrix2 ? "True" : "False") << "\n";

}