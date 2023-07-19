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

void Reserve(List &list, int start, int end, int size) {
    // if (end <= start || end >= size) {
    //     printf("end of range is error!\n");
    //     return ;
    // }
    int mid = (end + start)/2;
    _rep(i,start,mid) {
        swap(list.data[i], list.data[size-i-1 + start]);
    }
}


int main()
{
    List A, B;
    int m = 5, n = 5;
    A.length = 10;
    B.length = 5;
    int Data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int Data1[] = { 11, 21, 31, 41, 51, 61, 71, 81, 91, 110 };
	for (int i = 0; i < A.length; i++)
		A.data[i] = Data[i];
	PrintList(A);
    for (int i = 0; i < B.length; i++)
		B.data[i] = Data[i];
	PrintList(B);
	Reserve(A, 0, m-1, m);
    PrintList(A);
    Reserve(A, m, n+m-1, n+m);
    PrintList(A);
    Reserve(A, 0, m+n-1, m+n);
	PrintList(A);

    return 0;
}

