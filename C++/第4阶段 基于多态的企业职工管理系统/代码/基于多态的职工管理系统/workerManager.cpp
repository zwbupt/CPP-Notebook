#include"workerManager.h"
#include<iostream>
using namespace std;

//构造函数
WorkerManager::WorkerManager()
{
	//根据FILENAME是否存在以及数据是否为空，分三种情况
	//情况1：文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		//初始化属性
		m_Empnum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		//关闭输入流
		ifs.close();
		return;
	}
	//情况2：文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		//初始化属性
		m_Empnum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		//关闭输入流
		ifs.close();
		return;
	}
	//情况3：文件存在，数据不为空
	int num = this->getFileEmpNum();
	//cout << "文件中已有 " << num << " 个职工" << endl;
	this->m_Empnum = num;
	//初始化职工数组
	this->m_EmpArray = new Worker*[this->m_Empnum];
	//将数据填充进去
	initEmp();

	//for (int i = 0; i < this->m_Empnum; i++)
	//{
	//	cout << m_EmpArray[i]->m_Id << "\t"
	//		<< m_EmpArray[i]->m_Name << "\t"
	//		<< m_EmpArray[i]->m_Did << endl;
	//}

}

//菜单展示函数
void WorkerManager::showMenu()
{
	cout << "*************************" << endl
		<< "欢迎使用职工管理系统!" << endl
		<< "0.退出系统" << endl
		<< "1.增加职工信息" << endl
		<< "2.显示职工信息" << endl
		<< "3.删除离职职工" << endl
		<< "4.修改职工信息" << endl
		<< "5.查找职工信息" << endl
		<< "6.按照编号排序" << endl
		<< "7.清空所有文档" << endl
		<< "*************************" << endl;

}

//0.退出系统
void WorkerManager::exitSystem()
{
	cout << "欢迎您下次使用" << endl;
	system("pause");
	exit(0);
}

//1.添加职工
void WorkerManager::addEmp()
{
	cout << "请输入需要添加的职工数量：" << endl;
	int addEmpNum = 0;
	cin >> addEmpNum;
	if (addEmpNum > 0)	
	{
		//新空间大小
		int newsize = this->m_Empnum + addEmpNum;
		//开辟新空间
		Worker* * newSpace = new Worker*[newsize];
		//拷贝已有职工
		if (this->m_Empnum != 0)
		{
			for (int i = 0; i < this->m_Empnum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加新职工
		for (int i = 0; i < addEmpNum; i++)
		{
			cout << "请输入第 " << i + 1 << " 个职工的编号：" << endl;
			int id;
			cin >> id;
			cout << "请输入第 " << i + 1 << " 个职工的姓名：" << endl;
			string name;
			cin >> name;
			cout << "第 " << i + 1 << " 个职工的部门是：" << endl
				<< "1 --- 普通职工" << endl
				<< "2 --- 经理" << endl
				<< "3 --- 老板" << endl;
			int did;
			while (true)
			{
				cin >> did;
				if (did == 1 || did == 2 || did == 3)
				{
					switch (did)
					{
					case 1:
						newSpace[this->m_Empnum + i] = new Employee(id, name, did);
						break;
					case 2:
						newSpace[this->m_Empnum + i] = new Manager(id, name, did);
						break;
					case 3:
						newSpace[this->m_Empnum + i] = new Boss(id, name, did);
						break;
					default:
						break;
					}
					break; //打破while循环
				}
				cout << "输入有误，请重新选择职工部门编号！" << endl;
			}
			
		}
		//释放原有空间数组
		delete[] this->m_EmpArray;
		//更改指针指向
		this->m_EmpArray = newSpace;
		//更改职工人数
		this->m_Empnum = newsize;

		//输出成功添加
		cout << "成功添加 " << addEmpNum << " 个新职工！" << endl;
		this->m_FileIsEmpty = false; //更新属性
		this->save(); //保存到文件中
	}
	else
	{
		cout << "输入有误，请重新输入！" << endl;
	}
}

//保存数据
void WorkerManager::save()
{
	//创建文件输出流
	ofstream ofs;
	//以输出的方式打开文件——写文件
	ofs.open(FILENAME, ios::out);
	//写文件
	for (int i = 0; i < this->m_Empnum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << "\t"
			<< this->m_EmpArray[i]->m_Name << "\t"
			<< this->m_EmpArray[i]->m_Did << endl;
	}
	//关闭文件
	ofs.close();
}

//获取文件中的数据个数
int WorkerManager::getFileEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int num = 0; //文件中的数据量
	int id;
	string name;
	int did;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}

//当文件不为空时的初始化函数
void WorkerManager::initEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		if (did == 1)
		{
			this->m_EmpArray[index] = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			this->m_EmpArray[index] = new Manager(id, name, did);
		}
		else
		{
			this->m_EmpArray[index] = new Boss(id, name, did);
		}
		index++;
	}
	ifs.close();
}

//2.显示职工
void WorkerManager::showEmp()
{
	if (m_FileIsEmpty == 1||m_Empnum == 0)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Empnum; i++)
		{
			//利用多态输出职工信息
			this->m_EmpArray[i]->showInfo();
		}
	}
}

//3.删除职工
void WorkerManager::deleteEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入您想删除的职工编号：" << endl;
		int index = 0;
		cin >> index;
		if (this->empIsExist(index) == -1)
		{
			cout << "删除失败，没有该职工" << endl;
		}
		else
		{
			for (int i = this->empIsExist(index); i + 1 < this->m_Empnum; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_Empnum--;
			//同步到文件中
			this->save();
			
			cout << "删除成功" << endl;
		}
	}
}

//判断职工编号是否存在
int WorkerManager::empIsExist(int index)
{
	int flag = -1;
	for (int i = 0; i < this->m_Empnum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == index)
		{
			flag = i;
		}
	}
	return flag;
}

//4.修改职工
void WorkerManager::modifyEmp()
{
	if (this->m_Empnum == 0||this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		//有数据
		cout << "请输入要修改的职工编号：" << endl;
		int index = 0;
		cin >> index;
		if (this->empIsExist(index) == -1)
		{
			cout << "修改失败，查无此人！" << endl;
			return;
		}
		else
		{
			cout << "请输入新的职工编号：" << endl;
			int id;
			cin >> id;
			cout << "请输入新的职工姓名：" << endl;
			string name;
			cin >> name;
			cout << "请输入新的职工的岗位编号：" << endl
				<< "1 --- 普通员工" << endl
				<< "2 --- 经理" << endl
				<< "3 --- 老板" << endl;
			int did;
			cin >> did;
			while (did != 1 && did != 2 && did != 3)
			{
				cout << "输入有误，请重新输入岗位编号" << endl;
				cin >> did;
			}
			Worker* worker = NULL; //要添加的职工
			switch (did)
			{
			case 1:
				worker = new Employee(id, name, did);
				break;
			case 2:
				worker = new Manager(id, name, did);
				break;
			case 3:
				worker = new Boss(id, name, did);
				break;
			default:
				break;
			}

			this->m_EmpArray[this->empIsExist(index)] = worker;
			
			cout << "职工信息修改成功" << endl;
			this->save();
		}
	}
}

//5.查找职工
void WorkerManager::findEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请选择查找方式" << endl
			<< "1 --- 按照编号查找" << endl
			<< "2 --- 按照姓名查找" << endl;
		int choice = 0;
		cin >> choice;
		while (choice != 1 && choice != 2)
		{
			cout << "输入有误，请重新输入！" << endl;
			cin >> choice;	
		}
		if (choice == 1) //按照编号
		{
			cout << "请输入要查找的职工编号：" << endl;
			int id = 0;
			cin >> id;
			if (this->empIsExist(id) == -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "找到此人，信息如下：" << endl;
				this->m_EmpArray[this->empIsExist(id)]->showInfo();
			}
		}
		if (choice == 2) //按照姓名
		{
			cout << "请输入要查找的职工姓名" << endl;
			string name;
			cin >> name;
			bool flag = false; //是否找到职工

			for (int i = 0; i < this->m_Empnum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查无此人" << endl;
			}
		}

	}
}

//6.按照编号排序（升序&降序）
void WorkerManager::sortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl; 
	}
	else
	{
		cout << "请选择排序方式" << endl
			<< "1 --- 升序" << endl
			<< "2 --- 降序" << endl;
		int select = 0;
		cin >> select;
		while (select != 1 && select != 2)
		{
			cout << "输入有误，请重新输入" << endl;
			cin >> select;
		}
		for (int i = 0; i < this->m_Empnum; i++)
		{
			int minOrMaxIndex = i;
			for (int j = i + 1; j < this->m_Empnum; j++)
			{
				if (select == 1) //升序
				{
					if (this->m_EmpArray[minOrMaxIndex]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMaxIndex = j;
					}
				}
				if (select == 2) //降序
				{
					if (this->m_EmpArray[minOrMaxIndex]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMaxIndex = j;
					}
				}
			}
			if (minOrMaxIndex != i)
			{
				Worker* temp = this->m_EmpArray[minOrMaxIndex];
				this->m_EmpArray[minOrMaxIndex] = this->m_EmpArray[i];
				this->m_EmpArray[i] = temp;
			}
		}
		cout << "排序完成！" << endl;
		this->save(); //保存到文件中
		this->showEmp();
	}
}

//7.清空职工
void WorkerManager::clearEmp()
{
	cout << "确定要清空吗？" << endl
		<< "1 --- 确定" << endl
		<< "2 --- 返回" << endl;
	int choice = 0;
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "输入有误，请重新输入" << endl;
		cin >> choice;
	}
	if (choice == 1)
	{
		//清空文件内容
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();
		//清空数组
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_Empnum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_Empnum = 0;
			this->m_FileIsEmpty = true;
		}

		cout << "清空成功" << endl;
	}
	else
	{
		return;
	}

}

//析构函数
WorkerManager::~WorkerManager()
{
	if (m_EmpArray != NULL)
	{
		delete[] m_EmpArray;
		m_EmpArray = NULL;
	}
}