// 1.4. Передача по ссылке и копирование
// Копия не меняет исходный объект; ссылка — меняет.
// const-ссылка даёт чтение без копирования.

#include <iostream>

struct Point { int x, y; };

void scaleCopy(Point p, int k) { p.x *= k; p.y *= k; }        // по значению: копия
void scaleRef (Point& p, int k) { p.x *= k; p.y *= k; }       // по ссылке: оригинал
void print    (const Point& p) { std::cout << "(" << p.x << "," << p.y << ")\n"; }

int main() {
    Point a{1, 2};
    print(a);

    scaleCopy(a, 10);
    print(a);   // не изменился

    scaleRef(a, 10);
    print(a);   // изменился
}