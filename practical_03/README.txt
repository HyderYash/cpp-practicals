IntBox owns one dynamically allocated int; the default value is zero.

All five special member functions are commented: copy constructor, move constructor, copy assignment, move assignment and destructor.

Copy operations allocate separate memory; move operations transfer the pointer and set the source pointer to nullptr.

The destructor releases the owned integer using delete.

AddressSanitizer and UndefinedBehaviorSanitizer reported no errors for this run. This macOS ASan run is not a leak check.

Apple leaks reported 0 leaks and 0 leaked bytes at program exit. The tool also reported restricted process inspection, so this result applies only to the observed run.

Memory check command: leaks --atExit -- ./program. AddressSanitizer and UndefinedBehaviorSanitizer were also used as alternatives to Valgrind.

Result/Outcome
I learned how the Rule of Five manages a dynamically allocated value. I made deep copies with independent data, transferred ownership by moving, and left moved-from objects safe to reuse.
