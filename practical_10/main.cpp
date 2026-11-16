#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class BankError : public runtime_error {
public:
    explicit BankError(const string& message) : runtime_error(message) {}
};

class InvalidAmount : public BankError {
public:
    InvalidAmount() : BankError("Amount must be greater than zero.") {}
};

class InsufficientFunds : public BankError {
public:
    InsufficientFunds() : BankError("Not enough money in the account.") {}
};

class BankAccount {
    double balance;

public:
    explicit BankAccount(double openingBalance) : balance(openingBalance) {}

    double getBalance() const {
        return balance;
    }

    void withdraw(double amount) {
        if (amount <= 0) throw InvalidAmount();
        if (amount > balance) throw InsufficientFunds();
        balance -= amount;
    }
};

void tryWithdrawal(BankAccount& account, double amount) {
    cout << "\nWithdrawal requested: " << amount << '\n';
    cout << "Balance before: " << account.getBalance() << '\n';
    try {
        account.withdraw(amount);
        cout << "Withdrawal successful.\n";
    } catch (const InvalidAmount& error) {
        cout << "Invalid amount: " << error.what() << '\n';
    } catch (const InsufficientFunds& error) {
        cout << "Insufficient funds: " << error.what() << '\n';
    }
    cout << "Balance after: " << account.getBalance() << '\n';
}

int main() {
    cout << "Name: Yash Sharma\n";
    cout << "Roll Number: E25B000411\n";
    cout << fixed << setprecision(2);
    BankAccount account(1000);
    cout << "Opening balance: " << account.getBalance() << '\n';
    tryWithdrawal(account, 250);
    tryWithdrawal(account, 1000);
    tryWithdrawal(account, -50);
    tryWithdrawal(account, 0);
    return 0;
}
