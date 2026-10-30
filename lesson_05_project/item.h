#pragma once

#include <string>

// Абстрактный интерфейс: всё, что лежит на полке библиотеки.
class Item {
public:
    virtual ~Item() = default;

    virtual std::string title()  const = 0;
    virtual std::string author() const = 0;
    virtual int         year()   const = 0;
    virtual double      value()  const = 0;
};