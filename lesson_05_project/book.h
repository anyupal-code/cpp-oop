#pragma once

#include "item.h"

class Book : public Item {
public:
    Book(std::string title, std::string author, int year, int pages);

    std::string title()  const override;
    std::string author() const override;
    int         year()   const override;
    double      value()  const override;

private:
    std::string title_, author_;
    int year_, pages_;
};