#ifndef _CONSOLE_H_
#define _CONSOLE_H_
#include <vector>
#include <fstream>
#include <string>
#include "Game.H"

class console
{
private:
	std::vector<game> my_games;
	std::string console_name; 
public:
	console(std::string console_name);
	
	bool add_game(std::string name, std::string status, std::string ownership);
	bool change_name(std::string name); 
	bool change_status(std::string name); 
	bool change_ownership(std::string name); 
	
	void display() const; 
	
	void save(std::string console_name) const;
	void load(std::string console_name); 
	
};

#endif