#pragma once

#include <vector>

#include "Stock.hpp"
#include "Player.hpp"

class Game {
  private:
    int player_num;
	  std::vector<Stock> chart;
	  std::vector<Player> players;

  public:
    Game ();

    void init();
    void loop();
    void run();
};
