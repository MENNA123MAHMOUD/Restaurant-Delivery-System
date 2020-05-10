//#include "Drawing.h"
#pragma once
#include<iostream>
#include "Rest\Restaurant.h"
#include "GUI\GUI.h"
#include<fstream>
#include"Rest\Motorcycle.h"
#include"Events\ArrivalEvent.h"
#include"CancelEvent.h"
#include"PromotionEvent.h"
#include"priorityqueue.h"
#include"LinkedList.h"
#include"Generic_DS/Queue.h"
#include"linkedbag.h"
//#include"Region.h"


int main()
{
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	
	//string l="lol";
	int x = 12;
	Restaurant res;
	int speedn, speedf, speedv;
	int nofnormalA, noffrozenA, nofvipA;
	int nofnormalB, noffrozenB, nofvipB;
	int nofnormalC, noffrozenC, nofvipC;
	int nofnormalD, noffrozenD, nofvipD;
	int Autopromotion, events;

	ifstream infile(res.Get_File_Name()+".txt");
	
	int countsteps = 1, ts;
	if (infile.is_open())
	{
		infile >> speedn >> speedf >> speedv;
		infile >> nofnormalA >> noffrozenA >> nofvipA;
		res.Addmotors(A_REG, speedn, speedf, speedv, nofnormalA, noffrozenA, nofvipA);
		infile >> nofnormalB >> noffrozenB >> nofvipB;
		res.Addmotors(B_REG, speedn, speedf, speedv, nofnormalB, noffrozenB, nofvipB);
		infile >> nofnormalC >> noffrozenC >> nofvipC;
		res.Addmotors(C_REG, speedn, speedf, speedv, nofnormalC, noffrozenC, nofvipC);
		infile >> nofnormalD >> noffrozenD >> nofvipD;
		res.Addmotors(D_REG, speedn, speedf, speedv, nofnormalD, noffrozenD, nofvipD);
		infile >> Autopromotion >> events;

		res.setpromote(Autopromotion);

		char type;
		infile >> type >> ts;
		while (events)
		{
			if (type == 'R') {
				int id, dst, mon;
				char reg, typ;
				infile >> typ >> id >> dst >> mon >> reg;
				ORD_TYPE t = (typ == 'N') ? TYPE_NRM : (typ == 'F') ? TYPE_FROZ : (typ == 'V') ? TYPE_VIP : t;
				REGION r = (reg == 'A') ? A_REG : (reg == 'B') ? B_REG : (reg == 'C') ? C_REG : D_REG;
				Event* AE = new ArrivalEvent(ts, id, t, r,dst,mon);
				res.AddEvent(AE);
			}
			else if (type == 'X') {
				int id;
				infile >> id;
				Event* CE = new cancelevent(ts, id);
				res.AddEvent(CE);
			}
			else if (type == 'P') {
				int id, exmon;
				infile >> id >> exmon;
				Event* PE = new PromotionEvent(ts, id, exmon);
				res.AddEvent(PE);
			}
			events--;
			if (events)
				infile >> type >> ts;

		}

	}
	infile.close();
	
	res.RunSimulation();
	return 0;
	
}