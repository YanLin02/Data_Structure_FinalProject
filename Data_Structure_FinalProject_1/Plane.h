#pragma once
#include <iostream>

using std::ostream;
using std::endl;
using std::pair;

//enum Plane_states//�ɻ�״̬(�����ò���)
//{
//	null,//��״̬
//	arriving,//׼������
//	departing//׼�����
//};

class Plane
{
	friend ostream& operator<< (ostream& out, const Plane& p);	//��ӡ�ɻ���Ϣ
public:
	Plane(int id, int t)										//����ɻ������ʣ��ʱ�乹��
		:m_id(id), m_timeRemaining(t) {}
	Plane(pair<int, int> args)									//һ�δ���������������
		:m_id(args.first), m_timeRemaining(args.second) {}

	void refresh();												//ˢ�·ɻ�

	bool check() const { return this->m_timeRemaining == 1; }	//�ɻ�����


private:
	int m_id;													//�ɻ����
	int m_timeRemaining;										//ʣ��ʱ��(-1��ʾ�ɻ�����׼�����״̬)
};

