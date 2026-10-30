// 0.5. Как ООП выглядит в C++
// class, объект, вызов метода через . и через ->

#include <iostream>

class Counter {
    int value_ = 0;                    // private по умолчанию
public:
    void inc()         { ++value_; }
    void dec()         { --value_; }
    int  value() const { return value_; }
};

int main() {
    Counter c;                // объект
    c.inc();
    c.inc();
    std::cout << "c.value = " << c.value() << "\n";    // 2

    Counter* p = &c;          // указатель на тот же объект
    p->dec();
    std::cout << "c.value = " << p->value() << "\n";   // 1

    // c.value_ = 42;         // ошибка: private
}