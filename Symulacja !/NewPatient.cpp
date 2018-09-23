#include "stdafx.h"
#include "NewPatient.h"


NewPatient::NewPatient(Center &center)
{
	
	setEventTime(center.actual_time() + center.crand3.exponential(center.getmeanP()));
}

void NewPatient::execute(Center &center)
{
	Patient temp(center.crand4.geometric(1 / center.getW()), center.crand1.blood_generator());
	center.queueOfPatient.push(temp);

	center.bufforOfProcess.push_back(12);

}
