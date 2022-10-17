#pragma once
#include "Plane.h"
#include "Runway.h"
#include "Setting.h"
#include <fstream>
#include <string>

class AirportManager
{

public:
	AirportManager();																		//��������

	void RandomTest(ostream& out, u_int num = 1);											//ͨ�����������

	void inputFromKeyboard();																//��������

	void inputFromFile(string inputPath = "Input.txt", string outputPath = "Output.txt");	//�ļ�����

private:

	void PlaneAddToLanding(ostream& out, int number = -1);					//����һ�������Ľ���ɻ�(�Զ�����ʱ��)
	void PlaneAddToLanding(ostream& out, int number, int times[]);			//����һ�������Ľ���ɻ�(�ֶ�����ʱ��)

	void PlaneAddToDeparting(ostream& out, int number = -1);				//����һ����������ɷɻ�

	void nextTurn(ostream& out);											//������һʱ��

	void showShowWay(ostream& out);											//��ʾ�ܵ�����

	void showLogs(ostream& out);											//��ʾͳ����Ϣ

	int checkEmergencyLanding(ostream& out);								//����Ƿ��зɻ���Ҫ�Ƚ�

	Runway& getMinQueue(Plane_states state);								//���ݴ���״̬����һ��������С���ܵ�

	void takeLog(const Plane& p) {											//��¼������Ϣ
		sum_landing_number++;
		sum_landing_wait += p.getWaitingTime();
		if (p.getState() == landing)
			sum_landing_Remaining += p.getTimeRemaining();
	}

private:

	Runway way_1, way_2, way_3;

	int sum_departing_wait;			//����ܵȴ�ʱ��
	int sum_departing_number;		//���������
	int sum_departing_add;			//��ӵ���ɷɻ����� id = 2k

	int sum_landing_wait;			//�����ܵȴ�ʱ��
	int sum_landing_number;			//����������
	int sum_landing_add;			//��ӵ���½�ɻ����� id = 2k+1
	int sum_landing_Remaining;		//������ʣ����ʱ��

	int sum_emergency_landing;		//��������ɻ���
};

