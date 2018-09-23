#pragma once
#include "Center.h"
#include "Process.h"

class Event : public Process
{
	int Time = 550; 
public:
	Event(Center&);
	void execute(Center& center) override;
};

