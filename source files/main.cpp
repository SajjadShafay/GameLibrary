#include "console.h"
#include <string>
#include <iostream> 
#include <stdlib.h>

void mainMenu(); 
void consoleMenu (std::string console_name); 
void actionMenu(); 
void addgame(console curr_console); 

int main() 
{
	std::string ps5 {"ps5"}, xbox {"xbox"}, nswitch {"switch"}, pc {"pc"}; 
	
	while (true)
	{
		mainMenu(); 
		char mainChoice{}; 
		std::cin >> mainChoice; 
		
		//MAIN MENU
		switch (mainChoice)
		{
			case 'a': 
			case 'A': 
			{
				consoleMenu(ps5);
				console new_console(ps5); 
				char consoleChoice{}; 
				std::cin >> consoleChoice; 
				//CONSOLE SUBMENU
				switch(consoleChoice)
				{
					case 'a':
					case 'A':
					{
						addgame(new_console);
						system("pause"); 
						break; 
					}
					case 'b':
					case 'B': 
					{
						std::cout << "Edit menu to be implemented" << std::endl;
						system("pause"); 
						break; 
					}
					case 'c':
					case 'C':
					{
						std::cout << "Delete option to be implemented" << std::endl;
						system("pause"); 
						break;
					}
					case 'd':
					case 'D':
					{
						 new_console.display(); 
						 system("pause"); 
						 break; 
					}
					case 'e':
					case 'E': break; 
					default: std::cout << "Invalid choice" << std::endl;
				}
				
				break;
			}
			case 'b':
			case 'B': 
			{
				consoleMenu(xbox); 
				char consoleChoice{}; 
				std::cin >> consoleChoice; 
				//CONSOLE SUBMENU
				console new_console(xbox);
				switch(consoleChoice)
				{
					case 'a':
					case 'A':
					{
						addgame(new_console);
						system("pause"); 
						break; 
					}
					case 'b':
					case 'B': 
					{
						std::cout << "Edit menu to be implemented" << std::endl;
						system("pause"); 
						break; 
					}
					case 'c':
					case 'C':
					{
						std::cout << "Delete option to be implemented" << std::endl;
						system("pause"); 
						break;
					}
					case 'd':
					case 'D':
					{
						 new_console.display(); 
						 system("pause"); 
						 break; 
					}
					case 'e':
					case 'E': break; 
					default: std::cout << "Invalid choice" << std::endl;
				}
				break;
			}
			case 'c':
			case 'C': 
			{
				consoleMenu (nswitch); 
				char consoleChoice{}; 
				std::cin >> consoleChoice; 
				//CONSOLE SUBMENU
				console new_console(nswitch);
				switch(consoleChoice)
				{
					case 'a':
					case 'A':
					{
						addgame(new_console);
						system("pause"); 
						break; 
					}
					case 'b':
					case 'B': 
					{
						std::cout << "Edit menu to be implemented" << std::endl;
						system("pause"); 
						break; 
					}
					case 'c':
					case 'C':
					{
						std::cout << "Delete option to be implemented" << std::endl;
						system("pause"); 
						break;
					}
					case 'd':
					case 'D':
					{
						 new_console.display(); 
						 system("pause"); 
						 break; 
					}
					case 'e':
					case 'E': break; 
					default: std::cout << "Invalid choice" << std::endl;
				}
				break;
			}
			case 'd': 
			case 'D': 
			{
				consoleMenu(pc); 
				char consoleChoice{}; 
				std::cin >> consoleChoice; 
				//CONSOLE SUBMENU
				console new_console(pc);
				switch(consoleChoice)
				{
					case 'a':
					case 'A':
					{
						addgame(new_console);
						system("pause"); 
						break; 
					}
					case 'b':
					case 'B': 
					{
						std::cout << "Edit menu to be implemented" << std::endl;
						system("pause"); 
						break; 
					}
					case 'c':
					case 'C':
					{
						std::cout << "Delete option to be implemented" << std::endl;
						system("pause"); 
						break;
					}
					case 'd':
					case 'D':
					{
						 new_console.display(); 
						 system("pause"); 
						 break; 
					}
					case 'e':
					case 'E': break; 
					default: std::cout << "Invalid choice" << std::endl;
				}
				
				break;
			}
			case 'q':
			case 'Q': 
			{
				return 0; 
			}
			default: 
				std::cout << "Invalid Choice" << std::endl;
		}
	}
	
	return 0;
}

void mainMenu()
{
	system("CLS"); 
	std::cout << "==================================" << std::endl;
	std::cout << "Game Library - Main Menu" << std::endl;
	std::cout << std::endl;
	std::cout << "A) PlayStation 5" << std::endl;
	std::cout << "B) XBox" << std::endl;
	std::cout << "C) Switch" << std::endl;
	std::cout << "D) PC" << std::endl;
	std::cout << "Q) Quit" << std::endl;
	std::cout << "==================================" << std::endl;
	std::cout << std::endl;
}

void consoleMenu(std::string console_name)
{
	system("CLS"); 
	
	std::cout << "==============================" << std::endl;
	if (console_name == "ps5") 
		std::cout << "PlayStation 5 Menu - Please select an action" << std::endl;
	else if(console_name == "xbox")
		std::cout << "XBox Menu - Please select an action" << std::endl;
	else if(console_name == "switch") 
		std::cout << "Switch Menu - Please select an action" << std::endl;
	else if(console_name == "pc") 
		std::cout << "PC Menu - Please select an action" << std::endl;
	std::cout << "==============================" << std:: endl;
	std::cout << std::endl;
	
	std::cout << "A) Add a game" << std::endl;
	std::cout << "B) Edit a game" << std::endl;
	std::cout << "C) Delete a game" << std::endl;
	std::cout << "D) Display all games" << std::endl;
	std::cout << "E) Return to main menu" << std::endl;
}

void addgame(console current_console)
{
	std::string name{}, status{}, ownership{}; 
	
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Please enter the name of the game: " << std::endl;
	std::cin >> name; 
	std::cout << "What's the status of this game? (Finished/Unfinished/Dropped)" << std::endl;
	std::cin >> status; 
	std::cout << "Do you own this game? (Owned/PS Plus/Gold)" << std::endl;
	std::cin >> ownership; 
	
	if (current_console.add_game(name, status, ownership))
	{
		std::cout << name << " was successfully added" << std::endl;
	}
	else
	{
		std::cout << "Game already exists" << std::endl;
	}
}
