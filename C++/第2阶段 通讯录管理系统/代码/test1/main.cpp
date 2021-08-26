//职工管理系统

#include <iostream>
#include <string>
#include "functions.h"
#include "person.h"
#include "addressbook.h"

using namespace std;

int main()
{
	Addressbook ab;
	ab.m_Num = 0; //初始化通讯录人数

	while (true)
	{
		//显示菜单
		showMenu();

		int flag;
		cin >> flag;
		switch (flag)
		{
		case 1:
			//1、添加联系人
			addPerson(ab);
			break;
		case 2:
			//2、显示（所有）联系人
			showPerson(ab);
			break;
		case 3:
			//3、删除联系人
			deletePerson(ab);
			break;
		case 4:
			//4、查找联系人
			findPerson(ab);
			break;
		case 5:
			//5、修改联系人
			modifyPerson(ab);
			break;
		case 6:
			//6、清空（所有）联系人
			clearPerson(ab);
			break;
		case 0:
			//0、退出系统
			cout << "欢迎您下次使用" << endl;
			system("pause");
			return 0; //退出main函数
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			break;
		}	
	
		system("pause");
		system("cls");
	}
	


	system("pause");
	return 0;
}