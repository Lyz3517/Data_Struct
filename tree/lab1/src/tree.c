#include "tree.h"

void CreateBiTree(BiTree *bt)
{ // 按照先序序列建立二叉树的二叉链表
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
        *bt = NULL;
    else
    {
        *bt = (BiTree)malloc(sizeof(BiTNode)); // 生成一个新结点
        (*bt)->data = ch;
        CreateBiTree(&((*bt)->LChild)); // 生成左子树
        CreateBiTree(&((*bt)->RChild)); // 生成右子树
    }
}

void Visit(char ch)
{ // 输出d结点
    printf("%c ", ch);
}
