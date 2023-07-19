#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

// 设计一个递归算法，删除不带头结点的单链表的所有值为x的结点

typedef int ElemType;
#define _for(i,a,b) for (int i = (a); i < (b); i++)

#pragma region 建立不带头结点的单链表

typedef struct LNode{
    struct LNode* next;
    ElemType data;
}LNode, *LinkList;

// 初始化链表
bool InitList(LinkList& head) {
    head = NULL;
    return true;
}

void PrintList(LinkList head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

bool IsEmpty(LinkList head) {
    return (head == NULL);
}

// 使用尾插法创建单链表
LinkList CreatList(LinkList& head, vector<int> data) {
    LNode* pre = (LinkList)malloc(sizeof(LNode));
    pre->data = data[0];
    pre->next = NULL;
    head = pre;
    _for(i, 1, data.size()) {
        LNode* s = (LinkList)malloc(sizeof(LNode));
        s->data = data[i];
        s->next = NULL;
        pre->next = s;
        pre = s;
    }
    return head;
}

#pragma endregion

void DeleteXNode(LinkList& head, ElemType X) {
    if (head == NULL) return ;
    if (head->data != X) {
        return DeleteXNode(head->next, X);
    }
    LNode* p = head;
    head = head->next;          // 等同于head->next = head->next->next;
    delete(p);
    return DeleteXNode(head, X);
}


int main(){
    vector<int> data{1, 2, 3, 4, 4, 5, 6};
    LinkList head;
    InitList(head);
    head = CreatList(head, data);
    PrintList(head);
    DeleteXNode(head, 4);
    PrintList(head);
    return 0;
}