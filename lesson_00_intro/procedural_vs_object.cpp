// 0.1. Процедурный vs объектный подход
// Одна и та же задача — двумя способами.

#include <iostream>

// --- Процедурный: данные и функции разделены ---
struct PointP { int x, y; };

void moveP(PointP& p, int dx, int dy) { p.x += dx; p.y += dy; }
void printP(const PointP& p)          { std::cout << "(" << p.x << "," << p.y << ")\n"; }

// --- Объектный: данные и функции вместе ---
class PointO {
    int x_, y_;
public:
    PointO(int x, int y) : x_(x), y_(y) {}
    void move(int dx, int dy) { x_ += dx; y_ += dy; }
    void print() const        { std::cout << "(" << x_ << "," << y_ << ")\n"; }
};

int main() {
    PointP p{1, 2};
    moveP(p, 3, 4);
    printP(p);            // (4,6)

    PointO q{1, 2};
    q.move(3, 4);
    q.print();            // (4,6)
}