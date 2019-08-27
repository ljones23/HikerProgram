// HikerProgram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include "Hiker.h"
#include "Bridge.h"
#include "Path.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Hiker H1, H2, *hptr1, *hptr2, *hptr3, *hptr4, *hptr5, *hptr6, *hptr7;
	Bridge *bPtr1, *bPtr2, *bPtr3;
	int min_speed_id = 0 , max_speed_id = 0;
	double cross_time = 0, tot_cross_time = 0;

	hptr1 = new Hiker("A", 100);
	hptr2 = new Hiker("B", 50);
	hptr3 = new Hiker("C", 20);
	hptr4 = new Hiker("D", 10);
	hptr5 = new Hiker("E", 2.5);
	hptr6 = new Hiker("F", 25);
	hptr7 = new Hiker("G", 15);

	bPtr1 = new Bridge(100, "Bridge1");
	bPtr1->addHiker(*hptr1);
	bPtr1->addHiker(*hptr2);
	bPtr1->addHiker(*hptr3);
	bPtr1->addHiker(*hptr4);

	bPtr2 = new Bridge(250, "Bridge2");
	bPtr2->addHiker(*hptr1);
	bPtr2->addHiker(*hptr2);
	bPtr2->addHiker(*hptr3);
	bPtr2->addHiker(*hptr4);
	bPtr2->addHiker(*hptr5);

	bPtr3 = new Bridge(150, "Bridge3");
	bPtr3->addHiker(*hptr1);
	bPtr3->addHiker(*hptr2);
	bPtr3->addHiker(*hptr3);
	bPtr3->addHiker(*hptr4);
	bPtr3->addHiker(*hptr5);
	bPtr3->addHiker(*hptr6);
	bPtr3->addHiker(*hptr7);

	cross_time = bPtr1->team_cross_bridge();
	tot_cross_time += cross_time;
	cout << "total time to cross " << bPtr1->name_id << " is " << cross_time << " (minutes)" << endl;
	cross_time = bPtr2->team_cross_bridge();
	tot_cross_time += cross_time;
	cout << "total time to cross " << bPtr2->name_id << " is " << cross_time << " (minutes)" << endl;
	cross_time = bPtr3->team_cross_bridge();
	tot_cross_time += cross_time;
	cout << "total time to cross " << bPtr3->name_id << " is " << cross_time << " (minutes)" << endl;
	cout << endl;
	cout << "total time to cross all bridges is " << tot_cross_time << " (minutes)" << endl;
	return 0;
}

