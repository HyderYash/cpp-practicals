#include <iomanip>
#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.141592653589793 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override {
        return length * width;
    }
};

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override {
        return 0.5 * base * height;
    }
};

int main() {
    cout << "Name: Yash Sharma\nRoll No: E25B000411\n\n";
    Circle circle(5);
    Rectangle rectangle(4, 6);
    Triangle triangle(6, 4);

    Shape* shapes[] = {&circle, &rectangle, &triangle};
    const char* labels[] = {"Circle", "Rectangle", "Triangle"};

    cout << fixed << setprecision(2);
    for (int i = 0; i < 3; i++) {
        cout << labels[i] << " area: " << shapes[i]->area() << '\n';
    }
    return 0;
}
