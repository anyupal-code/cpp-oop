// 1.1. struct vs class
// Единственное техническое отличие — уровень доступа по умолчанию.

#include <iostream>

struct PointStruct {
    int x, y;              // public по умолчанию
};

class PointClass {
    int x, y;              // private по умолчанию
public:
    PointClass(int x_, int y_) : x(x_), y(y_) {}
    int getX() const { return x; }
    int getY() const { return y; }
};

int main() {
    PointStruct s{1, 2};
    s.x = 10;              // OK: public

    PointClass c{3, 4};
    // c.x = 10;           // ошибка компиляции: private
    std::cout << "struct: " << s.x << "," << s.y << "\n";
    std::cout << "class : " << c.getX() << "," << c.getY() << "\n";
}