#include "Classes.h"


//------------------- Orc functions -----------------------------
Orc::Orc(std::string t_name)
{
	setName(t_name);
}



//------------- Troll functions ---------------------------------
Troll::Troll(std::string t_name)
{
	setName(t_name);
}



//---------------- Character functions ---------------------------
void Character::setName(std::string t_name)
{
	m_name = t_name;
}

int Character::getHeath()
{
	return m_health;
}

int Character::getSpellsNum()
{
	return m_spellsNum;
}

int Character::getMeleeNum()
{
	return m_meleeNum;
}

int Character::getSheildNum()
{
	return m_shieldNum;
}

int Character::getDodgeNum()
{
	return m_dodgeNum;
}

std::string Character::getName()
{
	return m_name;
}

void Character::meleeDamage()
{
	m_health = m_health - 40;
	std::cout << getName() + " has been damaged and lost 40 health.\n" << std::endl; // \n because puts a seperation between battle phases
}

void Character::spellDamage()
{
	m_health = m_health - 60;
	std::cout << getName() + " has been damaged and lost 60 health.\n" << std::endl;
}

void Character::meleeUsed()
{
	m_meleeNum--;
}

void Character::spellUsed()
{
	m_spellsNum--;
}

void Character::shieldUse()
{
	m_shieldNum--;
	std::cout << getName() + " has raised his shield and blocked the attack.\n" << std::endl;
}

void Character::dodgeUse()
{
	m_dodgeNum--;
	std::cout << getName() + " was too quick and managed to dodge the attack.\n" << std::endl;
}

void Character::kill()
{
	alive = false;
	std::cout << getName() + " has ran out of health and is now dead! R.I.P\n" << std::endl;
}




