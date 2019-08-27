#include "stdafx.h"
#include "Hiker.h"


Hiker::Hiker(void)
{
}


Hiker::~Hiker(void)
{
}


Hiker::Hiker(string name_id_, double speed_) {

	name_id = name_id_;
	speed = speed_;
	crossed = false;
}


void Hiker::print(string delim) {
	cout << delim << "Hiker:\n";
	cout << delim << "\tname_id = " << name_id << endl;
	cout << delim << "\tspeed = " << speed << " (ft/min) " << endl;
	string c;
	(crossed) ? c = "True" : c = "False";
	cout << delim << "\tcrossed bridge = " << c << " (ft/min) " << endl;
}
