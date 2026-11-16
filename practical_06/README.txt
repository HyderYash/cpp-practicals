Shape is abstract because area() is pure virtual, so a Shape object cannot be created directly.

Circle, Rectangle, and Triangle override area() with their own formulas.

The virtual call through a Shape pointer selects the method of the actual object at runtime.

The virtual destructor supports correct destruction if a derived object is deleted through a Shape pointer.

All three objects are created on the stack, so this example needs no new or delete.

Circle uses radius 5, rectangle uses length 4 and width 6, and triangle uses base 6 and height 4. Areas are in square units.

Result/Outcome
I learned to define an abstract class using a pure virtual function. I used Shape pointers to call the correct area() method for three different shapes at runtime. I displayed the results with two decimal places.
