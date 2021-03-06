// Symulacja !.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Process.h"
#include  "Center.h"
#include <iostream>
#include "NewDonor.h"
#include "NewPatient.h"
#include "Event.h"
#include "Accident.h"
#include "DeleteOfBlood.h"
#include "TakeBlood.h"
#include <fstream>


Center center;
list <Process*> listProcess;
Process *myEvent;
void symulation();
void init();
void updateListProcess();
bool my_comp(Process *, Process *);

using namespace std;

int main()
{

	symulation();
	delete myEvent; 

	return 0;
}



void symulation()
{
	init();
	cout << " ***   Start   ***" << endl;
	cout << " Wybierz tryb dzialania : 1 - co krok , 0 - ciagly " << endl;
	bool setOfWork;
	cin >> setOfWork;

	ofstream model_stats;
	model_stats.open("stat.csv", std::ios_base::out | std::ios_base::trunc);
	model_stats << "Krok " << ';' << " Czas " << ';' << " Prawdopodobienstwo A  " << ';' << " Liczba krwi A na stanie  " << ';'<< 
		 "Liczba krwi B na stanie : " << ';' << "ilosc krwi zamowionej " << ';' << "  ( idBlood) " << ';' << " ilosc krwi usunietej " << ';' << " ilosc usunietej / idblood  " << ';' << " ilosc obsluzonych pacjentow " << '\n';


	for (int counter = 0; counter <25000; counter++) {


		if (listProcess.size()) {
			listProcess.sort(my_comp);

			while (listProcess.front()->getEventTime() <center.actual_time() ){
				listProcess.pop_front();
			}
		
			listProcess.front()->execute(center);
			center.updateTime(listProcess.front()->getEventTime());
			listProcess.pop_front();
			
			// zdarzenia warunkowe 
			myEvent->execute(center);
			updateListProcess();

			if(setOfWork)
			{
				cout << " Krok numer : " << counter << endl;
				cout << " Czas aktualny : " << center.actual_time() << endl;
				cout << " Czas najblizszego procesu : " << listProcess.front()->getEventTime();
				cout << " Liczba procesow w kalendarzu : " << listProcess.size();
				cout << " Liczba krwi na stanie : " << center.listOfBloodA.size() + center.listOfBloodB.size() << endl;
				cout << " Liczba krwi zamowionej w kolejce " << center.listOfBookedBloodA.size() + center.listOfBookedBloodB.size() << endl;
				cout << " Liczba krwi zamowionej awaryjnie dotychczas " << center.getQuantityOfemergencyBlood() << endl;
				cout << " Liczba krwi zamowionej  dotychczas " << center.getQuantityOfNormalBlood() << endl;
				cout << " Liczba pacjentow w kolejce " << center.queueOfPatient.size() << endl;
				cout << " Liczba krwi usunietej : " << center.getDeleteofBlood() << endl;
				cout << " Aktualne id krwi : " << center.getIDBlood() << endl;
				cout << " Liczba obsluzonych pacjentow :" << center.getQuantityOfPatient() << endl;
				getchar();
			}


			if(counter == 1500) center.reset();

			if (counter >1500) {
			              // zresetuj parametry w Center  oraz zacznij zapisywac aktualne do pliku 
				double sum = center.getQuantityOfNormalBlood() + center.getQuantityOfemergencyBlood();
				double idBlood = center.getIDBlood();
				model_stats << counter << ';' << " " << center.actual_time() << ';' << (center.getQuantityOfemergencyBlood() / sum) << ' ; '
					<< center.listOfBloodA.size() << ' ; ' << center.listOfBloodB.size() << ';' << (center.listOfBookedBloodA.size() + center.listOfBookedBloodB.size()) << ';' << idBlood << ';' << center.getDeleteofBlood() << ';' << (center.getDeleteofBlood() / idBlood) << ';' << center.getQuantityOfPatient() << '\n';
			}
		}
	}
	getchar();
	model_stats.close();

	while (!listProcess.empty())
		listProcess.pop_front();

}


void init()
{
	listProcess.push_back(new NewPatient(center));
	listProcess.push_back(new NewDonor(center));
	listProcess.push_back(new Accident(center));
	myEvent =new Event(center);
}

bool my_comp(Process *A, Process * B)
{
	return ((A->getEventTime()) < (B->getEventTime()));
}

void updateListProcess()
{
	while ( ! center.bufforOfProcess.empty()  ) {
		
		int temp = center.bufforOfProcess.front();
	
		if (temp == 10) 
			listProcess.push_back(new TakeBlood(center));
		else if (temp == 11) 
			listProcess.push_back(new DeleteOfBlood(center));
		else if (temp == 12)
			listProcess.push_back(new NewPatient(center));
		else if (temp == 13) 
			listProcess.push_back(new NewDonor(center));
		else if (temp == 14) 
			listProcess.push_back(new Accident(center));
		
	
		center.bufforOfProcess.pop_front();	
	}

}