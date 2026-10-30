#include "audiobook.h"

AudioBook::AudioBook(std::string title, std::string author, int year, int minutes)
    : title_(std::move(title)), author_(std::move(author)),
      year_(year), minutes_(minutes) {}

std::string AudioBook::title()  const { return title_;  }
std::string AudioBook::author() const { return author_; }
int         AudioBook::year()   const { return year_;   }
double      AudioBook::value()  const { return minutes_ * 0.05; }