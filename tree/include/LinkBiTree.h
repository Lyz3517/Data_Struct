#pragma once
#include <iostream>

typedef char ElemType;

class LinkBiTree
{
public:
    struct BiTreeNode{
        ElemType data;  // 当前结点的数据域
        BiTreeNode *lchild, *rchild;   // 当前结点的指针域：指向左右孩子。
    };
    // LinkBiTree(/* args */);
    // ~LinkBiTree();
    void Init_PreCreateBiTree();    // 前序创建二叉树接口模块：调用私有成员函数
    void De_PreReleaseBiTree();     // 销毁前序创建的二叉树的接口模块：调用私有成员销毁

    void Port_PreOrder();            // 前序遍历接口模块
    void Port_InOrder();             // 中序遍历接口模块
    void Port_PostOrder();           // 后序遍历接口模块

private:        // 二叉树在私有权限，和前面提到的数据结构有很大的不同，主要原因是使用了递归这种函数
    /* data */
    BiTreeNode *root;                   // 头指针，指向根结点

    BiTreeNode * PreCreateBiTree(BiTreeNode *bt); // 使用前序建立二叉树，输入二叉树的前序序列，创建结用于存储(返回创建杰结点的地址)

    void PreReleaseBiTree(BiTreeNode *bt);      // 销毁前序创建的二叉树

    void PreOrder(BiTreeNode *bt);      // 前序遍历二叉树
    void InOrder(BiTreeNode *bt);       // 中序遍历二叉树
    void PostOrder(BiTreeNode *bt);     // 后序遍历二叉树
};

// LinkBiTree::LinkBiTree(/* args */)
// {
// }

// LinkBiTree::~LinkBiTree()
// {
// }

