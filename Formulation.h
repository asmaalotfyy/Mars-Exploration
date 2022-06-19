#pragma once
#include "Event.h"
class Formulation :
    public Event
{
    char MissionType;
    int TargetLocation;
    int MissionDuration;
    int Significance;
    int  MissionID;
    int EventDay;



public:

    
    Formulation(char MissionType, int TargetLocation, int MissionDuration, int Significance, int MissionID, int EventDay);
    virtual void Execute(PriQueue<missions>& Emergency, LinkedQueue<missions>& Polar);

};