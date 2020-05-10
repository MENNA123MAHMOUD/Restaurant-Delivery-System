#pragma once
#include <cstdlib>
#include <time.h>
#include <iostream>
#include "Restaurant.h"
#include "..\Events\ArrivalEvent.h"
//#include"../CancelEvent.h"
#include"../PromotionEvent.h"
//#include"..\Region.h"
using namespace std;
Restaurant::Restaurant() 
{
	TOTAL_MONEY = 0;
	pGUI = NULL;
}
void Restaurant::RunSimulation()
{
	
	
	bool y;
	Event* e;
	y = EventsQueue.peekBack(e);
	int t_s = e->getEventTime();
	PROG_MODE	mode = pGUI->getGUIMode();
	switch (mode)	//Add a function for each mode in next phases
	{
	case MODE_INTR:
		InterActive(t_s);
		break;
	case MODE_STEP:
		STEP_BY_STEP();
		break;
	case MODE_SLNT:
		SILENT();
		break;

	};
}
//////////////////////////////////  Event handling functions   /////////////////////////////
void Restaurant::AddEvent(Event* pE)	//adds a new event to the queue of events
{
	EventsQueue.enqueue(pE);
}

//Executes ALL events that should take place at current timestep
void Restaurant::ExecuteEvents(int CurrentTimeStep)
{
	Event *pE;
	while( EventsQueue.peekFront(pE) )	//as long as there are more events
	{
		if(pE->getEventTime() > CurrentTimeStep )	//no more events at current time
			return;
		pE->Execute(this);
		EventsQueue.dequeue(pE);	//remove event from the queue
		delete pE;	//deallocate event object from memory
	}
}
Region* Restaurant::getregion(REGION c) {

	if (c == A_REG)
		return &R[0];
	else if (c == B_REG)
		return &R[1];
	else if (c == C_REG)
		return &R[2];
	else if (c == D_REG)
		return &R[3];

}
void Restaurant::printinfo() {
	long long c1 = R[2].VIP.getsize();
	long long c3 = R[2].normalorder.size();
	long long c2 = R[2].frozenorder.size();
	string c22 = to_string(c2);
	string c33 = to_string(c3);
	string c11 = to_string(c1);
	long long A1 = R[0].VIP.getsize();
	long long A3 = R[0].normalorder.size();
	long long A2 = R[0].frozenorder.size();
	string A22 = to_string(A2);
	string A33 = to_string(A3);
	string A11 = to_string(A1);
	long long B1 = R[1].VIP.getsize();
	long long B3 = R[1].normalorder.size();
	long long B2 = R[1].frozenorder.size();
	string B22 = to_string(B2);
	string B33 = to_string(B3);
	string B11 = to_string(B1);
	long long D1 = R[3].VIP.getsize();
	long long D3 = R[3].normalorder.size();
	long long D2 = R[3].frozenorder.size();
	string D22 = to_string(D2);
	string D33 = to_string(D3);
	string D11 = to_string(D1);

	long long man = R[0].NormalIdle.size();
	long long maf = R[0].FrozenIdle.size();
	long long mav = R[0].VipIdle.size();
	string man1 = to_string(man);
	string maf1 = to_string(maf);
	string mav1 = to_string(mav);

	long long mbn = R[1].NormalIdle.size();
	long long mbf = R[1].FrozenIdle.size();
	long long mbv = R[1].VipIdle.size();
	string mbn1 = to_string(mbn);
	string mbf1 = to_string(mbf);
	string mbv1 = to_string(mbv);

	long long mcn = R[2].NormalIdle.size();
	long long mcf =R[2].FrozenIdle.size();
	long long mcv = R[2].VipIdle.size();
	string mcn1 = to_string(mcn);
	string mcf1 = to_string(mcf);
	string mcv1 = to_string(mcv);

	long long mdn = R[3].NormalIdle.size();
	long long mdf = R[3].FrozenIdle.size();
	long long mdv = R[3].VipIdle.size();
	string mdn1 = to_string(mdn);
	string mdf1 = to_string(mdf);
	string mdv1 = to_string(mdv);
	long long t=t_s;
	string ts = to_string(t);
	AllordersArray();
	sortfinish();
	int As = allorders[0].size();
	int Bs = allorders[1].size();
	int Cs = allorders[2].size();
	int Ds = allorders[3].size();
	int Acount = 0;
	for (int i = 0; i < As ; i++) {
		if (ALLORDERS[0][i]->getFinish() <= t_s) {
			Acount++;
		}
		else break;

	}
	int Bcount = 0;
	for (int i = 0; i < Bs; i++) {
		if (ALLORDERS[1][i]->getFinish() <= t_s) {
			Bcount++;
		}
		else break;

	}
	int Ccount = 0;
	for (int i = 0; i < Cs ; i++) {
		if (ALLORDERS[2][i]->getFinish() <= t_s) {
			Ccount++;
		}
		else break;

	}
	int Dcount = 0;
	for (int i = 0; i < Ds ; i++) {
		if (ALLORDERS[3][i]->getFinish() <= t_s) {
			Dcount++;
		}
		else break;

	}
	int totalcount = Acount + Bcount + Ccount + Dcount;

	long long Acountl=Acount;
	long long Bcountl=Bcount;
	long long Ccountl=Ccount;
	long long Dcountl=Dcount;
	long long totall=totalcount;
	string Ado1 = to_string(Acountl);
	string Bdo1 = to_string(Bcountl);
	string Cdo1 = to_string(Ccountl);
	string Ddo1 = to_string(Dcountl); 
	string Tdo1=to_string(totall);
	pGUI->PrintMessage("the active events in A : " + A33 + "  " + A22 + "  " + A11 + "    the active events in B : " + B33 + "  " + B22 + "  " + B11 + "    the active events in C : " + c33 + "  " + c22 + "  " + c11 + "     the active events in D : " + D33 + "   " + D22 + "  " + D11, "the motors in A : " + man1 + " " + maf1 + " " + mav1 + "    the motors in B : " + mbn1 + " " + mbf1 + " " + mbv1 + "    the motors in C : " + mcn1 + " " + mcf1 + " " + mcv1 + "     the motors in D : " + mdn1 + "  " + mdf1 + " " + mdv1, "time step:" + ts, "dlivered ordersin A: " + Ado1 + "    dlivered ordres in region B: " + Bdo1 + "    dlivered orders in C: " + Cdo1 + "    dlivered orders in D: " + Ddo1+ "   total dlivered orders in all regions: "+Tdo1);
	printinfodynamic();
}
void Restaurant::printinfodynamic()
{
	AllordersArray();
	int k = 0;
	int x;
	double y = 500;
	string r;
	while (k < 4) {
		x = 10;
		if (k == 1) {
			r = "regionB : ";
		}
		else if (k == 2) {
			r = "regionC : ";
		}
		else if (k == 3) {
			r = "regionD : ";
		}
		else 
		r = "regionA : ";
		pGUI->printdynamic(r, x, y);
		x += 65;
		for (int i = allorders[k].size() - 1; i >= 0; i--) {
			if ((ALLORDERS[k])[i]->getwt() + (ALLORDERS[k])[i]->getarr() == t_s) {
				string s;
				if ((ALLORDERS[k])[i]->getmotorcycle()->gettype() == TYPE_NRM)
					s = 'N';
				else if ((ALLORDERS[k])[i]->getmotorcycle()->gettype() == TYPE_VIP)
					s = 'V';
				else
					s = 'F';
				long long idmotor = (ALLORDERS[k])[i]->getmotorcycle()->getid();
				s += to_string(idmotor);
				s += '(';
				if ((ALLORDERS[k])[i]->GetType() == TYPE_NRM)
					s += 'N';
				else if ((ALLORDERS[k])[i]->GetType() == TYPE_VIP)
					s += 'V';
				else
					s += 'F';
				long long idorder = (ALLORDERS[k])[i]->GetID();
				s += to_string(idorder);
				s += ')';
				pGUI->printdynamic(s, x, y);
				x += 60;
				if (x > 1200) {
					y += 20;
					x = 10;
				}
			}
			else {
				break;
			}
		}
		y += 20;
		k++;
	}
}
void Restaurant::InterActive(int ts) {
	t_s = 1;
	bool test = R[0].normalorder.isempty() && R[0].frozenorder.isEmpty() && R[0].VIP.isEmpty() && R[1].normalorder.isempty() && R[1].frozenorder.isEmpty() && R[1].VIP.isEmpty() && R[2].normalorder.isempty() && R[2].frozenorder.isEmpty() && R[2].VIP.isEmpty() && R[3].normalorder.isempty() && R[3].frozenorder.isEmpty() && R[3].VIP.isEmpty();
	
	while (!EventsQueue.isEmpty()||!test) {
		ExecuteEvents(t_s);
		Auto_Promote();
		
		test = R[0].normalorder.isempty() && R[0].frozenorder.isEmpty() && R[0].VIP.isEmpty() && R[1].normalorder.isempty() && R[1].frozenorder.isEmpty() && R[1].VIP.isEmpty() && R[2].normalorder.isempty() && R[2].frozenorder.isEmpty() && R[2].VIP.isEmpty() && R[3].normalorder.isempty() && R[3].frozenorder.isEmpty() && R[3].VIP.isEmpty();
		
		this->addarrays();
		
		printinfo();
		
		pGUI->UpdateInterface();
		
		pGUI->DrawOrders();
		Sleep(700);
		pGUI->ResetDrawingList();
		
		checkmotor();
		
		pGUI->UpdateInterface();
		
		assignmotors();
		
		this->addarrays();
		
		pGUI->UpdateInterface();
		
		pGUI->DrawOrders();
		
		pGUI->ResetDrawingList();
		
		printinfo();
		
		pGUI->waitForClick();
		
		
		t_s++;
		
	}
	this->addarrays();
	
	pGUI->UpdateInterface();
	
	pGUI->DrawOrders();
	Auto_Promote();
	printinfo();
	
	pGUI->waitForClick();
	
	AllordersArray();
	
	sortfinish();
	
	printorders();
	
}

void Restaurant::Addmotors(REGION r,int speedN, int speedF, int speedV, int NoN, int NoF, int NoV) {
	int j = 0;
	if(r == A_REG) 
		j = 0;
	else if (r == B_REG)
		j = 1;
	else if (r == C_REG)
		j = 2;
	else if (r == D_REG)
		j = 3;
	R[j].MOTORF = NoF;
	R[j].MOTORN = NoN;
	R[j].MOTORV = NoV;
	for (int i = 0; i < NoN; i++) {
		Motorcycle*m=new Motorcycle;
		m->setspeed(speedN);
		m->setid(i + 1);
		m->setregion(r);
		m->settype(TYPE_NRM);
		m->setstatus(IDLE);
		getregion(r)->NormalIdle.enqueue(m);
	}
	for (int i = 0; i < NoF; i++) {
		Motorcycle* m = new Motorcycle;
		m->setspeed(speedF);
		m->setid(i + 1);
		m->setregion(r);
		m->settype(TYPE_FROZ);
		m->setstatus(IDLE);
		getregion(r)->FrozenIdle.enqueue(m);
	}
	for (int i = 0; i < NoV; i++) {
		Motorcycle* m = new Motorcycle;
		m->setspeed(speedV);
		m->setid(i + 1);
		m->setregion(r);
		m->settype(TYPE_VIP);
		m->setstatus(IDLE);
		getregion(r)->VipIdle.enqueue(m);
	}

}

void Restaurant::addarrays() {
	int i = 0;
	while(i<4){
		int n1 = R[i].normalorder.size();
		int n2 = R[i].frozenorder.size();
		int n3 = R[i].VIP.getsize();
		Order**p1 = new Order*[n1];
		p1 = R[i].normalorder.toArray();
		Order**p2 = new Order*[n2];
		p2 = R[i].frozenorder.toArray();
		Order**p3 = new Order*[n3];
		p3 = R[i].VIP.toArray();
		for (int i = 0; i < n3; i++) {
			pGUI->AddOrderForDrawing(p3[i]);
		}

		for (int i = 0; i < n2; i++) {
			pGUI->AddOrderForDrawing(p2[i]);
		}
		for (int i = 0; i < n1; i++) {
			pGUI->AddOrderForDrawing(p1[i]);
		}
		i++;
	}
	
	
}
void Restaurant::assignmotors(){
	int i = 0;
	while (i < 4) {
		while (!R[i].VIP.isEmpty()) {
			if (!R[i].VipIdle.isEmpty()) {
				Order* r;
				R[i].VIP.pop(r);
				allorders[i].enqueue(r);
				Motorcycle* m;
				R[i].VipIdle.dequeue(m);
				m->setTOreturn(r->GetDistance(), t_s);
				R[i].VipServ.add(m);
				r->setmotor(m);
				r->settime(t_s);
				R[i].VIPcount++;

			}
			else if (!R[i].NormalIdle.isEmpty()) {
				Order* r;
				R[i].VIP.pop(r);
				allorders[i].enqueue(r);
				Motorcycle* m;
				R[i].NormalIdle.dequeue(m);

				m->setTOreturn(r->GetDistance(), t_s);
				R[i].NormalServ.add(m);
				r->setmotor(m);
				r->settime(t_s);
				R[i].VIPcount++;
			}
			else if (!R[i].FrozenIdle.isEmpty()) {
				Order* r;
				R[i].VIP.pop(r);
				allorders[i].enqueue(r);
				Motorcycle* m;
				R[i].FrozenIdle.dequeue(m);
				m->setTOreturn(r->GetDistance(), t_s);
				R[i].FrozenServ.add(m);
				r->setmotor(m);
				r->settime(t_s);
				R[i].VIPcount++;
			}
			else { break; }

		}
		i++;
	}
	i = 0;
	while (i < 4) {
		while (R[i].VIP.isEmpty() && !R[i].frozenorder.isEmpty()) {
			if (!R[i].FrozenIdle.isEmpty()) {
				Order* r;
				R[i].frozenorder.dequeue(r);
				allorders[i].enqueue(r);
				Motorcycle* m;
				R[i].FrozenIdle.dequeue(m);
				m->setTOreturn(r->GetDistance(), t_s);
				R[i].FrozenServ.add(m);
				r->setmotor(m);
				r->settime(t_s);
				R[i].FRZcount++;
			}
			else { break; }
		}
		i++;
	}
	i = 0;
	while (i < 4) {
		while (R[i].VIP.isEmpty() && !R[i].normalorder.isempty()) {
			if (!R[i].NormalIdle.isEmpty()) {
				Order* r;
				R[i].normalorder.DeleteFirst(r);
				allorders[i].enqueue(r);
				Motorcycle* m;
				R[i].NormalIdle.dequeue(m);
				m->setTOreturn(r->GetDistance(), t_s);
				R[i].NormalServ.add(m);

				r->setmotor(m);
				r->settime(t_s);
				R[i].Normalcount++;
			}
			else if (!R[i].VipIdle.isEmpty()) {
				Order* r;
				R[i].normalorder.DeleteFirst(r);
				allorders[i].enqueue(r);
				Motorcycle* m;
				R[i].VipIdle.dequeue(m);
				m->setTOreturn(r->GetDistance(), t_s);
				R[i].VipServ.add(m);

				r->setmotor(m);
				r->settime(t_s);
				R[i].Normalcount++;
			}
			else { break; }
		}
		i++;
	}
}
void Restaurant::AllordersArray() {
	int s[4];
	for (int i = 0; i < 4; i++) {
		s[i] = allorders[i].size();
	}
	for (int i = 0; i < 4; i++) {
		ALLORDERS[i] = new Order*[s[i]];
		ALLORDERS[i] = allorders[i].toArray();
	}
}
void Restaurant::sortfinish() {
	int s[4];
	for (int i = 0; i < 4; i++) {
		s[i]= allorders[i].size();
	}
	int k = 0;
	while (k < 4) {
		for (int i = 0; i < s[k] - 1; i++) {
			for (int j = i + 1; j < s[k]; j++) {
				if ((ALLORDERS[k])[i]->getFinish() > (ALLORDERS[k])[j]->getFinish()) {
					Order* tmp = (ALLORDERS[k])[j];
					(ALLORDERS[k])[j] = (ALLORDERS[k])[i];
					(ALLORDERS[k])[i] = tmp;
				}
			}
		}
		k++;
	}
	k=0;
	while (k < 4) {
		for (int i = 0; i < s[k] - 1; i++) {
			for (int j = i + 1; j < s[k]; j++) {
				if ((ALLORDERS[k])[i]->getFinish() == (ALLORDERS[k])[j]->getFinish()) {
					if ((ALLORDERS[k])[i]->getst() > (ALLORDERS[k])[j]->getst()){
					Order* tmp = (ALLORDERS[k])[j];
					(ALLORDERS[k])[j] = (ALLORDERS[k])[i];
					(ALLORDERS[k])[i] = tmp;}
				}
			}
		}
		k++;
	}
}
string Restaurant::Get_File_Name() {
	pGUI = new GUI;
	pGUI->PrintMessage("Please write the File Name:(1)TEST1, (2)TEST2, (3)TEST3,(4)TEST4,(5)TEST5,(6)TEST6 ", " ", " "," ");
	f_n = pGUI->GetString();
	while (f_n != "TEST1" && f_n != "TEST2" && f_n != "TEST3"&&f_n != "TEST4"&&f_n != "TEST5"&&f_n != "TEST6") {
		pGUI->PrintMessage("Please write the File Name:(1)TEST1, (2)TEST2, (3)TEST3,(4)TEST4,(5)TEST5,(6)TEST6 ", " ", " "," ");
		f_n = pGUI->GetString();
	}
	return f_n;
}

void Restaurant::printorders()
{
	string l;
	ofstream out(f_n+"OUT.txt");
	int motorn = 0;
	int motorf = 0;
	int motorv = 0;
	int avgwt = 0;
	int avgst = 0;
	int s[4];
	int i = 0;
	while (i < 4) {
		s[i] = allorders[i].size();
		i++;
	}
	int j = 0;
	while (j < 4) {
		motorn = R[j].NormalIdle.size();
		motorf = R[j].FrozenIdle.size();
		motorv = R[j].VipIdle.size();
		for (int i = 0; i < s[j]; i++)
		{
			avgwt += (ALLORDERS[j])[i]->getwt();
			avgst += (ALLORDERS[j])[i]->getst();
			TOTAL_MONEY += (ALLORDERS[j])[i]->getMoney();
			(ALLORDERS[j])[i]->print(out);
		}
		avgst /= s[j];
		avgwt /= s[j];
		if(j==0)
		    out << "RegionA:" << endl;
		else if(j==1)
			out << "RegionB:" << endl;
		else if(j==2)
		    out << "RegionC:" << endl;
		else
			out << "RegionD:" << endl;
		out << "    " << "orders: " << R[j].VIPcount + R[j].FRZcount + R[j].Normalcount << "  " << "[Norm:" << R[j].Normalcount << ", Froz:" << R[j].FRZcount << ", VIP:" << R[j].VIPcount << "]" << endl;
		out << "    " << "Motorc:" <<R[j].MOTORN +R[j].MOTORV + R[j].MOTORF << "  " << "[Norm:" << R[j].MOTORN << " ,Froz:" <<R[j].MOTORF << " ,VIP:" << R[j].MOTORV << "]" << endl;
		out << "    " << "AVG WAIT=" << avgwt << "   " << "AVD SERV =" << avgst << endl << endl;

		avgwt = 0;
		avgst = 0;

		j++;
	}
}
void Restaurant::SILENT() {
	t_s = 1;
	bool test = R[0].normalorder.isempty() && R[0].frozenorder.isEmpty() && R[0].VIP.isEmpty() && R[1].normalorder.isempty() && R[1].frozenorder.isEmpty() && R[1].VIP.isEmpty() && R[2].normalorder.isempty() && R[2].frozenorder.isEmpty() && R[2].VIP.isEmpty() && R[3].normalorder.isempty() && R[3].frozenorder.isEmpty() && R[3].VIP.isEmpty();

	while (!EventsQueue.isEmpty() || !test) {
		ExecuteEvents(t_s);
		Auto_Promote();
		test = R[0].normalorder.isempty() && R[0].frozenorder.isEmpty() && R[0].VIP.isEmpty() && R[1].normalorder.isempty() && R[1].frozenorder.isEmpty() && R[1].VIP.isEmpty() && R[2].normalorder.isempty() && R[2].frozenorder.isEmpty() && R[2].VIP.isEmpty() && R[3].normalorder.isempty() && R[3].frozenorder.isEmpty() && R[3].VIP.isEmpty();
		checkmotor();
		assignmotors();
		t_s++;
	}
	AllordersArray();
	sortfinish();
	printorders();

}
void Restaurant::STEP_BY_STEP() {
	t_s = 1;
	bool test = R[0].normalorder.isempty() && R[0].frozenorder.isEmpty() && R[0].VIP.isEmpty() && R[1].normalorder.isempty() && R[1].frozenorder.isEmpty() && R[1].VIP.isEmpty() && R[2].normalorder.isempty() && R[2].frozenorder.isEmpty() && R[2].VIP.isEmpty() && R[3].normalorder.isempty() && R[3].frozenorder.isEmpty() && R[3].VIP.isEmpty();

	while (!EventsQueue.isEmpty() || !test) {
		ExecuteEvents(t_s);
		Auto_Promote();
		test = R[0].normalorder.isempty() && R[0].frozenorder.isEmpty() && R[0].VIP.isEmpty() && R[1].normalorder.isempty() && R[1].frozenorder.isEmpty() && R[1].VIP.isEmpty() && R[2].normalorder.isempty() && R[2].frozenorder.isEmpty() && R[2].VIP.isEmpty() && R[3].normalorder.isempty() && R[3].frozenorder.isEmpty() && R[3].VIP.isEmpty();

		this->addarrays();
		printinfo();

		pGUI->UpdateInterface();
		pGUI->DrawOrders();
		Sleep(1000);
		
		pGUI->ResetDrawingList();
		checkmotor();
		assignmotors();
		this->addarrays();
		pGUI->UpdateInterface();
		pGUI->DrawOrders();
		pGUI->ResetDrawingList();
		printinfo();
		Sleep(1000);
		t_s++;
	}
	this->addarrays();
	pGUI->UpdateInterface();
	pGUI->DrawOrders();
	printinfo();
	Sleep(1000);
	AllordersArray();
	sortfinish();
	printorders();
}
void Restaurant::checkmotor()
{
	bool test = true;
	int i = 0;
	while (i < 4) {
		test = true;
		while (test && !R[i].VipServ.isEmpty()) {
			Motorcycle* m;
			R[i].VipServ.peek(m);
			if (m->getTOreturn() == t_s) {
				R[i].VipServ.pop(m);
				R[i].VipIdle.enqueue(m);
			}
			else {
				test = false;
			}
		}
		i++;
	}
	test = true;
	i = 0;
	while (i < 4) {
		test = true;
		while (test && !R[i].FrozenServ.isEmpty()) {
			Motorcycle* m;
			R[i].FrozenServ.peek(m);
			if (m->getTOreturn() == t_s) {
				R[i].FrozenServ.pop(m);
				R[i].FrozenIdle.enqueue(m);
			}
			else {
				test = false;
			}
		}
		i++;
	}
		test = true;
		i = 0;
	while (i < 4) {
		test = true;
		while (test && !R[i].NormalServ.isEmpty()) {
				Motorcycle* m;
				R[i].NormalServ.peek(m);
				if (m->getTOreturn() == t_s) {
					R[i].NormalServ.pop(m);
					R[i].NormalIdle.enqueue(m);
				}
				else {
					test = false;
				}
			}
			i++;
		}
}
Restaurant::~Restaurant()
{
	int s[4];
	for (int i = 0; i < 4; i++) {
		s[i]= allorders[i].size();
	}
	int k = 0;
	while (k < 4) {
		for (int i = 0; i < s[k]; i++) {
			delete (ALLORDERS[k])[i];
		}
		k++;
	}
	k = 0;
	while (k < 4) {
		while (!R[k].NormalIdle.isEmpty()) {
			Motorcycle*m;
			R[k].NormalIdle.dequeue(m);
			delete m;
		}
		k++;
	}
	k = 0;
	while (k < 4) {
		while (!R[k].FrozenIdle.isEmpty()) {
			Motorcycle*m;
			R[k].FrozenIdle.dequeue(m);
			delete m;
		}
		k++;
	}
	k = 0;
	while (k < 4) {
		while (!R[k].VipIdle.isEmpty()) {
			Motorcycle*m;
			R[k].VipIdle.dequeue(m);
			delete m;
		}
		k++;
	}
	delete pGUI;
}

void Restaurant::Auto_Promote()
{
	Order* O;
	int k = 0;
	while (k < 4) {
		if (!R[k].normalorder.isempty()) {
			O = R[k].normalorder.Find(0);
		}
		else
			return;
		while (O != NULL && R[k].normalorder.Find(0) && O->OverWait(t_s, Autopromotion)) {
			O = R[k].normalorder.Find(0);
			R[k].normalorder.DeleteFirst(O);
			O->promote();
			
			R[k].VIP.add(O);
			

		}
		k++;
	}
}
void Restaurant::setpromote(int op)
{
	Autopromotion = op;
}

string Restaurant::get_outfile_name()
{
	GUI pGUI;
	pGUI.PrintMessage("Please write the output File Name ", " ", " ", " ");
	o_n= pGUI.GetString();
	return o_n;
}







