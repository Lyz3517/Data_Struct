#include "tree.h"

void PreOrder(BiTree root) {      // 先序遍历二叉树，root为指向二叉树(或某一子树)根结点的指针
    if (root != NULL) {
        Visit(root->data);
        PreOrder(root->LChild);
        PreOrder(root->RChild);
    }

}

void InOrder(BiTree root) {      // 中序遍历二叉树
    if (root != NULL) {
        InOrder(root->LChild);
        Visit(root->data);
        InOrder(root->RChild);
    }
}

void PostOrder(BiTree root) {    // 后序遍历二叉树
    if (root != NULL) {
        PostOrder(root->LChild);
        PostOrder(root->RChild);
        Visit(root->data);
    }
}