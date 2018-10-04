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

std::string Character::getName()
{
	return m_name;
}


