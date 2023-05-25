#pragma once
#include <climits>
class Set
{
	mutable int iter = INT_MIN;
	mutable bool isEmpty = false;

public:
	virtual bool contains(int) const = 0;
	int generateMember() const;
	void printAllMembersInInterval(int a, int b) const;
	virtual ~Set() = default;
};

