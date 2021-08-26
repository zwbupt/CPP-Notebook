#include <iostream>
#include <string>
#include "addressbook.h"
#include "functions.h"

using namespace std;

//函数定义

//显示菜单
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 职工管理系统 *****" << endl;
	cout << "1、添加联系人" << endl;
	cout << "2、显示（所有）联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
	cout << "6、清空（所有）联系人" << endl;
	cout << "0、退出系统" << endl;
	cout << "************************" << endl;
}

//1、添加联系人
void addPerson(Addressbook &ab)
{
	cout << "正在添加联系人，请按提示输入以下信息..." << endl;
	//姓名
	cout << "姓名：" << endl;
	string name;
	cin >> name;
	ab.m_Person[ab.m_Num].m_Name = name;
	//性别
	cout << "性别" << endl
		<< "1 --- 男" << endl
		<< "2 --- 女" << endl;
	int sex;
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			ab.m_Person[ab.m_Num].m_Sex = sex;
			break;
		}
		else
		{
			cout << "性别输入有误，请重新输入" << endl;
		}
	}
	//年龄
	cout << "年龄：" << endl;
	int age;
	cin >> age;
	ab.m_Person[ab.m_Num].m_Age = age;

	cout << "联系人添加成功" << endl;
	ab.m_Num++;
}

//2、显示（所有）联系人
void showPerson(const Addressbook &ab)
{
	if (ab.m_Num == 0)
	{
		cout << "通讯录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < ab.m_Num; i++)
		{
			cout << i + 1 << "\t"
				<< "姓名：" << ab.m_Person[i].m_Name << "\t"
				<< "性别：" << (ab.m_Person[i].m_Sex == 1 ? "男" : "女") << "\t"
				<< "年龄：" << ab.m_Person[i].m_Age << endl;
		}
	}
}

//3、删除联系人
void deletePerson(Addressbook &ab)
{
	cout << "请输入要删除的联系人姓名：" << endl;
	string name;
	cin >> name;
	int personIndex = isExist(ab, name);
	if (personIndex != -1) //存在该联系人
	{
		for (int i = personIndex; i + 1 < ab.m_Num; i++)
		{
			//前移覆盖
			ab.m_Person[i] = ab.m_Person[i + 1];
		}
		ab.m_Num--;
		cout << "联系人删除成功" << endl;
	}
	else
	{
		cout << "联系人不存在，删除无效！" << endl;
	}
}

//4、查找联系人
void findPerson(const Addressbook &ab)
{
	cout << "请输入要查找的联系人" << endl;
	string name;
	cin >> name;
	int personIndex = isExist(ab, name);
	if (personIndex != -1) //存在该联系人
	{
		cout << "姓名：" << ab.m_Person[personIndex].m_Name << "\t"
			<< "性别：" << (ab.m_Person[personIndex].m_Sex == 1 ? "男" : "女") << "\t"
			<< "年龄：" << ab.m_Person[personIndex].m_Age << endl;
	}
	else
	{
		cout << "联系人不存在！" << endl;
	}

}

//5、修改联系人
void modifyPerson(Addressbook &ab)
{
	cout << "请输入要修改的联系人姓名" << endl;
	string name;
	cin >> name;
	int personIndex = isExist(ab, name);
	if (personIndex != -1) //存在
	{
		//姓名
		cout << "姓名：" << endl;
		string name;
		cin >> name;
		ab.m_Person[personIndex].m_Name = name;
		//性别
		cout << "性别" << endl
			<< "1 --- 男" << endl
			<< "2 --- 女" << endl;
		int sex;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				ab.m_Person[personIndex].m_Sex = sex;
				break;
			}
			else
			{
				cout << "性别输入有误，请重新输入" << endl;
			}
		}
		//年龄
		cout << "年龄：" << endl;
		int age;
		cin >> age;
		ab.m_Person[personIndex].m_Age = age;

		cout << "联系人修改成功！" << endl;
	}
	else //不存在
	{
		cout << "联系人不存在，无法修改！" << endl;
	}
}
//6、清空（所有）联系人
void clearPerson(Addressbook &ab)
{
	cout << "确认清空（所有）联系人吗？" << endl
		<< "1 === 继续" << endl
		<< "0 --- 取消" << endl;
	int flag = 0;
	cin >> flag;
	if (flag == 1)
	{
		ab.m_Num = 0;
		cout << "（所有）联系人已清空" << endl;
	}
}

//附加函数
//判断联系人是否存在
int isExist(const Addressbook &ab,string name)
{
	for (int i = 0; i != ab.m_Num; i++)
	{
		if (ab.m_Person[i].m_Name == name)
		{
			//cout << "联系人存在" << endl;
			return i;
		}
	}
	return -1; //未找到相应联系人
}
