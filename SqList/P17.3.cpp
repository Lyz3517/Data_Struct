#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#pragma region  建立线性表


#define WAY 1       // 1: 表示方法一， 2: 表示方法二
typedef int ElemType;

#define MAX_SIZE 30
#define _for(i,a,b) for (int i = a; i < b; ++i)
#define _rep(i,a,b) for (int i = a; i <= b; ++i)

typedef struct {
    ElemType data[MAX_SIZE];
    int length;
}List;

void swap(ElemType *a, ElemType *b){
    ElemType temp;
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


bool Del_All_X(List & list, ElemType X) {
    if (list.length < 1) {
        printf("This is eltype SqList!\n");
        return -1;
    }
// #ifndef WAY == 1
    // 设置一个辅助变量为cnt记录当前已有的x的个数
    // int cnt = 0;
    // _for(i,0,list.length) {
    //     if (list.data[i] != X) {
    //         list.data[i-cnt] = list.data[i];
    //     } else cnt++;
    // }
    // list.length -= cnt;

// #elif WAY == 2
    // 利用快慢指针的方法进行标记
    int fat = 0, slow = 0;
    _for(i,0,list.length) {
        if (list.data[i] != X) {
            list.data[slow++] = list.data[i];
        }
    }
    list.length = slow;
// #endif
    return 1;
}

int main()
{
    List list;
    list.length = 4;
    int X = 2;
    int Data[] = { 2,2,3,9 };
	for (int i = 0; i < list.length; i++)
		list.data[i] = Data[i];
    printf("Before with Del_All_X:\t");
	PrintList(list);   
    printf("after with Del_All_X:\t");
    if (Del_All_X(list, X)) cout << "Is find all X" << endl;
    else cout << "X of find is fair!" << endl;
    PrintList(list);   
    return 0;
}













