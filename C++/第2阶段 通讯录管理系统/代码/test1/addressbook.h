#ifndef __HEADER_H__
#define __HEADER_H__

#include"person.h"
#define MAX 1000 //通讯录人数上限


//类——通讯录
class Addressbook
{
public:
	//通讯录中的所有联系人
	Person m_Person[MAX];

	//通讯录中所有联系人的数量
	int m_Num;
};

#endif

