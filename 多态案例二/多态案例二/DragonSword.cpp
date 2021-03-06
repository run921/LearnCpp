#include "DragonSword.h"

DragonSword::DragonSword()
{
	this->m_BaseDamage = 20;
	this->m_WeaponName = "屠龙刀";
	this->suckRate = 20;
	this->holdRate = 30;
	this->critRate = 35; 
}

int DragonSword::getBeaseDamage()
{
	return this->getBeaseDamage;
}

int DragonSword::getSuckBlood()
{
	if(isTrigger(suckRate))
	{
		return this->getBeaseDamage * 0.5;		//按照基础伤害的一半回血
	}
	return ;
}

bool DragonSword::getHold()
{
	return false;
}

bool DragonSword::getCrit()
{
	return false;
}

bool DragonSword::isTrigger(int rate)
{
	//通过isTrigger判断是否触发特效
	int num = rand() % 100 + 1;
	if (num > rate)
	{
		return true;
	}
	return false;
	
}
