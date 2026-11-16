#include <iostream>
#include <iomanip>

class BankAccount {
private:  // Only member functions can directly access this data.
    int accountNumber;
    double balance;

public:  // Other parts of the program can call these functions.
    BankAccount(int number, double amount) {
        accountNumber = number;
        balance = amount >= 0 ? amount : 0;
    }

    void display() const {
        std::cout << "Account " << accountNumber;
        std::cout << " | Balance: " << balance << "\n";
    }

    void deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Deposit rejected: amount must be positive.\n";
            return;
        }
        balance += amount;
        std::cout << "Deposited: " << amount << "\n";
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Withdrawal rejected: amount must be positive.\n";
        } else if (amount > balance) {
            std::cout << "Withdrawal rejected: insufficient balance.\n";
        } else {
            balance -= amount;
            std::cout << "Withdrawn: " << amount << "\n";
        }
    }
};

int main() {
    std::cout << "Name: Yash Sharma\n";
    std::cout << "Roll No: E25B000411\n";
    std::cout << std::fixed << std::setprecision(2);

    BankAccount first(1001, 1500);
    BankAccount second(1002, 2000);
    first.display();
    second.display();

    first.deposit(500);
    first.withdraw(300);
    first.deposit(-100);
    first.withdraw(-50);
    first.withdraw(5000);

    std::cout << "Final balances:\n";
    first.display();
    second.display();
    return 0;
}
