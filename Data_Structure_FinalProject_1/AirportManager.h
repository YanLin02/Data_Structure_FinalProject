#pragma once
#include "Plane.h"
#include "Runway.h"
#include "Setting.h"


class AirportManager
{

public:
	AirportManager();

	void PlaneAddToArrive(int number = MAX_PLANE_NUM);
	void PlaneAddToLeave(int number = MAX_PLANE_NUM);

private:

	Runway way_1, way_2, way_3;

	int sum_takeoff_time;			//起飞总时间
	int sum_takeoff_number;			//起飞总数量

	int sum_loading_time;			//降落总时间
	int sum_loading_number;			//降落总数量

};

