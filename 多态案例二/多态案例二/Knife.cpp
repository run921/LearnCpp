#include"Knife.h"

Knife::Knife()
{
	this->m_BaseDamage = 10;
	this->m_WeaponName = "ะกตถ";
}

int Knife::getBeaseDamage()
{
	return this->m_BaseDamage;
}

int Knife::getSuckBlood()
{
	return 0;
}

bool Knife::getHold()
{
	return false;
}

bool Knife::getCrit()
{
	return false;
}
