//
// Created by kochu on 21.02.2024.
//

#include <iostream>
#include <cmath>
#include <vector>
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

    double area() const override {
        return base * height;
    }
    double perimeter() const override {
        return (2 * (base + (height/(sin(angle* M_PI/180)))));
    }

    double mass() const override{
        return area();
    }

    void draw() const override{
        cout << "\nParralelogram with base = " << base << ", height = " << height << " and angle = " << angle << '\n';
        cout << "\nArea = " << area();
        cout << "\nPerimeter = " << perimeter();
        cout << "\n\n";
    }
};

int StartParallelogram(){
    vector<Parallelogram> parallelogram;
    char choice;

    do {
        double b, h, a;
        cout << "Enter the base, height and angle of the parallelogram separated by spaces: ";
        cin >> b >> h >> a;
        parallelogram.emplace_back(b, h, a);
        cout << "Add another? (y/n): ";
        cin >> choice;
    } while (choice == 'y');
    cout << '\n';

    double sum_mass = 0;
    double sum_memory = parallelogram.size() * sizeof(Parallelogram);;
    double total_area = 0;
    double total_perimeter = 0;

    for (auto& shape : parallelogram){
        total_area += shape.area();
        total_perimeter += shape.perimeter();
        sum_mass += shape.mass();

    }
    cout << "All about all:\n";
    for (auto& shape : parallelogram){
        cout << "\n";

        shape.draw();
        cout << '\n';
    }
    cout << "Summa of perimeter = " << total_perimeter << '\n';
    cout << "Summa of area = " << total_area << '\n';
    cout << "Summa of mass = " << sum_mass << '\n';
    cout << "Total memory = " << sum_memory << '\n';

    return 0;
}