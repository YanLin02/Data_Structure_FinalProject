#pragma once
#include "myQueue.h"
#include "mySeqList.h"
#include "Plane.h"
#include "Setting.h"

class Runway
{
	//打印跑道信息
	friend ostream& operator<< (ostream& out, const Runway& way) {
		out << ">>> " << way.m_id << " 号跑道情况：\n";

		out << "等待队列：\n";
		int taknum = way.getTaskNum();
		if (taknum == 0)
			out << " + 空 \n";
		for (size_t i = 0; i < taknum; i++)
			if (way.l_infoList[i].getState() != null)
				out << way.l_infoList[i];
		out << "=======================================================================\n";
		return out;
	}
public:

	Runway(int id) :m_id(id) {}

	u_int getTaskNum() const;													//返回任务量

	void addPlane(const Plane& p);												//添加飞机任务

	void use(ostream& out);														//使用跑道

	void refreshAll(); 															//更新飞机信息

	u_int checkPlane(ostream& out);												 //检测飞机油量，返回迫降飞机数

private:
	int m_id;										//跑道id
	myQueue<Plane> q_waitingQueue;					//等待队列
	mySeqList<Plane> l_infoList;					//信息队列（与等待对应）
};

