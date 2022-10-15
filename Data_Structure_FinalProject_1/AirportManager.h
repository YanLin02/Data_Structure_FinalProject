#pragma once
#include "Plane.h"
#include "Runway.h"
#include "Setting.h"


class AirportManager
{

public:
	AirportManager();

private:

	void PlaneAddToLanding(int number = -1);					//����һ�������Ľ���ɻ�(�Զ�����ʱ��)
	void PlaneAddToLanding(int number, int times[]);			//����һ�������Ľ���ɻ�(�ֶ�����ʱ��)

	void PlaneAddToDeparting(int number = -1);					//����һ����������ɷɻ�(�Զ�����ʱ��)
	void PlaneAddToDeparting(int number, int times[]);			//����һ����������ɷɻ�(�ֶ�����ʱ��)

	void nextTurn(ostream& out);

	int checkEmergencyLanding(ostream& out);

	Runway& getMinQueue(Plane_states state);					//���ݴ���״̬����һ��������С���ܵ�


private:

	Runway way_1, way_2, way_3;

	int sum_departing_time;			//�����ʱ��
	int sum_departing_number;		//���������
	int sum_departing_add;			//��ӵ���ɷɻ����� id = 2k

	int sum_landing_time;			//������ʱ��
	int sum_landing_number;			//����������
	int sum_landing_add;			//��ӵ���½�ɻ����� id = 2k+1

	int sum_emergency_landing;
};

