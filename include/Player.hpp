#pragma once

#include <vector>
#include <string>
#include <format>

#include "Stock.hpp"
#include "Card.hpp"

class Player {
	public:
		int cash;
		std::vector<Stock> portfolio;
		std::vector<Card> cards;
		std::string name;

    Player();
		Player(int cash, std::string name);
		Player(std::string name);

		void set_name(std::string s);
		void show_menu(const std::vector<Stock>& chart);
		void display_cards();
};
