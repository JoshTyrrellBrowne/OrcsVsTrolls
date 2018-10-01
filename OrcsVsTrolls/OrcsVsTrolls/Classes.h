#pragma once


#include <iostream>

//using namespace std;

class Character {
public:
	void flip() { std::cout << "I know how to flip and I will flipping do it" << std::endl; }
	virtual void walk() { std::cout << "just in case they are too young to walk yet" << std::endl; }
	virtual void fly() = 0; //pure virtual function
};

class Orc : public Character {
public:
	std::string name = "";

	void barrelRoll() { std::cout << "rooooooolllllllllllinggggggg" << std::endl; }
	void walk() { std::cout << "Orc is walking" << std::endl; }
	void fly() { std::cout << "Orc is flying" << std::endl; }

};

class Troll : public Character {
public:
	std::string name = "";

	void fly() { std::cout << "Troll is flying" << std::endl; }
};