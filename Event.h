#pragma once
#include <iostream>
#include "PriQueue.h"
#include "LinkedQueue.h"
#include "Event.h"
#include "Missions.h"
#include "Rovers.h"


class Event
{
protected:
	int EventDay;
	int MissionID;

public:

	
	Event(int, int);
	int getED();
	virtual void Execute(PriQueue<missions>& Emergency, LinkedQueue<missions>& Polar) = 0;
};