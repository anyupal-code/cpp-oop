// 0.2. Класс и объект
// Класс — чертёж. Объекты — независимые экземпляры.

#include <iostream>

class Point {
    int x_, y_;
public:
    Point(int x, int y) : x_(x), y_(y) {}
    void move(int dx, int dy) { x_ += dx; y_ += dy; }
    int x() const { return x_; }
    int y() const { return y_; }
};

int main() {
    Point a{1, 2};
    Point b{1, 2};

    a.move(10, 10);

    std::cout << "a = (" << a.x() << "," << a.y() << ")\n"; // (11,12)
    std::cout << "b = (" << b.x() << "," << b.y() << ")\n"; // (1,2) — не изменился
}