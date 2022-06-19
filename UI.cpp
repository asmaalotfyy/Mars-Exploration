#include "UI.h"
#include "MarsStation.h"
#include "Formulation.h"
#include<Windows.h>
UI::UI(MarsStation* Mars)
{
	pMars = Mars;
}

void UI::PrintWait(PriQueue<missions> Emergency, LinkedQueue<missions> Polar)
{
	
	PriQueue<missions> Emergency2;
	LinkedQueue<missions> Polar2;
	int waiting_count=0;

	
	missions m1;
	missions m2;
	
	
	while (Emergency.dequeue(m1))
	{
		waiting_count++;
		int x = (m1.getTLOC() * m1.getMDUR() * m1.getSIG()) / (m1.getTLOC() + m1.getMDUR() + m1.getSIG());
		Emergency2.enqueue(m1,x);

	}
	

	
	
	while (Polar.dequeue(m2))
	{
		waiting_count++;
			
		Polar2.enqueue(m2);

	}
	




	while (Emergency2.dequeue(m1))
	{
		int x = (m1.getTLOC() * m1.getMDUR() * m1.getSIG()) / (m1.getTLOC() + m1.getMDUR() + m1.getSIG());
		Emergency.enqueue(m1, x);

	}
	while (Polar2.dequeue(m2))
	{
		Polar.enqueue(m2);

	}

	cout << waiting_count << " waiting missions:";

	cout << "[";

	if (!(Emergency.peek(m1)))
	{
		cout << "] ";
	}
	else
	{

		while (Emergency.dequeue(m1))
		{
			cout << m1.getID() << " ,";
			int x = (m1.getTLOC() * m1.getMDUR() * m1.getSIG()) / (m1.getTLOC() + m1.getMDUR() + m1.getSIG());
			Emergency2.enqueue(m1, x);
		}
		cout << "] ";




	}
	cout << "(";
	if (!(Polar.peek(m1)))
	{
		cout << ") ";
	}
	else
	{

		while (Polar.dequeue(m2))
		{
			cout << m2.getID() << " ,";
			int x = (m2.getTLOC() * m2.getMDUR() * m2.getSIG()) / (m2.getTLOC() + m2.getMDUR() + m2.getSIG());
			Emergency2.enqueue(m2, x);
			
		}
		cout << ") ";




	}


	while (Emergency2.dequeue(m1))
	{
		int x = (m1.getTLOC() * m1.getMDUR() * m1.getSIG()) / (m1.getTLOC() + m1.getMDUR() + m1.getSIG());
		Emergency.enqueue(m1, x);

	}
	while (Polar2.dequeue(m2))
	{
		Polar.enqueue(m2);

	}

	cout << endl;
	cout << "--------------------------------------" << endl;


}
void UI::PrintInEx(LinkedQueue<missions> InEx)
{
	int CountP = 0;
	int CountE = 0;
	int CountInEx = 0;
	LinkedQueue<missions> Emerge;
	LinkedQueue<missions> Polar;
	missions MissionNode;
	while (!InEx.isEmpty())
	{
		InEx.dequeue(MissionNode);
		if (MissionNode.getTYP() == 'E')
		{
			CountE++;
			CountInEx++;
			Emerge.enqueue(MissionNode);
		}
		else if (MissionNode.getTYP() == 'P')
		{
			CountP++;
			CountInEx++;
			Polar.enqueue(MissionNode);
		}
	}
	cout << CountInEx << " In-Execution Missions/Rovers: ";

	cout << "[  ";
	while (!Emerge.isEmpty())
	{
		Emerge.dequeue(MissionNode);
		cout << MissionNode.getID() << "/" << MissionNode.getrover().get_id() << ", ";

	}
	cout << "\b\b  ] ";
	cout << "(  ";
	while (!Polar.isEmpty())
	{
		Polar.dequeue(MissionNode);
		cout << MissionNode.getID() << "/" << MissionNode.getrover().get_id() << ", ";

	}
	cout << "\b\b  ) ";
	cout << endl;
	cout << "--------------------------------------" << endl;
}

void UI::PrintAvailRovers(LinkedQueue<Rovers>AvailERovers, LinkedQueue<Rovers>AvailPRovers)
{

	LinkedQueue<Rovers>AvailERovers2;
	LinkedQueue<Rovers>AvailPRovers2;


	Rovers r1;
	Rovers r2;
	int Avail_count = 0;

	while (AvailERovers.dequeue(r1))
	{
		Avail_count++;
		
		AvailERovers2.enqueue(r1);

	}




	while (AvailPRovers.dequeue(r2))
	{
		Avail_count++;

		AvailERovers2.enqueue(r2);

	}





	while (AvailERovers2.dequeue(r1))
	{
		
		AvailERovers.enqueue(r1);

	}
	while (AvailPRovers2.dequeue(r2))
	{
		AvailPRovers.enqueue(r2);

	}


	cout << Avail_count << " Available rovers: ";






	cout << "[";

	if (!(AvailERovers.peek(r1)))
	{
		cout << "] ";
	}
	else
	{

		while (AvailERovers.dequeue(r1))
		{
			cout << r1.get_id() << " ,";
			
			AvailERovers2.enqueue(r1);
		}
		cout << "] ";




	}
	cout << "(";
	if (!(AvailPRovers.peek(r1)))
	{
		cout << ") ";
	}
	else
	{

		while (AvailPRovers.dequeue(r2))
		{
			cout << r2.get_id()<< " ,";
			
			AvailPRovers2.enqueue(r2);

		}
		cout << ") ";




	}




	while (AvailERovers2.dequeue(r1))
	{

		AvailERovers.enqueue(r1);

	}
	while (AvailPRovers2.dequeue(r2))
	{
		AvailPRovers.enqueue(r2);

	}







	cout << endl;
	cout << "--------------------------------------" << endl;
}

void UI::PrintInCheckUp(LinkedQueue<Rovers> ICUERovers, LinkedQueue<Rovers> ICUPRovers)
{
	LinkedQueue<Rovers>ICUERovers2;
	LinkedQueue<Rovers>ICUPRovers2;


	Rovers r1;
	Rovers r2;
	int Avail_count = 0;

	while (ICUERovers.dequeue(r1))
	{
		Avail_count++;

		ICUERovers2.enqueue(r1);

	}




	while (ICUPRovers.dequeue(r2))
	{
		Avail_count++;

		ICUPRovers2.enqueue(r2);

	}





	while (ICUERovers2.dequeue(r1))
	{

		ICUERovers.enqueue(r1);

	}
	while (ICUERovers2.dequeue(r2))
	{
		ICUPRovers.enqueue(r2);

	}


	cout << Avail_count << " in checkup rovers: ";






	cout << "[";

	if (!(ICUPRovers.peek(r1)))
	{
		cout << "] ";
	}
	else
	{

		while (ICUERovers.dequeue(r1))
		{
			cout << r1.get_id() << " ,";

			ICUERovers2.enqueue(r1);
		}
		cout << "] ";




	}
	cout << "(";
	if (!(ICUPRovers.peek(r1)))
	{
		cout << ") ";
	}
	else
	{

		while (ICUPRovers.dequeue(r2))
		{
			cout << r2.get_id() << " ,";

			ICUPRovers2.enqueue(r2);

		}
		cout << ") ";




	}



	while (ICUERovers2.dequeue(r1))
	{

		ICUERovers.enqueue(r1);

	}
	while (ICUERovers2.dequeue(r2))
	{
		ICUPRovers.enqueue(r2);

	}







	
	cout << endl;
	cout << "--------------------------------------" << endl;
}
void UI::PrintComplete(LinkedQueue<missions> CMissions)
{
	int CountP = 0;
	int CountE = 0;
	int CountComp = 0;
	LinkedQueue<missions> Emerge;
	LinkedQueue<missions> Polar;
	missions MissionNode;
	while (!CMissions.isEmpty())
	{
		CMissions.dequeue(MissionNode);
		if (MissionNode.getTYP() == 'E')
		{
			CountE++;
			CountComp++;
			Emerge.enqueue(MissionNode);
		}
		else if (MissionNode.getTYP() == 'P')
		{
			CountP++;
			CountComp++;
			Polar.enqueue(MissionNode);
		}
	}
	cout << CountComp << " Completed Missions: ";
	cout << "[  ";
	while (!Emerge.isEmpty())
	{
		Emerge.dequeue(MissionNode);
		cout << MissionNode.getID() << ", ";

	}
	cout << "\b\b  ] ";
	cout << "(  ";
	while (!Polar.isEmpty())
	{
		Polar.dequeue(MissionNode);
		cout << MissionNode.getID() << ", ";

	}
	cout << "\b\b  ) ";
	cout << endl;
	cout << "--------------------------------------" << endl;
}
void UI::Mode(int mode)
{
	if (mode == 3)
	{
		return;
	}

	PriQueue<missions> Emergency= pMars->get_WEMissions();
	LinkedQueue<missions> Polar=pMars->get_WPMissions();
	LinkedQueue<missions> InEx= pMars->get_IEmissions();
	LinkedQueue<Rovers> AvailERovers= pMars->get_AERovers();
	LinkedQueue<Rovers> AvailPRovers=pMars->get_APRovers();
	LinkedQueue<Rovers> ICUERovers=pMars->get_CUERover();
	LinkedQueue<Rovers> ICUPRovers=pMars->get_CUPRover();
	LinkedQueue<missions> CMissions=pMars->get_CMissions(); 

	cout << "Current day: " << pMars->get_current_day() << endl;
	PrintWait(Emergency, Polar);
	PrintInEx(InEx);
	PrintAvailRovers(AvailERovers, AvailPRovers);
	PrintInCheckUp(ICUERovers, ICUPRovers);
	PrintComplete(CMissions);

	if (mode == 1)
	{
		cout << "Press Enter to Continue";
		cin.ignore();

	}
	if (mode == 2)
	{
		Sleep(1000);
	}

	cout << "======================= New Day ======================" << endl;
}