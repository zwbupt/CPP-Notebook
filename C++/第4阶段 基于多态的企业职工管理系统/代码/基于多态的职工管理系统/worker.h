#ifndef __WORKER_H__
#define __WORKER_H__
#include<string>
using namespace std;

//员工抽象类
class Worker
{
public:
	//获取员工的岗位
	virtual string getDid() = 0;
	//显示员工的信息
	virtual void showInfo() = 0;

public:
	//员工编号
	int m_Id;
	//员工姓名
	string m_Name;
	//员工岗位编号
	int m_Did;
};

#endif