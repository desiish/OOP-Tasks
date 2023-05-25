#include "IntersectionOfSets.h"
IntersectionOfSets::IntersectionOfSets(MyVector<Set*>&& sets)
{
	size_t size = sets.size();
	for (int i = 0; i < size; i++)
		_sets.push_back(std::move(sets[i]));
}
bool IntersectionOfSets::contains(int x) const 
{
	size_t size = _sets.size();
	for (int i = 0; i < size; i++)
	{
		if (!_sets[i]->contains(x))
			return false;
	}
	return true;
}
int IntersectionOfSets::generateMember() const
{
	return Set::generateMember();
}
void IntersectionOfSets::printAllMembersInInterval(int a, int b) const
{
	Set::printAllMembersInInterval(a, b);
}