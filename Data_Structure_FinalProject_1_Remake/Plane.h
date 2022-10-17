#pragma once
#include <iostream>
#include <ctime>
#include "Setting.h"

enum Plane_states	//飞机状态
{
	null,			//无状态(已经达成目的)
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

	bool check() const;														//飞机警报

	Plane_states getState()const { return m_state; }						//返回飞机状态

	void emergencyLanding(ostream& out);									//紧急降落
	bool report(ostream& out);												//降落或者起飞时返回true，已经达成目的返回false

	//void depart(ostream& out)const;	//起飞
	//void land(ostream& out)const;		//普通降落

	int getTimeRemaining()const { return this->m_timeRemaining; }

private:
	int m_id;																//飞机编号
	Plane_states m_state;													//飞机状态

	int m_timeRemaining;													//剩余时间(-1表示飞机处于准备起飞状态)
	int m_waitingTime;														//等待时间
};

