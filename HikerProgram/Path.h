#pragma once
#include <list>
#include "Bridge.h";

using namespace std;

class Path // the path class represents a list (Path) of Bridges
{
public:
	Path(void);
	virtual ~Path(void);

	Path(list<Bridge> bridge_list_);
	list<Bridge> bridge_list;

	void print();
};

