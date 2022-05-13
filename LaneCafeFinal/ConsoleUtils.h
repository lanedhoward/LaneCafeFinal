#include <string>
#pragma once
namespace ConsoleUtils
{
	void Print(std::string s);
	void Print();
	void WaitForKeyPress();
	std::string ReadString();
	int ReadInt();
	bool ReadBool();
	int GetInputInt(int min, int max);
	bool GetInputBool();
};

