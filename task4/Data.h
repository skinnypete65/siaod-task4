#pragma once
#include <string>

using namespace std;
class Data
{
public:

	string groupNumber;
	string fullName;

	Data(string groupNumber, string fullName) {
		this->groupNumber = groupNumber;
		this->fullName = fullName;
	}
};

