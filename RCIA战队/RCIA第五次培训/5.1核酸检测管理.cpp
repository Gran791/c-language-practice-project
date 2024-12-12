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
 *          ���汣��             ����BUG
 */


using namespace std;

class Person
{
private:
    string name;
    long long telephone;
    string card;
public:
    //���캯��
    Person(string na, long long te, string ca) : name(na), telephone(te), card(ca) {}
    void printinfo() const
    {
        cout << "������" << name << "���绰���룺" << telephone << "�����֤��" << card << endl << endl;
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
    long sampleno;//�걾���
    int samplevalue;//�걾ֵ
    string result;//�����
public:
    void set()
    {
        cout << "������걾��ţ�";
        cin >> sampleno;
        /*cout << "������걾ֵ��";
        cin >> samplevalue;*/
    }
    void collect()
    {
        samplevalue = rand() % 20;
    }
    void test()
    {
        if (samplevalue > 15)
            result = "����";
        else
            result = "����";
    }
    void out() const
    {
        cout << "�걾��ţ�" << sampleno << "���걾ֵ��" << samplevalue << "���������" << result << endl;
    }
};

//��ά����arr����һλΪPerson������λΪSample
//ԭʹ��variant�����Ϊpair�������ģ�
vector< pair< Person, vector<Sample> > > arr;

//����ܼ��˴���+�����˵�
int check(string card, int menu)
{
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        if (it->first.getcard() == card || it->first.getname() == card)
        {
            it->first.printinfo();
            //����˵�
            if (menu == 1)
            {
                int d = 1;
                cout << "1.�˳�  2.�޸�  3.�г��걾  0.ɾ�� :";
                cin >> d;
                cin.ignore();
                switch (d)
                {
                    //0.ɾ��
                    case 0:
                        it = arr.erase(it);
                        cout << "ɾ���ɹ�" << endl;
                        return 1;
                    //2.�޸�
                    case 2:
                    {
                        string name;
                        long long telephone;
                        string card;
                        cout << "������������";
                        getline(cin, name);
                        cout << "������绰���룺";
                        cin >> telephone;
                        cin.ignore();
                        cout << "���������֤�ţ�";
                        getline(cin, card);
                        //ʹ�ø��º�������½�һ��Ԫ��
                        const auto& samples = it->second;
                        Person newperson(name, telephone, card);
                        vector<Sample> newsamples = samples;
                        //ɾ��ԭԪ��
                        it = arr.erase(it);
                        //д�����Ԫ��
                        arr.emplace_back(newperson, newsamples);
                        //arr.reserve(arr.size() + 1);
                        cout << "�ɹ���������" << endl;
                        return 1;
                    }
                    //3.�г��걾
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
                            cout << "�޼�¼" << endl;
                        break;
                    }
                    default:
                        break;
                }
                return 1;
            }
            //�����˵�
            else if (menu == 0)
            {
                Sample sample;
                sample.set();
                sample.collect();
                sample.test();
                const auto& samples = it->second;
                it->second.emplace_back(sample);
                cout << "�����ϴ��ɹ�" << endl;
                return 1;
            }
        }
    }
    return 0;
}

//��ѯ�ܼ���
void info()
{
    string card;
    cout << "�������ܼ������֤����/������";
    getline(cin, card);
    system("cls");
    if (check(card, 1) != 1)
        cout << "δ�ҵ����ܼ���" << endl;
    system("pause");
}

//�½��ܼ���
void newinfo()
{
    string name, card;
    long long telephone;
    cout << "������������";
    getline(cin, name);
    cout << "������绰���룺";
    cin >> telephone;
    cin.ignore();
    cout << "���������֤�ţ�";
    getline(cin, card);
    Person newperson(name, telephone, card);
    vector<Sample> newsamples;
    arr.emplace_back(newperson, newsamples);
    cout << "�½��ɹ�" << endl;
    system("pause");
}

//�걾���ݵ���
void input()
{
    string card;
    cout << "�������֤����/������";
    getline(cin, card);
    system("cls");
    if (check(card, 0) != 1)
        cout << "δ�ҵ����ܼ���" << endl;
    system("pause");
}

//���˵�
void menu()
{
    system("cls");
    int d = 0;
    cout << "1.��ѯ/�޸��ܼ�����Ϣ  2.�½��ܼ�����Ϣ  3.�걾�ɼ����룺";
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
        cout << "��������" << endl;
        system("pause");
    }
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "ע�⣺�ڹرձ���������ݽ����ᱣ����" << endl;
    system("pause");
    while(1)
        menu();
    return 0;
}
