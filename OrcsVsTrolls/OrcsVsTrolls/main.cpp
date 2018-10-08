#include <iostream>
#include <string>
#include "Classes.h"


std::string getSide(int t_side);          // returns the side which the player is playing with
void attacking(Orc t_orc, Troll t_troll, int t_meleeOrSpell);
void gettingAttacked(Orc t_orc, Troll t_troll, int t_meleeOrSpell);


int main(void)
{
	int sideSelection = 0;
	int meleeOrSpell = 0;

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
	
	attacking(orcOne, trollOne, meleeOrSpell);
	attacking(orcTwo, trollTwo, meleeOrSpell);
	attacking(orcThree, trollThree, meleeOrSpell);



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

void attacking(Orc t_orc, Troll t_troll, int t_meleeOrSpell)
{
	std::cout << t_orc.getName() + " is attacking " + t_troll.getName() + "! \nShould he 1: Melee Attack or 2: Spell Attack ?" << std::endl;
	std::cin >> t_meleeOrSpell;

	if (t_meleeOrSpell == 1)
	{
		if (t_orc.getMeleeNum() > 0)
		{
			t_troll.meleeDamage();
			t_troll.meleeDamageOutput();
			t_orc.meleeUsed();
		}
		else
		{
			std::cout << t_orc.getName() + " does not have enough strength left for a melee attack and so he recieves a melee attack." << std::endl;
			t_orc.meleeDamage();
			t_orc.meleeDamageOutput();
		}
	}

	if (t_meleeOrSpell == 2)
	{
		if (t_orc.getSpellsNum() > 0)
		{
			t_troll.spellDamage();
			t_troll.spellDamageOutput();
			t_orc.spellUsed();
		}
		else
		{
			std::cout << t_orc.getName() + " does not have enough magic left for a spell attack and so he recieves a spell attack." << std::endl;
			t_orc.spellDamage();
		}
	}
}


// unfinished
void gettingAttacked(Orc t_orc, Troll t_troll, int t_meleeOrSpell)
{
	std::cout << t_troll.getName() + " is attacking " + t_orc.getName() + "! \nShould he 1: Block using shield or 2: Dodge ?" << std::endl;
	std::cin >> t_meleeOrSpell;

	if (t_meleeOrSpell == 1)
	{
		if (t_troll.getMeleeNum() > 0)
		{
			
		}
		else
		{
			std::cout << t_orc.getName() + " does not have enough strength left for a melee attack and so he recieves a melee attack." << std::endl;
			t_orc.meleeDamage();
			t_orc.meleeDamageOutput();
		}
	}

	if (t_meleeOrSpell == 2)
	{
		if (t_orc.getSpellsNum() > 0)
		{
			t_troll.spellDamage();
			t_troll.spellDamageOutput();
			t_orc.spellUsed();
		}
		else
		{
			std::cout << t_orc.getName() + " does not have enough magic left for a spell attack and so he recieves a spell attack." << std::endl;
			t_orc.spellDamage();
		}
	}
}
