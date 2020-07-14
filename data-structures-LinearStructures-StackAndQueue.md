## 栈与队列

### 栈

#### 栈的定义和基本运算

1. **栈的定义**：栈（Stack）可以认为是只允许在末端进行插入和删除元素的线性表。

2. **栈的特点**：栈只允许在末端进行元素的访问，这里的末端有一个形象的名称——栈顶。也就是，栈只能在栈顶进行元素的插入和删除操作。由于栈的这种结构，往往先被插入到栈的元素要等到相较于该元素后被插入的元素退出栈，即该元素处于栈顶位置，才能被访问。因此，栈也被称作后进先出（LIFO,Last In First Out）或先进后出（FILO,First In Last Out）的线性表。

3. **栈的基本运算**：栈的基本操作（运算）有如下5种：

    - **栈初始化操作**：创建一个空的栈S并对其初始化；

    - **栈判空操作**：判断一个栈是否为空；

    - **进栈操作**：将元素压入栈内；

    - **出栈操作**：弹出栈顶元素；

    - **访问栈顶元素**：获取栈顶元素的值。

利用栈的这5种基本操作，可以实现基于栈的问题的求解。

---

#### 栈的混洗（Shuffle）

当一组序列通过入栈，出栈操作后，可能的出入栈序列跟这组元素的排列组合有关。当一组序列按照 $1,2,3,\cdots,n$的编号进栈时，可能的不同出栈序列数可以利用Catalan函数算出：

**$$\frac{1}{n+1}C^n_{2n} = \frac{1}{n+1} \times \frac{(2n)!}{n! \times n!} $$**

---

#### 栈的顺序存储结构

栈的顺序存储也称顺序栈。是指用一组地址连续的存储单元一次存放栈中的元素，并用top指着指向当前栈顶元素，当栈空时，top = -1。顺序栈往往借助数组来实现，可以使用静态或者动态方式来分配内存空间。

下面是顺序栈的编码实现：

**C++语言编程实现**：

```C++
#include <iostream>
using namespace std;

typedef int ElementType;
const int MAX_SIZE = 10;

#pragma region 顺序栈开始
//栈结构
struct Stack
{
private:
    ElementType *data;
    int top;

public:
    void init();                    //初始化栈
    void init(int size);            //初始化栈
    bool empty();                   //判断栈空
    bool full();                    //判断栈满
    bool push(ElementType element); //元素入栈
    bool pop(ElementType &element); //元素出栈
    ElementType getTop();           //获取栈顶元素
};

//初始化栈
void Stack::init()
{
    this->data = new ElementType[MAX_SIZE];
    this->top = -1;
}

//初始化栈
void Stack::init(int size)
{
    this->data = new ElementType[size];
    this->top = -1;
}

//判断栈是否为空
bool Stack::empty()
{
    return this->top == -1;
}

//判断栈是否已满
bool Stack::full()
{
    return this->top == sizeof(this->data);
}

//入栈操作
bool Stack::push(ElementType element)
{
    if (full())
        return false;
    this->top += 1;
    this->data[top] = element;
    return true;
}

//出栈操作
bool Stack::pop(ElementType &element)
{
    if (empty())
        return false;
    element = this->data[this->top];
    this->top -= 1;
    return true;
}

//获取栈顶元素
ElementType Stack::getTop()
{
    if (!empty())
        return this->data[this->top];
}

#pragma endregion 顺序栈结束

//main函数
int main(){
     //测试栈
    cout << "顺序栈测试：" << endl;
    cout << "声明一个顺序栈，将1，2，3，4，5五个元素依次入栈并出栈：" << endl;
    Stack sequenceStack;
    sequenceStack.init(5);
    sequenceStack.push(1);
    sequenceStack.push(2);
    sequenceStack.push(3);
    sequenceStack.push(4);
    sequenceStack.push(5);
    ElementType e;
    while (!sequenceStack.empty())
    {
        sequenceStack.pop(e);
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
```

---

#### 栈的链式存储结构

栈的链式存储也称链栈。通常采用地址不连续的内存单元来存放栈中元素。实现方式与单链表类似，不同在于链式栈的实现一般不要头结点。链表的表头指针即为链栈的栈顶指针。

下面是链栈的编码实现：

**C++语言编程实现**：

```C++
#include <iostream>
using namespace std;

typedef int ElementType;
const int MAX_SIZE = 10;

#pragma region 链栈开始

//链式栈结点结构
struct LinkStackNode
{
    ElementType data;    
    LinkStackNode *link; 
};

//链式栈结构
struct LinkStack
{
private:
    LinkStackNode *top; //栈顶指针

public:
    void init();                    //初始化栈
    bool empty();                   //判断栈是否为空
    bool push(ElementType element); //入栈操作
    bool pop(ElementType &element); //出栈操作
    ElementType getTop();           //获取栈顶元素
};

//初始化栈
void LinkStack::init()
{
    this->top = new LinkStackNode;
    this->top->link = nullptr;
}

//判断栈是否为空
bool LinkStack::empty()
{
    return this->top->link == nullptr || top->link == NULL;
}

//入栈操作
bool LinkStack::push(ElementType element)
{
    LinkStackNode *node = new LinkStackNode;
    node->data = element;
    node->link = this->top->link;
    this->top->link = node;
    return true;
}

//出栈操作
bool LinkStack::pop(ElementType &element)
{
    if (empty())
        return false;
    element = this->top->link->data;
    LinkStackNode *node = this->top->link;
    this->top->link = node->link;
    delete node;
    return true;
}

//获取栈顶元素
ElementType LinkStack::getTop()
{
    if (!empty())
        return this->top->link->data;
}

#pragma endregion 链栈结束

//main函数
int main(){
    cout << "链式栈测试：" << endl;
    cout << "声明一个链式栈，将6，7，8，9，10五个元素依次入栈并出栈：" << endl;
    LinkStack linkStack;
    linkStack.init();
    linkStack.push(6);
    linkStack.push(7);
    linkStack.push(8);
    linkStack.push(9);
    linkStack.push(10);
    while (!linkStack.empty())
    {
        linkStack.pop(e);
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
```

---

#### 疑难解答

1. **理解栈的存储结构的要点。**

>答：
    (1). 顺序栈的操作一般在栈顶指针处进行。在顺序栈的实现中，初始化函数多用于为栈赋初值，令top = -1，置栈空。
    (2). 在实现进栈操作时，首先要判断栈是否已满。若 top = MAX_SIZE - 1，则说明栈满。
    (3). 在进行出栈操作时，首先要判断栈是否为空。即top是否等于-1。如栈空，则不执行出栈操作。
    (4). 链栈的栈顶在链表的表头。一般实现链栈的链表不含头结点。链表的插入删除操作都在表头进行，表头即栈顶。另外也不需要记录链表尾指针。
    (5). 在不能预知栈的大小时，一般采用链式栈作为栈的存储方式更合适。

2. **栈是一种先进后出的顺序存取结构，它是顺序存储结构吗？**

>答：顺序存取跟顺序存储是两个不同的概念。顺序存取是指，只能逐个存取或者访问结构中的元素。而顺序存储是指元素在实际物理空间中的存放是连续的，即物理存储地址是连续的。栈只能在栈顶进行顺序存取，而栈的实现可以是基于数组的顺序存储方式或者基于链表的链式存储方式。

3. **一个较早进栈的元素能否先于在它之后进栈的元素从栈中取出？**

>答：若，该元素被压入栈中，后面的元素也被压入栈中，且在该元素额顶部，则该元素不能先于在它之后进栈的元素从栈中取出。若该元素后面的元素还未入栈，则该元素可以直接从栈顶取出。

4. **一般来讲，只允许栈顶元素从栈中退出，在什么情况下元素可以从栈底泄出？**

>答：操作系统的调度算法设计中，可以允许元素从栈底泄出。

5. **以1，2，3，...，n的顺序进栈，如何判断可能的出栈序列？**

>答：可以使用Catalan函数来求解。

6. **当一个顺序栈已满，如何才能扩充栈长度，使得程序能够继续使用这个栈？**

>答：顺序栈的扩充，只适用于基于动态分配数组存储空间的栈。可以分配一个空间较之前栈空间大一倍的空间来取代原来栈的存储空间。

7. **当两个栈共享同一存储空间V\[m]时，可设栈顶指针数组t\[2]和栈底指针数组b\[2]。如果进栈采用两个栈相向前行的方式，则任一栈的栈满条件是什么？**

>答：当两个栈栈顶指针碰面，即表达式：t\[0] + 1 == t\[1]为真时，表明栈满。

8. **顺序栈的优点是什么？缺点是什么？**

>答：顺序栈的优点是：存取速度快，实现简单。缺点是：顺序栈分配空间过大会造成空间浪费，分配过小，则容易发生栈满溢出。

9. **链式栈可否增加头结点？如果增设了头结点，链式栈的栈顶在链表的什么位置？栈底在链表的什么位置？栈指针如何设置？栈空的条件是什么？栈满的条件是什么？**

>答：链式栈可以增加头结点。若增加了头结点，则栈顶指针位置应该在头结点指针指向的结点。栈尾在链表的表尾。栈顶指针应设置在头结点处。每次进出栈操作都在头结点后进行。栈空的条件是头结点指针域为是否为空。无栈满条件。

10. **链式栈的优点是什么？缺点是什么？**

>答：链式栈的优点是：便于结点的插入和删除，无栈满条件，同一个程序中使用多个栈时，可以共享一个链式栈，不仅提高了效率，还能共享空间。缺点是：需要额外的存储空间来存储链表信息，比如指向下一个结点的指针。

11. **链式栈只能顺序存取，而顺序栈不但能顺序存取，还能直接存取，这种说法对吗？**

>答：不对。栈的特点决定它只能是一种顺序存储结构，无论顺序栈还是链式栈都不能直接存取元素，只能在栈顶对元素进行存取操作。

12. **理论上链式栈没有栈满问题，但在进栈时还有一个后置条件，是什么？**

>答：该后置条件应该为判断动态申请栈结点存储空间是否成功。当栈结点存储空间分配成功时，才能进行入栈操作，否则应该报告分配空间失败的相关信息。

---

#### 栈相关算法

1. 改写顺序栈的进栈成员函数push(x)，要求当栈满时，执行一个stackFull()操作进行溢出处理。其功能是：动态创建一个比原来的栈数组大一倍的新数组，代替原来的栈数组，原来栈数组中的元素占据新数组的前maxSize个位置。

**C++语言编程实现**：

```C++
//改写顺序栈的进栈成员函数push(x)，要求当栈满时，执行一个stackFull()操作进行溢出处理。其功能是：动态创建一个比原来的栈数组大一倍的新数组，代替原来的栈数组，原来栈数组中的元素占据新数组的前maxSize个位置。
void StackFull(Stack &stack)
{
    Stack tmpStack;
    tmpStack.init(stack.MAX_SIZE);
    while (!stack.empty())
    {
        tmpStack.push(stack.pop());
    }
    stack.init(2 * stack.MAX_SIZE);
    while (!tmpStack.empty())
    {
        stack.push(tmpStack.pop());
    }
}
```

2. 设一个栈的输入序列是：1，2，3，...，n。设计一个算法，判断一个序列：$p_1，p_2，\cdots ，p_n$ 是否是一个合理的栈输出序列。

**C++语言编程实现**：

```C++
//设一个栈的输入序列是：1，2，3，...，n。设计一个算法，判断一个序列：$p_1，p_2，\cdots ，p_n$ 是否是一个合理的栈输出序列。
bool IsIllegalStackSequence(ElementType *pushSequence, ElementType *popSequence, int length)
{
    Stack stack;
    stack.init(length);
    int i = 0;
    int j = 0;
    stack.push(pushSequence[i]);
    while (true)
    {
        if (stack.getTop() == popSequence[j])
        {
            stack.pop();
            i++;
        }
        else
        {
            j++;
            stack.push(popSequence[j]);
        }
        if (i >= length || j >= length)
            break;
    }
    return stack.empty();
}
```

---

### 队列

#### 队列的定义和基本运算

1. **队列的定义**：队列（queue）是一种限定存取位置的线性表。

2. **队列的特点**：队列允许只能在表的一端进行插入，而在另一端进行删除。通常插入的一端被称为队尾（rear），删除的一端被称为队头（front）。由于队列一端只能进行插入（也称入队），另一端只能进行删除（也称出队），因此，最早从队尾进入队列的元素，必最先从队头出来。因此，队列也称先进先出（FIFO,First In First Out）的线性表。

3. **队列的基本运算**：队列的基本（运算）操作包含如下5种：

    - **队列初始化操作**：创建一个空的队列Q并初始化；

    - **队列判空操作**：判断队列是否为空队列；

    - **入队操作**：当队列未满时，将元素插入队尾；

    - **出队操作**：当队列为空时，移除队头元素；

    - **访问队头元素操作**：获取队头元素的值。

---

#### 队列的顺序存储结构

队列的顺序存储也称顺序队列。它是利用一组地址连续的存储空间来存放队列元素，通常借用数组来实现。并且设置队头指针front与队尾指针rear分别指向队列的队头跟队尾。

1. **循环队列**：普通顺序存储的队列可由一维数组来实现。当队列为空时，队头指针front与队尾指针rear满足front = rear = -1。每当有元素入队后，rear的值增加1；有元素出队时，front的值增加1。当队满时，不能再进行入队操作，假设此时有n个元素退出了队列，而实际上在实现队列的数组中下标为0~n-1的位置缺空了下来（实际上是不属于队列，出队操作往往修改的是队头指针的指向位置，原本数组中存在的元素不一定被删除覆盖），这种现象也成为假溢出——当队列满时，实际上分配的数组空间还有位置可以存放元素。“假溢出”势必会造成存储空间的浪费。为了解决这个问题，引入了循环队列。

**循环队列**是指：当顺序队列队尾指针指向存储数组的最后一个元素时，再进行入队操作，若该队列有元素出队，造成存储数组前面的位置空了下来，则将入队元素从数组的0号下标位置依次继续插入队列。这样整个队列看起来就像一个环。故称作循环队列。对于循环队列，若队满之后，每次有一个元素出队的同时有一个元素入队，则该循环队列可以进行无限次这样的操作。

2. **循环队列判空跟判断队满**：在普通的顺序队列中，当rear值等于分配数组的长度减一时，表示队列已满，当front=rear时表示队列为空。而对于一个可以存放n个元素的数组，将其作为循环队列的实现结构，则front=rear时，可以认为队列为空，也可以认为该队列已经放入了n个元素。因此，front==rear不能作为循环队列判空的条件。为了区分循环队列是否为空或者是否为满队，常用的方法有三种：

- **牺牲一个存储空间。** 即队列中只存放**n-1**个元素，此时**front == rear**仍可作为队空的判断条件，而判断队满的条件则是：**(rear + 1) % n == front**。

- **增加计数器。** 即在队列结构中增加一个计数器，每**入队**一个元素，该计数器加一，每**出队**一个元素，计数器减一。该计数器也可称为队长，或者队列的容量（大小）。这样，当 **front == rear** 条件为真时，判断计数器的大小，若计数器等于0，则表示队空，若计数器等于分配的数组的长度，则表示队满。

- **标记法。** 所谓标记法，就是在队列结构中增加一个标记tag，并在队列中有元素时保证tag=1，无元素时保证tag=0。这样 **front == rear && tag = 0** 为真时，表示循环队列为空。**front == rear && tag = 1** 为真时表示队列已满。

3. **顺序队列的实现：**

**C++语言编码实现**：

```C++
#include <iostream>
using namespace std;

typedef int ElementType;
const int MAX_SIZE = 10;

//普通顺序队列结构
struct SequenceQueue
{
private:
    ElementType *data;
    int front;
    int rear;
    int MAX_SIZE;

public:
    void init();                    //初始化队列
    void init(int size);            //初始化队列
    bool empty();                   //判断队列是否为空
    bool full();                    //判断队列是否已满
    void push(ElementType element); //入队操作
    ElementType pop();              //出队操作
    ElementType getFront();         //获取队头元素
};

//初始化队列
void SequenceQueue::init()
{
    this->data = new ElementType[MAX_SIZE];
    this->front = -1;
    this->rear = -1;
    this->MAX_SIZE = MAX_SIZE;
}

//初始化队列
void SequenceQueue::init(int size)
{
    this->data = new ElementType(size);
    this->front = -1;
    this->rear = -1;
    this->MAX_SIZE = size;
}

//判断队列是否为空
bool SequenceQueue::empty()
{
    return this->front == this->rear;
}

//判断队列是否已满
bool SequenceQueue::full()
{
    return this->rear == MAX_SIZE - 1;
}

//入队操作
void SequenceQueue::push(ElementType element)
{
    if (!full())
    {
        this->rear += 1;
        this->data[rear] = element;
    }
}

//出队操作
ElementType SequenceQueue::pop()
{
    if (!empty())
    {
        this->front += 1;
        return this->data[front];
    }
}

//获取队头元素
ElementType SequenceQueue::getFront()
{
    if (!empty() && this->front > -1)
        return this->data[front];
}

#pragma endregion 普通顺序队列结束

#pragma region 循环队列开始

//循环队列结构
struct LoopQueue
{
private:
    ElementType *data;
    int front;
    int rear;
    int count;
    int tag;

public:
    int MAX_SIZE;
    void init();                    //初始化队列
    void init(int size);            //初始化队列
    bool empty();                   //根据front与rear关系判断队列是否为空
    bool empty();                   //根据队列元素个数判断队列是否为空
    bool empty();                   //根据自定义标签tag判断队列是否为空
    bool full();                    //根据front与rear关系判断队列是否已满
    bool full();                    //根据队列元素个数判断队列是否已满
    bool full();                    //根据自定义标签tag判断队列是否已满
    int length();                   //获取队列长度
    void push(ElementType element); //入队操作
    ElementType pop();              //出队操作
    ElementType getFront();         //获取队头元素
};

//初始化队列
void LoopQueue::init()
{
    this->data = new ElementType[MAX_SIZE];
    this->front = 0;
    this->rear = 0;
    this->MAX_SIZE = MAX_SIZE;
    this->count = 0;
    this->tag = 0;
}

//初始化队列
void LoopQueue::init(int size)
{
    this->data = new ElementType[size];
    this->front = 0;
    this->rear = 0;
    this->MAX_SIZE = size;
    this->count = 0;
    this->tag = 0;
}

//根据front与rear的关系判断队列是否为空
bool LoopQueue::empty()
{
    return this->front == this->rear;
}

//根据队列元素个数判断队列是否为空
bool LoopQueue::empty()
{
    return this->count == 0 && this->front == this->rear;
}

//根据自定义标签tag判断队列是否为空
bool LoopQueue::empty()
{
    return this->tag == 0 && this->front == this->rear;
}

//根据front与rear的关系判断队列是否已满
bool LoopQueue::full()
{
    return this->rear + 1 == this->front;
}

//根据队列元素个数判断队列是否已满
bool LoopQueue::full()
{
    return this->count == this->MAX_SIZE && this->front == this->rear;
}

//根据自定义标签tag判断队列是否已满
bool LoopQueue::full()
{
    return this->tag = 1 && this->front == this->rear;
}

//入队操作
void LoopQueue::push(ElementType element)
{
    if (!full())
    {
        this->data[(this->rear + 1) % this->MAX_SIZE];
        this->rear += 1;
        this->count += 1;
        this->tag = 1;
    }
}

//出队操作
ElementType LoopQueue::pop()
{
    if (!empty())
    {
        this->front = (this->front + 1) % this->MAX_SIZE;
        this->count -= 1;
        this->tag = 0;
        return this->data[this->front];
    }
}

//获取队列长度
int LoopQueue::length()
{
    return this->count;
}

//获取队头元素
ElementType LoopQueue::getFront()
{
    if (!empty())
    {
        return this->data[(this->front + 1) % this->MAX_SIZE];
    }
}

//main函数
int main(){
    return 0;
}
```

---

#### 队列的链式存储结构

队列的链式存储也成为链式队列。是采用链表来作为队列元素存储的实现方式。队列的链式存储一般借助单链表或者单循环链表来实现。

1. **采用单链表实现队列**：基于单链表实现队列，链表结点结构即为单链表的链表结构。与单链表的不同是，需要指定队头指针front与队尾指针rear。一般带头结点的单链表，头结点位置即为队头指针位置，队尾指针指向尾结点。不带头结点的单链表，单链表表头指针位置即为队头指针。队尾指针仍在链表尾。

2. **采用单循环链表实现队列**：基于单循环链表的链式队列实现，结构上与单循环链表类似。基于单循环链表的链式队列只需要指定队尾指针rear。由于链表表尾通过指针又指向链表表头，因此，当进行入队操作时，在rear后面增加结点。而出队操作，实际上也是删除rear后面的结点。这种方式实现的链式队列，入队跟出队操作时间复杂度都是O(1)。

3. **链式队列的实现**：

**C++语言编码实现**：

```C++
#include <iostream>
using namespace std;

typedef int ElementType;
const int MAX_SIZE = 10;

#pragma region 基于单链表的链式队列开始

//链式队列结点结构
struct LinkQueueNode
{
    ElementType data;
    LinkQueueNode *link;
};

//链式队列结构
struct LinkQueue
{
private:
    LinkQueueNode *front; //队头指针
    LinkQueueNode *rear;  //队尾指针
    int count;            //队列元素个数

public:
    void init();                    //初始化队列
    bool empty();                   //判断队列是否为空
    void push(ElementType element); //入栈操作
    ElementType pop();              //出栈操作
    ElementType getFront();         //获取队头元素
};

//初始化队列
void LinkQueue::init()
{
    this->front = new LinkQueueNode;
    this->rear = NULL;
    this->front->link = this->rear;
    this->count = 0;
}

//判断队列是否为空
bool LinkQueue::empty()
{
    return this->front->link == nullptr || this->front->link == NULL;
}

//入队操作
void LinkQueue::push(ElementType element)
{
    LinkQueueNode *node = new LinkQueueNode;
    node->data = element;
    node->link = nullptr;
    if (empty())
    {
        this->front->link = node;
        this->rear = node;
    }
    else
    {
        this->rear->link = node;
        this->rear = node;
    }
}

//出队操作
ElementType LinkQueue::pop()
{
    if (!empty())
    {
        LinkQueueNode *ptr = this->front->link;
        this->front->link = ptr->link;
        ElementType element = ptr->data;
        delete ptr;
        return element;
    }
}

//获取队头元素
ElementType LinkQueue::getFront()
{
    if (!empty)
        return this->front->link->data;
}

#pragma endregion 基于单链表的链式队列结束

#pragma region 基于单循环链表的队列开始

//基于单循环链表的队列结点结构
struct SingleLoopLinkQueueNode
{
    ElementType data;
    SingleLoopLinkQueueNode *link;
};

//基于单循环链表的队列结构
struct SingleLoopLinkQueue
{
private:
    SingleLoopLinkQueueNode *rear; //队尾指针
    int count;                     //队列元素个数

public:
    void init();                    //初始化队列
    bool empty();                   //判断队列是否为空
    void push(ElementType element); //入栈操作
    ElementType pop();              //出栈操作
    ElementType getFront();         //获取队头元素
};

//初始化队列
void SingleLoopLinkQueue::init()
{
    this->rear = new SingleLoopLinkQueueNode;
    count = 0;
}

//判断队列是否为空
bool SingleLoopLinkQueue::empty()
{
    return this->rear->link == nullptr || this->rear->link == NULL;
}

//入队操作
void SingleLoopLinkQueue::push(ElementType element)
{
    if (this->count == 0)
    {
        this->rear->data = element;
        this->rear->link = this->rear;
        count += 1;
    }
    else
    {
        SingleLoopLinkQueueNode *node = new SingleLoopLinkQueueNode;
        node->data = element;
        node->link = this->rear->link;
        this->rear->link = node;
    }
}

//出队操作
ElementType SingleLoopLinkQueue::pop()
{
    if (!empty())
    {
        SingleLoopLinkQueueNode *ptr = this->rear->link;
        ElementType element = ptr->data;
        this->rear->link = ptr->link;
        delete ptr;
        return element;
    }
}

//获取队头元素
ElementType SingleLoopLinkQueue::getFront()
{
    if (!empty())
        return this->rear->link->data;
}

#pragma endregion 基于单循环链表的队列结束

#pragma endregion 链式队列结束

//main函数
int main(){
    return 0;
}
```

---

#### 疑难解答

1. **理解队列的要点**

>答：
    (1). 出队操作会删除队头的元素，而访问队头操作只是获取队头元素的值，实际元素还在队列当中；
    (2). 当一组元素按一定顺序一次进入队列，出队序列仍与原序列一致。即无论其入队和出队操作如何组合，最后输出的元素次序与入队时相同；
    (3). 当一组元素以1,2,3,...,n编号进入队列后，可能的出队序列只有一种，仍是：1,2,3,...,n；
    (4). 初始化时，令front = rear = 0，则置空队列；
    (5). 每次入队，先将元素插入，再移动队尾指针，出队也一样，先保存队头元素，再移动队头指针；
    (6). 每次从队头退出一个元素时，需要先判断队列是否为空，入队时，如果是顺序队列，则需要判断队列是否已满；

2. **队列具有先进先出的特性，可不可以加塞，在队列其他位置进出队列？**

>答：不能。队列是限制了存取位置的线性结构。若允许在其他任意位置进出队列，便不能再称之为队列，而是成为普通的线性表了。

3. **以1，2，3，...，n进队，可能的出队序列有多少种？**

>答：可能的出队序列只有一种，与入队时一致，仍是：1，2，3，...，n。

4. **栈，队列和向量（一维数组）有什么不同？**

>答：最大的区别在于，向量可以直接（随机）存取，而栈跟队列只能在指定位置顺序存取。其中栈约定只能在栈顶进行元素的存取，而队列只能在队头出队，队尾入队。

5. **在循环队列中进行插入和删除时，是否需要移动队列元素的位置？**

>答：在循环队列中进行插入和删除时，不需要比较和移动队列任何元素，只需要修改队头指针front和队尾指针rear，并向队尾插入元素或从队头取出元素。

6. **可否在链式队列中增加头结点？此时链式队列的队头和队尾在链表的什么地方？对空的条件是什么？**

>答：可以在链式队列中增加头结点，此时队头在链表的头结点处，队尾在链表的队尾处。队空的条件是队列链表头结点指针域为空。

7. **同时使用多个队列时需采用何种队列结构？如何组织？**

>答：同时使用多个队列时应采用链式队列结构。入队，出队，判空等操作与一般队列相同。

8. **链式队列的每个结点是否还可以是队列？**

>答： 可以。队列是一种限定了元素存取位置的线性表，按照一般线性表的定义，每个线性表元素应为不再分的数据元素。但处于实际应用额需要，链式队列的每个结点仍可以是一个队列。

---

#### 队列相关算法

1. 改进采用用一维数组存储元素的循环队列的入队函数。当队列满并需要插入新元素时将数组空间扩大一倍，使得新元素得以插入。

**C++语言编码实现**：

```C++
//改进采用用一维数组存储元素的循环队列的入队函数。当队列满并需要插入新元素时将数组空间扩大一倍，使得新元素得以插入。
void QueueExpansion(LoopQueue &loopQueue)
{
    LoopQueue tmpQueue;
    tmpQueue.init(loopQueue.MAX_SIZE);
    while (!loopQueue.empty())
    {
        tmpQueue.push(loopQueue.pop());
    }
    loopQueue.init(2 * loopQueue.MAX_SIZE);
    while (!tmpQueue.empty())
    {
        loopQueue.push(tmpQueue.pop());
    }
}
```

2. 改进采用用一维数组存储元素的循环队列的出队函数。当队列元素少于数组空间的1/4时将数组空间自动缩小一半。

**C++语言编码实现**：

```C++
//改进采用用一维数组存储元素的循环队列的出队函数。当队列元素少于数组空间的1/4时将数组空间自动缩小一半。
void ShrinkQueue(LoopQueue &loopQueue)
{
    if (loopQueue.length() < loopQueue.MAX_SIZE / 4)
    {
        LoopQueue tmpQueue;
        tmpQueue.init(loopQueue.MAX_SIZE / 2);
        while (!loopQueue.empty())
        {
            tmpQueue.push(loopQueue.pop());
        }
        loopQueue.init(loopQueue.MAX_SIZE / 2);
        while (!tmpQueue.empty())
        {
            loopQueue.push(tmpQueue.pop());
        }
    }
}
```

---

### 栈的应用

#### 栈在表达式求值中的应用

1. **中缀表达式**：中缀表达式，是我们日常日生活中最常用的表达式。即运算符位于两个运算数之间（双目运算符）。

2. **后缀表达式**：后缀表达式是指根据运算顺序，一般运算符在参与运算数的后面。

在计算机中，计算后缀表达式要比计算中缀表达式容易的多。一个中缀表达式，在计算机中往往先转化为后缀表达式，再进行求值。

- **后缀表达式计算方法**：在后缀表达式中，运算符在运算数的后面。因此，对于双目运算符，需要找到运算符临近的前两个数，而单目运算符需要找到临近的前一个数。同时在计算完之后要保存结果，方便下一个运算符临近的数参与运算。根据后缀表达式计算的特点，往往采用栈结构来计算后缀表达式。一般方法是：顺序扫描表达式，若遇到运算数，则压入栈中，若遇到运算符，则从栈中弹出两个运算数（如果是单目运算符，则弹出一个）做对应运算符的运算，并将结果重新压入栈中。当表达式扫描处理完成之后，堆栈中存放的元素即为后缀表达式计算的结果。

- **中缀表达式转后缀表达式方法**：中缀表达式转后缀表达式同样也借助栈结构来完成。一般方法是：遇到运算数，则直接输出。遇到操作符，则与栈顶操作符比较，若栈空或者栈顶操作符优先级小于当前运算符优先级，则输出该操作符。否则，需要再判断下一个运算符的优先级，若下一个运算符的优先级比栈顶运算符优先级高，则直接输出该优先级，否则输出栈顶运算符，并将该运算符压入栈中。当遇到左括号时，左括号入栈，优先级降到最低，当遇到右括号时，栈中左括号前的内容全部输出。依次类推，最后输出的序列就是中缀表达式转为后缀表达式的结果。

**C++语言编程实现**：

```C++
```

#### 栈在递归中的应用

一个递归程序在其内部常常多次调用自己。程序内部递归调用的位置以及结束时返回结果的位置也不同。每次调用时，需要保存局部变量，传入的参数以及调用结束后返回的结果。由于程序执行的顺序性，这些结果的保存往往需要用到栈结构。在许多高级语言中，都使用栈来处理函数调用问题，这种栈也被称为 **“递归工作栈”**。

#### 疑难解答

1. **在后缀表达式求值过程中用栈存放什么？在中缀表达式求值过程中又用栈存放什么？**

>答：在后缀表达式求值过程中用栈存放运算数（操作数）和运算的中间结果。在中缀表达式求值过程中需要两个栈，一个用来存放运算数（操作数）和运算的中间结果，另一个根据运算符（操作符）的优先级从地到高存放运算符（操作符）。

2. **为判断表达式式中的括号是否配对，可采用何种结构辅助进行判断？**

>答：可以借助栈结构，扫描一遍表达式，遇到左括号则压入栈中，若遇到右括号，则判断栈顶的左括号是否配对，如果配对则弹出栈顶左括号，否则返回不匹配信息。依次类推，最后再判断栈是否为空，空则表示表达式括号匹配，否则不匹配。

3. **在递归算法中采用何种结构来存放递归过程每层的局部变量，返回地址和实参副本？**

>答：在递归算法中采用栈来存放递归过程中每层的局部变量，返回地址和实参副本。外部递归调用（第一次调用）和内部调用（自身调用）返回上层的地址不用，传值参数和引用参数的暂存内容不同。

4. **递归深度与递归工作栈有何关系？**

>答：一般地，递归深度等于递归工作栈占用内存的工作单元数。

5. **递归调用与问题规模n有何关系？**

>答：递归调用与问题规模n的关系需要根据实际问题具体分析。

6. **如果在调用过程中传递的参数体积比较大，需要在过程中为参数分配副本空间，并把实参的信息传到这个副本空间中。这将消耗较多的时间和空间，如何避免或减少这种消耗？**

>答：可以将参数定义为引用型，同时尽可能减少函数的调用次数。

#### 栈的应用相关算法

- . 表达式求值系列问题。

**C++语言编程实现**

```C++
```

### 队列的应用

#### 逐层处理

由于队列“先来先服务”的特点，队列可用来保存某程序或操作的处理顺序。因此，对于逐行打印二项式展开式 $(ax+b)^i$的系数，就可以借助队列来实现。

#### “先来先服务”调度策略

在操作系统的调度算法中，由于队列的“先进先出”特点，进而衍生出了“先来先服务”的调度策略。在操作系统中作业调度，进程调度中都用到了队列。不仅如此，比如银行客户排队，医院患者排队，计算机输入/输入缓冲区的处理等应用场合也都用到了队列。

#### 数和二叉树搜索策略

树或二叉树是层次结构，逐层搜索是寻找目标结点的一种重要策略。对于寻找数，二叉树和森林中指定层或指定深度的结点以及寻找数，二叉树和森林中指定结点的深度，层级或距离都要用到队列。

#### 图或网格中广度优先搜索策略

图或网格的搜索主要包括深度优先搜索和广度优先搜索。广度优先搜索是靠队列来实现的。另外计算无权图的单源或多源最短路径或计算任意两点的最短路径长度以及计算连通子图等也需要借助队列。

#### 疑难解答

1. **队列应用最大的问题是不能事先直到为解决问题到底需要多大的队列，这种问题该如何处理？**

>答：可以选择可以扩充的队列。比如动态分配存储空间的队列，循环队列，链式队列等。优先考虑链式队列。

2. **为了做到在应用中逐层处理，在队列中如何识别一层的结束？**

>答：可以在定义完队列的front，rear指针后再增加两个辅助标记量，比如last和level。last记录一层元素中最后一个元素再队列中的位置，level记录层号。当前一行元素都出队，下一行元素都进队后，队尾元素一定是下一行的最后一个元素，使用last记录该位置，用level记录层号。当不断出队，导致队头指针front指向last位置时，就可以断定一行结束，让last指向下一行末尾，level值加一。

3. **为了实现输入-处理-输出并行需要建立多个输入缓存区队列，这些队列是按照数组组织函数链表组织的？**

>答：输入输入缓冲区是按照链表来组织的。采用链式队列可以及时释放取空的缓冲区，及时补充需要分配的缓冲区。

#### 队列应用相关算法

1. 试利用循环队列编写求k阶斐波那契序列中前n+1项 $(f_0,f_1,\cdots,f_{n-1},f_n)$ 的算法，要求满足：$f_n \leq max$ 而 $f_{n+1} \geq max$ ，其中max为某个约定的常数。另外要求循环队列长度为k，并且在算法执行结束后，循环队列中的元素应是该斐波那契序列的最后k项 $f_{n-k+1},\cdots,f_n$。

**C++语言编程实现**

```C++
/*试利用循环队列编写求k阶斐波那契序列中前n+1项 
    $(f_0,f_1,\cdots,f_{n-1},f_n)$ 的算法，要求满足：
    $f_n \leq max$ 而 $f_{n+1} \geq max$ ，其中max为
    某个约定的常数。另外要求循环队列长度为k，并且在算法执
    行结束后，循环队列中的元素应是该斐波那契序列的最后k项
     $f_{n-k+1},\cdots,f_n$。*/

long FibonacciSequence(long queue[], int k, int &rear, int &n, long maxValue)
{
    long sum = 0;
    for (int i = 0; i < k - 1; i++)
    {
        queue[i] = 0;
    }
    queue[k - 1] = 1;
    rear = n = k - 1;
    sum = 1;
    while (true)
    {
        for (int i = 1; i < k; i++)
        {
            sum += queue[(rear - i + k) % k];
        }
        if (sum > maxValue)
            break;
        n++;
        rear = (rear + 1) % k;
        queue[rear] = sum;
    }
    return queue[rear];
}
```

### 双端队列

#### 双端队列的概念

双端队列是一种特殊的队列。双端队列又可分3类：**允许在两端插入和删除的双端队列**，**允许在两端插入，但只允许在一端删除的双端队列** 以及 **允许在一端插入，但允许在两端删除的双端队列** 。

一般的双端队列可以看成是两个队列相互叠加：A队列的队头与B队列的队尾叠在一起，A队列的队尾与B队列的队头叠在一起。由此形成的队列，一端既是队头也是队尾，另一端既是队尾也是队头，故可以在两端插入和删除。

允许在两端插入，只允许在一端删除的队列也被称为：**输出受限的双端队列**。

允许在两端删除，只允许在一端插入的队列也被称为：**输入受限的双端队列**。

#### 输入受限的双端队列

1. 若只限定在双端队列的一端输入，可以在两端输出，则对于一个输入序列，输出有三种可能：在同一端输出，相当于栈；在另一端输出，相当于队列，或者混合输出。

2. 假设双端队列的两端分别为end1和end2，并限定输入端是end1。输入序列是1234,则可能的进出队列情况如下：

    - 若输入元素都从end1端进，再从end1端出，则相当于栈。有 $\frac{1}{(4+1)}C_8^4 = 14种合理的栈序列。则不可能的出栈序列有 4! - 14 = 24 - 14 = 10$ 种。

    - 若输入元素从end1端进，从end2端出，则相当于队列，可能的输出序列只有一种1234。

    - 若输入元素都从end1端进，但可以从end1端或end2端出，则是混合出队情形，它的合理输出序列不仅包含作为栈的部分，还包含作为队列的部分甚至还有两者的混合。

#### 输出受限的双端队列

1. 若限定只能在双端队列的一端输出，但可以在两端输入，则对于一个确定的输入序列，输入也只能有三种可能：在同一端输入和输出，相当于栈；在一段输入和另一端输出，即为队；或者混合输入输出。

2. 假设双端队列的两端分别为end1和end2，并限定输出端是end2。输入的序列是1234,则所有不同的排列序列有4! = 24种。

    - 当限定在end2端输入，在end2端输出，则相当于栈。有14种合理的输出序列，它们可以从同一端输入输出得到。

#### 疑难解答

1. **在双端队列的顺序存储中如何进队？**

>答：在双端队列的顺序存储中。设它的两端分别为end1和end2。它的队空条件是end1 = end2，队列初始化操作时让end1 = end2 = 0。与一般队列不同的是，它的两个指针不是同一方向变动，而是朝相反方向变动，因此，在每次插入时，end2顺时针加一，end1逆时针减一；删除时正好相反。
>插入和删除操作的实现与一般队列相同，插入新元素到end2端时，先把end2加一，再把新元素插入end2指向的新位置。
>但插入新元素到end1端时，不能采取同样策略，否则会把end2指示的位置的元素冲掉，需要改一下，让end1先减一，再按此位置插入元素。所有操作的时间复杂度和空间复杂度均为O(1)。

2. **在双端队列的链式存储表示中如何进队和出队？**

>答：双端队列的链式存储表示与链式队列相同，可借用链式队列的结构定义。在链尾插入新元素时可以直接使用链式队列的插入算法：创建一个新的结点，将元素放入该结点，再将该结点链接到链表尾结点之后，并修改尾结点指向。在头部插入时，新建结点插入链表的头部即可。在删除时也可使用链式队列的删除算法。以上操作的时间复杂度均为O(1)。在链表尾删除时，必须从头扫描一次链表，找到尾结点的前驱结点，才能实现删除，时间复杂度尾O(n)。
