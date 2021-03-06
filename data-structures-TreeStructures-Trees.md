## 树

### 树的基本概念

#### 树的定义

1. **树**：树即树形结构，是一种非常重要的非线性结构。树是 $n(n \geq 0)$ 个结点的集合。当 $n = 0$ 时，称该树为 **空树** 。在任一非空 $(n \gt 0)$ 的树中，有且仅有一个称作 **根** 的结点，其余结点再分成 $m (m \geq 0)$ 个不相交的 **子树 （根结点的子树）**。每个子树又可视作同样定义的树。

2. **树的特点**：

    - **树的定义是递归的：** 根据树的定义，树的是一种递归的数据结构，递归结束于叶子结点。

    - **树是一种分层逻辑结构：** 树结构中，若父节点作为直接前驱，子女结点作为直接后继，则除根节点和叶子结点外，所有的结点都有一个唯一的直接前驱，有多个个直接后继。而根节点只有后继没有前驱，叶子结点只有唯一前驱没有后继。在 $n$ 个结点的树中，有 $n - 1$ 条边。

    - **树形逻辑结构：** 树结构在形式上可视为一颗倒立的“树”。树的顶端是根节点，最末端是叶子结点。

3. **有序树和无序树**：

    - **有序树：** 树结构中，结点的各子树从左到右是有次序的，不能互换。

    - **无序树：** 树结构中，结点的各子树的顺序是任意的。

#### 树的基本术语

1. **根结点：** 树结构中，所有结点都由该结点直接或间接引出。

2. **叶子结点：** 树结构中，其后继不再有其他结点的结点称为叶子结点（度为0）。也称终端结点。

3. **父结点：** 树结构中，除根结点外，每一个结点的直接前驱称为该结点的父结点。

4. **子女结点：** 树结构中，除叶子节点外,每一个结点的直接后继称为改结点的子女结点。

5. **结点的度：** 树结构中一个结点拥有的子女结点（孩子结点）的个数称为该结点的度。

6. **分支结点：** 度大于零的结点称为分支结点，也称非终端结点。

6. **树的度：** 树结构中，所有结点的度的最大值称为该树的度。

7. **兄弟结点：** 树结构中，若若干结点拥有同一个直接前驱（这些结点的父结点是同一个结点），则称这些结点互为兄弟。

8. **树的层次：** 从根节点开始，根结点作为树的第一层，它的子女结点作为第二层，此后每经过一代，树的层树增加一。

9. **堂兄弟结点：** 双亲（父结点）在同一层的结点互为堂兄弟。

10. **树的深度：** 从根结点开始，树的层数加一，则树的深度加一。数值上等于树的层数。

11. **树的高度：** 从距离根结点最远（层数最大）的叶子结点开始，到根结点的层数即为树的高度。数值上等于树的层数。

12. **路径：** 树结构中，从一个结点到另一个结点所经过的结点序列，称为这两个结点之间的路径。

13. **路径长度：** 即路径中所经过的边的个数。

14. **森林：** $m (m \geq 0)$ 颗树的集合。树与森林极为相似，在形式上，将 $m (m \geq 0)$ 颗树形成的森林通过根节点串起来，即构成一个新的树。当一个树被抹去根结点之后便可转化称森林。

### 二叉树

#### 二叉树的定义和特性

##### 二叉树的定义

- **二叉树** 或为一颗空树，或为一颗由一个根结点和两颗互不相交的分别被称为根结点的左子树和右子树组成的非空树。二叉树的左子树根右子树同样是一棵二叉树。 

##### 二叉树的特性

1. **递归性** ：二叉树的定义是递归的。递归结束于空子树。

2. **顺序性** ：二叉树是有序树，二叉树的子树要区分左子树和右子树。左右子树有严格的顺序，位置不能随意交换。

##### 完全二叉树

**完全二叉树的定义** ：设二叉树 $T$ 有 $n$ 个结点，则：

- 二叉树 $T$ 的深度： $k = \log_2{n+1}$ ；

- 二叉树 $T$ 第 $k$ 层的结点数 $r = n - (2^{k - 1} -1)$ 。

若其中 $2^{k - 1}$ 个结点放满第1到第 $k - 1$ 层，若 $0 \lt r \leq 2^{k - 1}$ ，则称 $T$ 为 **完全二叉树** 。特别地，当 $r = 2^{k - 1}$ 时，称 $T$ 为 **满二叉树** 。 **满二叉树属于完全二叉树** 。

##### 二叉树的性质

1. 二叉树的第 $i$ 层上至多有 $2^{i - 1}$ 个结点( $i \geq 1$ ，根结点所在层次为1)。

2. 高度为 $h$ 的二叉树至多有 $2^{h - 1}$ 个结点( $h \geq 0$ ,空树的高度为0)。

3. 设二叉树中度为2的结点有 $n_2$ 个，度为1的结点有 $n_1$ 个，度为0（叶子结点）的结点有 $n_0$ 个，则 **$n_0 = n_2 + 1$** 。

4. 具有 $n ( n \gt 0)$ 个结点的完全二叉树的深度为 $\log_2{(n+1)}$ 或 $\log_2{n} + 1$ 。

5. 若将一颗有n个结点而完全二叉树按层次自顶向下，同一层自左向右给结点编号 $1, 2, , \dots , n$ ，并简编号为 $i$ 的结点为结点 $i (0 \leq i \leq n)$ ，则：

    - 若 $i = 1$ ，则结点 $i$ 为根节点，该结点无父节点；若 $i \gt 1$ ，则结点 $i$ 的父节点为：$\frac{i}{2}$ 。

    - 若 $2i \lt n$ ，则结点 $i$ 的左子女结点为 $2i$ 。

    - 若 $2i + 1 \lt n$ ，则结点 $i$ 的右子女结点为 $2i + 1$ 。

    - 若结点编号 $i$ 为奇数，且 $i \gt 1$ ，则它的左兄弟为结点 $i - 1$ 。

    - 若结点编号 $i$ 为偶数，且 $i \lt n$ ，则它的右兄弟为结点 $i + 1$ 。
 

    - 结点 $i$ 所在层次为： $\log_2{i} + 1$ 。

##### 疑难点辨析

1. **二叉树是树吗？**

>答：

#### 二叉树的存储

##### 二叉树的顺序存储

##### 二叉树的链式存储

#### 二叉树的遍历

#### 线索二叉树

### 树与森林

### 数与二叉树的应用

#### 二叉查找树

#### AVL树

#### Huffman树与Huffman编码

#### 堆

#### 并查集
