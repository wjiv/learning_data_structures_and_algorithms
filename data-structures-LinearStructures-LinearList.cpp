
// 头文件及名称空间

#include <iostream>
using namespace std;

// 公共变量
const int INIT_SIZE = 100;
typedef int ElementType;

// 顺序表
/*顺序表：
    线性表的顺序存储又称顺序表；
    顺序表的特点是：逻辑上相邻元素其物理存储也相邻，即顺序表表中元素的逻辑顺序与其物理顺序相同。
                   顺序表的主要特点是随机访问（访问也称读写），对于查找和更新元素，只要给出索引，即可在O(1)的时间复杂度内找到指定元素位置。
                   顺序表插入跟删除操作需要移动大量元素，因此其时间复杂度为：O(n)。
    下面是以顺序表的 C++ 实现 
*/

// 顺序表结构
struct SequenceList
{
    ElementType *data;
    int size = 0;                                //表长
    int count = 0;                               //当前元素个数
    void initList();                             //初始化顺序表
    void initList(int length);                   //初始化顺序表
    bool isEmpty();                              //判断顺序表是否为空
    bool insert(ElementType element, int index); //插入元素
    bool deleteElement(int index);               //删除指定位置元素
    ElementType find(int index);                 //根据位置查找元素
    //int find(ElementType element);               //查找元素所在位置
    void update(ElementType e);              //跟新顺序表中元素
    bool replace(int inddex, ElementType e); //替换指定位置元素
    void print();
};

// 初始化顺序表
void SequenceList::initList()
{
    data = new ElementType(INIT_SIZE);
    size = INIT_SIZE;
}

// 初始化顺序表
void SequenceList::initList(int length)
{
    data = new ElementType(length);
    size = length;
}

//判断顺序表是否为空
bool SequenceList::isEmpty()
{
    return count == 0;
}

// 插入元素
bool SequenceList::insert(ElementType element, int index)
{
    if (index < 1 || index > count + 1)
        return false;
    if (count >= size)
        return false;
    for (int i = count; i >= index - 1; i--)
    {
        data[i] = data[i - 1];
    }
    data[index - 1] = element;
    count++;
    return true;
}

// 删除元素
bool SequenceList::deleteElement(int index)
{
    if (index > count || index < 1)
        return false;
    for (int i = index; i < count; i++)
    {
        data[i - 1] = data[i];
    }
    return true;
}

//查询指定位置元素
ElementType SequenceList::find(int index)
{
    if (index >= 1 && index <= count)
        return data[index - 1];
    else
        return -1;
}

//遍历顺序表
void SequenceList::print()
{
    for (int i = 0; i < count; i++)
    {
        if (i <= count - 1 && i != 0)
            cout << " ";
        cout << data[i];
    }
    cout << endl;
}

//测试函数
void test()
{
    SequenceList list;
    list.initList(200);
    for (int i = 0; i < 100; i++)
    {
        list.insert(i + 1, i + 1);
    }

    cout << list.insert(2, 101) << endl;

    list.print();
}

/*单链表：
    线性表的链式存储又称单链表；
    头指针：头指针用来表示一个单链表，头指针为NULL时表示链表为空。
    头结点：为了方便操作，在单链表的第一个结点之前附加一个结点，称之为头结点，头结点只包含指针域。
    单链表的特点是：对于链表，逻辑上相邻的元素其物理存储不要求相邻，即链表中的元素是离散分布在存储单元中的。因此链表是非随机存取的存储结构。
                在链表中，每个结点的指针都指向其逻辑顺序的后一个元素的地址。                    
    下面是以单链表的 C++ 实现 
*/

// 单链表结点定义
struct ListNode
{
    ElementType data;
    ListNode *next;
};

//单链表定义
struct LinkList
{
    ListNode *head;                          //头结点
    ListNode *tail;                          //尾结点
    int length;                              //表长
    void initLinkList();                     //初始化单链表
    void insertFront(ElementType element);   //头部插入元素
    void insertBack(ElementType element);    //尾部插入元素
    void removeElement(ElementType element); //删除元素
    void deleteElement(int index);           //删除元素
    void find();                             //查找元素
    void update();                           //更新元素
    void getLength();                        //求表长
    void print();                            //遍历单链表
};

//初始化单链表
void LinkList::initLinkList()
{
    head = new ListNode;
    head->next = nullptr;
    tail == NULL;
    length = 0;
}

//头部插入元素
void LinkList::insertFront(ElementType element)
{
    ListNode *list_node = new ListNode;
    list_node->data = element;
    list_node->next = head->next;
    head->next = list_node;
    if (length == 0)
        tail = list_node;
    length++;
}

//尾部插入元素
void LinkList::insertBack(ElementType element)
{
    ListNode *list_node = new ListNode;
    list_node->data = element;
    list_node->next = nullptr;
    if (tail != NULL)
    {
        tail->next = list_node;
        tail = list_node;
    }
    else
    {
        head->next = list_node;
        tail = list_node;
    }
}

//删除元素
void LinkList::deleteElement(ElementType element)
{
    ListNode *list_node = head->next;
    while (list_node->next)
    {
        if (list_node->next->data == element)
        {
            ListNode *tempNode = list_node->next;
            list_node->next = tempNode->next;
            delete (tempNode);
        }
    }
}

//遍历单链表
void LinkList::print()
{
    ListNode *ptr = head;
    while (ptr->next != nullptr)
    {
        cout << ptr->next->data << endl;
        ptr = ptr->next;
    }
    delete ptr;
}

//单链表测试函数
void testLinkList()
{
}

//列表合并
SequenceList mergeList(SequenceList listA, SequenceList listB)
{
    SequenceList result;
    result.initList();
    if (listA.count < listB.count)
    {
        SequenceList tempList = listA;
        listA = listB;
        listB = tempList;
    }
    for (int i = 0; i < listA.count + listB.count; i++)
    {
        if (i <= listA.count - 1)
        {
            result.data[i] = listA.data[i];
            result.count++;
        }
        else
        {
            result.data[i] = listB.data[i - listA.count];
            result.count++;
        }
    }

    return result;
}

//有序列表归并
bool mergeList(SequenceList listA, SequenceList listB, SequenceList result)
{

}

//main函数
int main()
{
    SequenceList listA;
    SequenceList listB;
    listA.initList(20);
    listB.initList(20);
    for (int i = 0; i < 10; i++)
    {
        listA.insert(i, i+1);
    }
    for (int i = 0; i < 15; i++)
    {
        listB.insert(i * i, i+1);
    }
    listA.print();
    listB.print();
    SequenceList result = mergeList(listA, listB);

    result.print();

    return 0;
}
