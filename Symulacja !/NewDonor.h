#pragma once
#include "Process.h"

class NewDonor : public Process
{
public:
	NewDonor(Center&);
	void execute(Center&) override;
	
};

