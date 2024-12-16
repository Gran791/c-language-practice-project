#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <deque>
#include <random>

using namespace std;

// 蛇结构体
struct Elem
{
    int x;  // x坐标
    int y;  // y坐标
};

// 食物结构体
Elem food = {0, 0};

// 方向结构体
struct Direction
{
    int p1 = 0;  // 玩家1的方向 (0 - 无操作， 2 - 上， 3 - 下， 5 - 左， 6 - 右)
    int p2 = 0;  // 玩家2的方向 (0 - 无操作， 2 - 上， 3 - 下， 5 - 左， 6 - 右)
};

// 蛇队列
deque<Elem> Snake;

// 地图大小
int mapSize = 20;

// 地图下方坐标
int mapBottom = mapSize + 2;

// 上次移动方向 (2 - 上， 3 - 下， 5 - 左， 6 - 右)
int lastMove = 3;

// 分数
int score;

// 碰撞标志
bool collideFlag;

// 加速相关
bool boostFlag;  // 是否加速
bool boostRecover;  // 加速恢复中
int boostCount;  // 加速次数
int boostRecoverCount;  // 加速恢复状态

// 延时
int sleepTime;

// 蛇头、身体、食物、墙、空白
char head = '@';
char body = 'O';
char foodChar = '*';
char wall = '#';
char emptyChar = ' ';

std::random_device rd;  // 真随机数生成器
std::mt19937 gen(rd()); // Mersenne Twister 引擎
std::uniform_int_distribution<> dis(1, mapSize);

// 在下处添加并编写自己的函数

// 光标定位
void gotoxy(unsigned char x, unsigned char y) {
    //COORD是Windows API中定义的一种结构，表示一个字符在控制台屏幕上的坐标
    COORD cor;

    //句柄 
    HANDLE hout;

    //设定我们要定位到的坐标 
    cor.X = x;
    cor.Y = y;

    //GetStdHandle函数获取一个指向特定标准设备的句柄，包括标准输入，标准输出和标准错误。
    //STD_OUTPUT_HANDLE正是代表标准输出（也就是显示屏）的宏 
    hout = GetStdHandle(STD_OUTPUT_HANDLE);

    //SetConsoleCursorPosition函数用于设置控制台光标的位置
    SetConsoleCursorPosition(hout, cor);
}

void resetCursor()
{
    gotoxy(0, mapBottom);
}

// 画出蛇头
void printHead()
{
    gotoxy(Snake.back().x, Snake.back().y);
    putchar(head);
    // 旧蛇头修改为身体
    gotoxy(Snake[Snake.size() - 2].x, Snake[Snake.size() - 2].y);
    putchar(body);
    resetCursor();
}

// 删除尾部
void delTail()
{
    gotoxy(Snake.front().x, Snake.front().y);
    putchar(emptyChar);
    Snake.pop_front();
    resetCursor();
}

// 生成食物
void generateFood()
{
    // 若无空间生成食物，程序结束
    if (Snake.size() >= mapSize * mapSize)
    {
        printf("空间用尽！\n");
        system("pause");
        exit(1);
    }
    food.x = dis(gen);
    food.y = dis(gen);
    // 防止食物生成在蛇身上
    for (auto i = Snake.begin(); i != Snake.end(); i++)
    {
        if (i->x == food.x && i->y == food.y)
        {
            //Snake.erase(i);  // 删除迭代器防止溢出
            generateFood();  // 重新生成食物
            return;
        }
    }
    gotoxy(food.x, food.y);
    printf("\033[33m%c\033[0m", foodChar);
    resetCursor();
}

// 初始化
void init()
{
    // 初始化变量
    collideFlag = 0;  // 是否碰撞
    boostFlag = 0;  // 是否加速
    boostRecover = 0;  // 加速恢复中
    boostCount = 0;  // 加速次数
    boostRecoverCount = 100;  // 加速恢复状态
    sleepTime = 300;
    lastMove = 3;
    score = 0;
    system("cls");
    printf("press e to boost, press p to pause\n");
    system("pause");
    //system("color 87");
    // 初始化蛇
    Snake.clear();
    Snake.push_back(Elem{ mapSize / 2, mapSize / 2 - 2 });
    Snake.push_back(Elem{ mapSize / 2, mapSize / 2 - 1 });
    Snake.push_back(Elem{ mapSize / 2, mapSize / 2 });

    system("cls");
    // 画墙
    for (int i = 0; i < mapSize + 2; i++)
    {
        gotoxy(i, 0);
        putchar(wall);
        gotoxy(i, mapSize + 1);
        putchar(wall);
        gotoxy(0, i);
        putchar(wall);
        gotoxy(mapSize + 1, i);
        putchar(wall);
    }
    // 画蛇
    for (auto i = Snake.begin(); i != Snake.end(); i++)
    {
        gotoxy(i->x, i->y);
        putchar(body);
    }
    // 画蛇头
    gotoxy(Snake.back().x, Snake.back().y);
    putchar(head);
    // 画食物
    generateFood();
}

// 获取输入
Direction getInput()
{
    Direction direction;
    char move = 'x'; // 无操作为x
    // 无输入
    if (_kbhit() == 0)
        return direction;
    char in;
    //in = _getch();
    
    while (_kbhit() != 0)
    {
        in = _getch();
        // 暂停
        if (in == 'p')
        {
            resetCursor();
            printf("游戏暂停中\n");
            system("pause");
            gotoxy(0, mapBottom);
            printf("                    ");
            gotoxy(0, mapBottom + 1);
            printf("                    ");
        }
        // 加速(按下e且不处于加速恢复中)
        if (in == 'e' && boostRecover == 0)
            boostFlag = 1;
        // 移动
        if ((in == 'w' && lastMove != 3) || (in == 's' && lastMove != 2) || (in == 'a' && lastMove != 6) || (in == 'd' && lastMove != 5))
            move = in;  // 读取最后一个有效输入
    }
    switch (move)
    {
    case 'w':
    {
        direction.p1 = 2;
        break;
    }
    case 's':
    {
        direction.p1 = 3;
        break;
    }
    case 'a':
    {
        direction.p1 = 5;
        break;
    }
    case 'd':
    {
        direction.p1 = 6;
        break;
    }
    default:
        return direction;
    }
    return direction;

}

// 检测是否吃到食物
bool eatFood()
{
    if (Snake.back().x == food.x && Snake.back().y == food.y)
        return true;
    else
        return false;
}

// 检测是否碰撞
bool collide()
{
    // 撞墙
    if (Snake.back().x == 0 || Snake.back().x == mapSize + 1 || Snake.back().y == 0 || Snake.back().y == mapSize + 1)
    {
        gotoxy(Snake.back().x, Snake.back().y);
        printf("\033[1;5;41m%c\033[0m", wall);
        return true;
    }
    // 撞身体
    for (auto i = Snake.begin(); i != Snake.end(); i++)
    {
        if (next(i) == Snake.end())  // 最后一节(蛇头)不检测
            return false;
        if (i->x == Snake.back().x && i->y == Snake.back().y)
        {
            gotoxy(Snake.back().x, Snake.back().y);
            printf("\033[1;5;41m%c\033[0m", body);
            return true;
        }
    }
    return false;
}

// 输出分数
void printScore()
{
    gotoxy(mapSize - 8, mapBottom);
    printf("Score: %d", score);
    resetCursor();
}

// 是否加速
void boostCheck()
{
    boostCount++;  // 加速次数加一
    boostRecoverCount -= 5;  // 加速恢复时间减五
    if (boostRecoverCount <= 0)  // 20次加速结束
    {
        boostFlag = 0;  // 加速标记恢复
        boostCount = 0;  // 重置加速次数
        
        sleepTime = 300;  // 恢复刷新间隔
        boostRecover = 1;  // 启动加速恢复
    }
}

// 加速恢复
void boostRecCheck()
{
    gotoxy(0, mapBottom);
    char red[21] = "\033[31m□\033[0m", green[21] = "\033[32m■\033[0m";
    if (boostRecoverCount < 100 && boostRecover == 1)  // 仅在启动加速恢复且恢复时间小于100时才开始恢复
        boostRecoverCount++;
    if (boostRecoverCount <= 20)
        printf("%s%s%s%s%s", red, red, red, red, red);
    else if (boostRecoverCount <= 40)
        printf("%s%s%s%s%s", green, red, red, red, red);
    else if (boostRecoverCount <= 60)
        printf("%s%s%s%s%s", green, green, red, red, red);
    else if (boostRecoverCount <= 80)
        printf("%s%s%s%s%s", green, green, green, red, red);
    else if (boostRecoverCount < 100)
        printf("%s%s%s%s%s", green, green, green, green, red);
    else 
    {
        printf("%s%s%s%s%s", green, green, green, green, green);
        boostRecover = 0;
    }
    resetCursor();
}

// 蛇移动
void moveSnake(Direction direction)
{
    // 判断移动方向是否合法
    if (abs(direction.p1 - lastMove) == 1)
        return;
    // lastMove更新
    if (direction.p1 != 0)
        lastMove = direction.p1;

    // 根据移动方向移动蛇头
    switch (lastMove)
    {
    // 上
    case 2:
    {
        Snake.push_back(Elem{ Snake.back().x, Snake.back().y - 1 });
        break;
    }
    // 下
    case 3:
    {
        Snake.push_back(Elem{ Snake.back().x, Snake.back().y + 1 });
        break;
    }
    // 左
    case 5:
    {
        Snake.push_back(Elem{ Snake.back().x - 1, Snake.back().y });
        break;
    }
    // 右
    case 6:
    {
        Snake.push_back(Elem{ Snake.back().x + 1, Snake.back().y });
        break;
    }
    default:
        break;
    }
    // 判断是否死亡
    if (collide())
    {
        collideFlag = 1;
        resetCursor();
        return;
    }
    // 输出蛇头
    printHead();
    // 若蛇吃到食物，则不删除蛇尾
    if (eatFood())
    {
        // 增加分数
        score += 10;
        // 加快恢复
        if (boostRecoverCount < 100)
            boostRecoverCount += 20;
        // 生成食物
        generateFood();
        return;
    }
    // 删除蛇尾
    delTail();

}

// 主函数 
int main()
{
    
    init();  // 初始化
    while (score < 1000)  // 循环直到分数达到1000
    {
        //system("color 87");
        Sleep(sleepTime);
        // 获取用户输入并更新蛇的位置
        moveSnake(getInput());
        // 判断是否加速
        if (boostFlag && boostRecover == 0)
        {
            sleepTime = 100;
            boostCheck();
        }
        // 加速恢复
        boostRecCheck();
        // 输出分数
        printScore();
        // 检测是否死亡
        if (collideFlag)
        {
            gotoxy(0, mapSize + 3);
            break;
        }
    }
    
    printf("\nGame Over\nPress q to quit, r to play again:");
    
    char input = getchar();
    getchar();  // 清除缓冲区
    if (input == 'r')
        main();
    system("pause");
    return 0;
}
