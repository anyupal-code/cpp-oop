// 1.2. Инкапсуляция
// Данные private, доступ — через public-методы с валидацией.

#include <iostream>
#include <stdexcept>

class Account {
    double balance_ = 0;
public:
    void deposit(double sum) {
        if (sum <= 0) throw std::invalid_argument("deposit: sum must be > 0");
        balance_ += sum;
    }
    void withdraw(double sum) {
        if (sum <= 0)       throw std::invalid_argument("withdraw: sum must be > 0");
        if (sum > balance_) throw std::runtime_error("withdraw: insufficient funds");
        balance_ -= sum;
    }
    double balance() const { return balance_; }
};

int main() {
    Account a;
    a.deposit(100);
    a.withdraw(30);
    std::cout << "balance = " << a.balance() << "\n";

    try { a.withdraw(1000); }
    catch (const std::exception& e) { std::cout << "error: " << e.what() << "\n"; }

    // a.balance_ = 1e9;   // ошибка компиляции: private
}