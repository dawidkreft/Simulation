#pragma once
class Patient
{

	unsigned int needBlood;   // wymagana ilosc krwi
	bool typeBlood; // typ krwi 
public:
	Patient(int, bool);
	unsigned int getNeededBlood();
	bool getTypeBlood();


};

