#include "cancelevent.h"



cancelevent::cancelevent(int eTime,int oID) :Event(eTime, oID)
{

}
void cancelevent::Execute(Restaurant* pRest)
{
	int n1 = pRest->getregion(A_REG)->normalorder.size();
	int n2 = pRest->getregion(B_REG)->normalorder.size();
	int n3 = pRest->getregion(C_REG)->normalorder.size();
	int n4 = pRest->getregion(D_REG)->normalorder.size();
	Order**p = new Order*[n1];
	Order**p2 = new Order*[n2];
	Order**p3 = new Order*[n3];
	Order**p4 = new Order*[n4];
	Order *o1;
	p = pRest->getregion(A_REG)->normalorder.toArray();
	p2 = pRest->getregion(B_REG)->normalorder.toArray();
	p3 = pRest->getregion(C_REG)->normalorder.toArray();
	p4 = pRest->getregion(D_REG)->normalorder.toArray(); bool test = false;
	for (int i = 0; i < n1; i++) {
		if (p[i]->GetID() == OrderID) {
			o1 = p[i]; test = true;
			break;
		}
	}
	for (int i = 0; i < n2; i++) {
		if (p2[i]->GetID() == OrderID) {
			o1 = p2[i]; test = true;
			break;
		}
	}
	for (int i = 0; i < n3; i++) {
		if (p3[i]->GetID() == OrderID) {
			o1 = p3[i]; test = true;
			break;
		}
	}
	for (int i = 0; i < n4; i++) {
		if (p4[i]->GetID() == OrderID) {
	        o1 = p4[i]; test = true;
			break;
		}
	}
	
	if (!test) return;
	Region* rr= pRest->getregion((o1)->GetRegion());
	rr->normalorder.DeleteNode(o1);
	
}

cancelevent::~cancelevent()
{
}
