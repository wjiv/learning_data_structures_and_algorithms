//线性结构——栈与队列完整代码

#include <iostream>
using namespace std;

typedef int ElementType;
const int MAX_SIZE = 10;

#pragma region 栈部分开始

#pragma region 顺序栈开始
//栈结构
struct Stack
{
private:
    ElementType *data;
    int top;

public:
    int MAX_SIZE;                   //栈最大存储空间
    void init();                    //初始化栈
    void init(int size);            //初始化栈
    bool empty();                   //判断栈空
    bool full();                    //判断栈满
    bool push(ElementType element); //元素入栈
    ElementType pop();              //元素出栈
    ElementType getTop();           //获取栈顶元素
};

//初始化栈
void Stack::init()
{
    this->data = new ElementType[MAX_SIZE];
    this->top = -1;
    this->MAX_SIZE = MAX_SIZE;
}

//初始化栈
void Stack::init(int size)
{
    this->data = new ElementType[size];
    this->MAX_SIZE = size;
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
ElementType Stack::pop()
{
    if (empty())
        return false;
    ElementType element = this->data[this->top];
    this->top -= 1;
    return element;
}

//获取栈顶元素
ElementType Stack::getTop()
{
    if (!empty())
        return this->data[this->top];
}

#pragma endregion 顺序栈结束

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
    ElementType pop();              //出栈操作
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
ElementType LinkStack::pop()
{
    ElementType element;
    if (!empty())
    {
        element = this->top->link->data;
        LinkStackNode *node = this->top->link;
        this->top->link = node->link;
        delete node;
    }
    return element;
}

//获取栈顶元素
ElementType LinkStack::getTop()
{
    if (!empty())
        return this->top->link->data;
}

#pragma endregion 链栈结束

//栈测试函数
void testStack()
{
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
    while (!sequenceStack.empty())
    {
        cout << sequenceStack.pop() << " ";
    }
    cout << endl;
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
        cout << linkStack.pop() << " ";
    }
    cout << endl;
}

#pragma endregion 栈部分结束

#pragma region 队列部分开始

#pragma region 顺序队列开始

#pragma region 普通顺序队列开始

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

#pragma endregion 循环队列结束

#pragma endregion 顺序队列结束

#pragma region 链式队列开始

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

//队列测试函数
void testQueue()
{
}

#pragma endregion 队列部分结束

#pragma region 栈与队列相关算法开始

#pragma region 栈相关算法开始

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

#pragma endregion 栈相关算法结束

#pragma region 队列相关算法开始

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

#pragma endregion 队列相关算法结束

#pragma region 栈的应用相关算法开始

#pragma region 栈的应用相关算法结束

#pragma region 队列的应用相关算法开始

#pragma endregion 队列的应用相关算法结束

#pragma region 双端队列相关算法开始

#pragma endregion 双端队列相关算法结束

#pragma endregion 栈与队列相关算法结束

#pragma region 栈与队列相关算法测试函数开始

#pragma endregion 栈与队列相关算法测试函数结束

#pragma region main函数部分开始

//main函数
int main()
{
    testStack(); //栈测试函数
    return 0;
}

#pragma endregion main函数部分结束