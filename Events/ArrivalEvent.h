#ifndef __ARRIVAL_EVENT_R_
#define __ARRIVAL_EVENT_R_
#pragma once

#include"..\Rest\Order.h"
#include "Event.h"



//class for the arrival event
class ArrivalEvent: public Event
{
	//info about the order ralted to arrival event
	int OrdDistance;	//order distance
	ORD_TYPE OrdType;		//order type: Normal, Frozen, VIP
	REGION OrdRegion;  //Region of this order	    
	int arrival;
	double OrdMoney;	//Total order money
public:
	ArrivalEvent(int eTime, int oID, ORD_TYPE oType, REGION reg, int des, double mon);
	//Add more constructors if needed
	virtual void Execute(Restaurant *pRest);	//override execute function

};

#endif