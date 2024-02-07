//
// Created by Сергей on 07.02.2024.
//
#include <iostream>
#include <math.h>
using namespace std;

void RoundFloat_ref(float& a){
    a = round(a);
}

void RoundFloat_point(float* a){
    *a = round(*a);
}