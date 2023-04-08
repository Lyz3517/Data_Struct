# tree

## 1. 树和二叉树

**树的概念**：

### 1.1 树的定义与性质

**性质**:

- 树可以没有结点，这种情况下把树成为空树(empty tree)
- 树的层次(layer)从根结点开始算起，即根结点为第一层，根结点子树的根结点为第二层，以此类推。
- 把结点的子树棵树称为结点的度(degree),而树中结点最大的度称为树的度(也称为树的宽度)。
- 由于一条边连接两个结点，且树中不存在环，因此对有n个结点的树，边数一定是n-1，且满足连通、边数等于顶点数减1的结构一定是一棵树。
- 叶子结点被定义为度为0的结点，因此当树中只有一个结点(即只有根结点)时，根结点也算做叶子结点。
- 结点的n深度(depth)是指从根结点(深度为1)开始自顶向下逐层至该节点时的深度。结点的高度(height)是指从最低层叶子结点

### 1.2 二叉树的递归定义

- 要么二叉树没有结点，是一颗空树
- 要么二叉树由根结点、左子树、右子树组成，且左子树和右子树都是二叉树

### 1.3 二叉树的存储结构与基本操作

**1. 存储结构**
```C
struct node {
    typename date;  // 数据域
    node * lchild;  // 指向左子树根结点的指针
    node * rchild;  // 指向右子树根结点的指针
};
```
**2. 新建操作**
```C
// 由于建树前根结点不存在，因此其地址一般设为NULL
node* root = NULL;

// 生成一个新的结点，v为结点权值
node * newNode(int v)
{
    node* Node = new node;      // 申请一个node型变量的地址空间
    Node->data = v;         // 结点权值v
    Node->lchild = Node->rchild = NULL; // 初始状态下没有左右孩子
    return Node;            // 返回新建结点的地址
}
```

**2. 二叉树结点的查找和修改**
```C
void search(node* root, int x, int newdata)
{
    if (root == NULL)
    {
        return ;    // 空树，死胡同(递归边界)
    }
    if (root->data == x) {  // 找到数据域为x的结点，把它修改成newdata
        root->data = newdata;
    }
    search(root->lchild, x, newdata);   // 往左子树搜索x(递归式)
    search(root->rchild, x, newdata);   // 往左子树搜索x(递归式)
}
```


**3. 二叉树的插入**
```C
// insert 函数将在二叉树中插入一个数据域为x的新节点
// 注意根结点指针root要使用引用，否则插入不成功
void insert(node* &root, int x) {
    if (root == NULL) {         // 空树
        root = newNode(x);
        return ;
    }
    if (由二叉树的n性质，x应该插在左子树) {
        insert(root->lchild, x);    // 往左子树搜索(递归式)
    } else {
        insert(root->rchild, x);    // 往右子树搜索(递归式)
    }
}
```

**4. 二叉树的创建**
```C
// 二叉树的创建
node* Create(int data[], int n) {
    node* root = NULL;      // 新建空根结点
    for (int i = 0; i < n; i++) {
        insert(root, data[i]);  // 将data[0]-data[n-1]插入二叉树中
    }
    return root;    // 返回根结点.
}
```


### 完全二叉树的性质
> 对于完全二叉树当中的任何一个结点(设为编号为x)，其左孩子的n编号一定为2x，而右孩子的编号一定为2x+1.

## 2. 二叉树的遍历

### 2.1 中序遍历

### 2.2 先序遍历

### 2.3 后序遍历

### 2.4 二叉树的静态实现

## 3. 树的遍历

### 3.1 树的静态写法

### 3.2 树的先根遍历

### 3.3 树的层次遍历

### 3.4 从树的遍历来看BFS与DFS
