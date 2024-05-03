#include <iostream>

class BankAccount {
private: // тип данных для users
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNumber, double initialBalance, double rate = 0.0) {
        this->accountNumber = accNumber;
        this->balance = initialBalance;
        this->interestRate = rate;
    }


    void deposit(double amount) {
        if (amount > 0) {
            this->balance += amount;
            std::cout << "Внесение $" << amount << " успешно.\n";
        } else {
            std::cout << "Некорректная сумма для внесения.\n";
        }
    }


    void withdraw(double amount) {
        if (amount > 0 && amount <= this->balance) {
            this->balance -= amount;
            std::cout << "Снятие $" << amount << " успешно.\n";
        } else {
            std::cout << "Некорректная сумма для снятия или недостаточно средств.\n";
        }
    }


    double getBalance() const {
        return this->balance;
    }


    double getInterest() const {
        return this->balance * this->interestRate * (1.0 / 12.0);
    }


    void setInterestRate(double rate) {
        this->interestRate = rate;
    }


    int getAccountNumber() const {
        return this->accountNumber;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};



bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (amount > 0 && amount <= from.balance) {
        from.balance -= amount;
        to.balance += amount;
        std::cout << "Перевод $" << amount << " успешно.\n";
        return true;
    } else {
        std::cout << "Некорректная сумма для перевода или недостаточно средств.\n";
        return false;
    }
}

int main() {

    BankAccount acc1(12345, 1000.0, 0.03); // Установим процентную ставку 3%
    BankAccount acc2(54321, 500.0);


    transfer(acc1, acc2, 200.0);


    std::cout << "Баланс счета " << acc1.getAccountNumber() << ": $" << acc1.getBalance() << std::endl;
    std::cout << "Баланс счета " << acc2.getAccountNumber() << ": $" << acc2.getBalance() << std::endl;


    std::cout << "Сумма процентов для счета " << acc1.getAccountNumber() << ": $" << acc1.getInterest() << std::endl;

    return 0;
}