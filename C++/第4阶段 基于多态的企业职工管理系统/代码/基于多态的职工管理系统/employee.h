#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include"worker.h"
using namespace std;

//普通员工类
class Employee:public Worker
{
public:
	//构造函数
	Employee(int id,string name,int did);
	//获取员工的岗位，重写父类纯虚函数
	string getDid();
	//显示员工信息，重写父类纯虚函数
	void showInfo();
};

#endif