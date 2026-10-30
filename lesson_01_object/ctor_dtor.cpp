// 1.3. Конструктор и деструктор
// Конструктор вызывается при создании, деструктор — при уничтожении.

#include <iostream>

class Point {
    int x, y;
public:
    Point()               : x(0), y(0) { std::cout << "Point()\n"; }
    Point(int x_, int y_) : x(x_), y(y_){ std::cout << "Point(" << x << "," << y << ")\n"; }
    ~Point()                            { std::cout << "~Point(" << x << "," << y << ")\n"; }
};

int main() {
    std::cout << "-- begin --\n";
    {
        Point a;        // Point()
        Point b{1, 2};  // Point(1,2)
    }                   // выход из блока: ~Point для b, затем для a (обратный порядок)
    std::cout << "-- end --\n";
}