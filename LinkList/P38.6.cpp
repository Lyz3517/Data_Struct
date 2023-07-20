#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#pragma region 建立带头结点的单链表

#define _for(i, a, b) for (int i = (a); i < (b); i++)
typedef int ElemType;

typedef struct ListNode {
    struct ListNode* next;
    ElemType data;
} ListNode, *LinkList;

/**
 * @brief 创建单链表
 * 
 * @param L 
 * @param mode 
 * @return LinkList 返回一个头指针
 */
LinkList IintList(LinkList& L, int mode) {
    if (mode == 1) {
        L = (LinkList)malloc(sizeof(ListNode));
        L->next = NULL;
        return L;
    } else if (mode == 2) {
        L = NULL;
        return L;
    }
}

/**
 * @brief 打印输出单链表
 * 
 * @param L : 单链表
 * @param mode : 
 *              1. 带头结点的链表输出
 *              2. 不带头结点的链表输出
 */
void PrintList(LinkList L, int mode) {
    if (mode == 1) {
        ;
    } else if (mode == 2) {
        ;
    }
}

/**
 * @brief 判断链表是否为空
 * 
 * @param L 
 * @return true 
 * @return false 
 */
bool IsEmpty(LinkList L, int mode) {
    if (mode == 1) {
        return (L->next == NULL);
    } else if (mode == 2) {
        return (L == NULL);
    }
}

/**
 * @brief 
 * 
 * @param L 
 * @param mode 
 * @return LinkList 
 */
LinkList HeadList(LinkList& L, int mode) {
    if (mode == 1) {
        ;
    } else if (mode == 2) {
        ;
    }
}

/**
 * @brief 
 * 
 * @param L 
 * @param mode 
 * @return LinkList 
 */
LinkList TailList(LinkList& L, int mode, vector<int> data) {
    if (mode == 1) {
        ListNode* tail = (LinkList)malloc(sizeof(ListNode));
        tail->data = data[0];
        tail->next = NULL;
        L->next = tail;

        _for(i, 1, data.size()) {
            ListNode* s = (LinkList)malloc(sizeof(ListNode));
            s->data = data[i];
            s->next = NULL;
            tail->next = s;
            tail = s;
        }
        return L;
    } else if (mode == 2) {
        ListNode* tail = (LinkList)malloc(sizeof(ListNode));
        tail->data = data[0];
        tail->next = NULL;
        L->next = tail;

        _for(i, 1, data.size()) {
            ListNode* s = (LinkList)malloc(sizeof(ListNode));
            s->data = data[i];
            s->next = NULL;
            tail->next = s;
            tail = s;
        }
        return L;
    }
}

#pragma endregion


int main(void)
{
    LinkList head;
    head = IintList(head, 1);

    return 0;
}