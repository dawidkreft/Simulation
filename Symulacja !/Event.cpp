#include "stdafx.h"
#include "Event.h" 



bool operator_check_2(const Blood & aar1, const Blood & aar2) {   // dodatkowy operator wspomagajacy sortowanie 
																  //kolejnoœæ - rosn¹co
	Blood a1 = aar1;
	Blood a2 = aar2;

	return a1.endTimeLifeBlood() < a2.endTimeLifeBlood();
}

Event::Event(Center &center)
{
	setEventTime(0);
}

void Event::execute(Center &center)
{ 

	if ( ! center.queueOfPatient.empty() )   // warunkowe zdarzenie  - obsluga pacjenta 
	{
		if (center.queueOfPatient.front().getTypeBlood()) {  // sprawdz typ krwi 

			if (center.queueOfPatient.front().getNeededBlood() <= center.listOfBloodA.size()) {   // sprawdz czy jest wystarczajaco duzo krwi

				for (unsigned int i = 0; i < center.queueOfPatient.front().getNeededBlood(); i++) {
					center.listOfBloodA.pop_front();
				}
				center.queueOfPatient.pop();
				center.setquantityOfPatient();
			}

		}
		else
		{
			if (center.queueOfPatient.front().getNeededBlood() <= center.listOfBloodB.size()) {   // sprawdz czy jest wystarczajaco duzo krwi

				for (unsigned int i = 0; i < center.queueOfPatient.front().getNeededBlood(); i++) {
					center.listOfBloodB.pop_front();
				}
				center.queueOfPatient.pop();
				center.setquantityOfPatient();
			}


		}
		
	}

	// zdarzenie warunkowe zamowienie krwi  grupy A 
	if (center.listOfBloodA.size() <= center.getMinBloodR())
	{
		for (int i = 0; i < center.getN(); i++)
		{
			Blood temp(center.getIDBlood(),Time, center.actual_time() + center.crand4.exponential(1800), true);    // druga zmienna to czas zycia   trzecia to czas zrobienia dodajemy bo dostaniemy ja w przyszlosci
			center.updateIDBlood();
			center.listOfBookedBloodA.push_back(temp);
			center.updateQuantityOfNormal();
		}
		center.listOfBookedBloodA.sort(operator_check_2);   // pokazdym przyjaciu krwi sortujemy wedlug daty waznsci 
		center.bufforOfProcess.push_back(10);

	}
	
	// zdarzenie warunkowe zamowienie krwi  grupy B 
	if (center.listOfBloodB.size() <= center.getMinBloodR())
	{
		for (int i = 0; i < center.getN(); i++)
		{
			Blood temp(center.getIDBlood(), Time, center.actual_time() + center.crand4.exponential(1800), false);    // druga zmienna to czas zycia   trzecia to czas zrobienia dodajemy bo dostaniemy ja w przyszlosci
			center.updateIDBlood();
			center.listOfBookedBloodB.push_back(temp);
			center.updateQuantityOfNormal();
		}
		center.listOfBookedBloodB.sort(operator_check_2);
		center.bufforOfProcess.push_back(10);

	}
	

	if (!center.queueOfPatient.empty()) {
		// zdarzenie zamowienie awaryjnego
		if (center.queueOfPatient.front().getTypeBlood()) {
			if (center.queueOfPatient.front().getNeededBlood() > center.listOfBloodA.size()) {
				int BookedBloodQ = 14;     // zamowienie na Q jednostek krwi 

				for (int i = 0; i < BookedBloodQ; i++)
				{
					Blood temp(center.getIDBlood(), Time, center.actual_time() + center.crand3.normal(center.getAveregeE(), 0.1), true);    // druga zmienna to czas zycia , trzecia zmienna to czas dojscia
					center.updateIDBlood();
					center.listOfBookedBloodA.push_back(temp);
					center.updateQuantityOfEmergency();
				}
				center.listOfBookedBloodA.sort(operator_check_2);   // pokazdym przyjaciu krwi sortujemy wedlug daty waznsci 
				center.bufforOfProcess.push_back(10);
			}
		}
		else {              // dla grupy B
			if (center.queueOfPatient.front().getNeededBlood() > center.listOfBloodB.size()) {
				int BookedBloodQ = 14;     // zamowienie na Q jednostek krwi 

				for (int i = 0; i < BookedBloodQ; i++)
				{
					Blood temp(center.getIDBlood(), Time, center.actual_time() + center.crand3.normal(center.getAveregeE(), 0.1), false);    // druga zmienna to czas zycia , trzecia zmienna to czas dojscia
					center.updateIDBlood();
					center.listOfBookedBloodB.push_back(temp);
					center.updateQuantityOfEmergency();
				}
				center.listOfBookedBloodB.sort(operator_check_2);
				center.bufforOfProcess.push_back(10);
			}
		}
	} 
	
}
