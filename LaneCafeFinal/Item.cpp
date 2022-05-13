#include "Item.h"
#pragma once

Item::Item()
{
	Name = "Default item";
	Price = 1;
}
Item::Item(std::string name, double price)
{
	Name = name;
	Price = price;
}