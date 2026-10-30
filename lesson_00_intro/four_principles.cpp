// 0.3. Четыре принципа ООП — минимальная демонстрация каждого.
// Полностью они раскрываются в следующих уроках.

#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

// --- 1. Инкапсуляция: данные private, доступ через методы ---
class Account {
    double balance_ = 0;
public:
    void deposit(double sum) {
        if (sum <= 0) throw std::invalid_argument("sum must be > 0");
        balance_ += sum;
    }
    double balance() const { return balance_; }
};

// --- 2. Абстракция: пользователь видит интерфейс, не реализацию ---
// Внешнему коду не важно, как хранится баланс — только deposit/balance.

// --- 3. Наследование: Dog и Cat — это Animal ---
class Animal {
public:
    virtual ~Animal() = default;
    virtual void speak() const = 0;     // интерфейс
};

class Dog : public Animal {
public:
    void speak() const override { std::cout << "Woof\n"; }
};

class Cat : public Animal {
public:
    void speak() const override { std::cout << "Meow\n"; }
};

// --- 4. Полиморфизм: один интерфейс — разные реализации ---
void makeSound(const Animal& a) { a.speak(); }

int main() {
    // 1. Инкапсуляция
    Account acc;
    acc.deposit(100);
    // acc.balance_ = 1e9;  // ошибка: private
    std::cout << "balance = " << acc.balance() << "\n";

    // 3 + 4. Наследование + полиморфизм
    std::vector<std::unique_ptr<Animal>> zoo;
    zoo.push_back(std::make_unique<Dog>());
    zoo.push_back(std::make_unique<Cat>());
    for (const auto& a : zoo) makeSound(*a);
}