#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int marks;
};

bool readNumber(const string& text, int& number) {
    stringstream field(text);
    char extra;
    if (!(field >> number)) return false;
    return !(field >> extra);
}

bool parseStudent(const string& line, Student& student) {
    if (count(line.begin(), line.end(), ',') != 2) return false;
    stringstream row(line);
    string id, name, marks;
    if (!getline(row, id, ',') || !getline(row, name, ',') ||
        !getline(row, marks)) return false;
    if (name.empty() || name.find_first_of(",\r\n") != string::npos)
        return false;
    if (!readNumber(id, student.id) || student.id <= 0) return false;
    if (!readNumber(marks, student.marks)) return false;
    if (student.marks < 0 || student.marks > 100) return false;
    student.name = name;
    return true;
}

int main() {
    cout << "Name: Yash Sharma\n";
    cout << "Roll Number: E25B000411\n";
    Student students[] = {
        {101, "Yash Sharma", 88},
        {102, "Aarav Patel", 76},
        {103, "Meera Shah", 92}
    };

    fstream csv("students.csv", ios::out | ios::trunc);
    if (!csv) {
        cerr << "Cannot open students.csv for writing.\n";
        return 1;
    }
    csv << "ID,Name,Marks\n";
    for (const Student& student : students)
        csv << student.id << ',' << student.name << ','
            << student.marks << '\n';
    csv.close();
    if (!csv) {
        cerr << "Could not finish writing students.csv.\n";
        return 1;
    }
    cout << "Saved 3 records in students.csv.\n";

    csv.open("students.csv", ios::in);
    string line;
    if (!csv || !getline(csv, line) || line != "ID,Name,Marks") {
        cerr << "Cannot read the CSV header.\n";
        return 1;
    }
    cout << "\nRecords read from the file:\n";
    while (getline(csv, line)) {
        Student student{};
        if (!parseStudent(line, student)) {
            cerr << "Malformed CSV record: " << line << '\n';
            return 1;
        }
        cout << student.id << " | " << student.name << " | "
             << student.marks << '\n';
    }
    if (!csv.eof()) {
        cerr << "Error while reading students.csv.\n";
        return 1;
    }
    csv.close();

    cout << "\nMalformed-record checks:\n";
    string badRows[] = {
        "104,Wrong,not-a-number", "105,Extra,90,field",
        "106,Out of range,105", "107,,80", "108,Missing",
        "109,Trailing text,80abc"
    };
    for (const string& row : badRows) {
        Student student{};
        cout << (parseStudent(row, student) ? "Accepted: " : "Rejected: ")
             << row << '\n';
    }

    fstream pos("position.txt", ios::in | ios::out | ios::trunc);
    if (!pos) {
        cerr << "Cannot open position.txt.\n";
        return 1;
    }
    pos << "HELLO WORLD";
    pos.flush();
    cout << "\nFile-position demonstration:\n";
    cout << "tellp() after writing: " << pos.tellp() << '\n';
    pos.seekg(6, ios::beg);
    cout << "tellg() after seekg(6): " << pos.tellg() << '\n';
    char word[6] = {};
    pos.read(word, 5);
    cout << "Word read: " << word << '\n';
    cout << "tellg() after reading: " << pos.tellg() << '\n';
    pos.seekp(6, ios::beg);
    cout << "tellp() after seekp(6): " << pos.tellp() << '\n';
    pos.write("CLASS", 5);
    pos.flush();
    cout << "tellp() after overwrite: " << pos.tellp() << '\n';
    if (!pos) {
        cerr << "File-position operation failed.\n";
        return 1;
    }
    pos.seekg(0, ios::beg);
    if (!getline(pos, line)) {
        cerr << "Cannot read the updated text.\n";
        return 1;
    }
    cout << "Updated text: " << line << '\n';
    pos.close();
    return 0;
}
