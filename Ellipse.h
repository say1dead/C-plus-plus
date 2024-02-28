//
// Created by kochu on 21.02.2024.
//

#ifndef LAB_PROGA_4_CORRECT_ELLIPSE_H
#define LAB_PROGA_4_CORRECT_ELLIPSE_H


#include <iostream>
#include <cmath>
#include "Shape.h"
using namespace std;

class Ellipse : public Shape{
private:
    double r_a;
    double r_b;
public:
    Ellipse(double a, double b)
            : r_a(a), r_b(b) {}

    double area() const override;

    double perimeter() const override;

    double mass() const override;

    void draw() const override;
};

int StartEllipse();
#endif //LAB_PROGA_4_CORRECT_ELLIPSE_H
