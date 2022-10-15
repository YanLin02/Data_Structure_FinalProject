#include "Plane.h"

ostream& operator<<(ostream& out, const Plane& p)
{
	out << "���Ϊ��" << p.m_id << "�ķɻ�";
	if (p.m_state == landing)
		out << "��δ���䣬�Ѿ��ȴ���" << p.m_waitingTime << "��λʱ�䣬ʣ��ʱ��Ϊ" << p.m_timeRemaining << endl;
	else
		out << "�ȴ���ɣ��Ѿ��ȴ���" << p.m_waitingTime << "��λʱ��" << endl;
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
