#pragma once
#include "Process.h"
class NewPatient : public Process
{
	
public:
	NewPatient(Center &);
	void execute(Center &) override;
	
};

