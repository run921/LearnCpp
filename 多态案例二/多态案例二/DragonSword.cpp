#include "DragonSword.h"

DragonSword::DragonSword()
{
	this->m_BaseDamage = 20;
	this->m_WeaponName = "������";
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
		return this->getBeaseDamage * 0.5;		//���ջ����˺���һ���Ѫ
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
	//ͨ��isTrigger�ж��Ƿ񴥷���Ч
	int num = rand() % 100 + 1;
	if (num > rate)
	{
		return true;
	}
	return false;
	
}
