#include "LinkBiTree.h"
#include <iostream>
using namespace  std;

LinkBiTree::BiTreeNode* LinkBiTree::PreCreateBiTree(BiTreeNode *bt)
{
    ElemType elem;  // 输入字符
    cin >> elem;

    if (elem == '#')    // 如果当前结点存储的是#，那么该节点为虚结点，指向该结点的指针为空指针    
    {
        cout << "当前结点为虚结点!" << endl;
        bt = NULL;      // 如果用函数
    } else {
        bt = new BiTreeNode;    // 如果当前结点的存储数据域地址不为#，是字符，创建结点空间

        bt->data = elem;        // 存下数据

        cout << "打印当前结点的数据域：" << bt->data << endl;
        bt->lchild = PreCreateBiTree(bt->lchild);
        bt->rchild = PreCreateBiTree(bt->rchild);
    }
    return bt;
}

void LinkBiTree::Init_PreCreateBiTree() // 调用私有成员函数:前序建立二叉树
{
    PreCreateBiTree(root);              // 头指针始终存在，不管有没有根结点。当根结点存在时，创建，创建根结点存储空间，并用头指针指向它
    cout << "前序创建二叉树完成!" << endl;
}