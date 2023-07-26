#pragma region   顺序栈

#include <cstdio>

#define MaxSize 50  // 定义栈中元素的最大个数
typedef int ElemType;
#define _for(i, a, b) for(int = (a); i < (b); i++) 

typedef struct {
    ElemType data[MaxSize];     // 存放栈中的元素
    int top;                    // 栈顶指针
} SqStack;

/**
 * @brief 初始化栈
 * 
 * @param S 
 */
void InitStack(SqStack &S) {
    S.top = -1;                 // 初始化栈顶指针
}

/**
 * @brief 判断栈空
 * 
 * @param S 
 * @return true 
 * @return false 
 */
bool StackEmpty(SqStack S) {
    return (S.top == -1);
}

/**
 * @brief 进栈
 * 
 * @param S 
 * @param x 
 * @return true 
 * @return false 
 */
bool Push(SqStack &S, ElemType x) {
    if (S.top == MaxSize-1)     // 栈满。报错
        return false;
    S.data[++S.top] = x;        // 指针先加1，再入栈
    return true;
}

/**
 * @brief 出栈
 * 
 * @param S 
 * @param x 
 * @return true 
 * @return false 
 */
bool Pop(SqStack &S, ElemType &x) {
    if (S.top == -1)            // 栈空，报错
        return false;
    x = S.data[S.top--];        // 先出栈，指针再减一
    return true;
}

/**
 * @brief 仅为读取栈顶元素，并没有出栈操作，因此原栈顶元素依然保留在栈中
 * 
 * @param S 
 * @param x 
 * @return true 
 * @return false 
 */
bool GetTop(SqStack S, ElemType &x) {
    if (S.top == -1) return false;      // 栈空，报错
    x = S.data[S.top];  
    return true;                        // x记录栈顶元素
}

void PrinList(SqStack S) {
    int i = 0;
    while (i <= S.top) {
        printf("%d ", S.data[i++]);
    } 
    printf("\n");
}

#pragma endregion