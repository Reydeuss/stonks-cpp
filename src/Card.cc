#include <cstdlib>
#include <utility>

#include "Card.hpp"

Card::Card() {
    int factor = std::rand() % 10;
    this->up = factor * 1000;
    this->down = factor * 1000;
}

PriceModifierType Card::get_price_modifiers() const {
  return std::pair(this->up, this->down);
}
