#pragma once
#include"Events/Event.h"
#include"Rest/Restaurant.h"



class cancelevent:public Event
{
public:
	cancelevent(int,int);
	virtual void Execute(Restaurant *pRest);	//override execute function
	~cancelevent();
};

