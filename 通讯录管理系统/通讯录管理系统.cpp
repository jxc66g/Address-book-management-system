#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];

	//通讯录中当前记录联系人个数
	int m_Size;

};

//判断联系人是否存在 存在返回位置，不存在返回-1
//参数1 通讯录 参数2 对比姓名
int isExit(Addressbooks *abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}

	}
	return -1;  
}
//添加联系人
void addPerson(Addressbooks * abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
//*******************************************************
		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "1 --- 男"     << endl;
		cout << "2 --- 女"     << endl;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入!" << endl;
			}
		}
//*******************************************************
		cout << "请输入年龄：" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age < 0 || age>150)
			{
				cout << "输入有误，请重新输入！" << endl;
			}
			else
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
		}
//*******************************************************
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
//*******************************************************
		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功！" << endl;

		system("pause");
		system("cls");
	}

}

//显示联系人
void showPerson(Addressbooks* abs)
{
	//判断通讯录中人数是否为0，如果为0，提示记录为空
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1?"男":"女" )<< "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << "\t";
			cout << endl;
		}
	}
	system("pause");
	system("cls");
	//如果不为0，显示记录的联系人信息
}

//删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs,name);
	if (ret == -1)
	{
		cout << "查无此人！" << endl;
	}
	else
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--; //更新通讯录中的人员数
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex ==1?"男":"女" )<< "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入。" << endl;
			}
		}

		cout << "请输入年龄：" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age < 0 || age>150)
			{
				cout << "输入有误请重新输入！" << endl;
			}
			else
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
		}

		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

//清空联系人
void cleanPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前通讯录为空" << endl;
	}
	else
	{
		cout << "是否要清空通讯录？" << endl;
		cout << "1 --- 清空" << endl;
		cout << "2 --- 返回" << endl;
		int clear = 0;
		while (true)
		{
			cin >> clear;
			if (clear == 1)
			{
				abs->m_Size = 0;
				cout << "通讯录已清空！" << endl;
				break;
			}
			else if (clear == 2)
			{
				system("pause");
				system("cls");
				return;
			}
			else
			{
				cout << "输入有误，请重新输入！" << endl;
			}
		}
	}
	system("pause");
	system("cls");

}
//菜单
void shouMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;


}

int main() {

	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;

	int select = 0;  //创建用户选择输入的变量

	while (true)
	{
		//菜单调用
		shouMenu();
		cin >> select;
		switch (select)
		{
		case 1:   //添加联系人
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0: //退出
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}