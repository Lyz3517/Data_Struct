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

void PrintList(List list) {
    _for(i, 0, list.length) {
        cout << list.data[i] << " ";
    }
    cout << endl;
}

#pragma endregion

void Del_All_Num(List &list) {
    if (list.length <= 0) cout << "SqList is empty!" << endl;

    if (list.length == 1) return ;

    int cnt = 1;
    _for(i, 0, list.length-1) {
        if (list.data[i] != list.data[i+1]) {
            list.data[cnt++] = list.data[i+1];
        }
    }
    list.length = cnt;
}

int main()
{
    List list;
    list.length = 10;
    int Data[] = { 1, 1, 2, 3, 7, 7, 8, 8, 9, 10 };
	for (int i = 0; i < list.length; i++)
		list.data[i] = Data[i];
	PrintList(list);
	Del_All_Num(list);
	PrintList(list);

    return 0;
}

