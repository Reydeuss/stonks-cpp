#pragma once

#include <vector>

#include "Stock.h"
#include "Player.h"

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
