#include"manager.h"
#include<iostream>
using namespace std;
//构造函数
Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

//获取员工的岗位
string Manager::getDid()
{
	return string("经理");
}

//显示员工的信息
void Manager::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDid()
		<< "\t岗位职责：完成老板交给的任务，管理员工" << endl;
}