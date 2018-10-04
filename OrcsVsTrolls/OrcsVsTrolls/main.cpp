#include <iostream>
#include <string>
#include "Classes.h"


int main(void)
{
	int sideSelection = 0;

	Orc orcOne(std::string ("Orc Josh"));
	Orc orcTwo(std::string("Orc Steve"));
	Orc orcThree(std::string("Orc Mike"));

	Troll trollOne(std::string("Troll Sam"));
	Troll trollTwo(std::string("Troll Frank"));
	Troll trollThree(std::string("Troll Luke"));


	std::cout << orcOne.getHeath() << std::endl;




	std::cout << "Welcome to the game of 'Orcs Vs Trolls'. This game tells the tale of a small village west of Mordor and how a gang \nof Orc's had a brutal battle with a gang of Troll's. They fought for control of the village because there was mines \nrich with ore located there. How will this battle unfold? You must decide." << std::endl;
	std::cout << "You will have control of one side of this battle." << std::endl;
	std::cout << "Enter 1 to choose to play as the Orc's, or 2 to choose the Troll's." << std::endl;

	std::cin >> sideSelection;

	if (sideSelection == 1)
	{
		std::cout << "You have choosen the Orc's." << std::endl;
	}
	else if (sideSelection == 2)
	{
		std::cout << "You have choosen the Troll's." << std::endl;
	}



	system("pause");
}