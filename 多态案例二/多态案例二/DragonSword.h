#pragma once
#include<iostream>
#include<string>
#include"Weapon.h"
using namespace std;

class DragonSword:public Weapon
{
public:
	DragonSword();
	// ��ȡ�����˺�
	virtual int getBeaseDamage();

	//��ȡ��Ѫ
	virtual int getSuckBlood();

	//��ȡ�Ƿ���
	virtual bool getHold();

	//��ȡ�Ƿ񱩻�
	virtual bool getCrit();

	//������ ��Ѫ�� ������
	int suckRate;
	int holdRate;
	int critRate;

	//��������Ƿ񴥷�
	bool isTrigger(int rate);
};