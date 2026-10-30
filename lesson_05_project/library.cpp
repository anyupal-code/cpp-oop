#include "library.h"

#include <iostream>
#include <typeinfo>

void Library::add(std::unique_ptr<Item> item) {
    items_.push_back(std::move(item));
}

void Library::printAll() const {
    for (const auto& it : items_)
        std::cout << "[" << typeid(*it).name() << "] "
                  << it->title()  << " — "
                  << it->author() << " ("
                  << it->year()   << ")\n";
}

double Library::totalValue() const {
    double sum = 0;
    for (const auto& it : items_) sum += it->value();
    return sum;
}

std::vector<const Item*> Library::findByAuthor(const std::string& author) const {
    std::vector<const Item*> out;
    for (const auto& it : items_)
        if (it->author() == author) out.push_back(it.get());
    return out;
}