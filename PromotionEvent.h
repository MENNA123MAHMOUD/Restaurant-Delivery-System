#pragma once
#include "Events\Event.h"
//class for the cancel event
class PromotionEvent: public Event
{
	//info about the order ralted to arrival event
	int OrdDistance;	//order distance
	ORD_TYPE OrdType;		//order type: Normal, Frozen, VIP
	REGION OrdRegion;  //Region of this order	                
	double OrdMoney;	//Total order money
public:
	PromotionEvent(int eTime, int oID,int exm);
	//Add more constructors if needed
	
	virtual void Execute(Restaurant *pRest);	//override execute function

};

