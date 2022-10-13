#include "Plane.h"

ostream& operator<<(ostream& out, const Plane& p)
{
	out << "编号为：" << p.m_id << "的飞机";
	if (p.m_timeRemaining > 0)
		out << "尚未降落，剩余时间为" << p.m_timeRemaining << endl;
	else
		out << "等待起飞" << endl;
	return out;
}

Plane::Plane(int id, Plane_states state)
	:m_id(id), m_waitingTime(0)
{
	if (state == arriving)
		this->m_timeRemaining = rand() % MAX_TIME + 1;
	else
		this->m_timeRemaining = -1;
}
