#include <iostream>
#include <cstring>

using namespace std;

void menu()
{
	char decide;
	int nofound = 1, replace = 0;
	static int i = -1;
	
	system("cls");
	
	cout << " ��ӭ����ѧ������ϵͳ" << endl << "----------------------" << endl << "|1�����ѧ����Ϣ     |" << endl << "|2����ʾѧ��������Ϣ |" << endl
		 << "|3����ѯѧ����Ϣ     |" << endl << "|4��ɾ��ѧ����Ϣ     |" << endl << "|0���˳�             |" << endl << "----------------------" << endl;
	cout << "������ѡ�";
	cin >> decide;
	
	system("cls");

	switch (decide)
	{
	case '1':  //�����Ϣ 
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

		cout << "������������";
		cin >> temp_name;
		cout << "���������䣺";
		cin >> temp_age;
		cout << "������ id ��";
		cin >> temp_id;
		cout << "�������Ա�";
		cin >> temp_sex;

		for (int p = 0; p < i; p++)  //i�����룬p�ǶԱ�
		{
			if (temp_id == list[p].id)  //����ѧ����Ϣ 
			{
				cout << "���и�ѧ��id����ѧ����Ϣ������" << endl;
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

		if (replace == 0)  //��ѧ����Ϣ 
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


	case '2':  //��ʾ������Ϣ
		if (i == -1)  cout << "��������" << endl;
		for (int p = 0; p <= i; p++)
		{
			cout << "�� " << p + 1 << " ��ѧ���������ǣ�" << list[p].name << " ;�����ǣ�" << list[p].age
				 << " ;id�ǣ�" << list[p].id << " ;�Ա��ǣ�" << list[p].sex << endl;
		}

		system("pause");
		break;


	case '3':  //��ѯ��Ϣ
		long find_id;

		cout << "������Ҫ���ҵ�ѧ��id��";
		cin >> find_id;

		for (int p = 0; p <= i; p++)
		{
			if (find_id == list[p].id)
			{
				cout << "��" << p + 1 << "��ѧ���������ǣ�" << list[p].name << " ; �����ǣ�" << list[p].age
					<< " ; id�ǣ�" << list[p].id << " ; �Ա��ǣ�" << list[p].sex << endl;
				nofound = 0;
			}
		}

		if (nofound == 1)
		{
			cout << "û���ҵ�" << endl;
		}

		system("pause");
		break;

	case '4':  //ɾ����Ϣ 
		long delete_find_id;

		cout << "������Ҫɾ����ѧ��id��";
		cin >> delete_find_id;

		for (int p = 0; p <= i; p++)
		{
			if (delete_find_id == list[p].id)
			{
				cout << "��" << p + 1 << "��ѧ���������ǣ�" << list[p].name << " ;�����ǣ�" << list[p].age
					<< " ;id�ǣ�" << list[p].id << " ;�Ա��ǣ�" << list[p].sex << endl << "��ɾ����ѧ����Ϣ" << endl;
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
			cout << "û���ҵ���ѧ��" << endl;
		}

		system("pause");
		break;

	case '0':  //�˳�
		exit(0);
		
	default: 
		cout << "��������������" << endl;
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
