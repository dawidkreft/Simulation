#pragma once

class Blood
{

	int id;
	double timeLife;
	double timeOfCreate;
	bool typeBlood;               // true - A   , false - B    
public:

	Blood(int id, double timeLife, double actualTime, bool type);
	double endTimeLifeBlood();
	double getTimeOfCreate();
	bool getType();
	int getID();


};

