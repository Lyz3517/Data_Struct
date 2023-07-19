#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

// 全篇mode = 1 表示不带头结点的方式进行实现的
// mode = 2 表示带头结点的方式实现的

#pragma region

typedef int ElemType;
#define _for(i,a,b) for (int i = (a); i < (b); ++i)

typedef struct List{
    ElemType data;
    struct List* next;
}LNode, *LinkList;


// 初始化链表 不带头结点
bool InitList(LinkList& L) {
    L = NULL;
    return true;
}

// 带头结点创建
LinkList CreatList(LinkList L) {
    LNode* head = (LinkList)malloc(sizeof(LNode));
    head->next = NULL;
    return head;
}

// 不带头结点创建
LinkList CreatList1(LinkList L) {

}

// 全篇mode = 1 表示不带头结点的方式进行实现的
// mode = 2 表示带头结点的方式实现的
LinkList HeadInster(LinkList &L, int n, int mode) {
    if (mode == 1) {
        LNode *s;
        int x = 1;
        L = (LinkList)malloc(sizeof(LNode));
        L->next = NULL;

        scanf("%d", &x);
        while (x != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
        }
    } else if (mode == 2) {
        ;
    }
    
    return L;
}

// 尾插法
LinkList List_TailInsert(vector<int> data) {
    if (data.size() < 1) {
        printf("Vecotr is emtype!\n");
        return NULL;
    }
    // 带头结点
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

// 删除

// 增加

// 修改
// 判断是否为空
bool IsEmpty(LinkList L, int mode) {
    if (mode == 1) return (L == NULL);
    else if (mode == 2) return (L->next == NULL);
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


// 设计一个算法实现链表反转，
LinkList Reverse(LinkList& head) {
    LNode *p = head->next, *r;
    // head->next = NULL;
    while (p != NULL) {
        r = p->next;
        p->next = head->next;
        head->next = p;
        p = r;
    }
    return head;
}

int main(){
    vector<int> data{1, 2, 3, 4, 5, 6, 7, 7, 10};
    LinkList head;
    // CreatList(head);        // 带头结点
    head = List_TailInsert(data);
    PrintLint(head, 2);
    head = Reverse(head);
    PrintLint(head, 2);
    return 0;
}

