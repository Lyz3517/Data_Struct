#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#pragma region  建立单链表

#define _for(i,a,b) for (int i = (a); i < (b); i++) 
typedef int ElemType;

typedef struct LNode{
    struct LNode* next;
    ElemType data;
} LNode, *LinkList;

LinkList CreatList(LinkList& head) {
    head = (LinkList)malloc(sizeof(LNode));
    head->next = NULL;
    return head;
}

LinkList Head_CreatList(LinkList& head, vector<int> data) {
    LinkList s = head;
    int i = 0;
    while(i < data.size()) {
        LNode* r = (LinkList)malloc(sizeof(LNode));
        r->data = data[i++];
        s->next = r;
        s = r;
    }
    return head;
}

void PrintList(LinkList& head) {
    if (head->next == NULL) {
        cout << "this is empty list" << endl;
        return ;
    }
    while (head->next != NULL) {
        printf("%d ", head->next->data);
        head = head->next;
    }
}

#pragma endregion

// 使用双指针法实现链表反转
LinkList Reverse(LinkList& head) {
    LNode* s, *p = head->next;
    head->next = NULL;
    while (p != NULL) {
        s = p->next;
        p->next = head->next;
        head->next = p;
        p = s;
    }
    return head;
}

// LinkList Reverse(LinkList& head) {
//     LNode *p = head->next, *r;
//     // head->next = NULL;
//     while (p != NULL) {
//         r = p->next;
//         p->next = head->next;
//         head->next = p;
//         p = r;
//     }
//     return head;
// }

int main(void) {
    LinkList head;
    head = CreatList(head);
    vector<int> data{ 1, 2, 3, 3, 4, 4, 5, 6};
    head = Head_CreatList(head, data);
    PrintList(head);
    head = Reverse(head);
    PrintList(head);
    return 0;
}