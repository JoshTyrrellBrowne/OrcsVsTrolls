#include <iostream>
#include <string>
#include <time.h>       /* time */
#include "Classes.h"


std::string getSide(int t_side);          // returns the side which the player is playing with
void attacking(Orc *t_orc, Troll *t_troll, int t_meleeOrSpell);             // using pointers 
void defending(Orc *t_orc, Troll *t_troll, int t_shieldOrDodge);      
void checkForBattleEnd(Orc *t_orc, Troll *t_troll, bool &t_battle);        // this checks if someone has been killed

int main(void)
{
	srand(time(NULL));		// seed for rand
	int sideSelection = 0;
	int meleeOrSpell = 0;
	int shieldOrDodge = 0;
	int randVar = 0;

	bool battleOne = true;
	bool battleTwo = true;
	bool battleThree = true;

	bool gameover = false;

	Orc orcOne(std::string ("Orc Josh"));
	Orc *orcOnePointer = &orcOne;
	Orc orcTwo(std::string("Orc Steve"));
	Orc *orcTwoPointer = &orcTwo;
	Orc orcThree(std::string("Orc Mike"));
	Orc *orcThreePointer = &orcThree;

	Troll trollOne(std::string("Troll Sam"));
	Troll *trollOnePointer = &trollOne;
	Troll trollTwo(std::string("Troll Frank"));
	Troll *trollTwoPointer = &trollTwo;
	Troll trollThree(std::string("Troll Luke"));
	Troll *trollThreePointer = &trollThree;

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
	
	while (gameover == false)
	{
		if (battleOne == true)
		{
			randVar = rand() % 2 + 1;     // initialise randomiser (either attacking or defending)
			if (randVar == 1)
			{
				attacking(orcOnePointer, trollOnePointer, meleeOrSpell);
			}
			if (randVar == 2)
			{
				defending(orcOnePointer, trollOnePointer, shieldOrDodge);
			}
			checkForBattleEnd(orcOnePointer, trollOnePointer, battleOne); // check for dead characters
		}

		if (battleTwo == true)
		{
			randVar = rand() % 2 + 1;     // initialise randomiser (either attacking or defending)
			if (randVar == 1)
			{
				attacking(orcTwoPointer, trollTwoPointer, meleeOrSpell);
			}
			if (randVar == 2)
			{
				defending(orcTwoPointer, trollTwoPointer, shieldOrDodge);
			}
			checkForBattleEnd(orcTwoPointer, trollTwoPointer, battleTwo); // check for dead characters
		}

		if (battleThree == true)
		{
			randVar = rand() % 2 + 1;     // initialise randomiser (either attacking or defending)
			if (randVar == 1)
			{
				attacking(orcThreePointer, trollThreePointer, meleeOrSpell);
			}
			if (randVar == 2)
			{
				defending(orcThreePointer, trollThreePointer, shieldOrDodge);
			}
			checkForBattleEnd(orcThreePointer, trollThreePointer, battleThree); // check for dead characters
		}

		if (battleOne == false && battleTwo == false && battleThree == false)
		{
			gameover = true;
		}
	}

	std::cout << "Congratulations!!!! You have defeated the Troll army." << std::endl;


	system("pause");
}

// function used to get which side (orc or troll) the player chooses
// Note: game does not implement this decision fully yet.
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

// funtion for attacking sequence
void attacking(Orc *t_orc, Troll *t_troll, int t_meleeOrSpell)
{
	std::cout << t_orc->getName() + " is attacking " + t_troll->getName() + "! \nShould he 1: Melee Attack or 2: Spell Attack ?" << std::endl;     // need to change all (.) to (->) because we need to derefrence
	std::cin >> t_meleeOrSpell;

	if (t_meleeOrSpell == 1)    // player chooses to melee attack
	{
		if (t_orc->getMeleeNum() > 0)
		{
			t_troll->meleeDamage();
			t_orc->meleeUsed();
		}
		else
		{
			std::cout << t_orc->getName() + " does not have enough strength left for a melee attack and so he recieves a melee attack." << std::endl;
			t_orc->meleeDamage();
		}
	}

	if (t_meleeOrSpell == 2)  // player chooses to spell attack
	{
		if (t_orc->getSpellsNum() > 0)
		{
			t_troll->spellDamage();
			t_orc->spellUsed();
		}
		else
		{
			std::cout << t_orc->getName() + " does not have enough magic left for a spell attack and so he recieves a spell attack." << std::endl;
			t_orc->spellDamage();
		}
	}
}


// Function for defending sequence
void defending(Orc *t_orc, Troll *t_troll, int t_shieldOrDodge)
{
	std::cout << t_orc->getName() + " is getting attacked by " + t_troll->getName() + "! \nShould he 1: Block using shield or 2: Dodge ?" << std::endl;
	std::cin >> t_shieldOrDodge;

	if (t_shieldOrDodge == 1) // shield choosen
	{
		if (t_orc->getSheildNum() > 0)
		{
			t_orc->shieldUse();
		}
		else
		{
			std::cout << t_orc->getName() + " has taken too much damage to his shield and it is now broken,\n and so he recieves a melee attack." << std::endl;
			t_orc->meleeDamage();
		}
	}

	if (t_shieldOrDodge == 2)  // dodge choosen
	{
		if (t_orc->getDodgeNum() > 0)
		{
			t_orc->dodgeUse();
		}
		else
		{
			std::cout << t_orc->getName() + " does not currently have enough energy to successfully dodge so he recieves a spell attack." << std::endl;
			t_orc->spellDamage();
		}
	}
}

void checkForBattleEnd(Orc * t_orc, Troll * t_troll, bool &t_battle)
{
	if (t_orc->getHeath() <= 0)  // orc has no health
	{
		// orc dead
		t_orc->kill();
		t_battle = false;
	}
	if (t_troll->getHeath() <= 0)  // troll has no health
	{
		// troll dead
		t_troll->kill();
		t_battle = false;
	}
}



