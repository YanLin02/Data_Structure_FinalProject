#pragma once
#include "Plane.h"
#include "Runway.h"
#include "Setting.h"
#include <fstream>
#include <string>

class AirportManager
{

public:
	AirportManager();																		//设置种子

	void RandomTest(ostream& out, u_int num = 1);											//通过随机数输入

	void inputFromKeyboard();																//键盘输入

	void inputFromFile(ostream& out, string inputPath = "Input.txt");						//文件输入

private:

	void PlaneAddToLanding(ostream& out, int number = -1);					//插入一定数量的降落飞机(自动分配时间)
	void PlaneAddToLanding(ostream& out, int number, int times[]);			//插入一定数量的降落飞机(手动分配时间)

	void PlaneAddToDeparting(ostream& out, int number = -1);				//插入一定数量的起飞飞机

	void nextTurn(ostream& out);											//进入下一时间

	void showShowWay(ostream& out);											//显示跑道队列

	void showLogs(ostream& out);											//显示统计信息

	int checkEmergencyLanding(ostream& out);								//检测是否有飞机需要迫降

	Runway& getMinQueue(Plane_states state);								//根据传入状态返回一个长度最小的跑道

	void takeLog(const Plane& p) {											//记录降落信息
		switch (p.getState())
		{
		case landing:
			sum_landing_number++;
			sum_landing_wait += p.getWaitingTime();
			sum_landing_Remaining += p.getTimeRemaining();
			break;
		case departing:
			sum_departing_number++;
			sum_departing_wait += p.getWaitingTime();
			break;
		case null:
		default:
			break;
		}
	}

private:

	Runway way_1, way_2, way_3;

	int sum_departing_wait;			//起飞总等待时间
	int sum_departing_number;		//起飞总数量
	int sum_departing_add;			//添加的起飞飞机数量 id = 2k

	int sum_landing_wait;			//降落总等待时间
	int sum_landing_number;			//降落总数量
	int sum_landing_add;			//添加的着陆飞机数量 id = 2k+1
	int sum_landing_Remaining;		//降落后的剩余总时间

	int sum_emergency_landing;		//紧急降落飞机数
};

