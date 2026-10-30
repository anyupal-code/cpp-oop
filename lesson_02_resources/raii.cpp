// 2.1. RAII
// Ресурс захватывается в конструкторе, освобождается в деструкторе.
// Деструктор сработает при любом выходе из блока, включая исключение.

#include <cstdio>
#include <iostream>
#include <stdexcept>

class File {
    std::FILE* f_ = nullptr;
public:
    explicit File(const char* path) : f_(std::fopen(path, "w")) {
        if (!f_) throw std::runtime_error("cannot open file");
        std::cout << "File opened: " << path << "\n";
    }
    ~File() {
        if (f_) {
            std::fclose(f_);
            std::cout << "File closed\n";
        }
    }
    std::FILE* get() const { return f_; }
};

void writeLine(const char* path) {
    File f(path);
    std::fputs("hello\n", f.get());
}   // File::~File закроет файл

int main() {
    writeLine("raii_demo.txt");
    std::cout << "-- done --\n";
}