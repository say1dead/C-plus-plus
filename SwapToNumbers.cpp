//
// Created by Сергей on 07.02.2024.
//
#include <iostream>
using namespace std;

void SwapToNumbers_ref(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void SwapToNumbers_point(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}