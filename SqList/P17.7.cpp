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

List merge(List A, List B) {
    List C;
    int i = 0, j = 0, cnt = 0;

    while (i < A.length && j < B.length) {
        if (A.data[i] <= B.data[j]) {
            C.data[cnt++] =  A.data[i++];
        } else if (A.data[i] > B.data[j]) {
            C.data[cnt++] =  B.data[j++];
        } 
    }
    while (i < A.length)  C.data[cnt++] =  A.data[i++];
    while (j < B.length)  C.data[cnt++] =  B.data[j++];
    C.length = cnt;
    return C;
}

int main()
{
    List A, B;
    A.length = 10;
    B.length = 10;
    int Data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int Data1[] = { 11, 21, 31, 41, 51, 61, 71, 81, 91, 110 };
	for (int i = 0; i < A.length; i++)
		A.data[i] = Data[i];
	PrintList(A);
    for (int i = 0; i < B.length; i++)
		B.data[i] = Data[i];
	PrintList(B);
	List C = merge(A, B);
	PrintList(C);

    return 0;
}

