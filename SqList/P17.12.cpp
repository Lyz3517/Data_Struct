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

#pragma endregion

// 算法思想

bool HaveMElem(List L) {


    return ;
}



int main()
{
    List list1, list2;
    list1.length = 5;
    list2.length = 5;
    int Data[] = { 11, 13, 15, 17, 19 };
    int Data1[] = { 2, 4, 6, 8, 9};
	for (int i = 0; i < list1.length; i++){
        list1.data[i] = Data[i];
        list2.data[i] = Data1[i];
    }
		
    printf("Before with Reserve:\t");
	PrintList(list1);   
    PrintList(list2);  
    // printf("%d", FindMind(list1, list2));  
    return 0;
}















