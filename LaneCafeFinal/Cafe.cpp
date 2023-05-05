#include "Cafe.h"
#include "ConsoleUtils.h"
#include <math.h>
#pragma once

using namespace ConsoleUtils;

Cafe::Cafe()
{
	InitializeInventory();
}

void Cafe::InitializeInventory()
{
	m_inventory.push_back(Item("Mocha Coffee", 4.99));
	m_inventory.push_back(Item("Caramel Coffee", 4.99));
	m_inventory.push_back(Item("Black Coffee", 3.49));
	m_inventory.push_back(Item("Glazed Donut", 1.49));
	m_inventory.push_back(Item("Specialty Donut", 1.99));
}

void Cafe::ShowInventory()
{
	if (!m_inventory.empty())
	{
		for (size_t i = 0; i < m_inventory.size(); i++)
		{
			Item temp = m_inventory[i];

			Print(std::to_string(i + 1) + ".  " + temp.Name + "  -  " + std::to_string(temp.Price));

		}
	}
}

void Cafe::ShowCart()
{
	if (!m_cart.empty())
	{
		for (size_t i = 0; i < m_cart.size(); i++)
		{
			Item temp = m_cart[i];

			Print(std::to_string(i + 1) + ".  " + temp.Name + "  -  " + std::to_string(temp.Price));

		}
	}
}

void Cafe::Run()
{
	//display inventory, get input
	Print("Welcome to the Cafe!");
	
	BuyStage();
	CheckoutStage();
}

void Cafe::BuyStage()
{
	Print("Here's what we have.");

	ShowInventory();

	Print("What would you like to buy?");
	int ind = GetInputInt(1, m_inventory.size()) - 1;
	Buy(ind);

	Print("Would you like to make another purchase?");

	if (GetInputBool())
	{
		BuyStage();
	}

	

}

void Cafe::Buy(int index)
{
	Item temp = m_inventory[index];

	m_cart.push_back(Item(temp.Name, temp.Price));

	Print("Added " + temp.Name + " to cart.");
}

void Cafe::CheckoutStage()
{
	Print("Here's your cart: ");
	ShowCart();

	double total = 0;
	double payment = 0;

	for (size_t i = 0; i < m_cart.size(); i++)
	{
		total += m_cart[i].Price;
	}

	Print("Subtotal: " + std::to_string(total));
	
	
	double tax = RoundToHundredths(total * 0.07);
	Print("7% tax: " + std::to_string(tax));
	total += tax; 
	

	Print("Total: " + std::to_string(total));

	Print("Add cash in dollar bill values: ");
	
	while (payment < total)
	{
		int k = AddCash();
		payment += k;
		Print("-$" + std::to_string(k) + ", remaining balance: $" + std::to_string(total - payment));
	}

	double change = RoundToHundredths(payment - total);
	Print("Change: $" + std::to_string(change));
	GiveChange(change);

	Print("Thanks for shopping with us! ");

}

int Cafe::AddCash()
{
	int c = GetInputInt(1, 100);
	if (c == 1 || c == 2 || c == 5 || c == 10 || c == 20 || c == 50 || c == 100)
	{
		return c;
	}
	else
	{
		Print("[Error: input a dollar bill value.]");
		return AddCash();
	}
}

double Cafe::GiveChange(double change)
{
	if (change <= 0) return 0;


	if (change >= 100)
	{
		change -= 100;
		Print("+$100");
	}
	else if (change >= 50)
	{
		change -= 50;
		Print("+$50");
	}
	else if (change >= 20)
	{
		change -= 20;
		Print("+$20");
	}
	else if (change >= 10)
	{
		change -= 10;
		Print("+$10");
	}
	else if (change >= 5)
	{
		change -= 5;
		Print("+$5");
	}
	else if (change >= 2)
	{
		change -= 2;
		Print("+$2");
	}
	else if (change >= 1)
	{
		change -= 1;
		Print("+$1");
	}
	else if (change >= 0.25)
	{
		change -= 0.25;
		Print("+$0.25");
	}
	else if (change >= 0.1)
	{
		change -= 0.1;
		Print("+$0.10");
	}
	else if (change >= 0.05)
	{
		change -= 0.05;
		Print("+$0.05");
	}
	else if (change >= 0.01)
	{
		change -= 0.01;
		Print("+$0.01");
	}
	Print("Change: $" + std::to_string(change));

	if (change > 0)
	{
		return GiveChange(RoundToHundredths(change));
	}
	else
	{
		return RoundToHundredths(change);
	}
}

double Cafe::RoundToHundredths(double input)
{
	// help from http://faculty.salisbury.edu/~dxdefino/roundoff.htm#:~:text=To%20round%20to%20nearest%20hundredth%3A&text=Ex%3A%20moneyValue%20%3D%20floor(floatValue,is%20now%20stored%20as%208.12.
	return floor(input * 100 + 0.5) / 100;
}