//
// Created by kochu on 21.02.2024.
//

#include <iostream>
#include <cmath>
#include <vector>
#include "Shape.h"
using namespace std;

class Ellipse : public Shape{
private:
    double r_a;
    double r_b;
public:
    Ellipse(double a, double b)
        : r_a(a), r_b(b) {}

    double area() const override{
        return M_PI * r_a * r_b;
    }

    double perimeter() const override{
        return 2 * M_PI * sqrt((r_a * r_a)/2);
    }

    double mass() const override{
        return area();
    }

    void draw() const override{
        cout << "\nEllipse with half-axis_a = " << r_a << " and half-axis_b = " << r_b << '\n';
        cout << "\nArea = " << area();
        cout << "\nPerimeter = " << perimeter();
        cout << "\n\n";
    }
};

int StartEllipse(){
    vector<Ellipse> ellipse;

    char choice;

    do {
        double a, b;
        cout << "Enter the half-axis_a and half-axis_b of the ellipse separated by spaces: ";
        cin >> a >> b;
        ellipse.emplace_back(a, b);
        cout << "Add another? (y/n): ";
        cin >> choice;
    } while (choice == 'y');
    cout << '\n';

    double sum_mass = 0;
    double sum_memory = ellipse.size() * sizeof(Ellipse);;
    double total_area = 0;
    double total_perimeter = 0;

    for (auto& shape : ellipse){
        total_area += shape.area();
        total_perimeter += shape.perimeter();
        sum_mass += shape.mass();

    }
    cout << "All about all:\n";
    for (auto& shape : ellipse){
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