// 3.2 + 3.3. Полиморфизм и абстрактные классы
// Первая часть — виртуальные функции и динамическое связывание.
// Вторая часть — Shape как абстрактный класс-интерфейс.

#include <iostream>
#include <memory>
#include <vector>

// --- 3.2. Полиморфизм ---
class Animal {
public:
    virtual void speak() const { std::cout << "...\n"; }
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void speak() const override { std::cout << "Woof\n"; }
};

class Cat : public Animal {
public:
    void speak() const override { std::cout << "Meow\n"; }
};

void makeSound(const Animal& a) { a.speak(); }

// --- 3.3. Абстрактный класс ---
class Shape {
public:
    virtual double area() const = 0;   // чисто виртуальный
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double r_;
public:
    explicit Circle(double r) : r_(r) {}
    double area() const override { return 3.14159 * r_ * r_; }
};

class Rectangle : public Shape {
    double w_, h_;
public:
    Rectangle(double w, double h) : w_(w), h_(h) {}
    double area() const override { return w_ * h_; }
};

int main() {
    // 3.2
    Dog d;
    Cat c;
    makeSound(d);   // Woof
    makeSound(c);   // Meow

    // 3.3
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(2));
    shapes.push_back(std::make_unique<Rectangle>(3, 4));
    for (const auto& s : shapes)
        std::cout << "area = " << s->area() << "\n";
}