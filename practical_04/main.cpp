#include <iostream>
#include <memory>
#include <string>
#include <utility>

class Student {
public:
    std::string name;

    Student(const std::string& studentName) : name(studentName) {
        std::cout << "Created student: " << name << "\n";
    }

    ~Student() {
        std::cout << "Destroyed student: " << name << "\n";
    }
};

int main() {
    std::cout << "Name: Yash Sharma\n";
    std::cout << "Roll No: E25B000411\n";

    std::cout << "\nUnique ownership:\n";
    {
        std::unique_ptr<Student> owner = std::make_unique<Student>("Yash");
        std::cout << "Owner has: " << owner->name << "\n";
        std::unique_ptr<Student> newOwner = std::move(owner);
        std::cout << "Old owner is empty: " << std::boolalpha;
        std::cout << (owner == nullptr) << "\n";
        std::cout << "New owner has: " << newOwner->name << "\n";
    }  // The only owner leaves scope, so the student is destroyed.
    std::cout << "Unique ownership scope ended.\n";

    std::cout << "\nShared ownership between two offices:\n";
    {
        std::shared_ptr<Student> admissionsOffice =
            std::make_shared<Student>("Riya");
        std::cout << "Owners before library: ";
        std::cout << admissionsOffice.use_count() << "\n";
        {
            std::shared_ptr<Student> libraryOffice = admissionsOffice;
            std::cout << "Admissions record: ";
            std::cout << admissionsOffice->name << "\n";
            std::cout << "Library record: " << libraryOffice->name << "\n";
            std::cout << "Owners with both offices: ";
            std::cout << libraryOffice.use_count() << "\n";
            std::cout << "Same student object: ";
            std::cout << (admissionsOffice == libraryOffice) << "\n";
        }  // The library releases its share; one owner still remains.
        std::cout << "Owners after library leaves: ";
        std::cout << admissionsOffice.use_count() << "\n";
        std::cout << "Student is still available: ";
        std::cout << admissionsOffice->name << "\n";
    }  // The last shared owner leaves, so the student is destroyed.
    std::cout << "Shared ownership scope ended.\n";
    return 0;
}
