//线性表部分实现完整代码

// 头文件及名称空间

#include <iostream>
using namespace std;

// 公共变量
const int INIT_SIZE = 100; //最大空间
typedef int ElementType;   //类型重定义

#pragma region 顺序表部分开始

// 顺序表结构
struct SequenceList
{
    ElementType *data;
    int size = 0;                                //顺序表空间大小
    int count = 0;                               //表长（顺序表元素个数）
    void initList();                             //初始化顺序表
    void initList(int length);                   //初始化顺序表
    bool isEmpty();                              //判断顺序表是否为空
    bool insert(ElementType element, int index); //插入元素
    bool deleteElement(int index);               //删除指定位置元素
    bool find(int index, ElementType &element);  //根据位置查找元素
    int locate(ElementType element);             //查找元素所在位置（按值查找）
    bool replace(int inddex, ElementType e);     //替换指定位置元素
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
    if (count == size)
        return false;
    for (int i = count; i >= index; i--)
    {
        data[i] = data[i - 1];
    }
    data[index - 1] = element;
    count += 1;
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
    count -= 1;
    return true;
}

//查询指定位置元素
bool SequenceList::find(int index, ElementType &element)
{
    if (index >= 1 && index <= count)
    {
        element = data[index - 1];
        return true;
    }
    else
    {
        element = NULL;
        return false;
    }
}

//查询指定元素的位置（按值查找元素）：返回顺序表中第一个等于给定值的元素的位置，找不到返回-1
int SequenceList::locate(ElementType element)
{
    for (int i = 0; i < count; i++)
    {
        if (data[i] == element)
            return i + 1;
    }
    return -1;
}

//替换顺序表中指定位置元素的值

bool SequenceList::replace(int index, ElementType element)
{
    if (index < 1 || index > count)
        return false; //位置不合法
    data[index - 1] = element;
    return true;
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

//顺序表测试函数
void testSequenceList()
{
    SequenceList list;
    list.initList(200);
    cout << "为顺序表list分配的存储空间大小为：" << list.size << endl;
    cout << "依次插入1——100共100个整数后，顺序表元素为：" << endl;
    for (int i = 0; i < 100; i++)
    {
        list.insert(i + 1, i + 1);
    }
    list.print();
    cout << "当前顺序表表长为：" << list.count << endl;
    cout << "在第1号位置插入2020，在第25号位置插入4，在100号位置插入1024，顺序表元素为：" << endl;
    list.insert(2020, 1);
    list.insert(4, 25);
    list.insert(1024, 100);
    list.print();
    list.deleteElement(1);
    list.deleteElement(50);
    list.deleteElement(100);
    cout << "删除顺序表第1，50，100号位置的元素，顺序表表长为：" << list.count << endl;
    cout << "顺序表元素为：" << endl;
    list.print();
    cout << "查找第10，30，60号位置的元素的值，分别为：" << endl;
    ElementType e;
    if (list.find(10, e))
        cout << "第10号元素查找成功，值为：" << e << endl;
    else
        cout << "第10号元素查找失败！" << e << endl;

    if (list.find(30, e))
        cout << "第30号元素查找成功，值为：" << e << endl;
    else
        cout << "第30号元素查找失败！" << e << endl;
    if (list.find(60, e))
        cout << "第60号元素查找成功，值为：" << e << endl;
    else
        cout << "第60号元素查找失败！" << e << endl;
    cout << "替换第55，66，77，号位置元素分别为 8,15,22后，顺序表list的元素为：" << endl;
    list.replace(55, 8);
    list.replace(66, 15);
    list.replace(77, 22);
    list.print();
    cout << "查找值为8，15，22的元素第一次出现的位置：" << endl;
    int location = 0;
    location = list.locate(8);
    if (location <= 0)
        cout << "值为8的元素没找到！";
    else
        cout << "值为8的元素在顺序表中第一次出现的位置为：" << location << endl;
    location = list.locate(15);
    if (location <= 0)
        cout << "值为15的元素没找到！";
    else
        cout << "值为15的元素在顺序表中第一次出现的位置为：" << location << endl;
    location = list.locate(22);
    if (location <= 0)
        cout << "值为22的元素没找到！";
    else
        cout << "值为22的元素在顺序表中第一次出现的位置为：" << location << endl;
    cout << "当前顺序表list的元素为：" << endl;
    list.print();
    cout << "测试结束！" << endl;
}

#pragma endregion 顺序表部分结束

#pragma region 单链表开始

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

#pragma endregion 单链表部分结束

#pragma region 公共算法部分开始
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
// void DeleteAllEmementsSameGiveElement(SequenceList &sequenceList, ElementType element)
// {
//     for (int i = 0; i < sequenceList.count; i++)
//     {
//         if (sequenceList.data[i] == element)
//     }
// }

#pragma endregion 公共算法部分结束

#pragma region main函数部分
//main函数
int main()
{
    // SequenceList list;
    // list.initList(20);
    // for (int i = 0; i < 10; i++)
    // {
    //     list.insert(i * i, i + 1);
    // }
    // list.print();
    // //逆置线性表
    // ReverseList(list);
    // //删除线性表最小元素
    // ElementType deleteData;
    // int flag = DeleteElementWithMinValue(list, deleteData);
    // cout << "删除标志（1：成功；0：失败）：" << flag << "  ; 删除的值为：" << deleteData << endl;
    // list.print();
    // flag = DeleteEmementByPosition(list, 5, deleteData);
    // cout << "删除标志（1：成功；0：表空；-1：删除位置不合理）：" << flag << "  ; 删除的值为：" << deleteData << endl;
    // list.print();
    // flag = InsertElementByPosition(list, 5, 25);
    // cout << "插入标志（1：成功；0：表空或表满；-1：插入失败）：" << flag << endl;
    // list.print();
    // return 0;
    testSequenceList(); //顺序表测试函数
    return 0;
}

#pragma endregion main函数部分结束