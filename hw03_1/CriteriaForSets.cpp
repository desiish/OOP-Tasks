#include "CriteriaForSets.h"
#include "HelperFunctions.h"
#include <iostream>
bool isInGivenSet(int n, const int* nums, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		if (nums[i] == n)
			return true;
	}
	return false;
}
bool cannotBeDividedByGivenSet(int n, const int* nums, size_t size)
{
	return (n % lcm(nums, size)) != 0;
}
bool isDivisibleByExactlyOneOfGivenSet(int n, const int* nums, size_t size)
{
	int* copyOfNums = new int[size];
	for (int i = 0; i < size; i++)
		copyOfNums[i] = nums[i];
	for (int i = 0; i < size; i++)
	{
		bool isSwapped = false;
		if (i != 0)
		{
			std::swap(copyOfNums[i], copyOfNums[0]);
			isSwapped = true;
		}
		if (n % copyOfNums[0] == 0 && cannotBeDividedByGivenSet(n, copyOfNums + 1, size - 1))
		{
			delete[] copyOfNums;
			return true;
		}
		if (isSwapped)
			std::swap(copyOfNums[i], copyOfNums[0]);
	}
	delete[] copyOfNums;
	return false;
}