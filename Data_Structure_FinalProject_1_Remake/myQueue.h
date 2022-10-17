#pragma once
#include <iostream>
using u_int = unsigned int;
using namespace std;

template <class T>
class myQueue
{
public:
	myQueue(u_int stackCapacity = 10);
	~myQueue() { delete[] queue; }

	myQueue(const myQueue<T>& q);
	const myQueue<T>& operator=(const myQueue<T>& q);

	bool isEmpty() const;							//是否为空

	T& front();										//读队首
	const T& front()const;							//读队首

	T& rear();										//读队尾
	const T& rear()const;							//读队尾

	u_int size()const { return m_size; }			//返回长度

	void push(const T& item);						//队尾入队
	void pop();										//队首出队

	//T& operator[](u_int index);						//根据偏移量返回数据
	//const T& operator[](u_int index)const;			//根据偏移量返回数据
private:

	void doubleCapacity();


private:
	T* queue;
	u_int front_index;								//头部
	u_int rear_index;								//尾部
	u_int m_capacity;								//容量
	u_int m_size;									//内容数量

};

template<class T>
myQueue<T>::myQueue(u_int size)
	:m_capacity(size), front_index(0), rear_index(0), m_size(0)
{
	if (size <= 0)
		throw out_of_range("StackCapacity is out of range!");
	this->queue = new T[size];
}

template<class T>
myQueue<T>::myQueue(const myQueue<T>& q)
	:m_capacity(q.m_capacity), front_index(q.front_index), rear_index(q.rear_index), m_size(0)
{
	this->queue = new T[q.m_capacity];
	for (size_t i = 0; i < q.m_capacity; i++)
		this->queue[i] = q.queue[i];
}

template<class T>
const myQueue<T>& myQueue<T>::operator=(const myQueue<T>& q)
{
	this->m_capacity = q.m_capacity;
	this->front_index = q.front_index;
	this->rear_index = q.rear_index;
	this->m_size = q.m_size;

	this->queue = new T[q.m_capacity];
	for (size_t i = 0; i < q.m_capacity; i++)
		this->queue[i] = q.queue[i];
	return *this;
}

template<class T>
inline bool myQueue<T>::isEmpty() const
{
	return this->front_index == this->rear_index;
}

template<class T>
inline T& myQueue<T>::front()
{
	if (this->isEmpty())
		throw out_of_range("Queue is empty!");
	return this->queue[(this->front_index + 1) % m_capacity];
}

template<class T>
inline const T& myQueue<T>::front() const
{
	if (this->isEmpty())
		throw out_of_range("Queue is empty!");
	return this->queue[(this->front_index + 1) % m_capacity];
}

template<class T>
inline T& myQueue<T>::rear()
{
	if (this->isEmpty())
		throw out_of_range("Queue is empty!");
	return this->queue[this->rear_index];
}

template<class T>
inline const T& myQueue<T>::rear() const
{
	if (this->isEmpty())
		throw out_of_range("Queue is empty!");
	return this->queue[this->rear_index];
}

template<class T>
inline void myQueue<T>::push(const T& item)
{
	if ((this->rear_index + 1) % m_capacity == this->front_index)
		this->doubleCapacity();
	this->rear_index = (this->rear_index + 1) % m_capacity;
	this->queue[this->rear_index] = item;
	this->m_size++;
}

template<class T>
void myQueue<T>::pop()
{
	if (this->isEmpty())
		throw out_of_range("Queue is empty!");
	this->front_index = (this->front_index + 1) % m_capacity;
	this->m_size--;
}

//template<class T>
//T& myQueue<T>::operator[](u_int index)
//{
//	//判断下标越界
//	if (index >= this->m_size)
//		throw out_of_range("Index is out of range!");
//	return this->queue[(this->front_index + index) % m_capacity];
//}
//
//template<class T>
//inline const T& myQueue<T>::operator[](u_int index) const
//{
//	//判断下标越界
//	if (index >= this->m_size)
//		throw out_of_range("Index is out of range!");
//	return this->queue[(this->front_index + index) % m_capacity];
//}

template<class T>
void myQueue<T>::doubleCapacity()
{
	u_int newsize = this->m_capacity * 2;
	T* newqueue = new T[newsize];

	size_t i = this->front_index;
	size_t j = 1;
	for (; i != this->rear_index; i = (i + 1) % m_capacity)
		newqueue[j++] = this->queue[i + 1];
	this->m_capacity = newsize;
	this->front_index = 0;
	this->rear_index = --j;
	delete[] this->queue;
	this->queue = newqueue;
	//cout << "_____________________________________________\n";
}
