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
    ElementType e;
    while (!sequenceStack.empty())
    {
        sequenceStack.pop(e);
        cout << e << " ";
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
        linkStack.pop(e);
        cout << e << " ";
    }
    cout << endl;
}

#pragma endregion 栈部分结束

#pragma region 队列部分开始

#pragma region 顺序队列开始

#pragma endregion 顺序队列结束

#pragma region 链式队列开始

#pragma endregion 链式队列结束

#pragma endregion 队列部分结束

#pragma region main函数部分开始

//main函数
int main()
{
    testStack(); //栈测试函数
    return 0;
}

#pragma endregion main函数部分结束