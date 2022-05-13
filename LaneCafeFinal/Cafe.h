#include <string>
#include <vector>
#include "Item.h"
#pragma once



class Cafe
{
public:
	std::vector<Item> m_inventory;
	std::vector<Item> m_cart;

	Cafe();

	void Run();


	void InitializeInventory();
	void ShowInventory();
	void ShowCart();
	
	void BuyStage();
	void Buy(int index);

	void CheckoutStage();
	int AddCash();
	double GiveChange(double change);

	double RoundToHundredths(double input);
};

