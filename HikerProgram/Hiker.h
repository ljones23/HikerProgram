#pragma once

#include <iostream>
#include <string>


using namespace std;

class Hiker
{
public:
	Hiker(void);
	virtual ~Hiker(void);

	Hiker(string name_id_, double speed_);

	string name_id;
	double speed;
	bool crossed;

	void print(string delim);
};

