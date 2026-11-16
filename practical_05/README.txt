Person is the base class, Student derives from Person, and GraduateStudent derives from Student.

Student adds a student ID (rollNumber) and course; GraduateStudent inherits these and adds a research topic.

Each derived constructor passes the required values to its base constructor.

With public inheritance, public base methods remain public. graduate.displayPerson() is therefore allowed.

The protected name and age members are accessible inside Student and GraduateStudent, but not directly from main().

Private members of a base class cannot be accessed directly by its derived classes.

Aarav and Meera are fictional examples; their ages and research details are not personal details of Yash Sharma.

Result/Outcome
I learned how a derived class reuses the members of its base class. I used multilevel inheritance and constructors to create Student and GraduateStudent objects. I also called a public method inherited from Person.
