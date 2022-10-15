#pragma once
#include <iostream>
#define DEFAULTSIZE 10
using u_int = unsigned int;
using namespace std;

template <class T>
class mySeqList
{
	friend istream& operator>> (istream& in, mySeqList& sl);
	friend ostream& operator<< (ostream& out, mySeqList& sl);
public:
	mySeqList(u_int size = DEFAULTSIZE);//传入容量大小构造
	mySeqList(const T[], u_int size);//用数组初始化
	mySeqList(const T& t, u_int size = DEFAULTSIZE);//用一堆t初始化
	mySeqList(const mySeqList& sl);
	~mySeqList();

	//赋值
	const mySeqList<T>& operator=(const mySeqList& sl);

	//获取数据
	u_int getLength()const { return this->m_length; }
	u_int getMaxsize()const { return this->m_maxSize; }

	T& at(u_int index);
	const T& at(u_int index)const;

	T& operator[](u_int index);
	const T& operator[](u_int index)const;

	//插入、删除

	void push_back(const T& data);
	T pop_back();

	T pop_front();

	void Insert(u_int index, const T& value);
	T Delete(u_int index);

	void clear();//清空

	//输入输出采用流做参数。
	void input(istream& in, u_int n);
	void output(ostream& out, u_int n);


	//特殊操作
	bool isEmpty();

	int Find(const T& value);//查找

	void resize(u_int size);//重定义空间

private://内部操作

	void enlarge();//扩大空间至两倍

	bool indexIsWrong(u_int i)const {
		if (i >= 0 && i <= m_length)return false;
		else return true;
	}

private:

	T* p_Data;//存储数据
	u_int m_length;//数据量
	u_int m_maxSize;//当前最大容量
};

template<class T>
mySeqList<T>::mySeqList(u_int size)
	:m_length(0), m_maxSize(size)
{
	this->p_Data = new T[size];
}

template<class T>
inline mySeqList<T>::mySeqList(const T t[], u_int size)
	:m_length(size), m_maxSize(size)
{
	this->p_Data = new T[size];
	for (size_t i = 0; i < size; i++)
		this->p_Data[i] = t[i];
}

template<class T>
inline mySeqList<T>::mySeqList(const T& t, u_int size)
	:m_length(size), m_maxSize(size)
{
	this->p_Data = new T[size];
	for (size_t i = 0; i < size; i++)
		this->p_Data[i] = t;
}

template<class T>
mySeqList<T>::mySeqList(const mySeqList& sl)
	:m_length(sl.m_length), m_maxSize(sl.m_maxSize)
{
	this->p_Data = new T[sl.m_maxSize];
	for (size_t i = 0; i < sl.m_length; i++)
		this->p_Data[i] = sl.p_Data[i];
}

template<class T>
const mySeqList<T>& mySeqList<T>::operator=(const mySeqList& sl)
{
	if (&sl == this) return *this;
	this->m_length = sl.m_length;
	this->m_maxSize = sl.m_maxSize;
	if (p_Data != NULL)
	{
		delete[] p_Data;
		p_Data = NULL;
	}
	this->p_Data = new T[m_maxSize];
	for (size_t i = 0; i < m_length; i++)
		this->p_Data[i] = sl.p_Data[i];
	return *this;
}

template<class T>
mySeqList<T>::~mySeqList()
{
	if (p_Data != NULL)
	{
		delete[] p_Data;
		p_Data = NULL;
	}
}

template<class T>
T& mySeqList<T>::at(u_int i)
{
	if (indexIsWrong(i))
		throw out_of_range("Index is out of range!");
	return this->p_Data[i];
}

template<class T>
const T& mySeqList<T>::at(u_int i) const
{
	if (indexIsWrong(i))
		throw out_of_range("Index is out of range!");
	return this->p_Data[i];
}

template<class T>
T& mySeqList<T>::operator[](u_int i)
{
	if (indexIsWrong(i))
		throw out_of_range("Index is out of range!");
	return this->p_Data[i];
}

template<class T>
const T& mySeqList<T>::operator[](u_int i) const
{
	if (indexIsWrong(i))
		throw out_of_range("Index is out of range!");
	return this->p_Data[i];
}

template<class T>
void mySeqList<T>::push_back(const T& data)
{
	if (this->m_length == this->m_maxSize)
		this->enlarge();
	this->p_Data[m_length++] = data;
}

template<class T>
T mySeqList<T>::pop_back()
{
	this->m_length--;
	return this->p_Data[m_length];
}

template<class T>
inline T mySeqList<T>::pop_front()
{
	T temp = this->p_Data[0];
	this->Delete(0);
	return temp;
}

template<class T>
void mySeqList<T>::Insert(u_int index, const T& value)
{
	if (indexIsWrong(index))
		throw out_of_range("Index is out of range!");
	if (this->m_length == this->m_maxSize)
		this->enlarge();
	for (size_t i = m_length; i > index; i--)//从最后一位开始向后移动
		this->p_Data[i] = this->p_Data[i - 1];
	this->p_Data[index] = value;
	this->m_length++;
}

template<class T>
T mySeqList<T>::Delete(u_int index)
{
	if (indexIsWrong(index))
		throw out_of_range("Index is out of range!");
	T temp = this->p_Data[index];
	this->m_length--;
	for (size_t i = index; i < m_length; i++)
		this->p_Data[i] = this->p_Data[i + 1];
	return temp;
}

template<class T>
void mySeqList<T>::clear()
{
	this->m_length = 0;
}

template<class T>
void mySeqList<T>::input(istream& in, u_int n)
{
	if (indexIsWrong(n))
		throw out_of_range("Index is out of range!");
	for (size_t i = 0; i < n; i++)
	{
		T temp;
		in >> temp;
		push_back(temp);
	}
}

template<class T>
istream& operator>>(istream& in, mySeqList<T>& sl)
{
	T temp;
	in >> temp;
	push_back(temp);
	return in;
}

template<class T>
void mySeqList<T>::output(ostream& out, u_int n)
{
	if (indexIsWrong(n))
		throw out_of_range("Index is out of range!");
	for (size_t i = 0; i < n; i++)
		out << this->p_Data[i] << endl;
}

template<class T>
inline ostream& operator<<(ostream& out, mySeqList<T>& sl)
{
	for (size_t i = 0; i < sl.getLength(); i++)
		out << this->p_Data[i] << endl;
	return out;
}

template<class T>
inline bool mySeqList<T>::isEmpty()
{
	return this->m_length == 0;
}

template<class T>
int mySeqList<T>::Find(const T& value)
{
	for (size_t i = 0; i < m_length; i++)
		if (value == this->p_Data[i])
			return i;
	return -1;
}

template<class T>
void mySeqList<T>::resize(u_int size)
{
	if (size == this->m_maxSize || size == 0)return;
	if (size == 0)throw out_of_range("Index is out of range!");

	this->m_maxSize = size;
	this->m_length = (size <= m_length ? size : m_length);
	T* newlist = new T[size];
	for (size_t i = 0; i < m_length; i++)
		newlist[i] = this->p_Data[i];
	if (p_Data != NULL)
	{
		delete[] p_Data;
		p_Data = NULL;
	}
	this->p_Data = newlist;
}

template<class T>
void mySeqList<T>::enlarge()
{
	this->m_maxSize *= 2;
	T* newlist = new T[m_maxSize];
	for (size_t i = 0; i < m_length; i++)
		newlist[i] = this->p_Data[i];
	if (p_Data != NULL)
	{
		delete[] p_Data;
		p_Data = NULL;
	}
	this->p_Data = newlist;
}
