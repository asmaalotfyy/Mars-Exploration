#pragma once
#include "Formulation.h"
Formulation::Formulation(char MT, int TL, int MD, int Signif, int MID, int ED) :Event(ED, MID)
{
    MissionType = MT;
    MissionID = MID;
    TargetLocation = TL;
    MissionDuration = MD;
    EventDay = ED;
    Significance = Signif;
}

void Formulation::Execute(PriQueue<missions>& Emergency, LinkedQueue<missions>& Polar)
{
    if (MissionType == 'E')
    {
    missions Emergenc (MissionType, MissionID, TargetLocation, MissionDuration, EventDay, Significance);
    int priority = (TargetLocation * MissionDuration * Significance) / (TargetLocation + MissionDuration + Significance);
    Emergency.enqueue(Emergenc, priority);
    }

    else if (MissionType == 'P')
    {
        missions Pola(MissionType, MissionID, TargetLocation, MissionDuration, EventDay, Significance);
        Polar.enqueue(Pola);
    }
   

}
