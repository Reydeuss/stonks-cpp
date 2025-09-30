#include <iostream>
#include <vector>

#include "Game.h"
#include "Stock.h"
#include "Player.h"

void clear_screen() {
	std::system("clear");
}

Game::Game () {
  this->chart = get_default_stocks();
}

void Game::init() {
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

void Game::loop() {
  for (auto& player : this->players) {
    clear_screen();
    player.show_menu(this->chart);
  }
}

void Game::run() {
  while (true) {
    this->loop();
  }
}
