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

	int sum_takeoff_time;			//�����ʱ��
	int sum_takeoff_number;			//���������

	int sum_loading_time;			//������ʱ��
	int sum_loading_number;			//����������

};

