#pragma once
#include "stdafx.h"
#include "Blood.h"
#include <queue>
#include <list>
#include "Crand.h"
#include "Patient.h"

using namespace std;

class Center
{
	int idBlood;
	unsigned const int minBloodR = 20;  // min liczba jednostek krwi
	double time;
	int quantityOfPatient;

	const int meanP = 150;        //150	
	const int  averageE = 300;         // oryginal is 300
	const int L = 900;
	const int N = 80;
	const double W = 0.22;
	int quantityofBookNormal;
	int quantityofBookemergency;
	int quantityDeleteBlood;


public:

	queue <Patient> queueOfPatient{};       // Kolejka Pacjentów
	list <Blood>  listOfBookedBloodA{};
	list <Blood>  listOfBloodA{};           // Kolejka krwi
	list <Blood>  listOfBookedBloodB{};
	list <Blood>  listOfBloodB{};
	list <int>    bufforOfProcess{};
	Crand crand, crand1, crand2, crand3, crand4;

	Center();
	double actual_time();
	double getmeanP();
	double getW();
	int getL();
	int getN();
	int getIDBlood();
	unsigned int getMinBloodR();
	int getAveregeE();
	int getQuantityOfNormalBlood();
	int getQuantityOfemergencyBlood();
	int getDeleteofBlood();
	void reset();
	void updateIDBlood();
	void updateTime(double time);
	void updateQuantityOfNormal();
	void updateQuantityOfEmergency();
	void updateQuantityDeleteBlood();
	void setquantityOfPatient();
	int getQuantityOfPatient();

	~Center() = default;
};

