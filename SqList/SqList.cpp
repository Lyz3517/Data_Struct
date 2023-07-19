#include <cstdio>
#include <iostream>
#include <algorithm>


using namespace std;

#pragma region 建立顺序存储的线性表

typedef int ELemType; 
#define MAX 30
#define _for(i,a,b) for (int i = (a); i < (b); ++i)
#define _rep(i,a,b) for (int i = (a); i <= (b); ++i)

typedef struct {
    ELemType data[MAX];
    int length;
}List;

void swap(ELemType *a, ELemType *b) {
    ELemType temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// 给定一个List，传入List的大小，要逆转的起始位置
void Reserve(List* list, int start, int end, int size) {
    if (end <= start || end >= size) {
        printf("end over sqlist of length!");
        return ;
    }
    int mid = (end - start) / 2 + start;
    _rep(i , 0, mid) {
        swap(&list->data[start + i], &list->data[end-i]);
    }
}

void PrintList(List list) {
    _for(i, 0, list.length) {
        cout << list.data[i] << " ";
    }
    cout << endl;
}

#pragma endregion

//P19.1
//从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值。空出的位
//置由最后一个元素填补, 若顺序表为空则显示出错信息并退出运行

int FindMin(List& list) {
    if (!list.length) {
        printf("Error!\n");
        return -1;
    }
    int Min = 999;
    int point  = 0;
    _for(i,0,list.length){
        if (list.data[i] < Min) {
            Min = list.data[i];
            point = i;
        }
    }
    list.data[point] = list.data[list.length-1];
    list.length--;
    return Min;
}

int main()
{
    List list;
    list.length = 4;
    int Data[] = { 2,4,3,9 };
	for (int i = 0; i < list.length; i++)
		list.data[i] = Data[i];
	PrintList(list);
	int del = 2;
	cout <<"删除最小值的元素为："<< FindMin(list) << endl;
	PrintList(list);

    return 0;
}

