#include "Runway.h"

u_int Runway::getTaskNum() const
{
	u_int num = 0;
	for (size_t i = 0; i < l_infoList.getLength(); i++)
		if (l_infoList[i].getState() != null)
			num++;
	return num;
}

void Runway::addPlane(const Plane& p)
{
	this->q_waitingQueue.push(p);
	this->l_infoList.push_back(p);
}

void Runway::use(ostream& out)
{
	while (!l_infoList.at(0).report(out))
	{
		//�㱨ʧ�ܾͻ���һ���㱨
		this->l_infoList.pop_front();
		this->q_waitingQueue.pop();
	}
	//�㱨�ɹ���ѻ㱨��Ҳ����
	this->l_infoList.pop_front();
	this->q_waitingQueue.pop();
}

void Runway::refreshAll()
{
	for (size_t i = 0; i < l_infoList.getLength(); i++)
		l_infoList[i].refresh();
}

u_int Runway::checkPlane(ostream& out)
{
	u_int num = 0;
	for (size_t i = 0; i < l_infoList.getLength(); i++)
		if (l_infoList[i].check())
		{
			num++;
			l_infoList[i].emergencyLanding(out);
		}
	return num;
}
