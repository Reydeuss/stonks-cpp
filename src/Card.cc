#include <cstdlib>

#include "Card.h"

Card::Card() {
    int factor = std::rand() % 10;
    this->up = factor * 1000;
    this->down = factor * 1000;
}
