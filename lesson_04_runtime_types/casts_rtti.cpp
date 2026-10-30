// 4.1 + 4.2. Приведение типов и RTTI
// static_cast  — компилятор, без проверки
// dynamic_cast — рантайм, nullptr при ошибке
// typeid       — имя реального типа в рантайме

#include <iostream>
#include <typeinfo>

class Animal {
public:
    virtual ~Animal() = default;
    virtual void speak() const { std::cout << "...\n"; }
};

class Dog : public Animal {
public:
    void speak() const override { std::cout << "Woof\n"; }
    void bark()  const          { std::cout << "BARK\n"; }
};

class Cat : public Animal {
public:
    void speak() const override { std::cout << "Meow\n"; }
};

void inspect(Animal* a) {
    std::cout << "typeid: " << typeid(*a).name() << "\n";

    // dynamic_cast: безопасно, nullptr если не Dog
    if (auto* d = dynamic_cast<Dog*>(a)) {
        std::cout << "  -> it's a Dog, calling bark(): ";
        d->bark();
    } else {
        std::cout << "  -> not a Dog\n";
    }

    // static_cast: без проверки — используем только когда точно знаем тип
    if (typeid(*a) == typeid(Dog)) {
        auto* d = static_cast<Dog*>(a);
        std::cout << "  -> static_cast OK, typeid confirmed Dog\n";
        (void)d;
    }
}

int main() {
    Dog d;
    Cat c;

    inspect(&d);
    inspect(&c);

    // обычный static_cast для чисел
    double x = 3.9;
    int    i = static_cast<int>(x);
    std::cout << "static_cast<int>(3.9) = " << i << "\n";
}