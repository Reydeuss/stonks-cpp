#include <iostream>
#include <vector>
#include <format>
#include <string>
#include <cstdlib>

#include "Card.h"
#include "Stock.h"
#include "Player.h"

#define STOCK_NUM 4
#define RAND_SEED 42

void clear_screen() {
	std::system("clear");
}

class Game {
	public:
		int player_num;
		std::vector<Stock> chart;
		std::vector<Player> players;

		Game () {
			// this->player_num = 0;
			this->chart = get_default_stocks();
			// this->players.resize(0);
		}

		void init() {
			std::string tmp_name;

			std::cout << "Welcome to STONKS!" << std::endl;
			std::cout << "How many players are playing? " << std::endl;
			std::cin >> this->player_num;
			std::cin.ignore();

			this->players.resize(this->player_num);

			for (int i = 0; i < this->player_num; i++) {
				std::cout << "Enter name of Player " << i+1 << ": ";
				std::cin >> tmp_name;
				std::cin.ignore();

				auto player = &players[i];
				player->set_name(tmp_name);
			}
		}

		void loop() {
			for (auto& player : this->players) {
				clear_screen();
				player.show_menu(this->chart);
			}
		}

		void run() {
			while (true)
				this->loop();
		}
};

int main() {
	std::srand(RAND_SEED);

	Game game = Game();
	game.init();
	game.run();

	return 0;
}
