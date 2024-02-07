//
// Created by Сергей on 07.02.2024.
//
#include <iostream>
using namespace std;

void MatrixTranspone_ref(int (&a)[3][3], int (&b)[3][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            b[i][j] = a[j][i];
        }
    }
}

void MatrixTranspone_point(int* a, int* b){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            b[j * 3 + i] = a[i * 3 + j];
        }
    }
}