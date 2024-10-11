#include <iostream>
#include <cstring>

using namespace std;

void menu()
{
	char decide;
	int nofound = 1, replace = 0;
	static int i = -1;
	
	system("cls");
	
	cout << " 欢迎来到学生管理系统" << endl << "----------------------" << endl << "|1、添加学生信息     |" << endl << "|2、显示学生所有信息 |" << endl
		 << "|3、查询学生信息     |" << endl << "|4、删除学生信息     |" << endl << "|0、退出             |" << endl << "----------------------" << endl;
	cout << "请输入选项：";
	cin >> decide;
	
	system("cls");

	switch (decide)
	{
	case '1':  //添加信息 
		i++;
		
		int temp_age;
		char temp_name[10], temp_sex[10];
		unsigned long long temp_id;

		static struct student
		{
		public:
			char name[10];
			int age;
			unsigned long long id;
			char sex[10];
		} list[100];

		cout << "请输入姓名：";
		cin >> temp_name;
		cout << "请输入年龄：";
		cin >> temp_age;
		cout << "请输入 id ：";
		cin >> temp_id;
		cout << "请输入性别：";
		cin >> temp_sex;

		for (int p = 0; p < i; p++)  //i是输入，p是对比
		{
			if (temp_id == list[p].id)  //存在学生信息 
			{
				cout << "已有该学生id！该学生信息被更新" << endl;
				list[p].age = temp_age;
				list[p].id = temp_id;
				for (int n = 0; n <= 10; n++)
				{
					list[p].name[n] = temp_name[n];
					list[p].sex[n] = temp_sex[n];
				}
				replace = 1;
				i--;
			}
		}

		if (replace == 0)  //新学生信息 
		{
			list[i].age = temp_age;
			list[i].id = temp_id;
			for (int n = 0; n <= 10; n++)
			{
				list[i].name[n] = temp_name[n];
				list[i].sex[n] = temp_sex[n];
			}
		}

		system("pause");
		break;


	case '2':  //显示所有信息
		if (i == -1)  cout << "暂无数据" << endl;
		for (int p = 0; p <= i; p++)
		{
			cout << "第 " << p + 1 << " 个学生的名字是：" << list[p].name << " ;年龄是：" << list[p].age
				 << " ;id是：" << list[p].id << " ;性别是：" << list[p].sex << endl;
		}

		system("pause");
		break;


	case '3':  //查询信息
		long find_id;

		cout << "请输入要查找的学生id：";
		cin >> find_id;

		for (int p = 0; p <= i; p++)
		{
			if (find_id == list[p].id)
			{
				cout << "第" << p + 1 << "个学生的名字是：" << list[p].name << " ; 年龄是：" << list[p].age
					<< " ; id是：" << list[p].id << " ; 性别是：" << list[p].sex << endl;
				nofound = 0;
			}
		}

		if (nofound == 1)
		{
			cout << "没有找到" << endl;
		}

		system("pause");
		break;

	case '4':  //删除信息 
		long delete_find_id;

		cout << "请输入要删除的学生id：";
		cin >> delete_find_id;

		for (int p = 0; p <= i; p++)
		{
			if (delete_find_id == list[p].id)
			{
				cout << "第" << p + 1 << "个学生的名字是：" << list[p].name << " ;年龄是：" << list[p].age
					<< " ;id是：" << list[p].id << " ;性别是：" << list[p].sex << endl << "已删除该学生信息" << endl;
				nofound = 0;

				for (p; p <= i; p++)
				{
					list[p] = list[p + 1];
				}
				i-- ;
				break;
			}
		}

		if (nofound == 1)
		{
			cout << "没有找到该学生" << endl;
		}

		system("pause");
		break;

	case '0':  //退出
		exit(0);
		
	default: 
		cout << "输入有误，请重试" << endl;
		system("pause");
		break;
	}
}

int main()
{
	while (1)
	{
		menu();
	}
}
