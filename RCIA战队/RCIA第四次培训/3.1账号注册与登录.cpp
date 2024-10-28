#define _CRT_SECURE_NO_WARNINGS
#include <iostream>  
#include <time.h>
#include <string>
#include <cstring>
#include <ctime>
#define LOG(x) std::cout<<x<<std::endl;
#define str std::string

using namespace std;

// 数据文件放在代码文件同一目录中，名称为data.txt
// 
// 已知问题（tackled）：注册/登录完成后概率让你重新注册/登录/输入密码
// 10.28 该问题似乎起源于新建文件函数中重复调用menu函数，以及在登陆成功后未跳出循环，已解决

void menu();

// 写入到另一文件
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
            //printf(" %lld\n", login_time); // 调试用
            fprintf(temp_data, " %lld\n", login_time);
            break;
        }
        else
        {
            //printf("%c", line.at(i)); // 调试用
            fprintf(temp_data, "%c", line[i]);
        }
    }
    fclose(temp_data);
}

// 判断密码强度
str isSolid()
{
    str pw;
    cout << "请输入密码：";
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
        cout << "密码长度太短，请重新输入" << endl;
        pw = isSolid();
    }
    else if (capital > 0 && lowercse > 0 && sign > 0 && number > 0)
    {
        cout << "密码强度很高";
    }
    else if (capital > 0 && lowercse > 0)
    {
        cout << "密码强度中等";
    }
    else
    {
        cout << "密码强度较低";
    }
    return pw;
}

// 判断用户名存在
int isExist(str name)
{
    FILE* data = fopen("data.txt", "r");
    if (data == NULL)
    {
        cout << "数据文件不存在！";
        cout << "键入1以创建一个数据文件，其他键退出：";
        int dec;
        cin >> dec;
        cin.ignore();
        if (dec == 1)
        {
            data = fopen("data.txt", "a");
            cout << "数据文件创建成功！";
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

// 判断密码正确
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
    // 覆盖源文件
    remove((const char*)"data.txt");
    rename("temp_data.txt", "data.txt");
    if (r == 1)
        return 1;
    else
        return 0;
}

// 写入注册信息
void WriteInfo(str name, str pswd)
{
    FILE* data = fopen("data.txt", "a+");
    //str number;
    int num = 1;
    char buf[1024];
    time_t regis_time;
    time(&regis_time);

    str line, temp[5];
    // 规定分隔符为空格
    const char* split = " ";
    // 逐行遍历
    while (fgets(buf, sizeof(buf), data) != NULL)
    {
        line = buf;
        char* p = strtok((char*)line.data(), split);
        if (p != NULL)
        {
            temp[0] = p;
            p = strtok(NULL, split);
        }
        // 编号自增
        sscanf(temp[0].c_str(), "%d", &num);
        num++;
    }
    fprintf(data, "%03d %s %s %lld \n", num, name.c_str(), pswd.c_str(), regis_time);
    fclose(data);
}

// 注册
void regis()
{
    system("cls");
    cout << "模式：注册。输入0退出注册模式" << endl;
    cout << "请输入用户名:";
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
        cout << "该用户名已被注册，请重新输入" << endl;
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
	        cout << endl << name << "恭喜你，注册成功！" << endl;
	        system("pause");
    	}
    }
}

// 登录
void login()
{
    system("cls");
    cout << "模式：登录。输入0退出登录模式" << endl;
    cout << "请输入用户名：";
    str name;
    getline(cin, name);
    if (name == "0")
        menu();
    else
    {
    	int exist = isExist(name);
		if (!exist)
	    {
	        cout << "用户名不存在，请重新输入" << endl;
	        system("pause");
	        login();
	    }
	    else if (exist != -1) 
	    {
	        str pswd;
	        for (int i = 0; i < 3; i++)
	        {
	            cout << "请输入密码：";
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
	                    cout << "早上好";
	                else if (hour <= 11)
	                    cout << "上午好";
	                else if (hour <= 14)
	                    cout << "中午好";
	                else if (hour <= 17)
	                    cout << "下午好";
	                else if (hour <= 19)
	                    cout << "傍晚好";
	                else if (hour <= 24)
	                    cout << "晚上好";
	                else
	                    cout << "凌晨好";
	                cout << "，欢迎您的登录" << endl;
	                system("pause");
	                break;
	            }
	            else if (i < 2)
	            {
	                cout << "密码错误，你还有" << 2 - i << "次机会" << endl;
	            }
	            else
	            {
	                cout << "密码尝试次数已用尽！" << endl;
	                system("pause");
	            }
	        }
	    }
	}
}

// 主菜单
void menu()
{
    system("cls");
    str mode;
    cout << "请输入模式（注册/登录）：";
    cin >> mode;
    cin.ignore();
    if (mode == "注册" || mode == "1")
    {
        system("cls");
        regis();
    }
    else if (mode == "登录" || mode == "2")
    {
        system("cls");
        login();
    }
    else
    {
        cout << "输入有误，请重试！" << endl;
        system("pause");
    }
}

int main()
{
    while (1)
        menu();
    return 0;
}