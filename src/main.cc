#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include "Card.hpp"
#include "Game.hpp"
#include "Stock.hpp"
#include "Player.hpp"

#define STOCK_NUM 4
#define RAND_SEED 42

int main() {
	std::srand(RAND_SEED);

	Game game = Game();
	game.init();
	game.run();

	return 0;
}
