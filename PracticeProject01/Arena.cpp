#include <iostream>
#include "Arena.h"
#include "Monster.h"

Arena::Arena()
{
}

void Arena::Initialize(int InContainerCount)
{
	printf("=Initialize=====\n");

	ContainerCount = 0;

	ContainerStart = new Unit[InContainerCount];
	ContainerSize = InContainerCount;
	ContainerOffset = sizeof(Unit);

	printf("ContainerStart: %p\n", ContainerStart);
	printf("ContainerSize: %d\n", ContainerSize);
	printf("ContainerOffset: %d\n", ContainerOffset);
	printf("----------------\n");

	for (int i = 0; i < ContainerSize; ++i)
	{
		Unit* temp = ContainerStart + i;

		temp->Unit_Monster = nullptr;
		temp->Unit_Number = -1;

		// printf("i: %d\n", i);
		// printf("temp: %p\n", temp);
		// printf("temp->Unit_Monster: %p\n", temp->Unit_Monster);
		// printf("temp->Unit_Number: %d\n", temp->Unit_Number);
		// printf("----------------\n");
	}

	printf("\n");
}

void Arena::Add_Monster(StatusData InStatusData)
{
	printf("=Add_Monster====\n");

	Monster* monster = new Monster;

	monster->initialize(InStatusData);

	for (int i = 0; i < ContainerSize; ++i)
	{
		Unit* temp = ContainerStart + i;

		// printf("i: %d\n", i);
		// printf("temp: %p\n", temp);
		// printf("temp->Unit_Monster: %p\n", temp->Unit_Monster);
		// printf("temp->Unit_Number: %d\n", temp->Unit_Number);
		// printf("----------------\n");

		if (temp->Unit_Number == -1)
		{
			temp->Unit_Monster = monster;
			temp->Unit_Number = i;

			++ContainerCount;

			printf("-Add_Units------\n");
			monster->Print_Name();
			printf("i: %d\n", i);
			printf("ContainerPointer: %p\n", temp);
			printf("Unit_MonsterPointer: %p\n", temp->Unit_Monster);
			printf("Unit_Number: %d\n", temp->Unit_Number);
			printf("----------------\n");

			break;
		}
	}

	printf("\n");
}

void Arena::Print_ContainerCount()
{
	printf("=Monster_Count==\n");
	printf("MonsterCount: %d\n", ContainerCount);
	printf("\n");
}

void Arena::Print_Monster_highestHP()
{
	float mostHP = FLT_MIN;
	Monster* mostHP_monster = nullptr;

	for (int i = 0; i < ContainerSize; ++i)
	{
		Unit* temp = ContainerStart + i;

		if (temp->Unit_Number != -1 && temp->Unit_Monster != nullptr)
		{
			float tempHP = temp->Unit_Monster->Get_HealthPoint();

			if (mostHP < tempHP)
			{
				mostHP = tempHP;
				mostHP_monster = temp->Unit_Monster;
			}
		}
	}

	if (mostHP != FLT_MIN && mostHP_monster != nullptr)
	{
		printf("=Monster_HighestHP=\n");
		mostHP_monster->Print_Name();
		mostHP_monster->Print_HealthPoint();
		printf("\n");
	}
}

void Arena::Print_Monster_StatusData(const char* InName, uint64_t InSize)
{
	printf("=Monster_StatusData=\n");
	for (int i = 0; i < ContainerSize; ++i)
	{
		Unit* temp = ContainerStart + i;

		if (temp->Unit_Number != -1 && temp->Unit_Monster != nullptr)
		{
			if (temp->Unit_Monster->Query_IsEqualName(InName, InSize))
			{
				temp->Unit_Monster->Print_StatusData();
				printf("\n");
				return;
			}
		}
	}

	printf("Find_Fail: %s\n", InName);
	printf("\n");
	return;
}


