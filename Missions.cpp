#pragma once
#include "Missions.h"
using namespace std;
missions::missions()
{
}
missions::missions(char type, int id, int location, int duration, int forday, int sig)
{
	TYP = type;
	ID = id;
	TLOC = location;
	MDUR = duration;
	SIG = sig;
}
void missions::setTYP(char type)
{
	TYP = type;
}
char missions::getTYP()
{
	return TYP;
}
void missions::setED(int eventday)
{
	FD = eventday;
}
int missions::getED()
{
	return FD;
}
void missions::setID(int id)
{
	ID = id;
}
int missions::getID()
{
	return ID;
}
void missions::setTLOC(int location)
{
	TLOC = location;
}
int missions::getTLOC()
{
	return TLOC;
}
void missions::setMDUR(int duration)
{
	MDUR = duration;
}
int missions::getMDUR()
{
	return MDUR;
}
void missions::setSIG(int significance)
{
	SIG = significance;
}
int missions::getSIG()
{
	return SIG;
}
void missions::increasingWD()
{
	WD++;
}
int missions::getWD()
{
	return WD;
}
int missions::getCD()
{
	return CD;
}
int missions::getExD()
{
	return ExD;
}
void missions::setrover(Rovers rov)
{
	rover = rov;
}
Rovers missions:: getrover()
{
	return rover;
}
void missions::CDED()
{
	ExD = ((TLOC) / (rover.getSpeed() * 25)) * 2 + MDUR;
	CD = FD + WD + ExD;
}
missions::~missions()
{
}
