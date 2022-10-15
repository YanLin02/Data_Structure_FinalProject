#pragma once
#include "Plane.h"
#include "Runway.h"
#include "Setting.h"


class AirportManager
{

public:
	AirportManager();

	//private:

	void PlaneAddToLanding(int number = -1);					//插入一定数量的降落飞机(自动分配时间)
	void PlaneAddToLanding(int number, int times[]);			//插入一定数量的降落飞机(手动分配时间)

	void PlaneAddToDeparting(int number = -1);					//插入一定数量的起飞飞机(自动分配时间)
	void PlaneAddToDeparting(int number, int times[]);			//插入一定数量的起飞飞机(手动分配时间)

	void nextTurn(ostream& out);

	void showShowWay(ostream& out);

	int checkEmergencyLanding(ostream& out);

	Runway& getMinQueue(Plane_states state);					//根据传入状态返回一个长度最小的跑道

	void landLog(const Plane& p, ostream& out) {
		sum_landing_number++;
		sum_landing_wait += p.m_waitingTime;
		sum_landing_Remaining += p.m_timeRemaining;
		p.land(out);
	}

	//void emergencyLog(const Plane& p, ostream& out);

	void departLog(const Plane& p, ostream& out) {
		sum_departing_number++;
		sum_departing_wait += p.m_waitingTime;
		p.depart(out);
	}

private:

	Runway way_1, way_2, way_3;

	int sum_departing_wait;			//起飞总等待时间
	int sum_departing_number;		//起飞总数量
	int sum_departing_add;			//添加的起飞飞机数量 id = 2k

	int sum_landing_wait;			//降落总等待时间
	int sum_landing_number;			//降落总数量
	int sum_landing_add;			//添加的着陆飞机数量 id = 2k+1
	int sum_landing_Remaining;		//降落后的剩余总时间

	int sum_emergency_landing;		//紧急降落飞机数
};

