#include "stdafx.h"
#include "Accident.h"



Accident::Accident(Center & center)
{
	setEventTime(center.actual_time() + center.crand.uniform(15000, 16000));

}

void Accident::execute(Center &center)
{
	int needBlood = static_cast<int> (center.crand.uniform(10, 20));
	bool typeBlood = center.crand1.blood_generator();
	
	if (typeBlood)
	{
		for (int i = 0; i< needBlood; i++)
		{
			if (!center.listOfBloodA.empty())
				center.listOfBloodA.pop_front();
		}
	}
	else
	{
		for (int i = 0; i< needBlood; i++)
		{
			if (!center.listOfBloodB.empty())
				center.listOfBloodB.pop_front();
		}
	}

	center.bufforOfProcess.push_back(14);
}



