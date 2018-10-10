#pragma once


#include <iostream>
#include <string>


class Character {
public:
	void flip() { std::cout << "I know how to flip and I will flipping do it" << std::endl; }
	virtual void walk() { std::cout << "just in case they are too young to walk yet" << std::endl; }
	virtual void fly() = 0; //pure virtual function

	void virtual setName(std::string t_name);
	int getHeath();
	int getSpellsNum();
	int getMeleeNum();
	int getSheildNum();
	int getDodgeNum();
	std::string getName();

	void meleeDamage();   // char takes damage
	void meleeUsed();	// char used melee
	void spellDamage();
	void spellUsed();

	void shieldUse();
	void dodgeUse();

	void kill();

private:
	std::string m_name = "";
	int m_health{ 100 };
	int m_spellsNum{ 3 };
	int m_meleeNum{ 5 };
	int m_shieldNum{ 3 };
	int m_dodgeNum{ 2 };
	bool alive{ true };
};

class Orc : public Character {
public:
	Orc(std::string t_name);

	void fly() { std::cout << "Orc is flying" << std::endl; }

private:
	
};

class Troll : public Character {
public:
	Troll(std::string t_name);

	void fly() { std::cout << "Troll is flying" << std::endl; }

private:

};