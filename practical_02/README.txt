accountNumber and balance are private; the constructor and other member functions are public.

Two account objects show that each object has its own balance.

Non-positive transactions and withdrawals above the current balance are rejected.

A negative opening amount is initialized to zero by the constructor.

The fixed test transactions are in main(), so stdin.txt is empty.

Apple clang version 21.0.0 (clang-2100.4.1.1), arm64-apple-darwin27.2.0

Result/Outcome
I learned how a class keeps account data private and provides public functions to use it. I created two separate objects and checked deposits and withdrawals before changing a balance.
