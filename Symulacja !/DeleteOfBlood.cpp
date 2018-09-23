#include "stdafx.h"
#include "DeleteOfBlood.h"
DeleteOfBlood::DeleteOfBlood(Center &center)
{
	setEventTime(-1);
	double temp1 = -1;   // blood type A
	double temp2 = -1;  // blood type B 

	if (! center.listOfBloodA.empty()) {       // pobierz czasy  z listy posortowanej krwi pod wzgledem czasu zycia
		temp1 = center.listOfBloodA.back().endTimeLifeBlood();
	}
	if ( ! center.listOfBloodB.empty()) {
		temp2 = center.listOfBloodB.back().endTimeLifeBlood();
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
	else if (temp1 == -1 && temp2 > 0)
	{
		setEventTime(temp2);
	}
	else if (temp2 == -1 && temp1>0)
	{
		setEventTime(temp1);
	}


}


void DeleteOfBlood::execute(Center &center)
{
	int temp = center.listOfBloodA.size();
	
	for(int i = 0 ; i<temp ; i++) {

			if (center.actual_time() >= (center.listOfBloodA.front().endTimeLifeBlood())) {   //  zwracamy czas konca najblizszego elementu z kolejki krwi 
				center.listOfBloodA.pop_front();
				center.updateQuantityDeleteBlood();	
			}
	}

			
    temp = center.listOfBloodB.size();
   	for (int i = 0; i<temp; i++) {
				

			if (center.actual_time() >= (center.listOfBloodB.front().endTimeLifeBlood())) {   //  zwracamy czas konca najblizszego elementu z kolejki krwi 
				center.listOfBloodB.pop_front();
				center.updateQuantityDeleteBlood();	
			}
	}
}





