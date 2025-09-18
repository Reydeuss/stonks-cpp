#include <iostream>
#include <vector>
#include <format>
#include <string>
#include <cstdlib>

#include "Stock.h"

#define STOCK_NUM 4
#define RAND_SEED 42

void clear_screen() {
	std::system("clear");
}

class Card {
	public:
		int up;
		int down;

		Card () {
			int factor = std::rand() % 10;
			this->up = factor * 1000;
			this->down = factor * 1000;
		}
};

class Player {
	public:
		int cash;
		std::vector<Stock> portfolio;
		std::vector<Card> cards;
		std::string name;

		Player () {
			const auto default_cash = 50000;
			this->cash = default_cash;
			this->name = std::string("");
			this->cards.resize(7);
			this->portfolio = get_default_stocks();
		}

		Player (int cash, std::string name) {
			this->cash = cash;
			this->name = name;
			this->cards.resize(7);
			this->portfolio = get_default_stocks();
		}

		Player (std::string name) {
			const auto default_cash = 50000;
			this->cash = default_cash;
			this->name = name;
			this->cards.resize(7);
			this->portfolio = get_default_stocks();
		}

		void set_name(std::string s) {
			this->name = s;
		}

		void show_menu(const std::vector<Stock>& chart) {
			int option_num, lots;
			std::string buy_code;

			std::cout << "===============" << std::endl;
			std::cout << "STONK City Stock Exchange" << std::endl;
			for (auto& stock : chart) {
				std::cout << stock.code << " " << stock.price << std::endl;
			}

			std::cout << "===============" << std::endl;
			std::cout << "Name: " << this->name << std::endl;
			std::cout << "Options: " << std::endl;
			std::cout << "1. Buy Stock" << std::endl;
			std::cout << "2. Sell Stock" << std::endl;
			std::cout << "3. View Cards" << std::endl;
			std::cout << "4. Play Card" << std::endl;

			while (true) {
				std::cout << "Enter option: ";
				std::cin >> option_num;
				std::cin.ignore();

				switch (option_num) {
					case 1:
						std::cout << "Type stock code: ";
						std::cin >> buy_code;
						std::cin.ignore();

						std::cout << "Enter lots: ";
						std::cin >> lots;
						std::cin.ignore();

						break;

					case 3:
						std::cout << "Cards:" << std::endl;
						this->display_cards();
						continue;

					default:
						std::cout << "Sorry, the game is incomplete yet and the dev is lazy." << std::endl;
						continue;
				}
			}
		}

		void display_cards() {
			for (const auto& card : this->cards) {
				const std::string card_str = std::format(
					"[Up: {} | Down: {}]", card.up, card.down
				);

				std::cout << card_str << std::endl;
			}
		}
};

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
