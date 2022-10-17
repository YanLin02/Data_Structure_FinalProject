#include "AirportManager.h"

AirportManager::AirportManager()
	:sum_landing_number(0), sum_landing_wait(0), sum_landing_add(0),
	sum_departing_number(0), sum_departing_wait(0), sum_departing_add(0),
	sum_emergency_landing(0), sum_landing_Remaining(0),
	way_1(1), way_2(2), way_3(3)
{
	srand(time(NULL));
}

void AirportManager::RandomTest(ostream& out, u_int num)
{
	for (size_t i = 0; i < num; i++)
	{
		out << ">>>>>>>>>>>> 第 " << i + 1 << " 单位时间 <<<<<<<<<<<<\n\n";
		PlaneAddToLanding(out);
		PlaneAddToDeparting(out);
		out << endl;
		showShowWay(out);
		nextTurn(out);
		showLogs(out);
	}
}

void AirportManager::inputFromKeyboard()
{
	int number = 0, t = 0;
	int time[3] = { 0,0,0 };
	cout << ">>>>>>>>>>>> 第 " << t++ + 1 << " 单位时间 <<<<<<<<<<<<\n\n";

	cout << "请输入准备着陆的飞机数（0-3），输入 -1 结束进程：";
	cin >> number;
	while ((number >= 0) && (number <= 3))
	{
		if (number != 0) cout << "请输入准备着陆的飞机油量\n";
		for (int i = 0; i < number; i++)
			cin >> time[i];
		PlaneAddToLanding(cout, number, time);

		cout << "请输入准备起飞的飞机数（0-3）:";
		cin >> number;
		PlaneAddToDeparting(cout, number, 0);

		cout << endl;
		showShowWay(cout);
		nextTurn(cout);
		showLogs(cout);

		cout << ">>>>>>>>>>>> 第 " << t++ + 1 << " 单位时间 <<<<<<<<<<<<\n\n";
		cout << "请输入准备着陆的飞机数（0-3），输入 -1 结束进程：";
		cin >> number;
	}
}

void AirportManager::inputFromFile(string inputPath, string outputPath)
{
	ifstream in(inputPath);
	ofstream out(outputPath);

	if (!in.is_open())
	{
		out << inputPath << "打开失败！";
		cout << inputPath << "打开失败！";
		exit(0);
	}

	int number = 0, t = 0;
	int time[3] = { 0,0,0 };
	in >> number;
	while ((number >= 0) && (number <= 3) && (in.peek() != EOF))
	{
		out << ">>>>>>>>>>>> 第 " << t++ + 1 << " 单位时间 <<<<<<<<<<<<\n\n";
		for (int i = 0; i < number; i++)
			in >> time[i];
		PlaneAddToLanding(out, number, time);

		in >> number;
		PlaneAddToDeparting(out, number, 0);

		out << endl;
		showShowWay(out);
		nextTurn(out);
		showLogs(out);

		in >> number;
	}

}


void AirportManager::PlaneAddToLanding(ostream& out, int number)
{
	//若输入非法数据，则随机产生一定数量的飞机
	if (number < 0 || number > MAX_PLANE_NUM)
		number = rand() % 4;
	/*循环number次*/
	for (size_t i = 0; i < number; i++)
	{
		//查询最小的降落队列,将飞机插入降落队列
		this->getMinQueue(landing).addLandingPlane(Plane(sum_landing_add * 2 + 1, landing));//编号为 2*sum_landing_add+1
		sum_landing_add++;
	}
	out << number << " 架飞机进入降落队列\n";
}

void AirportManager::PlaneAddToLanding(ostream& out, int number, int times[])
{
	//若输入非法数据，则抛出异常
	if (number < 0 || number > MAX_PLANE_NUM)
		throw invalid_argument("非法参数：飞机数量输入错误!");
	/*循环number次*/
	for (size_t i = 0; i < number; i++)
	{
		//查询最小的降落队列,将飞机插入降落队列
		this->getMinQueue(landing).addLandingPlane(Plane(sum_landing_add * 2 + 1, times[i]));//编号为 2*sum_landing_add+1
		sum_landing_add++;
	}
	out << number << " 架飞机进入降落队列\n";
}

void AirportManager::PlaneAddToDeparting(ostream& out, int number)
{
	//若输入非法数据，则随机产生一定数量的飞机
	if (number < 0 || number > MAX_PLANE_NUM)
		number = rand() % 4;
	/*循环number次*/
	for (size_t i = 0; i < number; i++)
	{
		//查询最小的起飞队列,将飞机插入队列
		this->getMinQueue(departing).addDepartingPlane(Plane(sum_departing_add * 2, departing));
		sum_departing_add++;
	}
	out << number << " 架飞机进入起飞队列\n";
}

void AirportManager::PlaneAddToDeparting(ostream& out, int number, bool temp)
{
	//若输入非法数据，则抛出异常
	if (number < 0 || number > MAX_PLANE_NUM)
		throw invalid_argument("非法参数：飞机数量输入错误!");
	/*循环number次*/
	for (size_t i = 0; i < number; i++)
	{
		//查询最小的起飞队列,将飞机插入队列
		this->getMinQueue(departing).addDepartingPlane(Plane(sum_departing_add * 2, departing));
		sum_departing_add++;
	}
	out << number << " 架飞机进入起飞队列\n";
}

void AirportManager::nextTurn(ostream& out)
{
	switch (this->checkEmergencyLanding(out))
	{
	case 0://三条跑道均可使用
		if (way_1.modSwitch() == landing)
			takeLog(way_1.landPlane(), out);
		else if (way_1.modSwitch() == departing)
			departLog(way_1.departPlane(), out);

		if (way_2.modSwitch() == landing)
			takeLog(way_2.landPlane(), out);
		else if (way_2.modSwitch() == departing)
			departLog(way_2.departPlane(), out);

		if (way_3.modSwitch() != null)
			departLog(way_3.departPlane(), out);
		break;

	case 1://第三条用于迫降，其他正常
		if (way_1.modSwitch() == landing)
			takeLog(way_1.landPlane(), out);
		else if (way_1.modSwitch() == departing)
			departLog(way_1.departPlane(), out);

		if (way_2.modSwitch() == landing)
			takeLog(way_2.landPlane(), out);
		else if (way_2.modSwitch() == departing)
			departLog(way_2.departPlane(), out);
		break;

	case 2://第三条和12中任务较小的迫降
		if (way_1.getTaskNum() <= way_2.getTaskNum())
		{
			if (way_1.modSwitch() == landing)
				takeLog(way_1.landPlane(), out);
			else if (way_1.modSwitch() == departing)
				departLog(way_1.departPlane(), out);
		}
		else
		{
			if (way_2.modSwitch() == landing)
				takeLog(way_2.landPlane(), out);
			else if (way_2.modSwitch() == departing)
				departLog(way_2.departPlane(), out);
		}
		break;

	case 3://全部迫降
		break;
	}
	//刷新每架飞机
	way_1.refreshAll();
	way_2.refreshAll();
	way_3.refreshAll();
}

void AirportManager::showShowWay(ostream& out)
{
	out << way_1 << way_2 << way_3 << endl;
}

void AirportManager::showLogs(ostream& out)
{
	out << "\n##############################################\n";
	out << "\t起飞的平均等待时间:" << (sum_departing_number == 0 ? 0 : (double(sum_departing_wait) / sum_departing_number)) << endl;
	out << "\t着陆的平均等待时间:" << (sum_landing_number == 0 ? 0 : (double(sum_landing_wait) / sum_landing_number)) << endl;
	out << "\t着陆的平均剩余油量:" << (sum_landing_number == 0 ? 0 : (double(sum_landing_Remaining) / sum_landing_number)) << endl;
	out << "\t紧急降落的飞机数量:" << sum_emergency_landing << endl;
	out << "##############################################\n\n";
}

int AirportManager::checkEmergencyLanding(ostream& out)
{
	int emergencyLanding = 0;
	int way_1PlaneNum = way_1.getLandingNum();
	int way_2PlaneNum = way_2.getLandingNum();
	for (size_t i = 0; i < way_1PlaneNum; i++)
	{
		if (way_1.checkPlane(i))
		{
			emergencyLanding++;
			emergencyLog(way_1.emergencyPlane(i), out);
		}
	}
	for (size_t i = 0; i < way_2PlaneNum; i++)
	{
		if (way_2.checkPlane(i))
		{
			emergencyLanding++;
			emergencyLog(way_2.emergencyPlane(i), out);
		}
	}
	if (emergencyLanding > 3)
	{
		out << "迫降数量过多，机场无力承载！\n";
		exit(0);
	}
	return emergencyLanding;
}

Runway& AirportManager::getMinQueue(Plane_states state)
{
	Runway* min = nullptr;
	if (state == departing)	//起飞搜索
	{
		min = &way_1;
		if (min->getDepartingNum() > way_2.getDepartingNum())
			min = &way_2;
		if (min->getDepartingNum() > way_3.getDepartingNum())
			min = &way_3;
	}
	else					//降落搜索
		min = (way_1.getLandingNum() <= way_2.getLandingNum() ? &way_1 : &way_2);
	return *min;
}

