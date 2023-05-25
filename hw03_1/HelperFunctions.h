#pragma once
#include "MyString.h"
#include <fstream>

MyString readStringFromFile(std::ifstream& ifs);
int gcd(int a, int b);
int lcm(int a, int b);
int lcm(const int* nums, size_t size);