#ifndef __MOTORCYCLE_H_
#define __MOTORCYCLE_H_


#include "..\Defs.h"

#pragma once
class Motorcycle	
{
	int ID;
	ORD_TYPE type;	//for each order type there is a corresponding motorcycle type 
	int speed;		//meters it can move in one clock tick (in one timestep)
	REGION	region;	//region of the motorcycle
	STATUS	status;	//idle or in-service
	int timetoreturn;

public:
	Motorcycle();
	void setid(int d);
	void settype(ORD_TYPE t);
	void setspeed(int s);
	void setregion(REGION r);
	void setstatus(STATUS st);
	int getid();
	ORD_TYPE gettype();
	int getspeed();
	REGION getregion();
	STATUS getstatus();
	virtual ~Motorcycle();
	bool IsAvilable(int);
	void setTOreturn(int,int);
	int getTOreturn();
	bool operator<=(Motorcycle);
};

#endif