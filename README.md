# C++ Programming Practicals

**Yash Sharma · E25B000411 · Second Year, AI and Data Science**

Twelve C++17 practicals covering programming fundamentals, object-oriented programming, memory ownership, templates, exceptions and file handling. Each example uses straightforward student-level code and includes captured output and a short explanation. Practical 12 combines these concepts in a Student Portal mini project.

## Practical index

| No. | Topic | Source code |
| --- | --- | --- |
| 01 | C++ fundamentals and Git | [main.cpp](practical_01/main.cpp) |
| 02 | Classes, access specifiers and member functions | [main.cpp](practical_02/main.cpp) |
| 03 | Constructors and the Rule of Five | [main.cpp](practical_03/main.cpp) |
| 04 | RAII and smart pointers | [main.cpp](practical_04/main.cpp) |
| 05 | Single and multilevel inheritance | [main.cpp](practical_05/main.cpp) |
| 06 | Abstract classes and runtime polymorphism | [main.cpp](practical_06/main.cpp) |
| 07 | Function and operator overloading | [main.cpp](practical_07/main.cpp) |
| 08 | Singleton design pattern | [main.cpp](practical_08/main.cpp) |
| 09 | Class templates and a generic stack | [main.cpp](practical_09/main.cpp) |
| 10 | Custom exceptions and exception handling | [main.cpp](practical_10/main.cpp) |
| 11 | File handling, CSV and file positions | [main.cpp](practical_11/main.cpp) |
| 12 | Student Portal mini project | [main.cpp](practical_12/main.cpp) |

Each practical folder contains `main.cpp`, `stdin.txt`, `stdout.txt` and `README.txt`. The input file is empty when the program uses fixed demonstration values. Some folders also include class diagrams or sample data.

## Practical manual

- [Read the PDF manual](manual/Yash_Sharma_E25B000411_CPP_Practical_Manual.pdf)
- [Download the editable Word manual](manual/Yash_Sharma_E25B000411_CPP_Practical_Manual.docx)

The manual includes each question, aim, numbered source code, output, explanation and learning outcome.

## Compile and run

Install a compiler that supports C++17, such as GCC or Clang. Compile each practical separately and run it from its own folder so that its data files stay together.

### Linux or macOS

From the repository root:

```sh
cd practical_01
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program
./program
```

Use `clang++` in place of `g++` when using Clang. To run with the supplied sample input:

```sh
./program < stdin.txt
```

### Windows

With GCC/MinGW-w64 available in **Command Prompt**, run these commands from the repository root:

```bat
cd practical_01
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
program.exe
```

For the supplied sample input in Command Prompt:

```bat
program.exe < stdin.txt
```

In PowerShell, launch the compiled program with `./program.exe`. To supply the sample input in PowerShell, use:

```powershell
Get-Content .\stdin.txt | .\program.exe
```

Change `practical_01` to the folder you want to run. The captured `stdout.txt` files begin with `Name: Yash Sharma`.

## Sample input and data

- Practical 01 reads three marks; its [sample input](practical_01/stdin.txt) is `78 85 91`.
- Practicals 02–11 use fixed demonstration values and do not require keyboard input.
- Practical 11 writes `students.csv` and `position.txt` in its working folder. Its [examples](practical_11/examples/) show the generated files.
- Practical 12 includes [first-run input](practical_12/stdin.txt), [captured output](practical_12/stdout.txt), [restart input](practical_12/restart_input.txt) and [restart output](practical_12/restart_output.txt).

Sample marks and the additional student records are demonstration data.

## Student Portal — Practical 12

Compile and launch [Practical 12](practical_12/) using the commands above. The program loads `portal.csv` from its working folder at startup and creates an empty file if one does not exist.

| Choice | Action |
| --- | --- |
| `1` | Add a student: enter ID, name, course and marks on separate lines. |
| `2` | Search for a student by ID. |
| `3` | List all students and their Pass/Fail results. |
| `4` | Save the current records to `portal.csv`. |
| `0` | Exit. |

**Choose `4` to save before choosing `0` to exit.** Changes are not saved automatically. A mark of at least 40 produces a Pass result.

The CSV format is `ID,name,course,marks`, with one record per line and **no header**. Text fields must be nonempty and cannot contain commas or embedded line breaks; quoted CSV fields are not supported. IDs must be unique, and marks must be whole numbers from 0 to 100. Invalid entries produce an error message. If the file contains an invalid record, the program stops before the menu so the file is not overwritten.

For a preloaded example, copy [examples/portal.csv](practical_12/examples/portal.csv) into the `practical_12` folder before running. The captured first-run output assumes an initially empty `portal.csv`; preserve any existing records before reproducing that example. After the sample run saves its records, `restart_input.txt` lists them in a second run.

## Local verification

All twelve programs were compiled and run locally on macOS with Apple Clang 21.0.0 using C++17, `-Wall`, `-Wextra` and `-pedantic`. The recorded builds had no compiler warnings, and the captured output was checked against the manual.

Practicals 03 and 04 were also run with AddressSanitizer and UndefinedBehaviorSanitizer, with no diagnostics in the tested runs. The macOS sanitizer runs were not leak checks. Apple `leaks` separately reported 0 leaks and 0 leaked bytes, alongside a restricted-process inspection notice. These observations apply to the tested runs. See the reports for [Practical 03](practical_03/leaks_report.txt) and [Practical 04](practical_04/leaks_report.txt).
