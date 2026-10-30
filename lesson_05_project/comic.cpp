#include "comic.h"

Comic::Comic(std::string title, std::string author, int year, int issues)
    : title_(std::move(title)), author_(std::move(author)),
      year_(year), issues_(issues) {}

std::string Comic::title()  const { return title_;  }
std::string Comic::author() const { return author_; }
int         Comic::year()   const { return year_;   }
double      Comic::value()  const { return issues_ * 0.3; }