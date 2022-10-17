﻿/*【程序设计项目】模拟飞机场的着陆和起飞管理模式。
* 设飞机场有3条跑道，有4种着陆等待模式(普通降落，紧急降落各两种)。
* 前两条跑道分别具有两种着陆等待模式，第3条跑道不用作正常着陆。
* 到达的飞机进入某个等待模式队列，并分配给该飞机一个整数id（身份号）和另一个整数t,
* t是飞机必须降落前（出于油量的原因）在队列中允许停留的时间单位数，称为剩余时间。
* 3个跑道中的每一个均有一个起飞队列。
* 在起飞队列中的飞机也分配有一个d值。各起飞队列的长度应大致相同。
* 在每个时间单位中，可允许最多有3架飞机进人着陆队列以及最多3架飞机进入起飞队列。
* 每条跑道在一个时间单位中，允许一次起飞或降落。
* 第3条跑道仅用作起飞（除非飞机须紧急降落）。
* 在每个时间单位中，任何一个着陆队列里剩余时间接近于0的飞机必须给予高于其他飞机（不论是着陆还是起飞）的优先级。
* 如果仅有一架飞机出现这种情况，则使用第3条跑道。
* 如果多于一架飞机(最多3架)发生此情况，则其他跑道也被使用。
* 用连续偶数（奇数）表示飞机在起飞（着陆）队列中的d值。
* 在每个单位时间中，假设进入队列的操作先于起飞或降落的操作。
*
* 设计一个算法用于模拟上述管理模式。要求队列不会过于增大，而到来的飞机又必须放到适当队列的尾部。队列不允许重新安排。
* 算法的输出应该清楚地显示出每个时间单位中所发生的事情。每次输出应包括：
* (a)每个队列的内容；
* (b)起飞的平均等待时间；
* (c)着陆的平均等待时间；
* (d)着陆的平均剩余时间；
* (e)紧急降落（无油料）的飞机数。
* (b)和(c)分别对应于已经起飞或降落的飞机。
* 输出应该是自说明的并易于理解（并且不混乱）。
* 算法的输人可以来自键盘、文件或随机数产生器。
* 在每个时间单位中，输入包括：
* 到达起飞队列的飞机数、
* 到达着陆队列的飞机数，
* 以及到达着陆队列的飞机所具有的剩余时间。
*/



/*思路：
* 每个跑道对应一个队列
* 飞机到来后加入最短队列
* 有一个线性表（或链表）与起飞队列对应，存储相应信息，并进行更新
* 飞机从队列退出时与线性表中的信息同步（或者直接输出线性表中的信息）
* 
*/
#include <iostream>
//#include"AirportManager.h"
using namespace std;

int main()
{
	//ofstream ofs("out.txt");
	//AirportManager am;
	//am.RandomTest(ofs, 10);
	//am.inputFromKeyboard();
	//am.inputFromFile();

	return 0;
}
