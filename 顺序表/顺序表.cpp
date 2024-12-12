#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

typedef struct 
{
	char arr[100];
	int length;
} SqList;

//指定位置插入元素 
int InsertElem(SqList *p, int pos, char content)
{
	pos -= 1;
	if(pos < 0 || pos > 99 || (*p).length == 100)
		return -1;
	//元素后移 
	for(int j = 98; j >= pos; j--)
		(*p).arr[j + 1] = (*p).arr[j];
	//插入元素 
	(*p).arr[pos] = content;
	(*p).length++;
	return 0;
}

//查找指定位置元素 
int GetElem(SqList p, int pos)
{
	pos -= 1 ;
	if(pos < 0 || pos > 99)
		return -1;
	cout << "Ele at " << pos + 1 << " : ";
	cout << p.arr[pos] << endl;
	return 0;
}

//查找指定元素的位置 
void SearchElem(SqList p, char content)
{
	int found = 0;
	cout << "Pos of " << content << " : ";
	for(int i = 0; i < p.length; i++)
	{
		if (p.arr[i] == content)
		{
			cout << i + 1 << " ";
			found = 1;
		}
	}
	if(found == 0)
		cout << "Not Found";
	cout << endl;
}

//删除指定位置元素 
int DeleteElem(SqList *p, int pos)
{
	pos -= 1;
	if(pos < 0 || pos > 99 || (*p).length == 0)
		return -1;
	cout << "Del " << (*p).arr[pos] << " at " << pos + 1 << endl;
	//元素前移 
	for(int j = pos; j < (*p).length; j++)
		(*p).arr[j] = (*p).arr[j + 1];
	(*p).length--;
	return 0;
}

//输出顺序表 
void PrintList(SqList p)
{
	cout << "-Printing SqList-" << endl << "Length : " << p.length << endl;
	for(int i = 0; i < p.length; i++)
		cout << p.arr[i] << " ";
	cout << endl << "-End of Printing-" << endl;
}

int main()
{
	SqList S;
	S.length = 0;
	
	InsertElem(&S, 1, 'a');
	InsertElem(&S, 2, 'b');
	InsertElem(&S, 3, 'c');
	InsertElem(&S, 4, 'd');
	InsertElem(&S, 5, 'e');

	PrintList(S);
	GetElem(S, 3);
	SearchElem(S, 'a');
	DeleteElem(&S, 3);
	PrintList(S);
	return 0;
}
