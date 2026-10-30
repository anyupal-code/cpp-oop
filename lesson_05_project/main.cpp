#include "audiobook.h"
#include "book.h"
#include "comic.h"
#include "library.h"

#include <iostream>

int main() {
    Library lib;
    lib.add(std::make_unique<Book>("Война и мир", "Толстой", 1869, 1225));
    lib.add(std::make_unique<AudioBook>("Война и мир (аудио)", "Толстой", 1869, 2400));
    lib.add(std::make_unique<Comic>("Хранители", "Мур", 1987, 12));

    std::cout << "-- все издания --\n";
    lib.printAll();

    std::cout << "\n-- найдено у Толстого --\n";
    for (const Item* it : lib.findByAuthor("Толстой"))
        std::cout << it->title() << "\n";

    std::cout << "\n-- статистика --\n";
    std::cout << "total value = " << lib.totalValue() << "\n";
    std::cout << "books       = " << lib.countByType<Book>()      << "\n";
    std::cout << "audiobooks  = " << lib.countByType<AudioBook>() << "\n";
    std::cout << "comics      = " << lib.countByType<Comic>()     << "\n";
}