#pragma once

struct PriceModifierType {
  int up;
  int down;

  PriceModifierType(int u, int d)
    : up(u), down(d) {};
};

class Card {
	private:
    int up;
    int down;

	public:
    PriceModifierType get_price_modifiers() const;

		Card ();
};
