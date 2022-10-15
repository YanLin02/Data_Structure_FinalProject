#pragma once
#include <iostream>
#include <ctime>
#include "Setting.h"
//using std::ostream;
//using std::endl;
//using std::pair;

enum Plane_states	//飞机状态
{
	null,			//无状态
	landing,		//准备降落
	departing		//准备起飞
};

class Plane
{
	friend ostream& operator<< (ostream& out, const Plane& p);				//打印飞机信息
public:
	Plane();																//默认构造（队列用）
	Plane(int id, int t);													//传入飞机编号与剩余时间构造
	Plane(int id, Plane_states state);

	void refresh();															//刷新飞机时间

	bool check() const { return this->m_timeRemaining == EMERGENCY_TIME; }	//飞机警报

	void emergencyLanding(ostream& out);
	void land(ostream& out);
	void depart(ostream& out);

	int getTimeRemaining()const { return this->m_timeRemaining; }

private:
	int m_id;																//飞机编号
	Plane_states m_state;													//飞机状态

	int m_timeRemaining;													//剩余时间(-1表示飞机处于准备起飞状态)
	int m_waitingTime;														//等待时间
};

