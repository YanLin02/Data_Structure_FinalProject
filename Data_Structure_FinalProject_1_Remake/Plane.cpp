#include "Plane.h"

ostream& operator<<(ostream& out, const Plane& p)
{
	out << " + 编号为：" << p.m_id << " 的飞机";
	switch (p.m_state)
	{
	case landing:
		out << "尚未降落，已经等待：" << p.m_waitingTime << " 单位时间，剩余油量为：" << p.m_timeRemaining << endl;
		break;
	case departing:
		out << "等待起飞，已经等待：" << p.m_waitingTime << " 单位时间" << endl;
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
	if (this->m_state == null) return;	//达成目的的飞机不再更新
	if (this->m_state == landing)		//降落的飞机减少油量
		this->m_timeRemaining--;
	this->m_waitingTime++;				//等待时间增加
}

bool Plane::check()const
{
	return (m_state == landing) ? (this->m_timeRemaining <= EMERGENCY_TIME) : false;
}

void Plane::emergencyLanding(ostream& out)
{
	m_state = null;
	out << this->m_id << "号飞机紧急降落！\n";
}

//void Plane::land(ostream& out)const
//{
//	out << this->m_id << "号飞机降落，等待时间为：" << this->m_waitingTime << " 剩余油量为：" << this->m_timeRemaining << endl;
//}
//
//void Plane::depart(ostream& out)const
//{
//	out << this->m_id << "号飞机起飞，等待时间为：" << this->m_waitingTime << endl;
//}

bool Plane::report(ostream& out)
{
	switch (m_state)
	{
	case landing:		//准备着陆
		m_state = null;
		out << this->m_id << "号飞机降落，等待时间为：" << this->m_waitingTime << " 剩余油量为：" << this->m_timeRemaining << endl;
		return true;
	case departing:		//准备起飞
		m_state = null;
		out << this->m_id << "号飞机起飞，等待时间为：" << this->m_waitingTime << endl;
		return true;
	case null:
	default:
		return false;
	}
}
