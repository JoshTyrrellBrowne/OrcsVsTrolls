#include <iostream>
#include <string>
#include "Classes.h"


std::string getSide(int t_side);          // returns the side which the player is playing with

int main(void)
{
	int sideSelection = 0;
	int meleeSpell;

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

	std::cout << "\n\n========================================================================================================================" << std::endl;

	std::cout << "Your gang of " + getSide(sideSelection) + " are storming the village." << std::endl;
	std::cout << orcOne.getName() + " is attacking " + trollOne.getName() + "! \nShould he 1: Melee Attack or 2: Spell Attack ?" << std::endl;
	std::cin >> meleeSpell;

	if (meleeSpell == 1)
	{
		if (orcOne.getMeleeNum() > 0)
		{
			trollOne.meleeDamage();
			trollOne.meleeDamageOutput();
			orcOne.meleeUsed();
		}
		else
		{
			std::cout << orcOne.getName() + " does not have enough strength left for a melee attack and so he recieves a melee attack." << std::endl;
			orcOne.meleeDamage();
			orcOne.meleeDamageOutput();
		}
	}

	if (meleeSpell == 2)
	{
		if (orcOne.getSpellsNum() > 0)
		{
			trollOne.spellDamage();
			trollOne.spellDamageOutput();
			orcOne.spellUsed();
		}
		else
		{
			std::cout << orcOne.getName() + " does not have enough magic left for a spell attack and so he recieves a spell attack." << std::endl;
			orcOne.spellDamage();
		}
	}

	system("pause");
}




std::string getSide(int t_side)
{
	std::string sideString;
	if (t_side == 1)
	{
		sideString = "Orc's";
	}
	else
	{
		sideString = "Troll's";
	}

	return sideString;
}
