#ifndef __ORDER_H_
#define __ORDER_H_
#pragma once
#include"Motorcycle.h"
#include "..\Defs.h"
#include <fstream>
#include<iostream>
using namespace std;
class Order
{

protected:
	int ID;         //Each order has a unique ID (from 1 --> 999 )
	ORD_TYPE type;		//order type: Normal, Frozen, VIP
	REGION Region;  //Region of this order
	int Distance;	//The distance (in meters) between the order location and the resturant 
	Motorcycle* c;        
	double totalMoney;	//Total order money
	
	int WaitingTime, ArrTime, ServTime, FinishTime;	//arrival, service start, and finish times
	int priority;
	
	
	//
	// TODO: Add More Data Members As Needed
	//

public:
	Order();
	Order(int ID, ORD_TYPE r_Type, REGION r_region, int dst, int arr,double mon);
	virtual ~Order();
	int getFinish();
	void settime(int ts);
	void setmotor(Motorcycle* );
	int GetID();
	double getMoney();
	void setmon(int);
	int GetType() const;
	REGION GetRegion() const;
	void SetDistance(int d);
	int GetDistance() const;
	bool operator==(Order);
	bool operator <=(Order);
	double calcpriority();
	void setd(int d);
	void print(ofstream &out);
	int getwt();
	int getarr();
	int getst();
	Motorcycle* getmotorcycle();
	void promote();
	bool OverWait(int t_s, int);
	// TODO: Add More Member Functions As Needed
	//

};

#endif