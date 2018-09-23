#include "stdafx.h"
#include "Blood.h"

Blood::Blood(int id, double timeLife, double actualTime, bool type)
{

	this->id = id;
	this->timeLife = timeLife;
	this->timeOfCreate = actualTime;
	this->typeBlood = type;
}

double Blood::endTimeLifeBlood()
{
	return timeOfCreate + timeLife;
}

double Blood::getTimeOfCreate()
{
	return timeOfCreate;
}

bool Blood::getType()
{
	return typeBlood;
}



int Blood::getID()
{
	return id;
}
