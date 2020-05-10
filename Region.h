#pragma once
#include"LinkedList.h"
#include"priorityqueue.h"
#include"Rest\Motorcycle.h"
#include"Generic_DS/Queue.h"
#include"Rest\Order.h"
#include"linkedbag.h"
struct Region{
public:
	//string name;
priorityqueue<Motorcycle*>NormalServ;
	Queue<Motorcycle*>NormalIdle;
	Queue<Motorcycle*>VipIdle;
	priorityqueue<Motorcycle*>VipServ;
	Queue<Motorcycle*>FrozenIdle;
	priorityqueue<Motorcycle*>FrozenServ;
	Queue<Order*> frozenorder;
	LinkedList<Order*> normalorder;
	priorityqueue<Order*> VIP;
	int VIPcount;
	int FRZcount;
	int Normalcount;
	Order**ALLORDERS;
	int MOTORN;
	int MOTORV;
	int MOTORF;
	Region();
};