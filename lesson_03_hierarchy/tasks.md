# Урок 03. Иерархии — задания и ответы

---

## 3.1. Наследование

**Задание 1.** Опишите базовый класс `Animal` с методом `eat()` и
наследника `Dog` с методом `bark()`. Создайте `Dog`, вызовите оба
метода.

**Ответ.**

```cpp
#include <iostream>

class Animal {
public:
    void eat() const { std::cout << "eating\n"; }
};

class Dog : public Animal {
public:
    void bark() const { std::cout << "woof\n"; }
};

int main() {
    Dog d;
    d.eat();
    d.bark();
}
```

**Задание 2.** Что не наследуется от базового класса?

**Ответ.** Конструкторы, деструктор и `operator=`. Их наследник должен
вызывать или определять сам.

**Задание 3.** Чем `public`-наследование отличается от `private`?

**Ответ.** При `public` унаследованные `public`-члены остаются
`public` — отношение is-a: `Dog` является `Animal`. При `private`
они становятся `private` в наследнике — деталь реализации, а не
интерфейс. В курсе используется `public`.

---

## 3.2. Полиморфизм

**Задание 1.** Сделайте `Animal::speak()` виртуальным. Добавьте
`Dog::speak` и `Cat::speak` с `override`. Напишите функцию
`makeSound(const Animal&)` и вызовите её для `Dog` и `Cat`.

**Ответ.**

```cpp
#include <iostream>

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

int main() {
    Dog d;
    Cat c;
    makeSound(d);   // Woof
    makeSound(c);   // Meow
}
```

**Задание 2.** Что будет, если убрать `virtual` у `Animal::speak()`?

**Ответ.** Включится статическое связывание: `makeSound(const Animal&)`
вызовет `Animal::speak()` для обоих объектов, потому что компилятор
смотрит на тип ссылки, а не на реальный тип объекта. Оба вызова
напечатают `...`.

**Задание 3.** Зачем нужен виртуальный деструктор?

**Ответ.** Если удалять наследника через указатель на базовый класс
(`delete base_ptr`), без виртуального деструктора вызовется только
`~Animal`, а `~Dog` — нет. Поля `Dog` не освободятся — утечка.

**Задание 4.** Зачем `override`?

**Ответ.** Компилятор проверяет, что метод действительно переопределяет
виртуальный метод базового класса. Если сигнатуры не совпадут
(например, забыт `const`), будет ошибка компиляции, а не молчаливое
создание нового метода.

---

## 3.3. Абстрактные классы

**Задание 1.** Сделайте `Shape` абстрактным классом с чисто
виртуальным `area()`. Реализуйте `Circle` и `Rectangle`.

**Ответ.**

```cpp
#include <iostream>

class Shape {
public:
    virtual double area() const = 0;
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
    Circle c(2);
    Rectangle r(3, 4);
    std::cout << c.area() << "\n";   // ~12.566
    std::cout << r.area() << "\n";   // 12
}
```

**Задание 2.** Можно ли создать объект `Shape`? Почему?

**Ответ.** Нельзя. `Shape` содержит чисто виртуальный метод `area()`
и является абстрактным классом. Компилятор не даст создать экземпляр —
он описывает только интерфейс.

**Задание 3.** Чем абстрактный класс отличается от обычного
с виртуальными методами?

**Ответ.** У обычного класса все виртуальные методы имеют реализацию,
и его экземпляр можно создать. У абстрактного есть хотя бы один
чисто виртуальный метод (`= 0`), и экземпляр создать нельзя.