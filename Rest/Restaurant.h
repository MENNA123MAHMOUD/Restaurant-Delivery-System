
#ifndef __RESTAURANT_H_
#define __RESTAURANT_H_

#pragma once
#include<iostream>
#include<fstream>
#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"
#include "..\Generic_DS\Queue.h"
#include "..\Events\Event.h"
#include "..\Events\ArrivalEvent.h"
//#include"..\CancelEvent.h"
#include"..\PromotionEvent.h"
//#include"..\Region.h"
#include "Order.h"
#include"..\Region.h"
#include"..\Generic_DS\Node.h"
// it is the maestro of the project
class Restaurant  
{	
private:
	GUI *pGUI;
	Queue<Event*> EventsQueue;	//Queue of all events that will be loaded from file
	Queue<Order*> allorders[4];
	Order**ALLORDERS[4];
	double TOTAL_MONEY;
	//	DEMO-related members. Should be removed in phases 1&2
	Queue<Order*> DEMO_Queue;	//Important: This is just for demo/// ==>
	Region R[4];
	int t_s; // to have the time steps;
	string f_n; // to know the file name
	string o_n;
	int Autopromotion;
public:
	
	Restaurant();
	~Restaurant();
	void addarrays();//calls toarray funtions in each ADT
	void AddEvent(Event* pE);	//adds a new event to the queue of events
	void assignmotors();
	void SILENT();
	void STEP_BY_STEP();
	void AllordersArray();
	void sortfinish();
	void ExecuteEvents(int TimeStep);	//executes all events at current timestep
	void RunSimulation();
	Region* getregion(REGION);
	void printinfo();//printing the restaurant information
	void printinfodynamic();
	void Addmotors(REGION, int speedN, int speedF, int speedV, int NoN, int NoF, int NoV);
	void InterActive(int); //the demo function for phase one
	string Get_File_Name();
	void printorders();
	void checkmotor();
	void Auto_Promote();
	void setpromote(int op);
	string get_outfile_name();
	
};

#endif