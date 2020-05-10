#pragma once
#include "Order.h"
#include<fstream>
#include<iostream>
Order::Order(int id, ORD_TYPE r_Type, REGION r_region, int dis, int arr,double mon)
{
	ID = (id > 0 && id < 1000) ? id : 0;	//1<ID<999
	type = r_Type;
	Region = r_region;

	Distance = dis;
	ArrTime = arr;
	totalMoney = mon;
	priority = 3 * totalMoney - Distance - ArrTime;
}
Order::~Order()
{
}
void Order::setmotor(Motorcycle* m){c=m;}
double Order::getMoney() { return totalMoney; }
void Order::setmon(int mon)
{
	totalMoney = mon;
}
void Order::setd(int d){ID=d;}
void Order::settime(int ts) {
	ServTime = (c->getTOreturn() - ts) / 2;
	WaitingTime = ts - ArrTime;
	FinishTime = ArrTime + WaitingTime + ServTime;
}
int Order::getFinish() { return FinishTime; }
void Order::promote()
{
	type = TYPE_VIP;
}

void Order::print(ofstream & out)
{
	out << FinishTime << "  " << ID << "  " << ArrTime << "  " << WaitingTime << "  " << ServTime << endl;

}

int Order::getwt()
{
	return WaitingTime;
}

int Order::getarr()
{
	return ArrTime;
}

int Order::getst()
{
	return ServTime;
}

Motorcycle * Order::getmotorcycle()
{
	return c;
}

int Order::GetID()
{
	return ID;
}


int Order::GetType() const
{
	return type;
}

REGION Order::GetRegion() const
{
	return Region;
}

void Order::SetDistance(int d)
{
	Distance = d>0?d:0;
}

int Order::GetDistance() const
{
	return Distance;
}

bool Order::operator==(Order o1) {
	return (ID == o1.ID);
}
double Order::calcpriority() {
	
	return priority;
}
bool Order::operator<=(Order o ) {
	return(priority <= o.priority);

}
bool Order::OverWait(int t_s, int ap)
{
	if (t_s - ArrTime == ap) {
		return true;
	}

	return false;
}
Order::Order() {}
