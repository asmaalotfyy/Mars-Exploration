#pragma once
#include "Event.h"
#include "Formulation.h"
#include "Missions.h"
#include "Rovers.h"
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;


class MarsStation
{
private:

	PriQueue<missions> WEMissions;
	LinkedQueue<missions> WPMissions;
	LinkedQueue<missions> CMissions;
	LinkedQueue<missions> IEmissions;

	LinkedQueue<Rovers> AERovers;
	LinkedQueue<Rovers> APRovers;
	LinkedQueue<Rovers> CUERover;
	LinkedQueue<Rovers> CUPRover;
	LinkedQueue<Event*> Events;

	int CurrentDay=0;
public:
	MarsStation();
	void StartUp(); // to load file
	void CurrentDayincreasing();
	bool AvailableEvents();
	void EventExecution(); 
	int getCurrentDay(); 
	void CheckIEmissions(); //check in IE missions only
	void MissionAssigning(); // assigning missions to rovers
	void WaitingMissions(); // checking on waiting list to increment days
	void MissionExecution(); // check on every thing related to missions
	void FreeRover(Rovers R); //to free the rover after the mission is completed
	void CheckUpERover(); // to check the checkup Erovers 
	void CheckUpPRover(); // to check the checkup Provers 
	void CheckingSystem(int mode); // to check on every each day and when everything finishes it prints output

	int get_current_day();
	PriQueue<missions> get_WEMissions();
	LinkedQueue<missions> get_WPMissions();
	LinkedQueue<missions> get_IEmissions();
	LinkedQueue<Rovers> get_AERovers();
	LinkedQueue<Rovers> get_APRovers();
	LinkedQueue<Rovers> get_CUERover();
	LinkedQueue<Rovers> get_CUPRover();
	LinkedQueue<missions> get_CMissions();

};
