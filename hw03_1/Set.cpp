#include "Set.h"
#include <iostream>
int Set::generateMember() const
{
	if (isEmpty)
		throw std::out_of_range("Empty set");
	while (1)
	{
		if (iter = INT_MAX)
		{
			isEmpty = true;
			break;
		}
		if (contains(iter))
			return (++iter - 1);
		iter++;
	}
}
void Set::printAllMembersInInterval(int a, int b) const
{
	for (int i = a; i <= b; i++)
	{
		if (contains(i))
			std::cout << i << " ";
	}
}