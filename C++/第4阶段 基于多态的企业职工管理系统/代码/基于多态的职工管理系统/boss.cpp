#include"boss.h"
#include<iostream>
using namespace std;
//构造函数
Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

//获取员工的岗位
string Boss::getDid()
{
	return string("老板");
}

//显示员工的信息
void Boss::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDid()
		<< "\t岗位职责：管理公司所有事务" << endl;
}