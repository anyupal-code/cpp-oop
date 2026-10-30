// 3.1. Наследование
// Dog наследует Animal: получает eat() и добавляет bark().
// Конструкторы и деструкторы не наследуются.

#include <iostream>

class Animal {
public:
    Animal()          { std::cout << "Animal()\n"; }
    virtual ~Animal() { std::cout << "~Animal()\n"; }
    void eat() const  { std::cout << "eating\n"; }
};

class Dog : public Animal {
public:
    Dog()          { std::cout << "Dog()\n"; }
    ~Dog()         { std::cout << "~Dog()\n"; }
    void bark() const { std::cout << "woof\n"; }
};

int main() {
    Dog d;      // Animal() -> Dog()
    d.eat();    // унаследовано
    d.bark();   // своё
}               // ~Dog() -> ~Animal()