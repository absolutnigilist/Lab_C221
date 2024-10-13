#include "Sort.h"

bool Author(const book& b1, const book& b2) {
    return std::tie(b1.get_author(), b1.get_title(), b1.get_year()) <
        std::tie(b2.get_author(), b2.get_title(), b2.get_year());
};

bool Title(const book& b1, const book& b2) {
    return std::tie(b1.get_title(), b1.get_author(), b1.get_year()) <
        std::tie(b2.get_title(), b2.get_author(), b2.get_year());
};

bool Year(const book& b1, const book& b2) {
    return std::tie(b1.get_year(), b1.get_author(), b1.get_title()) <
        std::tie(b2.get_year(), b2.get_author(), b2.get_title());
};

std::vector<std::function<bool(const book&, const book&)>>comparators = { Author,Title, Year };
