#include "AirportManager.h"

AirportManager::AirportManager()
	:sum_landing_number(0), sum_landing_time(0), sum_landing_add(0),
	sum_departing_number(0), sum_departing_time(0), sum_departing_add(0),
	sum_emergency_landing(0),
	way_1(1), way_2(2), way_3(3)
{
	srand(time(NULL));
}

void AirportManager::PlaneAddToLanding(int number)
{
	//������Ƿ����ݣ����������һ�������ķɻ�
	if (number < 0 || number > MAX_PLANE_NUM)
		number = rand() % 4;
	/*ѭ��number��*/
	for (size_t i = 0; i < number; i++)
	{
		//��ѯ��С�Ľ������,���ɻ����뽵�����
		this->getMinQueue(landing).addLandingPlane(Plane(sum_landing_add * 2 + 1, landing));//���Ϊ 2*sum_landing_add+1
		sum_landing_add++;
	}
}

void AirportManager::PlaneAddToLanding(int number, int times[])
{
	//������Ƿ����ݣ����׳��쳣
	if (number < 0 || number > MAX_PLANE_NUM)
		throw invalid_argument("�Ƿ��������ɻ������������!");
	/*ѭ��number��*/
	for (size_t i = 0; i < number; i++)
	{
		//��ѯ��С�Ľ������,���ɻ����뽵�����
		this->getMinQueue(landing).addLandingPlane(Plane(sum_landing_add * 2 + 1, times[i]));//���Ϊ 2*sum_landing_add+1
		sum_landing_add++;
	}
}

void AirportManager::PlaneAddToDeparting(int number)
{
	//������Ƿ����ݣ����������һ�������ķɻ�
	if (number < 0 || number > MAX_PLANE_NUM)
		number = rand() % 4;
	/*ѭ��number��*/
	for (size_t i = 0; i < number; i++)
	{
		//��ѯ��С����ɶ���,���ɻ��������
		this->getMinQueue(departing).addLandingPlane(Plane(sum_departing_add * 2, departing));
		sum_departing_add++;
	}
}

void AirportManager::PlaneAddToDeparting(int number, int times[])
{
	//������Ƿ����ݣ����׳��쳣
	if (number < 0 || number > MAX_PLANE_NUM)
		throw invalid_argument("�Ƿ��������ɻ������������!");
	/*ѭ��number��*/
	for (size_t i = 0; i < number; i++)
	{
		//��ѯ��С����ɶ���,���ɻ��������
		this->getMinQueue(departing).addLandingPlane(Plane(sum_departing_add * 2, times[i]));
		sum_departing_add++;
	}
}

void AirportManager::nextTurn(ostream& out)
{
	switch (this->checkEmergencyLanding(out))
	{
	case 0://�����ܵ�����ʹ��
		break;
	case 1://�����������Ƚ�����������
		break;
	case 2://��������12�������С���Ƚ�
		break;
	case 3://ȫ���Ƚ�
		break;
	}

}

int AirportManager::checkEmergencyLanding(ostream& out)
{
	int emergencyLanding = 0;
	for (size_t i = 0; i < way_1.getLandingNum(); i++)
	{
		if (way_1.q_landing[i].check())
		{
			emergencyLanding++;
			sum_emergency_landing++;
			way_1.q_landing[i].emergencyLanding(out);
			way_1.q_landing.Delete(i);
		}
	}
	for (size_t i = 0; i < way_2.getLandingNum(); i++)
	{
		if (way_2.q_landing[i].check())
		{
			emergencyLanding++;
			sum_emergency_landing++;
			way_2.q_landing[i].emergencyLanding(out);
			way_2.q_landing.Delete(i);
		}
	}
	if (emergencyLanding > 3)
	{
		out << "�Ƚ��������࣬�����������أ�\n";
		exit(0);
	}
	return emergencyLanding;
}

Runway& AirportManager::getMinQueue(Plane_states state)
{
	Runway* min = nullptr;
	if (state == departing)	//�������
	{
		min = &way_1;
		if (min->getDepartingNum() > way_2.getDepartingNum())
			min = &way_2;
		if (min->getDepartingNum() > way_3.getDepartingNum())
			min = &way_3;
	}
	else					//��������
		min = (way_1.getLandingNum() <= way_2.getLandingNum() ? &way_1 : &way_2);
	return *min;
}
