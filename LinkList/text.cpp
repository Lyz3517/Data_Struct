#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

#pragma region

typedef int ElemType;
#define _for(i, a, b) for (int i = (a); i < (b); i++) 

typedef struct ListNode {
    ElemType data;
    struct ListNode* next;
} ListNode, *LinkList;


LinkList InitList(LinkList& head) {
    head = (LinkList)malloc(sizeof(ListNode));
    head->next = NULL;

    return head;
}

LinkList head_List(LinkList& head, vector<int> data) {
    // ListNode* pre = (LinkList)malloc(sizeof(ListNode));
    // pre->data = data[0];
    // pre->next = NULL;
    // head->next = pre;

    _for(i, 0, data.size()) {
        ListNode* s = (LinkList)malloc(sizeof(ListNode));
        s->data = data[i];
        s->next = head->next;
        head->next = s;
    }
    return head;
} 

void PrintList(LinkList head) {
    if (head->next == NULL) {
        printf("this is empty!\n");
        return ;
    }
    while (head->next != NULL) {
        head = head->next;
        printf("%d ", head->data);
    }
}

#pragma endregion



/**
 * @brief 给定一个带头结点的单链表，设head为头结点，结点结构为(data, next)
 *         data为整型元素，next为指针元素，试写出算法：按递增次序输出单链表中各结点的数据元素，
 *         并释放结点所占的存储空间(要求：不允许使用数组作为辅助空间)
 * 
 * @return int 
 */

int main(void) {
    vector<int> data{ 6, 5, 4, 3, 2, 1 };
    LinkList head;
    head = InitList(head);
    head = head_List(head, data);
    PrintList(head);
    return 0;
}