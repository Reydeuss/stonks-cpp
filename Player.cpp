#include <iostream>
#include <vector>
#include <string>
#include <format>

#include "Stock.h"
#include "Player.h"
#include "Card.h"

Player::Player() {
    const auto default_cash = 50000;
    this->cash = default_cash;
    this->name = std::string("");
    this->cards.resize(7);
    this->portfolio = get_default_stocks();
}

Player::Player(int cash, std::string name) {
    this->cash = cash;
    this->name = name;
    this->cards.resize(7);
    this->portfolio = get_default_stocks();
}

Player::Player(std::string name) {
    const auto default_cash = 50000;
    this->cash = default_cash;
    this->name = name;
    this->cards.resize(7);
    this->portfolio = get_default_stocks();
}

void Player::set_name(std::string s) {
    this->name = s;
}

void Player::show_menu(const std::vector<Stock>& chart) {
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

void Player::display_cards() {
    for (const auto& card : this->cards) {
        const std::string card_str = std::format(
            "[Up: {} | Down: {}]", card.up, card.down
        );

        std::cout << card_str << std::endl;
    }
}
