// 1.5. Перегрузка операторов
// operator+ и operator== — члены класса (левый операнд — Point).
// operator<< — свободная функция (левый операнд — std::ostream).

#include <iostream>

struct Point {
    int x, y;

    Point operator+(const Point& o) const { return {x + o.x, y + o.y}; }
    Point operator*(int k)          const { return {x * k, y * k}; }
    bool  operator==(const Point& o) const { return x == o.x && y == o.y; }
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << "(" << p.x << "," << p.y << ")";
}

int main() {
    Point a{1, 2}, b{3, 4};
    std::cout << "a + b  = " << (a + b) << "\n";
    std::cout << "a * 3  = " << (a * 3) << "\n";
    std::cout << "a == b = " << (a == b) << "\n";
    std::cout << "a == a = " << (a == a) << "\n";
}