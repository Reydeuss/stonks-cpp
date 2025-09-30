#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include "Card.h"
#include "Game.h"
#include "Stock.h"
#include "Player.h"

#define STOCK_NUM 4
#define RAND_SEED 42

int main() {
	std::srand(RAND_SEED);

	Game game = Game();
	game.init();
	game.run();

	return 0;
}
