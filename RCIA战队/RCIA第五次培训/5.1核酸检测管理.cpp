#define _CRT_SECURE_NO_WARNINGS
#include <iostream>  
#include <time.h>
#include <string>
#include <cstring>
#include <ctime>
#include <random>
#include <vector>

/*
 *                    _ooOoo_
 *                   o8888888o
 *                   88" . "88
 *                   (| -_- |)
 *                    O\ = /O
 *                ____/`---'\____
 *              .   ' \\| |// `.
 *               / \\||| : |||// \
 *             / _||||| -:- |||||- \
 *               | | \\\ - /// | |
 *             | \_| ''\---/'' | |
 *              \ .-\__ `-` ___/-. /
 *           ___`. .' /--.--\ `. . __
 *        ."" '< `.___\_<|>_/___.' >'"".
 *       | | : `- \`.;`\ _ /`;.`/ - ` : | |
 *         \ \ `-. \_ __\ /__ _/ .-` / /
 * ======`-.____`-.___\_____/___.-`____.-'======
 *                    `=---='
 *
 * .............................................
 *          佛祖保佑             永无BUG
 */


using namespace std;

class Person
{
private:
    string name;
    long long telephone;
    string card;
public:
    //构造函数
    Person(string na, long long te, string ca) : name(na), telephone(te), card(ca) {}
    void printinfo() const
    {
        cout << "姓名：" << name << "，电话号码：" << telephone << "，身份证：" << card << endl << endl;
    }
    string getcard() const
    {
        return card;
    }
    string getname() const
    {
        return name;
    }
};

class Sample
{
private:
    long sampleno;//标本编号
    int samplevalue;//标本值
    string result;//检测结果
public:
    void set()
    {
        cout << "请输入标本编号：";
        cin >> sampleno;
        /*cout << "请输入标本值：";
        cin >> samplevalue;*/
    }
    void collect()
    {
        samplevalue = rand() % 20;
    }
    void test()
    {
        if (samplevalue > 15)
            result = "阳性";
        else
            result = "阴性";
    }
    void out() const
    {
        cout << "标本编号：" << sampleno << "，标本值：" << samplevalue << "，检测结果：" << result << endl;
    }
};

//二维容器arr，第一位为Person，其他位为Sample
//原使用variant，后改为pair（查来的）
vector< pair< Person, vector<Sample> > > arr;

//检查受检人存在+二级菜单
int check(string card, int menu)
{
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        if (it->first.getcard() == card || it->first.getname() == card)
        {
            it->first.printinfo();
            //进入菜单
            if (menu == 1)
            {
                int d = 1;
                cout << "1.退出  2.修改  3.列出标本  0.删除 :";
                cin >> d;
                cin.ignore();
                switch (d)
                {
                    //0.删除
                    case 0:
                        it = arr.erase(it);
                        cout << "删除成功" << endl;
                        return 1;
                    //2.修改
                    case 2:
                    {
                        string name;
                        long long telephone;
                        string card;
                        cout << "请输入姓名：";
                        getline(cin, name);
                        cout << "请输入电话号码：";
                        cin >> telephone;
                        cin.ignore();
                        cout << "请输入身份证号：";
                        getline(cin, card);
                        //使用更新后的数据新建一个元素
                        const auto& samples = it->second;
                        Person newperson(name, telephone, card);
                        vector<Sample> newsamples = samples;
                        //删除原元素
                        it = arr.erase(it);
                        //写入更新元素
                        arr.emplace_back(newperson, newsamples);
                        //arr.reserve(arr.size() + 1);
                        cout << "成功更新数据" << endl;
                        return 1;
                    }
                    //3.列出标本
                    case 3:
                    {
                        int t = 0;
                        const auto& samples = it->second;
                        for (const auto& sample : samples)
                        {
                            sample.out();
                            t++;
                        }
                        if (t == 0)
                            cout << "无记录" << endl;
                        break;
                    }
                    default:
                        break;
                }
                return 1;
            }
            //跳过菜单
            else if (menu == 0)
            {
                Sample sample;
                sample.set();
                sample.collect();
                sample.test();
                const auto& samples = it->second;
                it->second.emplace_back(sample);
                cout << "数据上传成功" << endl;
                return 1;
            }
        }
    }
    return 0;
}

//查询受检人
void info()
{
    string card;
    cout << "请输入受检人身份证号码/姓名：";
    getline(cin, card);
    system("cls");
    if (check(card, 1) != 1)
        cout << "未找到该受检人" << endl;
    system("pause");
}

//新建受检人
void newinfo()
{
    string name, card;
    long long telephone;
    cout << "请输入姓名：";
    getline(cin, name);
    cout << "请输入电话号码：";
    cin >> telephone;
    cin.ignore();
    cout << "请输入身份证号：";
    getline(cin, card);
    Person newperson(name, telephone, card);
    vector<Sample> newsamples;
    arr.emplace_back(newperson, newsamples);
    cout << "新建成功" << endl;
    system("pause");
}

//标本数据导入
void input()
{
    string card;
    cout << "输入身份证号码/姓名：";
    getline(cin, card);
    system("cls");
    if (check(card, 0) != 1)
        cout << "未找到该受检人" << endl;
    system("pause");
}

//主菜单
void menu()
{
    system("cls");
    int d = 0;
    cout << "1.查询/修改受检人信息  2.新建受检人信息  3.标本采集导入：";
    cin >> d;
    cin.ignore();
    if (d == 1)
        info();
    else if (d == 2)
        newinfo();
    else if (d == 3)
        input();
    else
    {
        cout << "输入有误" << endl;
        system("pause");
    }
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "注意：在关闭本程序后，数据将不会保留！" << endl;
    system("pause");
    while(1)
        menu();
    return 0;
}
