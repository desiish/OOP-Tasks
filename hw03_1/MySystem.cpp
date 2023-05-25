#include "MySystem.h"
#include <iostream>
#include "SetByCriteria.h"
#include "UnionOfSets.h"
#include "IntersectionOfSets.h"
#include <fstream>
#include "HelperFunctions.h"
#include "CriteriaForSets.h"

Set* readSetFromFile(const MyString& inputFile)
{
	std::ifstream ifs("set.dat", std::ios::in | std::ios::binary);
	if (!ifs.is_open())
		throw "Error";
	short N, T;
	ifs.read((char*)&N, sizeof(short));
	ifs.read((char*)&T, sizeof(short));
	if (T > 32)
	{
		ifs.clear();
		ifs.close();
		throw std::invalid_argument("N is too big");
	}
	if (T == 0)
	{
		int nums[32] = { 0 };
		ifs.read((char*)nums, N * sizeof(int));
		Set* setByCr = new SetByCriteria(isInGivenSet, nums, N);
		ifs.clear();
		ifs.close();
		return setByCr;
	}
	else if (T == 1)
	{
		int nums[32] = { 0 };
		ifs.read((char*)nums, N * sizeof(int));
		Set* setByCr = new SetByCriteria(cannotBeDividedByGivenSet, nums, N);
		ifs.clear();
		ifs.close();
		return setByCr;
	}
	else if (T == 2)
	{
		int nums[32] = { 0 };
		ifs.read((char*)nums, N * sizeof(int));
		Set* setByCr = new SetByCriteria(isDivisibleByExactlyOneOfGivenSet, nums, N);
		ifs.clear();
		ifs.close();
		return setByCr;
	}
	else if (T == 3)
	{
		MyVector<Set*> sets;
		for (int i = 0; i < N; i++)
		{
			MyString fileName = readStringFromFile(ifs);
			Set* toAdd = readSetFromFile(fileName);
			sets.push_back(std::move(toAdd));
		}
		Set* Union = new UnionOfSets(std::move(sets));
		ifs.clear();
		ifs.close();
		return Union;
	}
	else if (T == 4)
	{
		MyVector<Set*> sets;
		for (int i = 0; i < N; i++)
		{
			MyString fileName = readStringFromFile(ifs);
			Set* toAdd = readSetFromFile(fileName);
			sets.push_back(std::move(toAdd));
		}

		Set* Intersection = new IntersectionOfSets(std::move(sets));
		ifs.clear();
		ifs.close();
		return Intersection;
	}

}

void System()
{
	Set* mySet = readSetFromFile("set.dat");

	int mode;
	std::cin >> mode;
	if (mode == 1)
	{
		int a, b;
		std::cin >> a >> b;
		mySet->printAllMembersInInterval(a, b);
	}
	else if (mode == 2)
	{
		while (1)
		{
			MyString toEnter;
			std::cin >> toEnter;
			if (toEnter == "\n")
				std::cout << mySet->generateMember() << std::endl;
		}
	}
}
