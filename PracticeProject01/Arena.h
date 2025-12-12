#pragma once

#include "GlobalStructure.h"

class Arena
{
public:
	Arena();
	~Arena();

public:
	int ContainerSize;
	int ContainerCount;

private:
	// Container
	Unit* ContainerStart;
	int* ContainerValidIndices;

public:
	void Initialize(int InContainerSize);

public:
	void Add_Monster(StatusData InStatusData);
	void Delete_Monster(int InUnitIndex);

public:
	void Print_ContainerCount();
	void Print_Monster_highestHP();
	void Print_Monster_StatusData(const char* InName, uint64_t InSize);

private:
	void Add_ValidIndex(int InUnitIndex);
	void Delete_ValidIndex(int InUnitIndex);

private:
	Unit* Find_Monster_ByUnitNum(int InUnitIndex);
	Unit* Find_Monster_ByUnitName(const char* InName, uint64_t InSize);

private:
	bool Check_Container_IsValid();
}; 