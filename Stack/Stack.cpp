/**
 * @file Stack.cpp
 * 
 * @author Lyz3517 (you@domain.com)
 * @brief 
 * 写代码：定义顺序存储的栈（数组实现），数据元素是 int 型
 * 写代码：基于上述定义，实现“出栈、入栈、判空、判满”四个基本操作
 * 写代码：定义链式存储的栈（单链表实现）
 * 写代码：基于上述定义，栈顶在链头，实现“出栈、入栈、判空、判满”
 * 四个基本操作写代码：定义链式存储的栈（双向链表实现）
 * 写代码：基于上述定义，栈顶在链尾，实现“出栈、入栈、判空、判满”四个基本操作
 * 给自己出题：自己动手创造，写一个具有多层小括号、中括号的算数表达式
 * 画图：针对2.1.7的算数表达式，使用栈进行“括号匹配”，画出栈内元素最多的状态
 * 简答：请描述使用栈进行括号匹配的过程
 * @version 0.1
 * @date 2023-07-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <SqStack.h.h>

using namespace std;

// #pragma region    栈的应用

// #define MaxSize 50  // 定义栈中元素的最大个数
// typedef int ElemType;
// #define _for(i, a, b) for(int = (a); i < (b); i++) 

// typedef struct {
//     ElemType data[MaxSize];     // 存放栈中的元素
//     int top;                    // 栈顶指针
// } SqStack;

// /**
//  * @brief 初始化栈
//  * 
//  * @param S 
//  */
// void InitStack(SqStack &S) {
//     S.top = -1;                 // 初始化栈顶指针
// }

// /**
//  * @brief 判断栈空
//  * 
//  * @param S 
//  * @return true 
//  * @return false 
//  */
// bool StackEmpty(SqStack S) {
//     return (S.top == -1);
// }

// /**
//  * @brief 进栈
//  * 
//  * @param S 
//  * @param x 
//  * @return true 
//  * @return false 
//  */
// bool Push(SqStack &S, ElemType x) {
//     if (S.top == MaxSize-1)     // 栈满。报错
//         return false;
//     S.data[++S.top] = x;        // 指针先加1，再入栈
//     return true;
// }

// /**
//  * @brief 出栈
//  * 
//  * @param S 
//  * @param x 
//  * @return true 
//  * @return false 
//  */
// bool Pop(SqStack &S, ElemType &x) {
//     if (S.top == -1)            // 栈空，报错
//         return false;
//     x = S.data[S.top--];        // 先出栈，指针再减一
//     return true;
// }

// /**
//  * @brief 仅为读取栈顶元素，并没有出栈操作，因此原栈顶元素依然保留在栈中
//  * 
//  * @param S 
//  * @param x 
//  * @return true 
//  * @return false 
//  */
// bool GetTop(SqStack S, ElemType &x) {
//     if (S.top == -1) return false;      // 栈空，报错
//     x = S.data[S.top];  
//     return true;                        // x记录栈顶元素
// }

// void PrinList(SqStack S) {
//     int i = 0;
//     while (i <= S.top) {
//         printf("%d ", S.data[i++]);
//     } 
//     printf("\n");
// }
// #pragma endregion


int main()
{
    int num;
    SqStack S;
    InitStack(S);
    Push(S, 1);
    printf("%d\n", StackEmpty(S));
    PrinList(S);
    Pop(S, num);
    printf("%d\n", StackEmpty(S));
    PrinList(S);
    return 0;
}


