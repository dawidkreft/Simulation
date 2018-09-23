#include "stdafx.h"
#include "Center.h"



Center::Center()
{
	idBlood = 0;
	time = 0;
	quantityOfPatient = 0;
	quantityDeleteBlood = 0;
	quantityofBookNormal = 0;
	quantityofBookemergency = 0;
	crand  = Crand(27);
	crand1 = Crand(83);
	crand2 = Crand(11);
	crand3 = Crand(311);
	crand4 = Crand(477);
}
double Center::actual_time()
{
	return time;
}

double Center::getmeanP()
{
	return meanP;
}

double Center::getW()
{
	return W;
}

int Center::getL()
{
	return L;
}

int Center::getN()
{
	return N;
}

int Center::getIDBlood()
{
	return idBlood;
}

unsigned int Center::getMinBloodR()
{
	return  minBloodR;
}

int Center::getAveregeE()
{
	return averageE;
}

int Center::getQuantityOfNormalBlood()
{
	return quantityofBookNormal;
}

int Center::getQuantityOfemergencyBlood()
{
	return quantityofBookemergency;
}

int Center::getDeleteofBlood()
{
	return quantityDeleteBlood;
}

void Center::updateIDBlood()
{
	idBlood++;
}


void Center::updateTime(double time)
{
	this->time = time;
}

void Center::updateQuantityOfNormal()
{
	quantityofBookNormal++;
}

void Center::updateQuantityOfEmergency()
{
	quantityofBookemergency++;
}

void Center::updateQuantityDeleteBlood()
{
	quantityDeleteBlood++;
}

void Center::setquantityOfPatient()
{
	quantityOfPatient++;
}

int Center::getQuantityOfPatient()
{
	return quantityOfPatient;
}

void Center::reset()
{
	quantityofBookNormal = 0;;
	quantityofBookemergency = 0;
	quantityOfPatient = 0;
	quantityDeleteBlood = 0;
}


