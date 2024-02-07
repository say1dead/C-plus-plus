//
// Created by Сергей on 07.02.2024.
//

#ifndef LAB_PLUS_1_MAIN_H
#define LAB_PLUS_1_MAIN_H

#include <iostream>
using namespace std;

void SwapToNumbers_ref(int& a, int& b);
void SwapToNumbers_point(int* a, int* b);

void RoundFloat_ref(float& a);
void RoundFloat_point(float* a);

struct StructCompNumber{
    float Real;
    float Imagine;
};

void CompNumber_ref(StructCompNumber& , float& );
void CompNumber_point(StructCompNumber* a, float* b);

void MatrixTranspone_ref(int (&a)[3][3], int (&b)[3][3]);
void MatrixTranspone_point(int* a, int* b);
#endif //LAB_PLUS_1_MAIN_H
