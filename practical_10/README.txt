BankError inherits runtime_error; InvalidAmount and InsufficientFunds inherit BankError.

withdraw checks the amount and available balance before changing the balance.

A reference to the account lets tryWithdrawal update the original account.

Separate catch blocks display a suitable message for each exception.

The fixed examples need no keyboard input.

Result/Outcome
I learned to create a custom exception hierarchy using runtime_error. I handled invalid amounts and insufficient funds separately, and verified that failed withdrawals do not change the balance.
