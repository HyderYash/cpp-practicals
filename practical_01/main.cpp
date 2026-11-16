#include <iostream>
#include <iomanip>

int main() {
    std::cout << "Name: Yash Sharma\n";
    std::cout << "Roll No: E25B000411\n";

    const int SUBJECTS = 3;
    int maths, programming, english;
    std::cout << "Enter marks in Maths, Programming and English: ";
    if (!(std::cin >> maths >> programming >> english)) {
        std::cout << "Invalid input. Enter whole numbers.\n";
        return 1;
    }
    std::cout << maths << " " << programming << " " << english << "\n";

    bool valid = maths >= 0 && maths <= 100 && programming >= 0
                 && programming <= 100 && english >= 0 && english <= 100;
    if (!valid) {
        std::cout << "Each mark must be between 0 and 100.\n";
        return 1;
    }

    int total = maths + programming + english;
    double percentage = static_cast<double>(total) / SUBJECTS;
    bool passed = maths >= 40 && programming >= 40 && english >= 40;
    char grade = percentage >= 75 ? 'A' : 'B';
    if (!passed) {
        grade = 'F';
    }

    std::cout << "Total: " << total << " / " << SUBJECTS * 100 << "\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Percentage: " << percentage << "%\n";
    std::cout << "Passed all subjects: " << std::boolalpha << passed << "\n";
    std::cout << "Grade: " << grade << "\n";
    return 0;
}
