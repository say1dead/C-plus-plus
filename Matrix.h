//
// Created by kochu on 15.02.2024.
//

#ifndef LAB_PROGA_3_MATRIX_H
#define LAB_PROGA_3_MATRIX_H

#include <iostream>
#include <utility>
#include <vector>
#include <iomanip>
using namespace std;

class Matrix{
private:
    vector<vector<float>> data;
public:
    Matrix();

    Matrix(vector<vector<float>> m);

    Matrix operator+(Matrix& other);

    Matrix operator-(Matrix& other);

    Matrix operator*(Matrix& other);

    Matrix operator*(float scalar);

    bool operator==(const Matrix& other);

    bool operator!=(const Matrix& other);

    bool operator>(Matrix& other);

    bool operator<(Matrix& other);

    void Show(Matrix& other);
};

void StartMatrix();
#endif //LAB_PROGA_3_MATRIX_H
