#include "stdafx.h"
#include "Bridge.h"


Bridge::Bridge(void)
{
}


Bridge::~Bridge(void)
{
}

Bridge::Bridge(double len, string name) {
	length = len;
	name_id = name;
}

unsigned Bridge::addHiker(Hiker &h) {

		hiker_list.push_back(h);
		return hiker_list.size();
}


double Bridge::team_cross_bridge() {
	Hiker H1, H2;
	int min_speed_index = 0, max_speed_index = 0, remainingHikers = 0;
	bridge_cross_time = 0;
	while( get_min_and_max_delay(min_speed_index, max_speed_index) > 0) {
		if(min_speed_index == max_speed_index) break;
		H1 = getHiker(min_speed_index);
		H2 = getHiker(max_speed_index);
		set_crossed(min_speed_index, true);
		set_crossed(max_speed_index, true);
		bridge_cross_time += bridge_cross(H1, H2);
		remainingHikers = get_number_not_crossed();
		if(remainingHikers > 0) {
			bridge_cross_time += torch_return(H2, true);
			set_crossed(max_speed_index, false);
		}
		
	}
	cout << "\nbridge_cross_time = " << bridge_cross_time << endl;

	return bridge_cross_time;

}


double Bridge::bridge_cross(Hiker &H1, Hiker &H2) {
	double speed1 = 0, speed2 = 0, time1 = 0, time2 = 0, time = 0;
	speed1 = H1.speed;
	speed2 = H2.speed;
	time1 = length/speed1;
	time2 = length/speed2;
	H1.crossed = true;
	H2.crossed = true;
	if(time1 < time2) time = time2;
	else time = time1;
	cout << endl;
	cout << H1.name_id << " and " << H2.name_id << " crossed " << name_id <<  " in " << time << " minutes" << endl;
	return time; // return max of time1 and time2
}

double Bridge::torch_return(Hiker &H, bool verbose) {

		double speed = H.speed, time = 0;
		time = length/speed;
		H.crossed = false;
		if(verbose) {
			cout << H.name_id << " returned torch across bridge in " << time << " minutes" << endl;
			cout << endl;
		}
		return time;
}


int Bridge::get_number_not_crossed() {
	Hiker H;
	int hikersRemaining = 0;
	for (list<Hiker>::iterator it = hiker_list.begin(); it != hiker_list.end(); it++) {
		H = *it;
		if(!H.crossed) hikersRemaining++;
	}
	cout << "\thikersRemaining = " << hikersRemaining << endl;
	return hikersRemaining;
}


double Bridge::get_min_and_max_delay(int &min_speed_index, int &max_speed_index) {
	int i = 0;
	int min_speed_id = 0, max_speed_id = 0;
	double min_speed = 1000000, max_speed = 0;
	Hiker h;
	
	for (list<Hiker>::iterator it = hiker_list.begin(); it != hiker_list.end(); it++) {
		h = *it;

		if(!h.crossed) {
			// h.print("\t");
			if(h.speed < min_speed) {
				min_speed = h.speed;
				min_speed_id = i;
			}
			if(h.speed > max_speed) {
				max_speed = h.speed;
				max_speed_id = i;
			}
		}
		i++;
	}
	min_speed_index = min_speed_id;
	max_speed_index = max_speed_id;

	return max_speed; // returns time to cross
}

void   Bridge::set_crossed(int index, bool crossed) {
	int i = 0;
	for (list<Hiker>::iterator it = hiker_list.begin(); it != hiker_list.end(); it++) {
		if(i == index) {
			(*it).crossed = crossed;
		}
		i++;
	}
}

Hiker Bridge::getHiker(int index) {
	Hiker H;
	int i = 0;
	for (list<Hiker>::iterator it = hiker_list.begin(); it != hiker_list.end(); it++) {
		if(i == index) {
			H = *it;
		}
		i++;
	}
	return H;
}