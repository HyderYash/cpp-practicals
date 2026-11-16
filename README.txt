C++ Practical Programs
Yash Sharma | E25B000411 | Second Year AI and DS

This pack contains simple examples for the twelve practicals in the manual.
The mini project is Option C: Student Portal.

Requirements: a C++17 compiler such as GCC, Clang or a C++17-enabled IDE.
Open one practical folder and compile its main.cpp separately:
  g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program
  ./program
On Windows, use program.exe or the IDE Run button.

Practical 01 takes three marks as input. stdin.txt records the tested input.
Practical 12 takes menu choices and student details. Choose 4 to save before
choosing 0 to exit. It loads portal.csv when it starts. The examples directory
contains sample CSV data; copy it into the program folder to preload it.
Other practicals use fixed demonstration values and need no keyboard input.

Run each program from its own folder so its data files stay together.
stdout.txt contains actual captured program output. All outputs begin with
Name: Yash Sharma. Sample marks and other student details are demonstration data.

Concepts covered: syntax, classes, Rule of Five, smart pointers, inheritance,
virtual functions, overloading, Singleton, templates, exceptions and file I/O.
See each practical's README.txt for its short explanation and learning outcome.
Practical 12: Person stores the name; Student inherits Person and stores ID,
course and marks. A vector stores records. Exceptions handle invalid entries.
CSV fields are unquoted and cannot contain commas. A mark of at least 40 passes.

Memory checks: Practicals 03 and 04 were checked with AddressSanitizer and
UndefinedBehaviorSanitizer. Apple leaks reported 0 leaked bytes with a
restricted-process inspection notice. The logs are retained as evidence.

Git history: the supplied cpp-practicals.bundle contains the local commits.
To restore them, run this from the extracted pack's parent folder:
  git clone cpp-practicals.bundle cpp-practicals-restored

GitHub publication is a separate step and has not been performed. After
creating an empty repository named cpp-practicals in your GitHub account,
open the restored folder, add its URL as origin and push the main branch.
Use your actual repository URL; no repository URL or upload is claimed here.
