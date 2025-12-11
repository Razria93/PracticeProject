#include "Monster.h"
#include <iostream>

Monster::Monster()
{
	initialize();
}

void Monster::initialize()
{
	Lifepoint = 50.f;
	Attack = 10.f;
	Defense = 5.f;
	atrribute = Attribute::Fire;
}

void Monster::Set_Name(const char* InName)
{
	if (sizeof(InName) > MAX_NAME_LENGTH - 1)
	{
		printf("InName Length is too long (max: %d)\n", MAX_NAME_LENGTH - 1);
		return;
	}

	int i = 0;

	for (i = 0; i < sizeof(InName); i++)
	{
		Name[i] = InName[i];
		// printf("InName(%d): %c\n",i, InName[i]);
	}

	if (i <= MAX_NAME_LENGTH)
		Name[i] = '\0';

	// printf("Name:%s\n", Name);
}

void Monster::SendDamage(Monster* InTarget)
{
	if (InTarget == nullptr)
	{
		printf("InTarget is Invalid\n");
		return;
	}

	float damage = (this->Attack) - (InTarget->Defense);

	InTarget->TakeDamage(damage);
}

void Monster::TakeDamage(float InDamagePoint)
{
	if (Lifepoint < 0.f)
	{
		printf("Not Enoungh LifePoint\n");
		return;
	}

	Lifepoint -= InDamagePoint;

	if (Lifepoint < 0.f)
	{
		Lifepoint = 0.f;

		printf("LifePoint is zero\n");
		return;
	}
}
