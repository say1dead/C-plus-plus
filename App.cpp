#include <iostream>
#include <vector>
#include <algorithm>
#include "Parallelogram.h"
#include "Ellipse.h"
#include "Shape.h"
using namespace std;

class ShapeContainer {
private:
    vector<Shape*> shapes;

public:
    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }

    double totalArea() {
        double total = 0.0;
        for (auto& shape : shapes) {
            total += shape->area();
        }
        return total;
    }

    double totalPerimeter() {
        double total = 0.0;
        for (auto& shape : shapes) {
            total += shape->perimeter();
        }
        return total;
    }

    void printShapesInfo() {
        for (auto& shape : shapes) {
            shape->draw();
        }
    }

    double totalMass() {
        double total = 0.0;
        for (auto& shape : shapes) {
            total += shape->mass();
        }
        return total;
    }

    double totalMemory() {
        double total = 0;
        for (auto& shape : shapes){
            total += shapes.size() * sizeof(ShapeContainer);
        }
        return total;
    }

    void sortAndPrintByMass() {
        sort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b) {
            return a->mass() < b->mass();
        });

        cout << "Sorted shapes by mass:" << endl;
        for (auto& shape : shapes) {
            cout << "Mass: " << shape->mass() << ", ";
            shape->draw(); // Вывод информации о фигуре
        }
    }

};

int App() {
    ShapeContainer container;

    char choice;

    do {
        double b, h, a;
        cout << "Enter the base, height and angle of the parallelogram separated by spaces: ";
        cin >> b >> h >> a;
        Parallelogram* newParallelogram = new Parallelogram(b, h, a);
        container.addShape(newParallelogram);

        cout << "Add another? (y/n): ";
        cin >> choice;
    } while (choice == 'y');
    cout << '\n';


    do {
        double a, b;
        cout << "Enter the half-axis_a and half-axis_b of the ellipse separated by spaces: ";
        cin >> a >> b;
        Ellipse* newEllipse = new Ellipse(a, b);
        container.addShape(newEllipse);

        cout << "Add another? (y/n): ";
        cin >> choice;
    } while (choice == 'y');
    cout << '\n';

    cout << "Total area of all shapes: " << container.totalArea() << endl;
    cout << "Total perimeter of all shapes: " << container.totalPerimeter() << endl;
    cout << "Total mass of all shapes: " << container.totalMass() << endl;
    cout << "Total memory of all shapes: " << container.totalMemory() << endl;

    container.sortAndPrintByMass();

    return 0;
}