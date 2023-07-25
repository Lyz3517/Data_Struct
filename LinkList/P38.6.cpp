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
        if (L->next == NULL) {
            printf("It is empty of List");
            return ;
        }

        while (L->next != NULL) {
            L = L->next;
            printf("%d ", L->data);
        }
    } else if (mode == 2) {
        if (L->next == NULL) {
            printf("It is empty of List");
            return ;
        }

        while (L != NULL) {
            printf("%d ", L->data);
            L = L->next;
        }
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
 * @param mode : 1. 带头结点的单链表
 *               2. 不带头结点的单链表
 * @return LinkList 
 */
LinkList HeadList(LinkList& L, int mode, vector<int> data) {
    if (mode == 1) {
        _for(i, 0, data.size()) {
            ListNode* s = (LinkList)malloc(sizeof(ListNode));
            s->data = data[i];
            s->next = L->next;
            L->next = s;     
        }
        return L;
    } else if (mode == 2) {         // 理解为 s1->L  转变为L->s1 第二轮 s2->L->s1 L->s2->s1
        _for(i, 0, data.size()) {
            ListNode* s = (LinkList)malloc(sizeof(ListNode));
            s->data = data[i];
            s->next = L;
            L = s;
        }
        return L;
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
    head = IintList(head, 2);
    vector<int> data{ 1, 2, 3, 3, 4, 5, 6, 8 };
    head = HeadList(head, 2, data);
    PrintList(head, 2);
    return 0;
}