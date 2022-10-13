#include "Plane.h"

ostream& operator<<(ostream& out, const Plane& p)
{
	out << "���Ϊ��" << p.m_id << "�ķɻ�";
	if (p.m_timeRemaining > 0)
		out << "��δ���䣬ʣ��ʱ��Ϊ" << p.m_timeRemaining << endl;
	else
		out << "�ȴ����" << endl;
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
