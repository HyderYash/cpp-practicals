add(int, int) handles integer arguments, while add(double, double) handles double arguments.

Function overloading uses the same function name with different parameter lists; changing only the return type is not enough.

operator+ adds the real parts together and the imaginary parts together, then returns a new object.

This example demonstrates compile-time polymorphism because overload selection uses argument or operand types known at compile time.

Runtime polymorphism instead uses virtual functions through base pointers or references, as in Practical 06.

The display method is kept simple for the positive imaginary values used in this example.

Result/Outcome
I learned to overload a function by changing its parameter types. I also overloaded the + operator to add two complex numbers. I understood that these overloads are selected at compile time.
