#pragma once
#include <string>
#include <list>
#include "Hiker.h"

using namespace std;

class Bridge
{
public:
	Bridge(void);
	~Bridge(void);

	Bridge(double len, string name);
	Bridge(list<Hiker> team, double len);

	unsigned addHiker(Hiker &h);

	list<Hiker> hiker_list;
	list<Hiker> crossed_bridge_list;
	string name_id;
	double length;
	Hiker getHiker(int index);
	double team_cross_bridge();
	double bridge_cross(Hiker &H1, Hiker &H2); // returns the bridge cross time
	double torch_return(Hiker &H, bool verbose); // returns the torch return time
	double get_min_and_max_delay(int &min_speed_index, int &max_speed_index); // function should accept a list of Hiker classes and
							// return the minimum crossing delay and the pairs that crossed
	void   set_crossed(int index, bool crossed);
	double bridge_cross_time; // accumulater for the amount of time crossing the bridge ths far
	int get_number_not_crossed(); // get the number of members who have not crossed the Bridge yet
	void print();
};

