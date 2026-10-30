# Урок 01. Объект — задания и ответы

---

## 1.1. `struct` и `class`

**Задание 1.** Опишите `struct Date { int day, month, year; }` и создайте
переменную. Убедитесь, что поля доступны напрямую.

**Ответ.**

```cpp
struct Date { int day, month, year; };

int main() {
    Date d{1, 1, 2025};
    d.day = 15;   // OK: public по умолчанию
}
```

**Задание 2.** Перепишите `Date` как `class`. Сделайте поля `private`,
добавьте конструктор и геттеры. Убедитесь, что прямой доступ `d.day`
больше не компилируется.

**Ответ.**

```cpp
class Date {
    int day_, month_, year_;
public:
    Date(int d, int m, int y) : day_(d), month_(m), year_(y) {}
    int day()   const { return day_; }
    int month() const { return month_; }
    int year()  const { return year_; }
};

int main() {
    Date d{1, 1, 2025};
    // d.day_ = 15;   // ошибка: private
    int x = d.day();  // OK: геттер
}
```

**Задание 3.** Сформулируйте одним предложением: когда выбирать
`struct`, а когда `class`.

**Ответ.** `struct` — для пассивных наборов данных без инвариантов;
`class` — когда есть логика, валидация или внутреннее состояние,
которое нужно защищать.

---

## 1.2. Инкапсуляция

**Задание 1.** Реализуйте класс `Temperature` с полем `double celsius`
(`private`). Добавьте `setCelsius(double)` с проверкой (не ниже
абсолютного нуля −273.15), `getCelsius()` и `getFahrenheit()`,
возвращающий `celsius * 9 / 5 + 32`.

**Ответ.**

```cpp
#include <stdexcept>

class Temperature {
    double celsius_ = 0;
public:
    void setCelsius(double c) {
        if (c < -273.15) throw std::invalid_argument("below absolute zero");
        celsius_ = c;
    }
    double getCelsius()    const { return celsius_; }
    double getFahrenheit() const { return celsius_ * 9.0 / 5.0 + 32.0; }
};
```

**Задание 2.** Почему сеттер с валидацией лучше, чем публичное поле?

**Ответ.** Публичное поле можно выставить в любое значение, включая
некорректное — инвариант класса нарушится, и ошибка всплывёт далеко
от места, где её допустили. Сеттер проверяет значение в одной точке
и гарантирует, что объект всегда в допустимом состоянии.

---

## 1.3. Конструктор и деструктор

**Задание 1.** Добавьте в класс `Point` конструктор по умолчанию
(`{0, 0}`), конструктор с двумя аргументами и деструктор, печатающий
`"Point destroyed"`.

**Ответ.**

```cpp
#include <iostream>

class Point {
    int x_, y_;
public:
    Point()               : x_(0), y_(0) {}
    Point(int x, int y)   : x_(x), y_(y) {}
    ~Point() { std::cout << "Point destroyed\n"; }
};
```

**Задание 2.** Создайте объект в блоке `{ }`. Убедитесь, что деструктор
сработал при выходе из блока.

**Ответ.**

```cpp
int main() {
    {
        Point p{1, 2};
    }   // здесь печатается "Point destroyed"
}
```

**Задание 3.** Что произойдёт, если создать `Point` через `new`,
но не вызвать `delete`?

**Ответ.** Деструктор не вызовется — утечка памяти. Объект останется
жить до конца программы (или до `delete`, которого нет). Это одна из
причин, почему в C++ предпочитают стек и умные указатели.

---

## 1.4. Передача по ссылке и копирование

**Задание 1.** Напишите две функции: `void scaleCopy(Point p, int k)` —
передача по значению, `void scaleRef(Point& p, int k)` — передача по
ссылке. Вызовите обе и проверьте, изменился ли исходный объект.

**Ответ.**

```cpp
struct Point { int x, y; };

void scaleCopy(Point p, int k) { p.x *= k; p.y *= k; }   // копия
void scaleRef (Point& p, int k) { p.x *= k; p.y *= k; }  // оригинал

int main() {
    Point a{1, 2};
    scaleCopy(a, 10);   // a остался {1, 2}
    scaleRef(a, 10);    // a стал {10, 20}
}
```

**Задание 2.** Напишите `void print(const Point& p)` и объясните,
зачем `const`.

**Ответ.**

```cpp
void print(const Point& p) { std::cout << p.x << "," << p.y << "\n"; }
```

`const` запрещает функции менять объект и позволяет передавать
`const`-объекты и временные значения. Без `const` вызов `print` от
`const Point&` не скомпилируется.

---

## 1.5. Перегрузка операторов

**Задание 1.** Для `Point` перегрузите `operator+`, `operator==`
и `operator<<`.

**Ответ.**

```cpp
#include <iostream>

struct Point {
    int x, y;

    Point operator+(const Point& o) const { return {x + o.x, y + o.y}; }
    bool  operator==(const Point& o) const { return x == o.x && y == o.y; }
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << "(" << p.x << "," << p.y << ")";
}
```

**Задание 2.** Почему `operator<<` обычно пишут свободной функцией,
а не членом класса?

**Ответ.** Потому что левый операнд `<<` — это `std::ostream`, а не
`Point`. Если бы оператор был членом `Point`, вызов выглядел бы как
`p << std::cout`, что противоречит привычной записи `std::cout << p`.

**Задание 3.** Перегрузите `operator*` для умножения точки на скаляр.

**Ответ.**

```cpp
Point operator*(int k) const { return {x * k, y * k}; }
```

Вызов: `Point b = a * 3;`.