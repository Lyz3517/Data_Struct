#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#pragma region  建立线性表

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

void Reserve(List &list, int start, int end, int size) {
    if (end <= start || end >= size) {
        printf("end of range is error!\n");
        return ;
    }
    int mid = (end - start)/2 + start;
    _rep(i,0,mid) {
        swap(list.data[i], list.data[size-i-1]);
    }
}

#pragma endregion

int main()
{
    List list;
    list.length = 4;
    int Data[] = { 2,4,3,9 };
	for (int i = 0; i < list.length; i++)
		list.data[i] = Data[i];
    printf("Before with Reserve:\t");
	PrintList(list);   
    printf("after with Reserve:\t");
    Reserve(list, 0, list.length-1, list.length);
    PrintList(list);   
    return 0;
}













