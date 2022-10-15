#pragma once
//#include "myQueue.h"
#include "mySeqList.h"
#include "Plane.h"
#include "Setting.h"

class Runway
{
	friend ostream& operator<< (ostream& out, const Runway& way) {				//打印跑道信息
		out << ">>> " << way.m_id << " 号跑道情况：\n";

		out << "降落等待队列：\n";
		if (way.getLandingNum() == 0)
			out << " + 空 \n";
		for (size_t i = 0; i < way.getLandingNum(); i++)
			out << way.q_landing[i];

		out << "起飞等待队列：\n";
		if (way.getDepartingNum() == 0)
			out << " + 空 \n";
		for (size_t i = 0; i < way.getDepartingNum(); i++)
			out << way.q_departing[i];

		out << "=======================================================================\n";
		return out;
	}
public:

	Runway(int id) :m_id(id) {}

	u_int getLandingNum()const { return q_landing.getLength(); }				//降落任务数
	u_int getDepartingNum()const { return q_departing.getLength(); }			//起飞任务数
	u_int getTaskNum() const { return getDepartingNum() + getLandingNum(); }	//返回任务量

	void addLandingPlane(const Plane& p) { q_landing.push_back(p); }			//添加降落飞机
	void addDepartingPlane(const Plane& p) { q_departing.push_back(p); }		//添加起飞飞机

	Plane landPlane() { return this->q_landing.pop_front(); }					//飞机降落
	Plane departPlane() { return this->q_departing.pop_front(); }				//飞机起飞
	Plane emergencyPlane(u_int index) { return q_landing.Delete(index); }		//紧急迫降
	//double averageLandingWait() {												//返回预计降落等待平均时间
	//	double sum = 0;
	//	for (size_t i = 0; i < q_landing.getLength(); i++)
	//		sum += q_landing[i].getTimeRemaining();
	//	return sum / q_landing.getLength();
	//}

	Plane_states modSwitch() {													//判断任务优先级
		if (q_departing.isEmpty() && q_landing.isEmpty())
			return null;
		return (getLandingNum() >= getDepartingNum() ? landing : departing);
	}


	void refreshAll() {															//更新飞机信息
		for (size_t i = 0; i < getLandingNum(); i++)
			q_landing[i].refresh();
		for (size_t i = 0; i < getDepartingNum(); i++)
			q_departing[i].refresh();
	}

	bool checkPlane(u_int index) { return q_landing[index].check(); }			//检测飞机油量

private:
	int m_id;

	mySeqList<Plane> q_landing;
	mySeqList<Plane> q_departing;
};

