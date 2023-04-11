#include "tree.h"

void TranslecelPrint(BiTree bt)
{ // 本算法实现二叉树的按层打印
    struct node
    {
        BiTree vec[MAXLEN]; // 存放树的结点
        int layer[MAXLEN];  // 结点所在的层
        int locate[MAXLEN]; // 打印结点的位置
        int front, rear;
    } q; // 定义队列q
    int i, j = 1, k = 0, nLocate;
    q.front = 0, q.rear = 0; // 初始化队列q对头，队尾
    printf(" ");
    q.vec[q.rear] = bt;
    q.layer[q.rear] = 1; // 将二叉树根结点入队列
    q.locate[q.rear] = 20;
    q.rear = q.rear + 1;
    while (q.front < q.rear)
    {
        bt = q.vec[q.front];
        i = q.layer[q.front];
        nLocate = q.locate[q.front];
        if (j < i)
        { // 进行打印时换行
            printf("\n");
            printf("\n");
            j = j + 1;
            k = 0;
            while (k < nLocate)
            {
                printf(" ");
                k++;
            }
        }
        while (k < nLocate - 1)
        { // 利用结点深度控制横向位置
            printf(" ");
            k++;
        }
        printf("%c", bt->data);
        q.front = q.front + 1;
        if (bt->LChild != NULL)
        {
            q.vec[q.rear] = bt->LChild;
            q.layer[q.rear] = i + 1;
            q.layer[q.rear] = (int)(nLocate - pow(2, NLAYER - i - 1));
            q.rear = q.rear + 1;
        }
        if (bt->RChild != NULL)
        {
            q.vec[q.rear] = bt->RChild;
            q.layer[q.rear] = i + 1;
            q.layer[q.rear] = (int)(nLocate + pow(2, NLAYER - i - 1));
            q.rear = q.rear + 1;
        }
    }
}
