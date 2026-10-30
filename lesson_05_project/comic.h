#pragma once

#include "item.h"

class Comic : public Item {
public:
    Comic(std::string title, std::string author, int year, int issues);

    std::string title()  const override;
    std::string author() const override;
    int         year()   const override;
    double      value()  const override;

private:
    std::string title_, author_;
    int year_, issues_;
};