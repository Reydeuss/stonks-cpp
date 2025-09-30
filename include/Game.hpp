#pragma once

#include <vector>

#include "Stock.hpp"
#include "Player.hpp"

class Game {
	public:
		int player_num;
		std::vector<Stock> chart;
		std::vector<Player> players;

		Game ();

		void init();
		void loop();
		void run();
};
