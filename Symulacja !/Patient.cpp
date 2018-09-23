#include "stdafx.h"
#include "Patient.h"


Patient::Patient(int quantity, bool  type)
{
	this->needBlood = quantity;
	this->typeBlood = type;

}

unsigned int Patient::getNeededBlood()
{
	return  needBlood;
}

bool Patient::getTypeBlood()
{
	return typeBlood;
}
