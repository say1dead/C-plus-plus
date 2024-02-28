//
// Created by Сергей on 28.02.2024.
//

#ifndef C_PLUS_PLUS_LAB_4_APP_H
#define C_PLUS_PLUS_LAB_4_APP_H

#include <iostream>
#include <vector>


#include <iostream>
#include <vector>
#include "Parallelogram.h"
#include "Ellipse.h"
#include "Shape.h"
using namespace std;

class ShapeContainer {
private:
    vector<Shape*> shapes;

public:
    void addShape(Shape* shape);

    double totalArea() ;

    double totalPerimeter() ;

    void printShapesInfo() ;

    double totalMass() ;

    double totalMemory() ;

    void sortAndPrintByMass();

};

int App();


#endif //C_PLUS_PLUS_LAB_4_APP_H
