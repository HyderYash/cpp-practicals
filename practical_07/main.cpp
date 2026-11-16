#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

class ComplexNumber {
private:
    int real, imaginary;

public:
    ComplexNumber(int r, int i) : real(r), imaginary(i) {}

    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real,
                             imaginary + other.imaginary);
    }

    void display() const {
        cout << real << " + " << imaginary << "i";
    }
};

int main() {
    cout << "Name: Yash Sharma\nRoll No: E25B000411\n\n";
    cout << "Integer sum: " << add(4, 6) << '\n';
    cout << "Double sum: " << add(2.5, 3.2) << '\n';

    ComplexNumber first(2, 3);
    ComplexNumber second(4, 5);
    ComplexNumber result = first + second;

    cout << "\nFirst complex number: ";
    first.display();
    cout << "\nSecond complex number: ";
    second.display();
    cout << "\nSum: ";
    result.display();
    cout << '\n';
    return 0;
}
