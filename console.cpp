#include "console.h"
#include <iostream>
#include <fstream>
#include <sstream>

console::console (std::string console_name)
{
	load(console_name); 
}

bool console::add_game (std::string name, std::string status, std::string ownership)
{
	for (auto const &c: my_games)
		if (c.get_name() == name)
			return false; 
	
	game new_game(name, status, ownership); 
	my_games.push_back(new_game); 
	return true; 
}

bool console::change_name (std::string name) 
{
	for (auto &c : my_games)
		if (c.get_name() == name)
		{
			std::cout << "Please enter a new name for this game" << std::endl;
			std::string new_name{}; 
			std::cin >> new_name; 
			c.set_name(new_name); 
			return true; 
		}
	return false;
}

bool console::change_status(std::string name)
{
	for (auto &c: my_games)
		if (c.get_name() == name)
		{
			std::cout << "Please enter a new status for this game" << std::endl;
			std::string new_status {}; 
			std::cin >> new_status; 
			c.set_status(new_status);
			return true; 
		}
	return false;
}

bool console::change_ownership(std::string name)
{
	for (auto &c: my_games)
		if (c.get_name() == name)
		{
			std::cout << "Please enter a new ownership status for this game" << std::endl; 
			std::string new_ownership {}; 
			std::cin >> new_ownership; 
			c.set_ownership(new_ownership); 
			return true;
		}
	return false;
}

void console::display() const
{
	if (my_games.size() == 0)
		std::cout << "Sorry, this list is empty" << std::endl;
	else 
		for (auto const &c: my_games)
			std::cout << c.get_name() << ", " << c.get_status() << ", " << c.get_ownership() << std::endl;
}

void console::save(std::string console_name) const
{
	std::string filename{}; 
	
	if (console_name == "ps5") 
		filename = "ps5.txt"; 
	else if (console_name == "xbox") 
		filename = "xbox.txt"; 
	else if (console_name == "switch")
		filename = "switch.txt"; 
	else if (console_name == "pc") 
		filename = "pc.txt";  
	
	std::ofstream MyFile{filename}; 

	if (MyFile)
	{
		for (auto const &c : my_games)
			MyFile << c.get_name() << "," << c.get_status() << "," << c.get_ownership() << "\n"; 
		MyFile.close(); 
	}
	else
	{
		std::cerr << "Error saving data to file." << std::endl;
	}
}

void console::load(std::string console_name)
{
	std::string filename{}; 
	
	if (console_name == "ps5") 
		filename = "ps5.txt"; 
	else if (console_name == "xbox") 
		filename = "xbox.txt"; 
	else if (console_name == "switch")
		filename = "switch.txt"; 
	else if (console_name == "pc") 
		filename = "pc.txt";  
	
	std::ifstream MyFile{filename}; 
	
	if (MyFile)
	{
		std::string line; 
		while (std::getline(MyFile, line))
		{
			std::stringstream ss(line);
			std::string name, status, owner; 
			std::getline(ss, name, ','); 
			std::getline(ss, status, ','); 
			std::getline(ss, owner, ','); 
			add_game(name, status, owner); 
		}
		MyFile.close();
	}
	else
	{
		std::cerr << "Error loading data from file." << std::endl;
	}
}
