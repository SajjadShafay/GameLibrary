#ifndef _GAME_H_
#define _GAME_H_
#include <string> 

class game 
{
private:
	std::string game_name; 
	std::string game_status; 
	std::string game_ownership; 
public: 
	game(std::string name, std::string status, std::string own); 
	
	std::string get_name() const {return game_name;}
	void set_name(std::string name) {this->game_name = name;} 
	
	std::string get_status() const {return game_status;} 
	void set_status(std::string status) {this->game_status = status;}
	
	std::string get_ownership() const {return game_ownership;}
	void set_ownership(std::string ownership) {this->game_ownership = ownership;}
};

#endif