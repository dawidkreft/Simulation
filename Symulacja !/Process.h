#pragma once
#include "Center.h"

class Process
{

	double eventTime = 0;

public:

	Process() = default;
	virtual void execute(Center &);
	double getEventTime();
	void setEventTime(double time);
	virtual ~Process() = default;
};

