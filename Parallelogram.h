//
// Created by kochu on 21.02.2024.
//
#ifndef LAB_PROGA_4_CORRECT_PARALLELOGRAM_H
#define LAB_PROGA_4_CORRECT_PARALLELOGRAM_H

#include <iostream>
#include <cmath>
#include "Shape.h"
using namespace std;

class Parallelogram : public Shape{
private:
    double base;
    double height;
    double angle;
public:
    Parallelogram(double b, double h, double a)
            : base(b), height(h), angle(a) {}

    double area() const override;

    double perimeter() const override;

    double mass() const override;

    void draw() const override;
};

int StartParallelogram();
#endif //LAB_PROGA_4_CORRECT_PARALLELOGRAM_H
