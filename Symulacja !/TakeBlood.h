#pragma once
#include "Process.h"

class TakeBlood : public  Process
{

public:
	TakeBlood(Center &);
	void execute(Center &) override;


};

