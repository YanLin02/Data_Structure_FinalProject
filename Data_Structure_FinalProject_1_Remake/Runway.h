#pragma once
#include "myQueue.h"
#include "mySeqList.h"
#include "Plane.h"
#include "Setting.h"

class Runway
{
	friend ostream& operator<< (ostream& out, const Runway& way) {				
		out << ">>> " << way.m_id << " 号跑道情况：\n";

		out << "等待队列：\n";
		int taknum = way.getTaskNum();
		if (taknum == 0)
			out << " + 空 \n";
		for (size_t i = 0; i < taknum; i++)
			out << way.l_infoList[i];
		out << "=======================================================================\n";
		return out;
	}
																				//打印跑道信息
public:

	Runway(int id) :m_id(id) {}

	u_int getTaskNum() const;													//返回任务量

	void addLandingPlane(const Plane& p);										//添加降落飞机
	void addDepartingPlane(const Plane& p);										//添加起飞飞机

	Plane landPlane();															//飞机降落
	Plane departPlane();														//飞机起飞
	Plane emergencyPlane(u_int index);											//紧急迫降

	Plane_states modSwitch();													//判断任务优先级

	void refreshAll(); 															//更新飞机信息

	bool checkPlane(u_int index);									 			//检测飞机油量

private:
	int m_id;										//跑道id

	myQueue<Plane> q_waitingQueue;					//等待队列
	mySeqList<Plane> l_infoList;					//信息队列（与等待对应）
};

