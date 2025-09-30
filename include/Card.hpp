#pragma once

#include <utility>

using PriceType = std::pair<int, int>;

class Card {
	private:
    int up;
    int down;

	public:
    PriceType get_price_modifiers();

		Card ();
};
