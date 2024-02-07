//
// Created by Сергей on 07.02.2024.
//
#include <iostream>
#include "main.h"
using namespace std;

void CompNumber_ref(StructCompNumber& a, float& b){
    a.Real = a.Real * b;
    a.Imagine = a.Imagine * b;
}

void CompNumber_point(StructCompNumber* a, float* b){
    a->Real = a->Real * (*b);
    a->Imagine = a->Imagine * (*b);
}