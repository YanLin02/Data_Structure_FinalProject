#pragma once
#include <iostream>

using std::ostream;
using std::endl;
using std::pair;

//enum Plane_states//飞机状态(可能用不到)
//{
//	null,//无状态
//	arriving,//准备降落
//	departing//准备起飞
//};

class Plane
{
	friend ostream& operator<< (ostream& out, const Plane& p);	//打印飞机信息
public:
	Plane(int id, int t)										//传入飞机编号与剩余时间构造
		:m_id(id), m_timeRemaining(t) {}
	Plane(pair<int, int> args)									//一次传入两个参数构造
		:m_id(args.first), m_timeRemaining(args.second) {}

	void refresh();												//刷新飞机

	bool check() const { return this->m_timeRemaining == 1; }	//飞机警报


private:
	int m_id;													//飞机编号
	int m_timeRemaining;										//剩余时间(-1表示飞机处于准备起飞状态)
};

