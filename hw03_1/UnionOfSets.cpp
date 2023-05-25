#include "UnionOfSets.h"
UnionOfSets::UnionOfSets(MyVector<Set*>&& sets)
{
	size_t size = sets.size();
	for (int i = 0; i < size; i++)
		_sets.push_back(std::move(sets[i]));
}
bool UnionOfSets::contains(int x) const
{
	size_t size = _sets.size();
	for (int i = 0; i < size; i++)
	{
		if (_sets[i]->contains(x))
			return true;
	}
	return false;
}
int UnionOfSets::generateMember() const
{
	return Set::generateMember();
}
void UnionOfSets::printAllMembersInInterval(int a, int b) const
{
	Set::printAllMembersInInterval(a, b);
}
UnionOfSets::~UnionOfSets() = default;