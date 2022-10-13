#pragma once
#include <iostream>
#include <ctime>
#include "Setting.h"
using std::ostream;
using std::endl;
using std::pair;

enum Plane_states//�ɻ�״̬(�����ò���)
{
	null,		//��״̬
	arriving,	//׼������
	departing	//׼�����
};

class Plane
{
	friend ostream& operator<< (ostream& out, const Plane& p);				//��ӡ�ɻ���Ϣ
public:
	Plane(int id, int t)													//����ɻ������ʣ��ʱ�乹��
		:m_id(id), m_timeRemaining(t), m_waitingTime(0) {}
	Plane(int id, Plane_states state);

	void refresh() { this->m_timeRemaining--; }								//ˢ�·ɻ�ʣ��ʱ��

	bool check() const { return this->m_timeRemaining == EMERGENCY_TIME; }	//�ɻ�����


private:
	int m_id;																//�ɻ����
	int m_timeRemaining;													//ʣ��ʱ��(-1��ʾ�ɻ�����׼�����״̬)
	int m_waitingTime;														//�ȴ�ʱ��
};

