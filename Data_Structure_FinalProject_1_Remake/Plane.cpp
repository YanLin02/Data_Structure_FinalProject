#include "Plane.h"

ostream& operator<<(ostream& out, const Plane& p)
{
	out << " + ���Ϊ��" << p.m_id << " �ķɻ�";
	switch (p.m_state)
	{
	case landing:
		out << "��δ���䣬�Ѿ��ȴ���" << p.m_waitingTime << " ��λʱ�䣬ʣ������Ϊ��" << p.m_timeRemaining << endl;
		break;
	case departing:
		out << "�ȴ���ɣ��Ѿ��ȴ���" << p.m_waitingTime << " ��λʱ��" << endl;
		break;
	default:
		break;
	}
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
	if (this->m_state == null) return;	//���Ŀ�ĵķɻ����ٸ���
	if (this->m_state == landing)		//����ķɻ���������
		this->m_timeRemaining--;
	this->m_waitingTime++;				//�ȴ�ʱ������
}

bool Plane::check()const
{
	return (m_state == landing) ? (this->m_timeRemaining <= EMERGENCY_TIME) : false;
}

void Plane::emergencyLanding(ostream& out)
{
	m_state = null;
	out << this->m_id << "�ŷɻ��������䣡\n";
}

//void Plane::land(ostream& out)const
//{
//	out << this->m_id << "�ŷɻ����䣬�ȴ�ʱ��Ϊ��" << this->m_waitingTime << " ʣ������Ϊ��" << this->m_timeRemaining << endl;
//}
//
//void Plane::depart(ostream& out)const
//{
//	out << this->m_id << "�ŷɻ���ɣ��ȴ�ʱ��Ϊ��" << this->m_waitingTime << endl;
//}

bool Plane::report(ostream& out)
{
	switch (m_state)
	{
	case landing:		//׼����½
		m_state = null;
		out << this->m_id << "�ŷɻ����䣬�ȴ�ʱ��Ϊ��" << this->m_waitingTime << " ʣ������Ϊ��" << this->m_timeRemaining << endl;
		return true;
	case departing:		//׼�����
		m_state = null;
		out << this->m_id << "�ŷɻ���ɣ��ȴ�ʱ��Ϊ��" << this->m_waitingTime << endl;
		return true;
	case null:
	default:
		return false;
	}
}
