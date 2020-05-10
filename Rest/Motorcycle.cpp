#include "Motorcycle.h"


Motorcycle::Motorcycle()
{

}


Motorcycle::~Motorcycle()
{
}
bool Motorcycle::IsAvilable(int ts)
{
	return(timetoreturn == ts);
}

void Motorcycle::setTOreturn(int dis, int ts)
{
	timetoreturn = (dis/speed)*2 + ts;
}
int Motorcycle::getTOreturn()
{
	return timetoreturn;
}
bool Motorcycle::operator<=(Motorcycle c)
{
	return (timetoreturn > c.timetoreturn);
}
void Motorcycle::setid(int d){
	ID=(d>0)?d:0;
}
void Motorcycle::settype(ORD_TYPE t){
	type=t;
}
void Motorcycle::setspeed(int s){
	speed=s;
}
void Motorcycle::setregion(REGION r){
	region=r;
}
void Motorcycle::setstatus(STATUS st){
	status=st;
}
int Motorcycle::getid(){
	return ID;
}
ORD_TYPE Motorcycle::gettype(){
	return type;
}
int Motorcycle::getspeed(){
	return speed;
}
REGION Motorcycle::getregion(){
	return region;
}
STATUS Motorcycle::getstatus(){
	return status;
}
