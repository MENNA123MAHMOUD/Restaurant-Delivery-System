#pragma once
#include "ArrivalEvent.h"
#include "..\Rest\Restaurant.h"



ArrivalEvent::ArrivalEvent(int eTime, int oID, ORD_TYPE oType, REGION reg, int dis, double mon) :Event(eTime, oID)
{
	OrdType = oType;
	OrdRegion = reg;
	OrdDistance = dis;
	arrival = eTime;
	OrdMoney = mon;
}

void ArrivalEvent::Execute(Restaurant* pRest)
{
	//This function should create and order and and fills its data 
	// Then adds it to normal, frozen, or VIP order lists that you will create in phase1
	Order* pOrd = new Order(OrderID, OrdType, OrdRegion, OrdDistance, arrival,OrdMoney);
	if (OrdType == TYPE_NRM){
		(pRest->getregion(OrdRegion))->normalorder.InsertEnd(pOrd);
	}
	if (OrdType == TYPE_FROZ){
		(pRest->getregion(OrdRegion))->frozenorder.enqueue(pOrd);
	}
	if (OrdType == TYPE_VIP){
		(pRest->getregion(OrdRegion))->VIP.add(pOrd);
	
                   }
	
	
}
