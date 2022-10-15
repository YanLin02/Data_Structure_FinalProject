#include "AirportManager.h"

AirportManager::AirportManager()
	:sum_landing_number(0), sum_landing_time(0), sum_departing_number(0), sum_departing_time(0), sum_departing_add(0), sum_landing_add(0)
{
	srand(time(NULL));
}

void AirportManager::PlaneAddToLanding(int number)
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
}

void AirportManager::PlaneAddToLanding(int number, int times[])
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
}

void AirportManager::PlaneAddToDeparting(int number)
{
	//若输入非法数据，则随机产生一定数量的飞机
	if (number < 0 || number > MAX_PLANE_NUM)
		number = rand() % 4;
	/*循环number次*/
	for (size_t i = 0; i < number; i++)
	{
		//查询最小的起飞队列,将飞机插入队列
		this->getMinQueue(departing).addLandingPlane(Plane(sum_departing_add * 2, departing));
		sum_departing_add++;
	}
}

void AirportManager::PlaneAddToDeparting(int number, int times[])
{
	//若输入非法数据，则抛出异常
	if (number < 0 || number > MAX_PLANE_NUM)
		throw invalid_argument("非法参数：飞机数量输入错误!");
	/*循环number次*/
	for (size_t i = 0; i < number; i++)
	{
		//查询最小的起飞队列,将飞机插入队列
		this->getMinQueue(departing).addLandingPlane(Plane(sum_departing_add * 2, times[i]));
		sum_departing_add++;
	}
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
