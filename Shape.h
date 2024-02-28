//
// Created by kochu on 21.02.2024.
//

#ifndef LAB_PROGA_4_CORRECT_SHAPE_H
#define LAB_PROGA_4_CORRECT_SHAPE_H

class Shape{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void draw() const = 0;
    virtual double mass() const = 0;
    virtual ~Shape() {};
};
#endif //LAB_PROGA_4_CORRECT_SHAPE_H
