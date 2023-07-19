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

// 找到两个升序序列的中位数，即第[L/2]个位置的数称为S的中位数

int FindMind(List A, List B) {
    if (A.length < 1 || B.length < 1) {
        printf("error!\n");
        return -1;
    }        
    
    int i = 0, j = 0, cnt = 0, IsMind = 0;
    int Mind = (A.length + B.length)/2;
    printf("Mind is %d", Mind);
    while (i < A.length && j < B.length) {
        if (A.data[i] >= B.data[j]) {
            IsMind = B.data[j];
            j++;
        }
        else if (A.data[i] < B.data[j]){
            IsMind = A.data[i];
            i++;
        }
        cnt++;
        printf("%d %d %d \n", i, j , cnt);
        if (cnt ==  Mind){
            printf("is find\n");
            return IsMind;
        }
    } 
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
    printf("%d", FindMind(list1, list2));  
    return 0;
}













