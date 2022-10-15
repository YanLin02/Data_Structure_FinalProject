#pragma once
//#include "myQueue.h"
#include "mySeqList.h"
#include "Plane.h"
#include "Setting.h"

class Runway
{
	friend ostream& operator<< (ostream& out, const Runway& way) {				//��ӡ�ܵ���Ϣ
		out << ">>> " << way.m_id << " ���ܵ������\n";

		out << "����ȴ����У�\n";
		if (way.getLandingNum() == 0)
			out << " + �� \n";
		for (size_t i = 0; i < way.getLandingNum(); i++)
			out << way.q_landing[i];

		out << "��ɵȴ����У�\n";
		if (way.getDepartingNum() == 0)
			out << " + �� \n";
		for (size_t i = 0; i < way.getDepartingNum(); i++)
			out << way.q_departing[i];

		out << "=======================================================================\n";
		return out;
	}
public:

	Runway(int id) :m_id(id) {}

	u_int getLandingNum()const { return q_landing.getLength(); }				//����������
	u_int getDepartingNum()const { return q_departing.getLength(); }			//���������
	u_int getTaskNum() const { return getDepartingNum() + getLandingNum(); }	//����������

	void addLandingPlane(const Plane& p) { q_landing.push_back(p); }			//��ӽ���ɻ�
	void addDepartingPlane(const Plane& p) { q_departing.push_back(p); }		//�����ɷɻ�

	Plane landPlane() { return this->q_landing.pop_front(); }					//�ɻ�����
	Plane departPlane() { return this->q_departing.pop_front(); }				//�ɻ����
	Plane emergencyPlane(u_int index) { return q_landing.Delete(index); }		//�����Ƚ�
	//double averageLandingWait() {												//����Ԥ�ƽ���ȴ�ƽ��ʱ��
	//	double sum = 0;
	//	for (size_t i = 0; i < q_landing.getLength(); i++)
	//		sum += q_landing[i].getTimeRemaining();
	//	return sum / q_landing.getLength();
	//}

	Plane_states modSwitch() {													//�ж��������ȼ�
		if (q_departing.isEmpty() && q_landing.isEmpty())
			return null;
		return (getLandingNum() >= getDepartingNum() ? landing : departing);
	}


	void refreshAll() {															//���·ɻ���Ϣ
		for (size_t i = 0; i < getLandingNum(); i++)
			q_landing[i].refresh();
		for (size_t i = 0; i < getDepartingNum(); i++)
			q_departing[i].refresh();
	}

	bool checkPlane(u_int index) { return q_landing[index].check(); }			//���ɻ�����

private:
	int m_id;

	mySeqList<Plane> q_landing;
	mySeqList<Plane> q_departing;
};

