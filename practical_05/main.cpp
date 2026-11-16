#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void displayPerson() const {
        cout << "Name: " << name << "\nAge: " << age << '\n';
    }
};

class Student : public Person {
protected:
    string rollNumber;
    string course;

public:
    Student(string n, int a, string r, string c)
        : Person(n, a), rollNumber(r), course(c) {}

    void displayStudent() const {
        displayPerson();
        cout << "Roll number: " << rollNumber << '\n';
        cout << "Course: " << course << '\n';
    }
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    GraduateStudent(string n, int a, string r, string c, string topic)
        : Student(n, a, r, c), researchTopic(topic) {}

    void displayGraduate() const {
        displayStudent();
        cout << "Research topic: " << researchTopic << '\n';
    }
};

int main() {
    cout << "Name: Yash Sharma\nRoll No: E25B000411\n\n";

    // These two objects use fictional example details.
    Student student("Aarav", 20, "S101", "B.Tech");
    GraduateStudent graduate("Meera", 23, "G201", "M.Tech",
                             "Computer Vision");

    cout << "Student details\n";
    student.displayStudent();
    cout << "\nGraduate student details\n";
    graduate.displayGraduate();
    cout << "\nCalling an inherited public method\n";
    graduate.displayPerson();
    return 0;
}
