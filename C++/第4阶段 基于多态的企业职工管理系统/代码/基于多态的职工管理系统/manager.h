#ifndef __MANAGER_H__
#define __MANAGER_H__

#include"worker.h"
//经理类
class Manager:public Worker
{
public:
	//构造函数
	Manager(int id,string name,int did);
	//获取员工的岗位
	string getDid();
	//显示员工的信息
	void showInfo();
};

#endif