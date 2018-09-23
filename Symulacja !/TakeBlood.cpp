#include "stdafx.h"
#include "TakeBlood.h"

bool operator_check(const Blood & aar1, const Blood & aar2) {   // dodatkowy operator wspomagajacy sortowanie 
																//kolejnoœæ - rosn¹co
	Blood a1 = aar1;
	Blood a2 = aar2;
	return a1.endTimeLifeBlood() > a2.endTimeLifeBlood();

}


TakeBlood::TakeBlood(Center &center)
{

	double temp1 = -1;   // blood type A
	double temp2 = -1;  // blood type B 

	if (! center.listOfBookedBloodA.empty()) {       // pobierz czasy  z listy posortowanej krwi pod wzgledem czasu zycia
		temp1 = center.listOfBookedBloodA.back().getTimeOfCreate();
	}
	if (!center.listOfBookedBloodB.empty()) {
		temp2 = center.listOfBookedBloodB.back().getTimeOfCreate();
	}

	if (temp1 > 0 && temp2 > 0)
	{
		if (temp1 > temp2) {
			setEventTime(temp2);
		}
		else {
			setEventTime(temp1);
		}
	}
	else if (temp1 == -1 && temp2> 0)
	{
		setEventTime(temp2);
	}
	else if (temp2 == -1 && temp1>0)
	{
		setEventTime(temp1);
	}



}

void TakeBlood::execute(Center &center)
{
	

		int temp = center.listOfBookedBloodA.size();
		
		for(int i = 0 ; i < temp ; i++){
			
			if (center.actual_time() >= center.listOfBookedBloodA.front().getTimeOfCreate()) {
				center.listOfBloodA.push_back(center.listOfBookedBloodA.front());
			}
			center.listOfBookedBloodA.pop_front();
		}
		// wyjonuj tak dlugo  az w liscie jest krew do pobranie w tym czasie
		if (center.listOfBloodA.size() > 2)
			center.listOfBloodA.sort(operator_check);   // pokazdym przyjaciu krwi sortujemy wedlug daty waznsci 

		 temp = center.listOfBookedBloodB.size();

		for (int i = 0; i < temp; i++) {

			if (center.actual_time() >= center.listOfBookedBloodB.front().getTimeOfCreate()) {
				center.listOfBloodB.push_back(center.listOfBookedBloodB.front());
			}
			center.listOfBookedBloodB.pop_front();
		}
		// wyjonuj tak dlugo  az w liscie jest krew do pobranie w tym czasie
		if (center.listOfBloodB.size() > 2)
			center.listOfBloodB.sort(operator_check);   // pokazdym przyjaciu krwi sortujemy wedlug daty waznsci 

	center.bufforOfProcess.push_back(11);
}

