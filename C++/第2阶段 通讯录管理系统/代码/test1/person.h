#ifndef __ADDRESSBOOK_H__
#define __ADDRESSBOOK_H__

#include<string>
using namespace std;

//类——联系人
class Person
{
public:
	//姓名
	string m_Name;
	//性别
	int m_Sex;
	//年龄
	int m_Age;
};

#endif