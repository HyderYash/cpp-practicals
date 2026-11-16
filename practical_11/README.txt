Run the executable in its practical folder; it creates students.csv and position.txt there.

This restricted CSV format uses exactly three unquoted fields: a positive integer ID, a nonempty name, and integer marks from 0 to 100.

Names must not contain commas or newline characters; quoted CSV fields are not supported.

Parsing checks field count, numeric values, missing names and marks range.

Open and I/O checks report file errors instead of silently continuing.

seekg and tellg move and report the read position; seekp and tellp move and report the write position.

Only position.txt is overwritten: WORLD becomes CLASS, so the replacement remains five characters long.

Result/Outcome
I learned to write and read student records using fstream and parse simple CSV fields. I also used seekg, tellg, seekp and tellp to read and replace text at a known file position.
