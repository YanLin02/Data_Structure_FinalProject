#pragma once
#include "myQueue.h"
#include "Plane.h"
#include "Setting.h"

//class AirportManager;
class Runway
{
	//friend class AirportManager;
public:

	//Runway();

	u_int getLandingNum()const { return q_landing.size(); }
	u_int getDepartingNum()const { return q_departing.size(); }

	void addLandingPlane(const Plane& p) { q_landing.push(p); }
	void addArrivingPlane(const Plane& p) { q_departing.push(p); }


private:
	myQueue<Plane> q_landing;
	myQueue<Plane> q_departing;


};

