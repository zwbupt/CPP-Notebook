#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "addressbook.h"

//显示菜单
void showMenu();
//1、添加联系人
void addPerson(Addressbook &ab);
//2、显示（所有）联系人
void showPerson(const Addressbook &ab);
//3、删除联系人
void deletePerson(Addressbook &ab);
//4、查找联系人
void findPerson(const Addressbook &ab);
//5、修改联系人
void modifyPerson(Addressbook &ab);
//6、清空（所有）联系人
void clearPerson(Addressbook &ab);

int isExist(const Addressbook &ab, string name); //判断联系人是否存在
#endif