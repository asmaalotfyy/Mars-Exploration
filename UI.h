#pragma once
#include <fstream>
#include <iostream>
#include "PriQueue.h"
#include "LinkedQueue.h"
#include "Missions.h"

using namespace std;
class MarsStation;
class Event;


class UI
{
	MarsStation* pMars;
	int mode;


public:
	UI(MarsStation* Mars);
	void Mode(int mode);
	void PrintWait(PriQueue<missions> Emergency,LinkedQueue<missions> Polar);
	void PrintInEx(LinkedQueue<missions> InEx);
	void PrintAvailRovers(LinkedQueue<Rovers>AvailERovers, LinkedQueue<Rovers>AvailPRovers);
	void PrintInCheckUp(LinkedQueue<Rovers> ICUERovers, LinkedQueue<Rovers> ICUPRovers);
	void PrintComplete(LinkedQueue<missions> CMissions);
	void SilentMode();
};