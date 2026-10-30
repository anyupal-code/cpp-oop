// 2.2. Правило трёх / пяти
// Класс владеет массивом в куче: нужны свои деструктор, копирование
// и присваивание (правило трёх). Перемещение — по желанию (правило пяти).

#include <algorithm>
#include <cstddef>
#include <iostream>

class Buffer {
    int* data_ = nullptr;
    std::size_t size_ = 0;
public:
    explicit Buffer(std::size_t n) : data_(new int[n]()), size_(n) {
        std::cout << "Buffer(" << n << ")\n";
    }

    ~Buffer() {                                    // 1. деструктор
        delete[] data_;
        std::cout << "~Buffer\n";
    }

    Buffer(const Buffer& o)                        // 2. копирование
        : data_(new int[o.size_]), size_(o.size_) {
        std::copy(o.data_, o.data_ + size_, data_);
        std::cout << "Buffer copy\n";
    }

    Buffer& operator=(const Buffer& o) {           // 3. присваивание
        if (this != &o) {
            delete[] data_;
            size_ = o.size_;
            data_ = new int[size_];
            std::copy(o.data_, o.data_ + size_, data_);
        }
        std::cout << "Buffer copy-assign\n";
        return *this;
    }

    std::size_t size() const { return size_; }
};

int main() {
    Buffer a(3);
    Buffer b = a;      // копирование
    b = a;             // присваивание
    std::cout << "b.size = " << b.size() << "\n";
}