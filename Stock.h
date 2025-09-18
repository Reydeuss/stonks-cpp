#pragma once

#include <vector>

struct Stock {
	std::string code;
	int price;
};

std::vector<Stock> get_default_stocks();
