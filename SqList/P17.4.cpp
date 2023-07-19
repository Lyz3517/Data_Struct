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

void Del_Bt_ST(List &list, ELemType s, ELemType t) {
    if (s >= t || t > list.length || s < 0)  cout << "range of s or t is error!" << endl;

    int cnt = 0;
    _for(i, 0, list.length) {
        if (list.data[i] >= s && list.data[i] <= t) {
            cnt++;
        } else list.data[i-cnt] = list.data[i];  
    }
    if (cnt == 0) {
        cout << "It is not X with SqList!" << endl;
        return ;
    }
    list.length = cnt;
}

int main()
{
    List list;
    list.length = 4;
    int s = 3, t = 5;
    int Data[] = { 2,4,3,9 };
	for (int i = 0; i < list.length; i++)
		list.data[i] = Data[i];
	PrintList(list);
	Del_Bt_ST(list, s, t);
	PrintList(list);

    return 0;
}

