#pragma once
#include "Set.h"
#include "MyVector.hpp"
class UnionOfSets: public Set
{
	MyVector<Set*> _sets;

public:
	UnionOfSets(MyVector<Set*>&& sets);
	bool contains(int x) const override;
	int generateMember() const;
	void printAllMembersInInterval(int a, int b) const;
};

