#pragma once
#include <iostream>
#include <ctime>
#include "Setting.h"
using std::ostream;
using std::endl;
using std::pair;

enum Plane_states	//�ɻ�״̬
{
	arriving,		//׼������
	departing		//׼�����
};

class Plane
{
	friend ostream& operator<< (ostream& out, const Plane& p);				//��ӡ�ɻ���Ϣ
public:
	Plane(int id, int t);													//����ɻ������ʣ��ʱ�乹��
	Plane(int id, Plane_states state);

	void refresh();															//ˢ�·ɻ�ʱ��

	bool check() const { return this->m_timeRemaining == EMERGENCY_TIME; }	//�ɻ�����


private:
	int m_id;																//�ɻ����
	Plane_states m_state;													//�ɻ�״̬

	int m_timeRemaining;													//ʣ��ʱ��(-1��ʾ�ɻ�����׼�����״̬)
	int m_waitingTime;														//�ȴ�ʱ��
};

