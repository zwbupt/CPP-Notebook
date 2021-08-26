#include<iostream>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

using namespace std;

int main()
{
	//测试代码
	//Worker *w = NULL;
	//w = new Employee(1, "张三", 1);
	//w->showInfo();
	//delete w;

	//w = new Manager(2, "李四", 2);
	//w->showInfo();
	//delete w;

	//w = new Boss(3, "王五", 3);
	//w->showInfo();
	//delete w;

	WorkerManager wm;

	while (true)
	{
		wm.showMenu();
		cout << "请输入您的选择：" << endl;
		int choice = 0;
		cin >> choice;

		switch (choice)
		{
		case 0: //退出系统
			wm.exitSystem();
			break;
		case 1: //添加职工
			wm.addEmp();
			break;
		case 2: //显示职工
			wm.showEmp();
			break;
		case 3: //删除职工
			wm.deleteEmp();
			break;
		case 4: //修改职工
			wm.modifyEmp();
			break;
		case 5: //查找职工
			wm.findEmp();
			break;
		case 6: //按照编号排序（升序&降序）
			wm.sortEmp();
			break;
		case 7: //清空职工
			wm.clearEmp();
			break;
		default:
			cout << "输入有误，请重新输入!" << endl;
			break;
		}
		system("pause");
		system("cls");
	}

	system("pause");

	return 0;
}