#pragma once
#include  "Process.h"

class Accident : public Process
{

public:
	Accident(Center &);
	void execute(Center&);
	

};
