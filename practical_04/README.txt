The unique_ptr is moved to a new owner, leaving the old pointer empty.

Admissions and library offices genuinely share the same Student object.

The shared ownership count changes from one to two and back to one.

RAII ties resource cleanup to object lifetime and scope exit.

A raw pointer does not express ownership or automatically delete its target; an owning raw pointer requires careful manual cleanup. Smart pointers manage this ownership and cleanup automatically.

AddressSanitizer and UndefinedBehaviorSanitizer reported no errors for this run. This macOS ASan run is not a leak check.

Apple leaks reported 0 leaks and 0 leaked bytes at program exit. The tool also reported restricted process inspection, so this result applies only to the observed run.

Memory check command: leaks --atExit -- ./program. AddressSanitizer and UndefinedBehaviorSanitizer were also used as alternatives to Valgrind.

Result/Outcome
I learned that unique_ptr gives one object exclusive ownership while shared_ptr allows joint ownership. I observed automatic destruction when the last owner left its scope.
