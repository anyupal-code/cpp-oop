// 2.4. Исключения
// throw / try / catch. В паре с RAII: при раскрутке стека
// деструкторы локальных объектов вызываются автоматически.

#include <iostream>
#include <stdexcept>

class Guard {
public:
    explicit Guard(const char* name) : name_(name) {
        std::cout << "Guard " << name_ << " created\n";
    }
    ~Guard() { std::cout << "Guard " << name_ << " destroyed\n"; }
private:
    const char* name_;
};

void fail() {
    Guard g("inside fail");
    throw std::runtime_error("something failed");
}   // g будет уничтожен при раскрутке

int main() {
    try {
        fail();
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << "\n";
    }
}