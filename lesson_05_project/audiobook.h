#pragma once

#include "item.h"

class AudioBook : public Item {
public:
    AudioBook(std::string title, std::string author, int year, int minutes);

    std::string title()  const override;
    std::string author() const override;
    int         year()   const override;
    double      value()  const override;

private:
    std::string title_, author_;
    int year_, minutes_;
};