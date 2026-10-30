#pragma once

#include "item.h"

#include <memory>
#include <string>
#include <vector>

class Library {
public:
    void add(std::unique_ptr<Item> item);

    void   printAll()   const;
    double totalValue() const;

    std::vector<const Item*> findByAuthor(const std::string& author) const;

    template <class T>
    int countByType() const;

private:
    std::vector<std::unique_ptr<Item>> items_;
};

// Шаблонный метод — определяем в заголовке, иначе он не инстанцируется
// в единице трансляции, где используется.
template <class T>
int Library::countByType() const {
    int n = 0;
    for (const auto& it : items_)
        if (dynamic_cast<const T*>(it.get())) ++n;
    return n;
}