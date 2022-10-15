#include "Plane.h"

ostream& operator<<(ostream& out, const Plane& p)
{
	out << "编号为：" << p.m_id << "的飞机";
	if (p.m_state == landing)
		out << "尚未降落，已经等待：" << p.m_waitingTime << "单位时间，剩余时间为" << p.m_timeRemaining << endl;
	else
		out << "等待起飞，已经等待：" << p.m_waitingTime << "单位时间" << endl;
	return out;
}

Plane::Plane()
	:m_id(-1), m_timeRemaining(-1), m_waitingTime(-1), m_state(null) {}

Plane::Plane(int id, int t)
	:m_id(id), m_timeRemaining(t), m_waitingTime(0)
{
	if (t < 0)
		this->m_state = departing;
	else
		this->m_state = landing;
}


Plane::Plane(int id, Plane_states state)
	:m_id(id), m_waitingTime(0), m_state(state)
{
	if (state == landing)
		this->m_timeRemaining = rand() % MAX_TIME + 1;
	else
		this->m_timeRemaining = -1;
}

void Plane::refresh()
{
	if (this->m_state == landing)
		this->m_timeRemaining--;
	this->m_waitingTime++;
}
