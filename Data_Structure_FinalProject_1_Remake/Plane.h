#pragma once
#include <iostream>
#include <ctime>
#include "Setting.h"

enum Plane_states	//�ɻ�״̬
{
	null,			//��״̬(�Ѿ����Ŀ��)
	landing,		//׼������
	departing		//׼�����
};

class Plane
{
	friend ostream& operator<< (ostream& out, const Plane& p);				//��ӡ�ɻ���Ϣ
public:
	Plane();																//Ĭ�Ϲ��죨�����ã�
	Plane(int id, int t);													//����ɻ������ʣ��ʱ�乹��
	Plane(int id, Plane_states state);

	void refresh();															//ˢ�·ɻ�ʱ��

	bool check() const;														//�ɻ�����

	Plane_states getState()const { return m_state; }						//���طɻ�״̬

	void emergencyLanding(ostream& out);									//��������
	bool report(ostream& out);												//����������ʱ����true���Ѿ����Ŀ�ķ���false

	//void depart(ostream& out)const;	//���
	//void land(ostream& out)const;		//��ͨ����

	int getTimeRemaining()const { return this->m_timeRemaining; }

private:
	int m_id;																//�ɻ����
	Plane_states m_state;													//�ɻ�״̬

	int m_timeRemaining;													//ʣ��ʱ��(-1��ʾ�ɻ�����׼�����״̬)
	int m_waitingTime;														//�ȴ�ʱ��
};

