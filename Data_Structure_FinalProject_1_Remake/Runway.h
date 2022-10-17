#pragma once
#include "myQueue.h"
#include "mySeqList.h"
#include "Plane.h"
#include "Setting.h"

class Runway
{
	//��ӡ�ܵ���Ϣ
	friend ostream& operator<< (ostream& out, const Runway& way) {
		out << ">>> " << way.m_id << " ���ܵ������\n";

		out << "�ȴ����У�\n";
		int taknum = way.getTaskNum();
		if (taknum == 0)
			out << " + �� \n";
		for (size_t i = 0; i < taknum; i++)
			if (way.l_infoList[i].getState() != null)
				out << way.l_infoList[i];
		out << "=======================================================================\n";
		return out;
	}
public:

	Runway(int id) :m_id(id) {}

	u_int getTaskNum() const;													//����������

	void addPlane(const Plane& p);												//��ӷɻ�����

	void use(ostream& out);														//ʹ���ܵ�

	void refreshAll(); 															//���·ɻ���Ϣ

	u_int checkPlane(ostream& out);												 //���ɻ������������Ƚ��ɻ���

private:
	int m_id;										//�ܵ�id
	myQueue<Plane> q_waitingQueue;					//�ȴ�����
	mySeqList<Plane> l_infoList;					//��Ϣ���У���ȴ���Ӧ��
};

