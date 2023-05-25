#pragma once
#include "Set.h"
#include "MyVector.hpp"
class SetByCriteria: public Set
{
public:
	struct Criteria
	{
		int _numbers[32] = { 0 };
		size_t _sizeOfArr = 0;
		bool (*_pred)(int n, const int* nums, size_t size);

		Criteria(bool (*pred)(int n, const int* nums, size_t size), const int* numbers, size_t sizeOfArr) : _pred(pred) 
		{
			_sizeOfArr = sizeOfArr;
			for (int i = 0; i < sizeOfArr; i++)
				_numbers[i] = numbers[i];
		}
	};

private:
	Criteria MyCr;

public:
	SetByCriteria(bool (*pred)(int n, const int* nums, size_t size), const int* numbers, size_t sizeOfArr);
	bool contains(int) const override;
	int generateMember() const;
	void printAllMembersInInterval(int a, int b) const;
	~SetByCriteria() override;
};

