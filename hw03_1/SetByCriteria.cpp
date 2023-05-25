#include "SetByCriteria.h"
SetByCriteria::SetByCriteria(bool (*pred)(int n, const int* nums, size_t size), const int* numbers, size_t sizeOfArr) :
	MyCr(pred, numbers, sizeOfArr){}

bool SetByCriteria::contains(int x) const 
{
	return MyCr._pred(x, MyCr._numbers, MyCr._sizeOfArr);
}
int SetByCriteria::generateMember() const 
{
	return Set::generateMember();
}
void SetByCriteria::printAllMembersInInterval(int a, int b) const
{
	Set::printAllMembersInInterval(a, b);
}
SetByCriteria::~SetByCriteria() = default;