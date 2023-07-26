#ifndef   链栈

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef int ElemType;
#define _for(i, a, b) for(int = (a); i < (b); i++) 

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
} StackNode, *LinkStack;

LinkStack InitStack(LinkStack &stack) {
    // 带头结点的链栈
    stack = (LinkStack)malloc(sizeof(StackNode));
    stack->next = NULL;

    return stack;
}

LinkStack HeadStack(LinkStack &stack, vector<int> num) {
    
}
#endif

