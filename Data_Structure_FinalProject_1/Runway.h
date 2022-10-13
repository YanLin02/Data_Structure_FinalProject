#pragma once
#include <queue>
#include "Plane.h"
#include "Setting.h"
using std::queue;

class Runway
{
public:
	Runway();




private:
	queue<Plane> q_landing_1;
	queue<Plane> q_takeoff;


};

