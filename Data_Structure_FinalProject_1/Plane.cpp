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
