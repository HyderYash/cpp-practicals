#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

// Person stores the common name of a person.
class Person {
protected:
    string name;
public:
    Person(string n) : name(n) {}
};

// Student adds academic details to Person.
class Student : public Person {
    string id, course;
    int marks;
public:
    Student(string i, string n, string c, int m)
        : Person(n), id(i), course(c), marks(m) {
        if (id.find_first_not_of(" \t\r\n") == string::npos ||
            name.find_first_not_of(" \t\r\n") == string::npos ||
            course.find_first_not_of(" \t\r\n") == string::npos)
            throw runtime_error("Fields cannot be empty.");
        if ((id + name + course).find(',') != string::npos)
            throw runtime_error("Do not use commas in fields.");
        if (marks < 0 || marks > 100)
            throw runtime_error("Marks must be between 0 and 100.");
    }
    string getId() const { return id; }
    void display() const {
        cout << id << " | " << name << " | " << course
             << " | " << marks << " | "
             << (marks >= 40 ? "Pass" : "Fail") << '\n';
    }
    void write(ofstream& file) const {
        file << id << ',' << name << ',' << course
             << ',' << marks << '\n';
    }
};

int findStudent(const vector<Student>& students, string id) {
    for (int i = 0; i < (int)students.size(); i++)
        if (students[i].getId() == id) return i;
    return -1;
}

// CSV format: ID,name,course,marks. Text fields cannot contain commas.
void load(vector<Student>& students) {
    // Append mode creates a missing file without erasing existing data.
    ofstream create("portal.csv", ios::app);
    if (!create) throw runtime_error("Cannot open portal.csv.");
    create.close();
    ifstream file("portal.csv");
    if (!file) throw runtime_error("Cannot read portal.csv.");
    string line, id, name, course;
    while (getline(file, line)) {
        stringstream row(line);
        int marks;
        if (!getline(row, id, ',') || !getline(row, name, ',') ||
            !getline(row, course, ',') || !(row >> marks))
            throw runtime_error("Invalid record in portal.csv.");
        row >> ws;
        if (!row.eof() || findStudent(students, id) != -1)
            throw runtime_error("Invalid or duplicate record in file.");
        students.push_back(Student(id, name, course, marks));
    }
    if (!file.eof()) throw runtime_error("File reading failed.");
    cout << "Loaded " << students.size() << " student(s).\n";
}

void save(const vector<Student>& students) {
    ofstream file("portal.csv");
    if (!file) throw runtime_error("Cannot open file for writing.");
    for (const Student& student : students) student.write(file);
    file.close();
    if (!file) throw runtime_error("File writing failed.");
    cout << "Saved " << students.size() << " student(s).\n";
}

// Read one whole number and reject any extra characters.
bool readInteger(int& number) {
    string line;
    getline(cin, line);
    stringstream input(line);
    char extra;
    if (!(input >> number)) return false;
    return !(input >> extra);
}

int main() {
    cout << "Name: Yash Sharma\n";
    vector<Student> students;
    try {
        load(students);
    } catch (const exception& error) {
        cout << "Error: " << error.what() << '\n';
        return 1; // Do not overwrite a damaged data file.
    }
    while (true) {
        cout << "\n1 Add  2 Search  3 List  4 Save  0 Exit\n";
        cout << "Choice: ";
        int choice;
        if (!readInteger(choice)) {
            if (cin.eof()) break;
            cout << "Enter a number.\n";
            continue;
        }
        cout << choice << '\n';
        if (choice == 0) break;
        try {
            if (choice == 1) {
                string id, name, course;
                int marks;
                cout << "Enter ID, name, course and marks on separate lines.\n";
                getline(cin, id);
                getline(cin, name);
                getline(cin, course);
                if (!readInteger(marks))
                    throw runtime_error("Marks must be a whole number.");
                if (findStudent(students, id) != -1)
                    throw runtime_error("Student ID already exists.");
                students.push_back(Student(id, name, course, marks));
                cout << "Added: ";
                students.back().display();
            } else if (choice == 2) {
                string id;
                cout << "Enter student ID: ";
                getline(cin, id);
                cout << id << '\n';
                int index = findStudent(students, id);
                if (index == -1) throw runtime_error("Student not found.");
                students[index].display();
            } else if (choice == 3) {
                if (students.empty()) cout << "No student records.\n";
                for (const Student& student : students) student.display();
            } else if (choice == 4) {
                save(students);
            } else {
                cout << "Invalid choice.\n";
            }
        } catch (const exception& error) {
            cout << "Error: " << error.what() << '\n';
        }
    }
    cout << "Goodbye.\n";
    return 0;
}
