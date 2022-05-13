#include <string>
#pragma once

class Item
{
public:
	std::string Name;
	double Price;

	Item();
	Item(std::string name, double price);
};

