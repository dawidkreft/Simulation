#pragma once
#include "Process.h"



class DeleteOfBlood : public Process
{

public:
	DeleteOfBlood(Center &);
	void execute(Center &) override;

};