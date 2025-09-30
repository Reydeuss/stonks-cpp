#include <cstdlib>

#include "Card.hpp"

Card::Card() {
    int factor = std::rand() % 10;
    this->up = factor * 1000;
    this->down = factor * 1000;
}
