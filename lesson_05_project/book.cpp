#include "book.h"

Book::Book(std::string title, std::string author, int year, int pages)
    : title_(std::move(title)), author_(std::move(author)),
      year_(year), pages_(pages) {}

std::string Book::title()  const { return title_;  }
std::string Book::author() const { return author_; }
int         Book::year()   const { return year_;   }
double      Book::value()  const { return pages_ * 0.1; }