#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

// P40.2
// 在带头结点的单链表中，删除所有值为x的结点，并释放其空间
// 不唯一，试编写算法以实现上述操作

#pragma region

typedef int ElemType;
#define _for(i,a,b) for (int i = (a); i < (b); ++i)

typedef struct List{
    ElemType data;
    struct List* next;
}LNode, *LinkList;

// 初始化链表
bool InitList(LinkList& head) {
    // 分配一个头结点
    head = (LNode*)malloc(sizeof(LNode));
    // 内存不足，分配失败
    if (head == NULL) {
        return false;
    }
    // 头结点之后暂时没有结点
    head->next = NULL;
    return true;
}

bool IsEmpty(LinkList& head) {
    return (head->next == NULL);
}

// 使用尾插法创建链表
LinkList CreatList(vector<int> data)
{
    if (data.size() < 1) return NULL;

    // 头结点
    LNode* head = (LinkList)malloc(sizeof(LNode));
    head->next = NULL;
    LinkList p = head;
    _for(i, 0, data.size()) {
        LNode* s = (LinkList)malloc(sizeof(LNode));
        s->data = data[i];
        s->next = NULL;
        p->next = s;
        p = s;
    }
    return head;
}

/**
 * PrintList: 打印单链表
 * 参数：
 * mode： 1: 不带头结点， 2: 带头结点
 * 
*/

void PrintLint(LinkList head, int mode) { 
    if (mode == 1) {
        if (head == NULL) return ;
        while (head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\nmode 1 Print is over!\n");
    } else if (mode == 2) {
        if (head->next == NULL) return ;
        head = head->next;
        while (head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\nmode 2 Print is over!\n");
    }
} 
#pragma endregion




// 删除带头结点中,所有为x的结点
LinkList DeleteXNode(LinkList& head, ElemType X) {
    if (head->next == NULL) {
        cout << "LinkList is empty" << endl;
    }

    LNode* s = head->next;
    LNode* p = head;
    while (s != NULL) {
        if (s->data == X) {
            LNode* d = s;
            p->next = s->next;
            s = s->next;
            delete d;
        } else {
            p = s;
            s = s->next;
        }
    }
    return head;
}

int main(){
    vector<int> data{ 1, 2, 3, 4, 5, 6, 7, 7, 10 };
    LinkList head;
    InitList(head);
    head = CreatList(data);        // 带头结点
    PrintLint(head, 2);
    // head = Reverse(head);
    head = DeleteXNode(head, 7);  
    PrintLint(head, 2);
    return 0;
}

