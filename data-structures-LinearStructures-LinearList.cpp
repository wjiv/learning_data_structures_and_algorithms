
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

//原地逆置线性表
void ReverseList(SequenceList &sequenceList)
{
    if (sequenceList.count == 0)
        return;
    ElementType tmp;
    for (int i = 0; i < sequenceList.count / 2; i++)
    {
        tmp = sequenceList.data[i];
        sequenceList.data[i] = sequenceList.data[sequenceList.count - 1 - i];
        sequenceList.data[sequenceList.count - 1 - i] = tmp;
    }
}

//从线性表中删除具有最小值的元素，返回被删元素的值及删除结果
int DeleteElementWithMinValue(SequenceList &sequenceList, ElementType &deleteData)
{
    if (sequenceList.count == 0)
        return 0; //0表示删除失败
    int minValuePosition = 0;
    for (int i = 0; i < sequenceList.count; i++)
    {
        if (sequenceList.data[i] <= sequenceList.data[minValuePosition])
            minValuePosition = i;
    }
    deleteData = sequenceList.data[minValuePosition];
    sequenceList.data[minValuePosition] = sequenceList.data[sequenceList.count - 1];
    return 1; //1表示删除成功
}

//从顺序表第position个位置删除元素，返回删除元素的值以及位置不合理等错误信息
int DeleteEmementByPosition(SequenceList &sequenceList, int position, ElementType &deleteData)
{
    if (sequenceList.count == 0)
        return 0; //0表示表为空
    if (position < 1 || position > sequenceList.count)
        return -1; //-1表示删除位置不合理
    deleteData = sequenceList.data[position - 1];
    for (int i = position - 1; i < sequenceList.count; i++)
    {
        sequenceList.data[i] = sequenceList.data[i + 1];
    }
    sequenceList.count -= 1;
    return 1; //1表示删除成功
}

//在线性表的第position位置插入一个元素，返回插入结果跟错误标志
int InsertElementByPosition(SequenceList &sequenceList, int position, ElementType element)
{
    if (sequenceList.count == 0)
        return 0; //线性表为空，返回0表示插入失败
    if (sequenceList.count == sequenceList.size)
        return 0; //线性表已满，返回0表示插入失败
    if (position < 1 || position > sequenceList.count)
        return -1; //-1表示插入位置不合理
    for (int i = sequenceList.count; i >= position; i--)
    {
        sequenceList.data[i] = sequenceList.data[i - 1];
    }
    sequenceList.data[position - 1] = element;
    sequenceList.count += 1;
    return 1; //插入成功，返回1
}

//从循序表中删除与给定值相同的所有元素
void DeleteAllEmementsSameGiveElement(SequenceList &sequenceList,ElementType element){
    for (int i = 0; i < sequenceList.count; i++)
    {
        if(sequenceList.data[i]==element)
            
    }
    
}

//main函数
int main()
{
    SequenceList list;
    list.initList(20);
    for (int i = 0; i < 10; i++)
    {
        list.insert(i * i, i + 1);
    }
    list.print();
    //逆置线性表
    ReverseList(list);
    //删除线性表最小元素
    ElementType deleteData;
    int flag = DeleteElementWithMinValue(list, deleteData);
    cout << "删除标志（1：成功；0：失败）：" << flag << "  ; 删除的值为：" << deleteData << endl;
    list.print();
    flag = DeleteEmementByPosition(list, 5, deleteData);
    cout << "删除标志（1：成功；0：表空；-1：删除位置不合理）：" << flag << "  ; 删除的值为：" << deleteData << endl;
    list.print();
    flag = InsertElementByPosition(list, 5, 25);
    cout << "插入标志（1：成功；0：表空或表满；-1：插入失败）：" << flag << endl;
    list.print();
    return 0;
}
