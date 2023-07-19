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

// void FindMin(List &list, ELemType X) {
//     if (list.length == 0) cout << "This is emptye SqList" << endl;

//     int pre = 0;
//     _for (i, 0, list.length) {
//         if (list.data[i] >= )
//     }


// }

// 答案方法 折半查找
void SearchExchangeInsert(List& A, int x)
{   
    int low = 0, mid = A.length / 2, high = A.length-1;
    bool Isfind = false;
    while (low <= high) {
        mid = (high - low) / 2 + low;
        if (x == A.data[mid]) { // 查找成功
            Isfind = true;
            printf("Find!\n");
            break;
        } else if (x > A.data[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (Isfind && mid != A.length - 1) {
        swap(A.data[mid], A.data[mid+1]);
    }
    if (!Isfind) {
        int i = 0;
        for (i = A.length - 1; i > high; i--) {
            A.data[i+1] = A.data[i];
        }
        A.data[i+1] = x;
        A.length += 1;
    }
}

int main()
{
    List list;
	list.length = 10;
	int Data[] = { 1,4,9,11,14,24,32,54,62,81 };
	_for(i, 0, list.length)
		list.data[i] = Data[i];
	PrintList(list);
	//CheckAndSwap(list, 54);
	SearchExchangeInsert(list, 23);
	PrintList(list);

    return 0;
}















