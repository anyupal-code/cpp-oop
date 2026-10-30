// 2.3. Умные указатели
// unique_ptr — единоличное владение, не копируется, только перемещается.
// shared_ptr — совместное владение через счётчик ссылок.
// weak_ptr   — слабая ссылка, не увеличивает счётчик.

#include <iostream>
#include <memory>

struct Point {
    int x, y;
    Point(int x_, int y_) : x(x_), y(y_) {}
    ~Point() { std::cout << "~Point(" << x << "," << y << ")\n"; }
};

int main() {
    // unique_ptr: только перемещение
    auto u = std::make_unique<Point>(1, 2);
    // auto copy = u;                 // ошибка: не копируется
    auto moved = std::move(u);        // OK: владение перешло в moved

    // shared_ptr: счётчик ссылок
    auto s1 = std::make_shared<Point>(3, 4);
    {
        auto s2 = s1;                 // счётчик = 2
        std::cout << "use_count = " << s1.use_count() << "\n";
    }                                 // счётчик = 1
    std::cout << "use_count = " << s1.use_count() << "\n";

    // weak_ptr: не владеет, не увеличивает счётчик
    std::weak_ptr<Point> w = s1;
    std::cout << "use_count after weak = " << s1.use_count() << "\n";
}