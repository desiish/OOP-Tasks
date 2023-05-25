#include "HelperFunctions.h"

MyString readStringFromFile(std::ifstream& ifs)
{
	int len;
	ifs.read((char*)&len, sizeof(len));

	char* buff = new char[len + 1];
	ifs.read(buff, sizeof(char) * len);
	buff[len] = '\0';

	MyString res(buff);
	delete[] buff;
	return res;
}
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int lcm(int a, int b)
{
	return (a / gcd(a, b)) * b;
}
int lcm(const int* nums, size_t size)
{
	if (size == 0)
		return 1;
	if (size == 1)
		return nums[0];
	int LCM = lcm(nums[0], nums[1]);
	for (int i = 2; i < size; i++)
		LCM = lcm(LCM, nums[i]);

	return LCM;
}