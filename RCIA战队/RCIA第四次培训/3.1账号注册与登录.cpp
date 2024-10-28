#define _CRT_SECURE_NO_WARNINGS
#include <iostream>  
#include <time.h>
#include <string>
#include <cstring>
#include <ctime>
#define LOG(x) std::cout<<x<<std::endl;
#define str std::string

using namespace std;

// �����ļ����ڴ����ļ�ͬһĿ¼�У�����Ϊdata.txt
// 
// ��֪���⣨tackled����ע��/��¼��ɺ������������ע��/��¼/��������
// 10.28 �������ƺ���Դ���½��ļ��������ظ�����menu�������Լ��ڵ�½�ɹ���δ����ѭ�����ѽ��

void menu();

// д�뵽��һ�ļ�
void CoverFile(str line, int non)
{
    FILE* temp_data = fopen("temp_data.txt", "a");
    int count = 0;
    time_t login_time;
    time(&login_time);
    for (int i = 0; i < line.size(); i++)
    {
        if (line.at(i) == '\0')
        {
            line.at(i) = ' ';
            count++;
        }
        else if (count == 4 && non == 1)
        {
            //printf(" %lld\n", login_time); // ������
            fprintf(temp_data, " %lld\n", login_time);
            break;
        }
        else
        {
            //printf("%c", line.at(i)); // ������
            fprintf(temp_data, "%c", line[i]);
        }
    }
    fclose(temp_data);
}

// �ж�����ǿ��
str isSolid()
{
    str pw;
    cout << "���������룺";
    getline(cin, pw);
    if (pw == "0")
    {
        return "-1";
    }
    char* pswd = (char*)pw.data();
    int capital = 0, lowercse = 0, sign = 0, number = 0;
    for (int i = 0; i < strlen(pswd); i++)
    {
        if (pswd[i] >= 'A' && pswd[i] <= 'Z')
            capital++;
        else if (pswd[i] >= 'a' && pswd[i] <= 'z')
            lowercse++;
        else if (pswd[i] >= '0' && pswd[i] <= '9')
            number++;
        else if (ispunct(pswd[i]))
            sign++;
    }
    if (strlen(pswd) < 8)
    {
        cout << "���볤��̫�̣�����������" << endl;
        pw = isSolid();
    }
    else if (capital > 0 && lowercse > 0 && sign > 0 && number > 0)
    {
        cout << "����ǿ�Ⱥܸ�";
    }
    else if (capital > 0 && lowercse > 0)
    {
        cout << "����ǿ���е�";
    }
    else
    {
        cout << "����ǿ�Ƚϵ�";
    }
    return pw;
}

// �ж��û�������
int isExist(str name)
{
    FILE* data = fopen("data.txt", "r");
    if (data == NULL)
    {
        cout << "�����ļ������ڣ�";
        cout << "����1�Դ���һ�������ļ����������˳���";
        int dec;
        cin >> dec;
        cin.ignore();
        if (dec == 1)
        {
            data = fopen("data.txt", "a");
            cout << "�����ļ������ɹ���";
            system("pause");
        }
        else
        {
            return -1;
        }
    }
    char buf[1024];
    str line, temp[5];
    const char* split = " ";
    while (fgets(buf, sizeof(buf), data) != NULL)
    {
        line = buf;
        char* p = strtok((char*)line.data(), split);
        for (int i = 0; i < 2 && p != NULL; i++)
        {
            temp[i] = p;
            p = strtok(NULL, split);
        }
        if (name == temp[1])
        {
            fclose(data);
            return 1;
        }
    }
    fclose(data);
    return 0;
}

// �ж�������ȷ
int isCorrect(str pswd)
{
    FILE* data = fopen("data.txt", "a+");
    char buf[1024];
    int r = 0;
    str line, temp[5];
    const char* split = " ";
    for (int i = 0; fgets(buf, sizeof(buf), data) != NULL; i++)
    {
        line = buf;
        char* p = strtok((char*)line.data(), split);
        for (int j = 0; j < 5 && p != NULL; j++)
        {
            temp[j] = p;
            p = strtok(NULL, split);
        }
        if (pswd == temp[2])
        {
            CoverFile(line, 1);
            r = 1;
        }
        else
        {
            CoverFile(line, 0);
        }
    }
    fclose(data);
    // ����Դ�ļ�
    remove((const char*)"data.txt");
    rename("temp_data.txt", "data.txt");
    if (r == 1)
        return 1;
    else
        return 0;
}

// д��ע����Ϣ
void WriteInfo(str name, str pswd)
{
    FILE* data = fopen("data.txt", "a+");
    //str number;
    int num = 1;
    char buf[1024];
    time_t regis_time;
    time(&regis_time);

    str line, temp[5];
    // �涨�ָ���Ϊ�ո�
    const char* split = " ";
    // ���б���
    while (fgets(buf, sizeof(buf), data) != NULL)
    {
        line = buf;
        char* p = strtok((char*)line.data(), split);
        if (p != NULL)
        {
            temp[0] = p;
            p = strtok(NULL, split);
        }
        // �������
        sscanf(temp[0].c_str(), "%d", &num);
        num++;
    }
    fprintf(data, "%03d %s %s %lld \n", num, name.c_str(), pswd.c_str(), regis_time);
    fclose(data);
}

// ע��
void regis()
{
    system("cls");
    cout << "ģʽ��ע�ᡣ����0�˳�ע��ģʽ" << endl;
    cout << "�������û���:";
    str name;
    getline(cin, name);
    if (name == "0")
    {
        menu();
    }
    else if (isExist(name) == -1)
    {
	}
    else if (isExist(name))
    {
        cout << "���û����ѱ�ע�ᣬ����������" << endl;
        system("pause");
        regis();
    }
    else
    {
        str pswd;
        pswd = isSolid();
        if (pswd == "-1")
        {
		}
		else
		{
	        WriteInfo(name, pswd);
	        cout << endl << name << "��ϲ�㣬ע��ɹ���" << endl;
	        system("pause");
    	}
    }
}

// ��¼
void login()
{
    system("cls");
    cout << "ģʽ����¼������0�˳���¼ģʽ" << endl;
    cout << "�������û�����";
    str name;
    getline(cin, name);
    if (name == "0")
        menu();
    else
    {
    	int exist = isExist(name);
		if (!exist)
	    {
	        cout << "�û��������ڣ�����������" << endl;
	        system("pause");
	        login();
	    }
	    else if (exist != -1) 
	    {
	        str pswd;
	        for (int i = 0; i < 3; i++)
	        {
	            cout << "���������룺";
	            getline(cin, pswd);
	            if (pswd == "0")
	            {
	            	break;
				}
	            else if (isCorrect(pswd))
	            {
	                time_t nowtime;
	                time(&nowtime);
	                tm* p = localtime(&nowtime);
	                int hour = p->tm_hour;
	                if (hour >= 5 && hour < 8)
	                    cout << "���Ϻ�";
	                else if (hour <= 11)
	                    cout << "�����";
	                else if (hour <= 14)
	                    cout << "�����";
	                else if (hour <= 17)
	                    cout << "�����";
	                else if (hour <= 19)
	                    cout << "�����";
	                else if (hour <= 24)
	                    cout << "���Ϻ�";
	                else
	                    cout << "�賿��";
	                cout << "����ӭ���ĵ�¼" << endl;
	                system("pause");
	                break;
	            }
	            else if (i < 2)
	            {
	                cout << "��������㻹��" << 2 - i << "�λ���" << endl;
	            }
	            else
	            {
	                cout << "���볢�Դ������þ���" << endl;
	                system("pause");
	            }
	        }
	    }
	}
}

// ���˵�
void menu()
{
    system("cls");
    str mode;
    cout << "������ģʽ��ע��/��¼����";
    cin >> mode;
    cin.ignore();
    if (mode == "ע��" || mode == "1")
    {
        system("cls");
        regis();
    }
    else if (mode == "��¼" || mode == "2")
    {
        system("cls");
        login();
    }
    else
    {
        cout << "�������������ԣ�" << endl;
        system("pause");
    }
}

int main()
{
    while (1)
        menu();
    return 0;
}