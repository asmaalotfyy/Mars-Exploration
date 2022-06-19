#pragma once
#include <iostream>

class Rovers
{
private:
	char RoverType;
	int CheckupDuration;
	int Speed;
	int MissionCount;
	bool Inmaintainance;
	int Entercheck;
	int Checknumb;
	int id;
	

public:
	/* Constructor */
	Rovers();
	Rovers(char roverType, int checkupDuration, int speed, int Checknumb);

	void setRoverType(char);
	char getRoverType();

	void setCheckupDuration(int);
	int getCheckupDuration();

	void setSpeed(int);
	int getSpeed();
	void setN(int n);
	int getN();
	void increamentMissionCount();
	int getMissionCount(int d);
	void setMaintain();
	void resetMaintain();

	bool Movetoavailable(int day);
	void operator=(Rovers const& rov);

	int get_id();
	void set_id(int x);
};