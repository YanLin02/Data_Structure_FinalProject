#pragma once
//#include "myQueue.h"
#include "mySeqList.h"
#include "Plane.h"
#include "Setting.h"

//class AirportManager;
class Runway
{
	friend class AirportManager;
	friend ostream& operator<< (ostream& out, const Runway& way);				//打印跑道信息
public:

	Runway(int id) :m_id(id) {}

	u_int getLandingNum()const { return q_landing.getLength(); }
	u_int getDepartingNum()const { return q_departing.getLength(); }

	void addLandingPlane(const Plane& p) { q_landing.push_back(p); }
	void addArrivingPlane(const Plane& p) { q_departing.push_back(p); }

	double averageLandingWait() {												//返回预计降落等待平均时间
		double sum = 0;
		for (size_t i = 0; i < q_landing.getLength(); i++)
			sum += q_landing[i].getTimeRemaining();
		return sum / q_landing.getLength();
	}

	Plane_states modSwitch() {													//判断任务优先级
		return (q_landing.getLength() >= q_departing.getLength() ? landing : departing);
	}

private:
	int m_id;

	mySeqList<Plane> q_landing;
	mySeqList<Plane> q_departing;
};

ostream& operator<<(ostream& out, const Runway& way)
{
	out << ">>> " << way.m_id << " 号跑道情况：\n";
	out << "降落等待队列：\n";
	for (size_t i = 0; i < way.getLandingNum(); i++)
		out << way.q_landing[i];
	out << "起飞等待队列：\n";
	for (size_t i = 0; i < way.getDepartingNum(); i++)
		out << way.q_departing[i];

	out << "===============================================\n";

	return out;
}
