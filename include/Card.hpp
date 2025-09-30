#pragma once

#include <utility>

using PriceModifierType = std::pair<int, int>;

class Card {
	private:
    int up;
    int down;

	public:
    PriceModifierType get_price_modifiers() const;

		Card ();
};
