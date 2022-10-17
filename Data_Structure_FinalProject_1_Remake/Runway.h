#pragma once
#include "myQueue.h"
#include "mySeqList.h"
#include "Plane.h"
#include "Setting.h"

class Runway
{
	friend ostream& operator<< (ostream& out, const Runway& way) {				
		out << ">>> " << way.m_id << " ���ܵ������\n";

		out << "�ȴ����У�\n";
		int taknum = way.getTaskNum();
		if (taknum == 0)
			out << " + �� \n";
		for (size_t i = 0; i < taknum; i++)
			out << way.l_infoList[i];
		out << "=======================================================================\n";
		return out;
	}
																				//��ӡ�ܵ���Ϣ
public:

	Runway(int id) :m_id(id) {}

	u_int getTaskNum() const;													//����������

	void addLandingPlane(const Plane& p);										//��ӽ���ɻ�
	void addDepartingPlane(const Plane& p);										//�����ɷɻ�

	Plane landPlane();															//�ɻ�����
	Plane departPlane();														//�ɻ����
	Plane emergencyPlane(u_int index);											//�����Ƚ�

	Plane_states modSwitch();													//�ж��������ȼ�

	void refreshAll(); 															//���·ɻ���Ϣ

	bool checkPlane(u_int index);									 			//���ɻ�����

private:
	int m_id;										//�ܵ�id

	myQueue<Plane> q_waitingQueue;					//�ȴ�����
	mySeqList<Plane> l_infoList;					//��Ϣ���У���ȴ���Ӧ��
};

