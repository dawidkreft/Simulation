#include "stdafx.h"
#include "NewDonor.h"
#include  "Blood.h"
#include "Center.h"

bool operator_check_1(const Blood & aar1, const Blood & aar2) {   // dodatkowy operator wspomagajacy sortowanie 
																  //kolejnoœæ - rosn¹co
	Blood a1 = aar1;
	Blood a2 = aar2;

	return a1.endTimeLifeBlood() > a2.endTimeLifeBlood();

}

NewDonor::NewDonor(Center &center)
{
	setEventTime(center.actual_time() + center.crand2.exponential(center.getL()));
}



void NewDonor::execute(Center & center)
{
	Blood temp = Blood(center.getIDBlood(), 750, center.actual_time(), center.crand1.blood_generator());    // second parametr is time of life blood 
	center.updateIDBlood();

	if (temp.getType()) {
		center.listOfBloodA.push_back(temp);
		center.listOfBloodA.sort(operator_check_1);   // pokazdym przyjaciu krwi sortujemy wedlug daty waznsci 

	}
	else {
		center.listOfBloodB.push_back(temp);
		center.listOfBloodB.sort(operator_check_1);   // pokazdym przyjaciu krwi sortujemy wedlug daty waznsci 

	}

	center.bufforOfProcess.push_back(11);
	center.bufforOfProcess.push_back(13);

}


