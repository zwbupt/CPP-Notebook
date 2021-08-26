#ifndef __BOSS_H__
#define __BOSS_H__

#include"worker.h"
//经理类
class Boss :public Worker
{
public:
	//构造函数
	Boss(int id, string name, int did);
	//获取员工的岗位
	string getDid();
	//显示员工的信息
	void showInfo();
};

#endif