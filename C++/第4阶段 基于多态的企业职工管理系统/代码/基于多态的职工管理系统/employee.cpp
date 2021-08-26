#include"employee.h"
#include <iostream>

Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

//获取岗位名称
string Employee::getDid()
{
	return string("员工");
}

//显示员工信息
void Employee::showInfo()
{
	std::cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDid()
		<< "\t岗位职责：完成经理交给的任务" << endl;
}