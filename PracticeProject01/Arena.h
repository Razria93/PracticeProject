#pragma once

#include "Monster.h"

struct Unit
{
	Monster* Unit_Monster;
	int Unit_Number; // Empty: -1
};

class Monster;

class Arena
{
public:
	Arena();

public:
	int ContainerCount;

private:
	// Container
	Unit* ContainerStart;
	int ContainerSize;
	int ContainerOffset;

public:
	void Initialize(int InContainerCount);

public:
	void Add_Monster(StatusData InStatusData);

public:
	void Print_ContainerCount();
	void Print_Monster_highestHP();
	
	void Print_Monster_StatusData(const char* InName, uint64_t InSize);
};