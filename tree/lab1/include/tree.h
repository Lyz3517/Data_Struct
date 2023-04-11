#pragma once

// #include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXLEN 100
#define NLAYER 4
BiTree T;

typedef struct BiTNode
{                                    // 定义二叉树结点结构
    char data;                       // 数据域
    struct BiTNode *LChild, *RChild; // 左右孩子指针域
} BiTNode, *BiTree;

void CreateBiTree(BiTree *bt);   // 建立二叉树
void TranslecelPrint(BiTree bt); // 树状打印二叉树
void Visit(char ch);             // 输出结点
void PreOrder(BiTree root);      // 先序遍历二叉树
void InOrder(BiTree root);       // 中序遍历二叉树
void PostOrder(BiTree root);     // 后序遍历二叉树
void PreOrderleaf(BiTree root);  // 输出叶子结点
int LeafCount(BiTree root);      // 输出叶子结点的个数
int PostTreeDepth(BiTree root);  // 输出二叉树的深度
void mainwork();                 // 主要工作函数。操作区用户界面
int main();                      // 主函数。创建二叉树，调用工作区模块函数
