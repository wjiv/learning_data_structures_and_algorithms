//线性表部分实现完整代码

// 头文件及名称空间

#include <iostream>
#include <cctype>

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
    data = new ElementType[INIT_SIZE];
    size = INIT_SIZE;
}

// 初始化顺序表
void SequenceList::initList(int length)
{
    data = new ElementType[length];
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
        element = (ElementType)NULL;
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
    cout << "顺序表测试：" << endl;
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
    cout << "顺序表测试结束！" << endl;
}

#pragma endregion 顺序表部分结束

#pragma region 单链表开始

//单链表结点定义
struct ListNode
{
    ElementType data;
    ListNode *next;
};

//单链表定义
struct LinkList
{
    ListNode *head;                                //头结点
    ListNode *tail;                                //尾结点
    int length;                                    //表长
    void initLinkList();                           //初始化单链表
    void insertFront(ElementType element);         //头部插入元素
    void insertBack(ElementType element);          //尾部插入元素
    bool deleteElement(int index);                 //删除指定位置元素结点
    bool find(int index, ElementType &element);    //查找指定位置结点的元素值
    int locate(ElementType element);               //查找给定元素第一次出现在单链表中的位置
    bool replace(int indenx, ElementType element); //替换指定位置结点的元素值
    void print();                                  //遍历单链表
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
    length += 1;
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
    length += 1;
}

//删除元素
bool LinkList::deleteElement(int index)
{
    if (index < 1 || index > length)
        return false;
    ListNode *node = head;
    int count = 0;
    while (node != NULL && count < index - 1)
    {
        node = node->next;
        count++;
    }
    if (node != NULL && count == index - 1)
    {
        ListNode *tmp = node->next;
        node->next = tmp->next;
        delete tmp;
        length -= 1;
        return true;
    }
    else
    {
        return false;
    }
}

//查找指定位置结点元素的值
bool LinkList::find(int index, ElementType &element)
{
    if (index < 1 || index > length)
        return false;
    ListNode *node = head;
    int count = 0;
    while (node != NULL && count < index)
    {
        node = node->next;
        count++;
    }
    if (node != NULL && count == index)
    {
        element = node->data;
        return true;
    }
    else
        return false;
}

//查找给定元素第一次出现在单链表中的位置 -1表示查找失败，
//大于0的整数表示查找成功，且返回整数即为元素在单链表中第一次出现的位置。
int LinkList::locate(ElementType element)
{
    int location = -1;
    int count = 0;
    ListNode *node = head;
    while (node != NULL && node->next != nullptr)
    {
        node = node->next;
        count++;
        if (node->data == element)
        {
            location = count;
            break;
        }
    }
    return location;
}

//替换单链表指定位置结点元素的值
bool LinkList::replace(int index, ElementType element)
{
    int count = 0;
    ListNode *node = head;
    while (node != NULL && count < index)
    {
        node = node->next;
        count++;
    }
    if (node != NULL && count == index)
    {
        node->data = element;
        return true;
    }
    else
        return false;
}

//遍历单链表
void LinkList::print()
{
    ListNode *ptr = head->next;
    int count = 0;
    while (ptr != NULL)
    {
        if (count != 0 && count < length)
            cout << " ";
        cout << ptr->data;
        ptr = ptr->next;
        count++;
    }
    cout << endl;
}

//单链表测试函数
void testLinkList()
{
    LinkList list;
    list.initLinkList();
    cout << "单链表测试：" << endl;
    cout << "采用前插法，向单链表插入分别以 1,2,3,4,5为值的五个结点，遍历单链表元素为：" << endl;
    list.insertFront(1);
    list.insertFront(2);
    list.insertFront(3);
    list.insertFront(4);
    list.insertFront(5);
    cout << "当前表长为：" << list.length << endl;
    list.print();
    cout << "采用尾插法，向单链表插入分别以 6,7,8,9,10为值的五个结点，遍历单链表元素为：" << endl;
    list.insertBack(6);
    list.insertBack(7);
    list.insertBack(8);
    list.insertBack(9);
    list.insertBack(10);
    cout << "当前表长为：" << list.length << endl;
    list.print();
    cout << "删除第1，3，5，7个结点元素，此时单链表元素为：" << endl;
    bool flag = false;
    flag = list.deleteElement(1);
    if (flag)
    {
        cout << "第1个结点删除成功！当前单链表元素为：" << endl;
    }
    else
    {
        cout << "第1个结点删除失败！当前单链表元素为：" << endl;
    }
    list.print();
    cout << "当前表长为：" << list.length << endl;
    flag = list.deleteElement(3);
    if (flag)
    {
        cout << "第3个结点删除成功！当前单链表元素为：" << endl;
    }
    else
    {
        cout << "第3个结点删除失败！当前单链表元素为：" << endl;
    }
    list.print();
    cout << "当前表长为：" << list.length << endl;
    flag = list.deleteElement(5);
    if (flag)
    {
        cout << "第5个结点删除成功！当前单链表元素为：" << endl;
    }
    else
    {
        cout << "第5个结点删除失败！当前单链表元素为：" << endl;
    }
    list.print();
    cout << "当前表长为：" << list.length << endl;
    flag = list.deleteElement(7);
    if (flag)
    {
        cout << "第7个结点删除成功！当前单链表元素为：" << endl;
    }
    else
    {
        cout << "第7个结点删除失败！当前单链表元素为：" << endl;
    }
    list.print();
    cout << "当前表长为：" << list.length << endl;
    ElementType e;
    cout << "查找第1，4，8个结点元素的值：" << endl;
    flag = list.find(1, e);
    if (flag)
    {
        cout << "第1个结点元素的值为：" << e << endl;
    }
    else
    {
        cout << "未找到第1个结点！" << endl;
    }
    flag = list.find(4, e);
    if (flag)
    {
        cout << "第4个结点元素的值为：" << e << endl;
    }
    else
    {
        cout << "未找到第4个结点！" << endl;
    }
    flag = list.find(8, e);
    if (flag)
    {
        cout << "第8个结点元素的值为：" << e << endl;
    }
    else
    {
        cout << "未找到第8个结点！" << endl;
    }
    cout << "查找结点值为3，6，7在单链表中的位置" << endl;
    int location = -1;
    location = list.locate(3);
    if (location <= 0)
        cout << "结点值为3的结点未找到！" << endl;
    else
        cout << "结点值为3的元素的结点位置为：" << location << endl;
    location = list.locate(6);
    if (location <= 0)
        cout << "结点值为6的结点未找到！" << endl;
    else
        cout << "结点值为6的元素的结点位置为：" << location << endl;
    location = list.locate(7);
    if (location <= 0)
        cout << "结点值为7的结点未找到！" << endl;
    else
        cout << "结点值为7的元素的结点位置为：" << location << endl;
    cout << "替换表中第1，3，5号位置结点的值为分别为2020,1,12" << endl;
    flag = list.replace(1, 2020);
    if (flag)
    {
        cout << "替换1号位置结点的值为2020成功！" << endl;
    }
    else
    {
        cout << "替换1号位置结点的值为2020失败！" << endl;
    }
    flag = list.replace(3, 1);
    if (flag)
    {
        cout << "替换3号位置结点的值为1成功！" << endl;
    }
    else
    {
        cout << "替换3号位置结点的值为1失败！" << endl;
    }
    flag = list.replace(5, 12);
    if (flag)
    {
        cout << "替换5号位置结点的值为12成功！" << endl;
    }
    else
    {
        cout << "替换5号位置结点的值为12失败！" << endl;
    }
    cout << "此时单链表各结点元素为：" << endl;
    list.print();
    cout << "单链表测试结束！" << endl;
}

#pragma endregion 单链表部分结束

#pragma region 单循环链表开始

//单循环链表结点结构
struct SingleLoopLinkListNode
{
    ElementType data;
    SingleLoopLinkListNode *link;
};

//单循环链表结构
struct SingleLoopLinkList
{
    SingleLoopLinkListNode *head;
    void initSingleLoopLinkList();
};

#pragma endregion 单循环链表结束

#pragma region 双向链表开始

//双向链表结点结构
struct DoubleLinkListNode
{
    ElementType data;
    DoubleLinkListNode *leftLink;
    DoubleLinkListNode *rightLink;
};

//双向链表结构
struct DoubleLinkList
{
    DoubleLinkListNode *head;
    void initDoubleLinkList();
};

#pragma endregion 双向链表结束

#pragma region 双向循环链表开始
//双向循环链表结点结构
struct DoubleLoopLinkListNode
{
    ElementType data;
    DoubleLoopLinkListNode *leftLink;
    DoubleLoopLinkListNode *rightLink;
};

//双向循环链表结构
struct DoubleLoopLinkList
{
    DoubleLoopLinkListNode *head;
    void initDoubleLoopLinkList();
};

#pragma endregion 双向循环链表结束

#pragma region 静态链表开始

//静态链表结点结构
struct StaticLinkList
{
    ElementType data;
    StaticLinkList *link;
};

#pragma endregion 静态链表结束

#pragma region 线性表相关算法部分开始

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

//在线性表的第i个位置插入一个元素，返回插入结果跟错误标志
int InsertElementByPosition(SequenceList &sequenceList, int index, ElementType element)
{
    if (sequenceList.count == 0)
        return 0; //线性表为空，返回0表示插入失败
    if (sequenceList.count == sequenceList.size)
        return 0; //线性表已满，返回0表示插入失败
    if (index < 1 || index > sequenceList.count)
        return -1; //-1表示插入位置不合理
    for (int i = sequenceList.count; i >= index; i--)
    {
        sequenceList.data[i] = sequenceList.data[i - 1];
    }
    sequenceList.data[index - 1] = element;
    sequenceList.count += 1;
    return 1; //插入成功，返回1
}

//从顺序表中删除具有给定值x的所有元素。
void RemoveAllValuesEqualGiveValue(SequenceList &sequenceList, ElementType element)
{
    int tmp = 0;
    for (int i = 0; i < sequenceList.count; i++)
    {
        if (sequenceList.data[i] != element)
        {
            if (tmp != i)
                sequenceList.data[tmp] = sequenceList.data[i];
            tmp++;
        }
    }
    sequenceList.count = tmp;
}

//从顺序表中删除其值在给定值s与t（s <= t）之间的所有元素，如果顺序表为空，则显示错误信息并退出运行。
int RemoveAllValuesInGiveRange(SequenceList &sequenceList, ElementType lowerBound, ElementType upperBound)
{
    if (sequenceList.count == 0)
        return 0;
    if (lowerBound > upperBound)
    {
        ElementType tmpBound = upperBound;
        upperBound = lowerBound;
        lowerBound = tmpBound;
    }
    int tmp = 0;
    for (int i = 0; i < sequenceList.count; i++)
    {
        if (sequenceList.data[i] < lowerBound || sequenceList.data[i] > upperBound)
        {
            if (tmp != i)
                sequenceList.data[tmp] = sequenceList.data[i];
            tmp++;
        }
    }
    sequenceList.count = tmp;
    return 1;
}

//设计一个算法，从有序顺序表中删除其值在给定值s与t（s <= t）之间的所有元素，如果顺序表为空，则显示错误信息并退出运行。
int RemoveAllSequenceListValuesInGiveRange(SequenceList &sequenceList, ElementType lowerBound, ElementType upperBound)
{
    if (sequenceList.count == 0)
        return 0;
    if (lowerBound > upperBound)
    {
        ElementType tmpBound = upperBound;
        upperBound = lowerBound;
        lowerBound = tmpBound;
    }
    int tmp = 0;
    for (int i = 0; i < sequenceList.count; i++)
    {
        if (sequenceList.data[i] <= lowerBound || sequenceList.data[i] >= upperBound)
        {
            if (tmp != i)
                sequenceList.data[tmp] = sequenceList.data[i];
            tmp++;
        }
    }
    sequenceList.count = tmp;
    return 1;
}

// 设计一个算法，将两个有序顺序表合并成一个新的有序顺序表并由函数返回结果顺序表。
int MergeSequenceList(SequenceList sequenceListA, SequenceList sequenceListB, SequenceList &result)
{
    if (result.size < sequenceListA.count + sequenceListB.count)
        return 0;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    while (count1 < sequenceListA.count && count2 < sequenceListB.count)
    {
        if (sequenceListA.data[count1] <= sequenceListB.data[count2])
        {
            result.data[count3] = sequenceListA.data[count1];
            count3++;
            count1++;
        }
        else
        {
            result.data[count3] = sequenceListB.data[count2];
            count3++;
            count2++;
        }
    }
    while (count1 < sequenceListA.count)
    {
        result.data[count3] = sequenceListA.data[count1];
        count3++;
        count1++;
    }
    while (count2 < sequenceListB.count)
    {
        result.data[count3] = sequenceListB.data[count2];
        count3++;
        count2++;
    }
    result.count = count3;
    return 1;
}

//设计一个算法，从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不相同。
int DeleteRepeatValuesFromSequenceList(SequenceList &sequenceList)
{
    if (sequenceList.count == 0)
        return 0;
    int tmp = 1;
    for (int i = 1; i < sequenceList.count; i++)
    {
        if (sequenceList.data[i - 1] != sequenceList.data[i])
        {
            if (tmp != i)
                sequenceList.data[tmp] = sequenceList.data[i];
            tmp++;
        }
    }
    sequenceList.count = tmp;
    return true;
}

//设计一个算法，以不多于 3n/2的平均比较次数，在一个有n个整数的顺序表A中找出具有最大值和最小值的整数。
int FindMaximumValueAndMinimumValue(SequenceList sequenceList, ElementType &maxValue, ElementType &minValue)
{
    if (sequenceList.count == 0)
        return 0;
    maxValue = minValue = sequenceList.data[0];
    for (int i = 0; i < sequenceList.count; i++)
    {
        if (sequenceList.data[i] > maxValue)
            maxValue = sequenceList.data[i];
        else if (sequenceList.data[i] < minValue)
            minValue = sequenceList.data[i];
    }
    return 1;
}

/* 设$A=(a_1,a_2,\cdots,a_{n-1},a_n)$和$B=(b_1,b_2,\cdots,b_{n-1},b_n)$均为顺序表，
    $A^{'}$和$B^{'}$分别是除去最大公共前缀子串后的子表。如A=('b','e','i','j','i','n','g')，
    B=('b','e','i','f','a','n','g')，则两者的最大公共前缀为'b','e','i'，在两个顺序表中除去
    最大公共前缀的子表分别为A'=('j','i','n','g')，B'=('f','a','n','g')。若A'=B'=空表，则A=B；
    若A'=空表且B'$\neq$空表，或两者均不空且A'的第一个元素值小于B'的第一个元素的值，则A$\lt$B，
    否则A$\gt$B。设计一个算法根据上述方法比较A和B的大小。*/
char CompareSequenceListWithSubList(SequenceList sequenceListA, SequenceList sequenceListB)
{
    int count = 0;
    while (count < sequenceListA.count && count < sequenceListB.count)
    {
        if (sequenceListA.data[count] == sequenceListB.data[count])
            count++;
        else
            break;
    }
    if (count >= sequenceListA.count && count >= sequenceListB.count)
        return '=';
    if (count >= sequenceListA.count || sequenceListA.data[count] < sequenceListB.data[count])
        return '<';
    else
        return '>';
}

//设计一个算法，在带头结点的单链表中寻找第i(i >= 1)。若找到，则返回第i个结点的地址；若找不到，则返回NULL
ListNode *FindNodeAddress(LinkList &linkList, int index)
{
    if (index < 0)
        return NULL;
    ListNode *node = linkList.head;
    int count = 0;
    while (node != NULL && count < index)
    {
        node = node->next;
        count++;
    }
    return node;
}

//设计一个算法，在带头结点的单链表中确定值最大的结点。
ListNode *FindListNodeWithMaximumValue(LinkList &linkList)
{
    if (linkList.head == NULL || linkList.head->next == nullptr)
        return NULL;
    ListNode *node = linkList.head;
    ListNode *tmpNode = linkList.head->next;
    while (tmpNode != NULL)
    {
        if (tmpNode->data > node->data)
            node = tmpNode;
        tmpNode = tmpNode->next;
    }
    return node;
}

//设计一个算法，统计带头结点的单链表中具有给定值x的所有元素数。
int CountNodeNumbersWithGiveValue(LinkList linkList, ElementType element)
{
    int count = 0;
    ListNode *ptr = linkList.head;
    while (ptr != NULL)
    {
        if (ptr->data == element)
            count += 1;
        ptr = ptr->next;
    }
    return count;
}

//设计一个算法，根据一维数组A\[n]建立一个带头结点的单链表，使单链表中各个元素的次序与A\[n]中各元素的次序相同，要求该程序的时间复杂度为O(n)。
void CreateLinkListByArray(LinkList &linkList, ElementType *array, int arrayLength)
{
    linkList.initLinkList();
    ListNode *node = new ListNode;

    for (int i = 0; i < arrayLength; i++)
    {
        node->data = array[i];
        node->next = nullptr;
        if (linkList.tail == NULL)
        {
            linkList.head->next = node;
            linkList.tail = node;
            linkList.length += 1;
        }
        else
        {
            linkList.tail->next = node;
            linkList.tail = node;
            linkList.length += 1;
        }
    }
}

//设计一个算法，在非递减有序的带头结点的单链表中删除值相同的多余结点。
void DeleteRepeatValueNodeInIncreaseList(LinkList &linkList)
{
    ListNode *ptr = linkList.head;
    ListNode *tmp = NULL;
    while (ptr != NULL && ptr->next != nullptr)
    {
        if (ptr->data == ptr->next->data)
        {
            tmp = ptr->next;
            ptr->next = tmp->next;
            delete tmp;
        }
        else
            ptr = ptr->next;
    }
}

/*已知L为不带头结点的单链表的表头指针，链表中存储的都是整型数据，试写出下列运算的递归算法：

    (1). 求链表中的最大整数；

    (2). 求链表结点的个数;

    (3). 求链表所有元素的平均值。
*/
// (1). 求链表中的最大整数；
ElementType GetMaximumValueRecursively(ListNode *node)
{
    if (node->next == nullptr)
        return node->data;
    int tmpValue = GetMaximumValueRecursively(node->next);
    return node->data > tmpValue ? node->data : tmpValue;
}
// (2). 求链表结点的个数;
int CountNodeNumbersOfLinkList(ListNode *node)
{
    if (node->next == nullptr)
        return 0;
    return CountNodeNumbersOfLinkList(node->next) + 1;
}
// (3). 求链表所有元素的平均值。
ElementType GetAveragAllOfLinkList(ListNode *node, int &count)
{
    if (node->next == NULL)
    {
        count = 1;
        return (float)(node->data);
    }
    else
    {
        float sum = GetAveragAllOfLinkList(node->next, count) * count;
        count++;
        return (node->data + sum) / count;
    }
}

//设ha和hb分别是两个带头结点的非递减有序单链表的表头指针，设计一个算法，将这个两个有序链表合并成一个非递增的单链表。要求结果链表仍使用原来两个链表的存储空间，不另外占用其他的存储空间。表中允许出现重复的数据。
void MerageSequenceLinkList(LinkList &linkListA, LinkList &linkListB)
{
    ListNode *nodeA = linkListA.head->next;
    ListNode *nodeB = linkListB.head->next;
    ListNode *lastNode;
    ListNode *ptr;
    linkListA.head->next = nullptr; //合并后的链表保存在A链表中
    delete linkListB.head;
    while (nodeA != NULL && nodeB != NULL)
    {
        if (nodeA->data <= nodeB->data)
        {
            ptr = nodeA;
            ptr = ptr->next;
        }
        else
        {
            ptr->next = nodeA->next;
            nodeA->next = ptr;
        }
    }
    if (nodeB != NULL)
        nodeA = nodeB;
    while (nodeA != NULL)
    {
        ptr = nodeA;
        nodeA = nodeA->next;
        ptr->next = nodeA->next;
        nodeA->next = ptr;
    }
}

//设有一个表头指针为h的单链表。设计一个算法，通过一次遍历，将链表中的所有结点的指针的链接方向逆转。
void ReverseLinkList(LinkList &linkList)
{
    ListNode *ptr = linkList.head->next;
    ListNode *tmpNode = NULL;
    linkList.head->next = nullptr;
    while (ptr != NULL)
    {
        tmpNode = ptr;
        ptr = ptr->next;
        ptr->next = linkList.head->next;
        linkList.head->next = ptr;
    }
}

//设在一个带头结点的单链表中所有元素结点的数据值按递增顺序排列，设计一个算法，删除所有大于min且小于max的元素结点（若存在）。
void DeleteSequenceLinkListValueInGiveRange(LinkList &linkList, ElementType minValue, ElementType maxValue)
{
    ListNode *ptr = linkList.head;
    ListNode *tmpNode = linkList.head->next;
    while (ptr != NULL && ptr->data <= minValue)
    {
        ptr = tmpNode;
        tmpNode = tmpNode->next;
    }
    while (tmpNode != NULL && tmpNode->data < maxValue)
    {
        ptr->next = tmpNode->next;
        delete tmpNode;
        tmpNode = ptr->next;
    }
}

//设在一个带头结点的单链表中所有元素结点的数据值无序排列，设计一个算法，删除所有大于min且小于max的元素结点（若存在）。
void DeleteLinkListValueInGiveRange(LinkList &linkList, ElementType minValue, ElementType maxValue)
{
    ListNode *ptr = linkList.head;
    ListNode *tmpNode = linkList.head->next;
    while (ptr != NULL)
    {
        if (tmpNode->data > minValue && tmpNode->data < maxValue)
        {
            ptr->next = tmpNode->next;
            delete tmpNode;
            tmpNode = ptr->next;
        }
        else
        {
            ptr = tmpNode;
            tmpNode = tmpNode->next;
        }
    }
}

//根据一个结点数据为整型的单链表创建两个单链表，使得第一个单链表中包含原单链表中所有数值为奇数的结点，第二个单链表中包含原单链表中所有数据为偶数的结点，原有单链表保持不变。
void SeparateLinkListAccordingToParity(LinkList &linkList, LinkList &linkList1, LinkList &linkList2)
{
    ListNode *node1 = new ListNode;
    ListNode *node2 = new ListNode;
    linkList1.initLinkList();
    linkList2.initLinkList();
    ListNode *ptr = linkList.head->next;
    ListNode *tmpNode = NULL;
    while (ptr != NULL)
    {
        tmpNode = new ListNode;
        tmpNode->data = ptr->data;
        tmpNode->next = nullptr;
        if (ptr->data % 2 == 1)
        {
            if (linkList1.tail == NULL)
            {
                linkList1.head->next = tmpNode;
                linkList1.tail = tmpNode;
            }
            else
            {

                linkList1.tail->next = tmpNode;
                linkList1.tail = tmpNode;
            }
            linkList1.length += 1;
        }
        else
        {
            if (linkList2.tail == NULL)
            {
                linkList2.head->next = tmpNode;
                linkList2.tail = tmpNode;
            }
            else
            {

                linkList2.tail->next = tmpNode;
                linkList2.tail = tmpNode;
            }
            linkList2.length += 1;
        }
    }
}

//已知一个带头结点的单链表中包含3类字符（数字字符，字母字符和其他字符），设计一个算法，构造3个新的单链表，使得每个单链表中只包含同一类字符。要求使用原来的空间，表头结点可以另辟空间。
void SeparateCharacterInLinkList(LinkList &linkListA, LinkList &linkListB, LinkList &linkListC)
{
    ListNode *ptrA = linkListA.head;
    ListNode *ptrB;
    ListNode *ptrC = linkListC.head;
    ListNode *ptr = linkListA.head->next;
    linkListB.initLinkList();
    linkListC.initLinkList();
    ptrB = linkListB.head;
    ptrC = linkListB.head;
    while (ptr != NULL)
    {
        if (isdigit(ptr->data))
        {
            ptr->next = nullptr;
            if (linkListB.tail == NULL)
            {
                linkListB.head->next = ptr;
                linkListB.tail = ptr;
            }
            else
            {

                linkListB.tail->next = ptr;
                linkListB.tail = ptr;
            }
            linkListB.length += 1;
        }
        else if (isalpha(ptr->data))
        {
            ptr->next = nullptr;
            if (linkListC.tail == NULL)
            {
                linkListC.head->next = ptr;
                linkListC.tail = ptr;
            }
            else
            {

                linkListC.tail->next = ptr;
                linkListB.tail = ptr;
            }
            linkListC.length += 1;
        }
        ptr = ptr->next;
    }
}

//设计一个算法,将一个带头结点的单循环链表中所有结点的链接方向逆转
void ReverseCircleLinkList(SingleLoopLinkList &singleLoopLinkList)
{
    SingleLoopLinkListNode *ptr;
    SingleLoopLinkListNode *tmpNode;
    ptr = singleLoopLinkList.head->link;
    singleLoopLinkList.head->link = singleLoopLinkList.head;
    while (ptr != NULL)
    {
        tmpNode = ptr->link;
        ptr->link = singleLoopLinkList.head->link;
        singleLoopLinkList.head->link = ptr;
        ptr = tmpNode;
    }
}

//设有一个带头结点的非空双向循环链表L，指针p指向链表中第一个元素值为x的结点，设计一个算法，从链表中删除*p结点。
int DeleteNodeFromDoubleLoopLinkList(DoubleLoopLinkList &doubleLoopLinkList, ElementType element)
{
    DoubleLoopLinkListNode *ptr = doubleLoopLinkList.head->rightLink;
    while (ptr != NULL && ptr->data != element)
    {
        ptr = ptr->rightLink;
    }
    if (ptr == doubleLoopLinkList.head)
        return 0;
    ptr->leftLink->rightLink = ptr->rightLink;
    ptr->rightLink->leftLink = ptr->leftLink;
    delete ptr;
    return 1;
}

//设计一个算法，逆转带头结点的双向循环链表中所有结点的链接方向。
void ReverseDoubleLoopLinkList(DoubleLoopLinkList doubleLoopLinkList)
{
    DoubleLoopLinkListNode *ptr = doubleLoopLinkList.head;
    DoubleLoopLinkListNode *tmpPtr;
    do
    {
        tmpPtr = ptr->rightLink;
        ptr->rightLink = ptr->leftLink;
        ptr->leftLink = tmpPtr;
        ptr = tmpPtr;
    } while (ptr != doubleLoopLinkList.head);
}

//设计一个算法，改造一个带头结点的双向链表，所有结点的原有次序保持在各结点的rLink域中，而lLink域把所有结点按照其值从小到大的顺序链接起来。
void ModifySpecialDoubleLinkList(DoubleLinkList &doubleLinkList)
{
    DoubleLinkListNode *ptr = NULL;
    DoubleLinkListNode *tmpPtr1 = NULL;
    DoubleLinkListNode *tmpPtr2 = doubleLinkList.head->rightLink->rightLink;
    doubleLinkList.head->leftLink = doubleLinkList.head->rightLink;
    doubleLinkList.head->leftLink->leftLink = NULL;
    while (tmpPtr2 != NULL)
    {
        tmpPtr1 = doubleLinkList.head->leftLink;
        ptr = doubleLinkList.head;
        while (tmpPtr1 != NULL && ptr->data < tmpPtr2->data)
        {
            ptr = tmpPtr1;
            tmpPtr1 = tmpPtr1->leftLink;
        }

        ptr->leftLink = tmpPtr2;
        tmpPtr2->leftLink = tmpPtr1;
        tmpPtr2 = tmpPtr2->rightLink;
    }
}

//设以带头结点的双向循环链表表示线性表L=（$a_1,a_2,\cdots ,a_{n-1},a_n$）。设计一个时间复杂度为O(n)的算法，将L改造为L=（$a_1,a_3,\cdots ,a_n, \cdots ,a_4,a_2$）。
void ModifySpecialDoubleLoopLinkList(DoubleLoopLinkList &doubleLoopLinkList)
{
    DoubleLoopLinkListNode *ptr = doubleLoopLinkList.head->rightLink;
    DoubleLoopLinkListNode *tmpPtr1 = ptr->rightLink;
    DoubleLoopLinkListNode *tmpPtr2 = tmpPtr1->rightLink;
    while (tmpPtr2 != NULL && tmpPtr1 != doubleLoopLinkList.head)
    {
        ptr->rightLink = tmpPtr2;
        tmpPtr2->leftLink = ptr;
        tmpPtr1->rightLink = ptr->leftLink;
        ptr->leftLink = tmpPtr1;
        ptr = tmpPtr2;
        tmpPtr1 = ptr->rightLink;
        tmpPtr2 = tmpPtr1->rightLink;
    }
    if (tmpPtr1 == doubleLoopLinkList.head)
    {
        tmpPtr2 = ptr->leftLink;
        ptr->rightLink = tmpPtr2;
        tmpPtr2->leftLink = ptr;
    }
}

/*设计一个实现下属要求的Locate运算函数。设有一个带头结点双向链表L，每个结点有4个数据成员：
    指向前驱结点的指针lLink，指向后继节点的指针rLink，存放数据的成员data和访问频度frequency。
    所有结点的frequency初始时都为0。每当在链表上进行一次Locate(x)操作时，令元素值x结点的访问
    频度frequency加1，并将该结点前移，链接到与它的访问频度相等的结点后面，使得链表中所有结点
    保持按访问品读递减的顺序排列，以使频繁访问的结点总是靠近表头。*/
struct SpecialDoubleLoopLinkListNode
{
    ElementType data;
    int frequency;
    SpecialDoubleLoopLinkListNode *rightLink;
    SpecialDoubleLoopLinkListNode *leftLink;
};

struct SpecialDoubleLoopLinkList
{
    SpecialDoubleLoopLinkListNode *head;
    void initSpecialDoubleLoopLinkList();
};

SpecialDoubleLoopLinkListNode *Locate(SpecialDoubleLoopLinkList &doubleLoopLinkList, ElementType element)
{
    SpecialDoubleLoopLinkListNode *ptr = doubleLoopLinkList.head->rightLink;
    SpecialDoubleLoopLinkListNode *tmpNode = NULL;
    while (ptr != NULL && ptr->data != element)
    {
        ptr = ptr->rightLink;
    }
    if (ptr != NULL)
    {
        tmpNode->frequency++;
        tmpNode = ptr;
        tmpNode->leftLink->rightLink = tmpNode->rightLink;
        tmpNode->rightLink->leftLink = tmpNode->leftLink;
        ptr = tmpNode->leftLink;
        while (ptr != NULL && tmpNode->frequency > ptr->frequency)
        {
            ptr = ptr->leftLink;
        }
        tmpNode->rightLink = ptr->rightLink;
        tmpNode->leftLink = ptr;
        ptr->rightLink->leftLink = tmpNode;
        ptr->rightLink = tmpNode;
        return tmpNode;
    }
    else
        return NULL;
}

/*Josephus问题：设n个人围坐在圆桌周围，现在从第s个人开始报数，报到第m个人让他出局；然后从出局者的下一个人开始从新报数，数到第m个人，再让他出局....如此反复，直到所有的人全部出局为止。对于任意给定的n,s,m,求出这n个人的出局序列。以n=9,s=1,m=5为例验证。

    （1）. 若用整数序列1，2，3，...，n表示顺序围坐在圆桌周围的人，设计一个算法用一维数组表示作为求解过程中使用的数据结构，解决上述问题。

    （2）. 采用带头结点的单循环链表作为求解过程中使用的数据结构，设计一个算法，解决上述问题。

    （3）. 采用带头结点的双向循环链表作为求解过程中使用的数据结构，设计一个算法，解决上述问题。*/

//采用数组作为数据结构
void Josephus(int *arr, int s, int m, int n)
{
    int i, j, k = n;
    for (i = 0; i < n; i++)
    {
        i = (s - 1 + n) % n;
    }
    while (k > 0)
    {
        for (j = 1; j < m; j++)
        {
            i = (i + 1) % k;
        }
        cout << arr[i] << " ";
        for (j = i + 1; j < k; j++)
        {
            arr[j - 1] = arr[j];
        }
        k--;
    }
    cout << endl;
}
//采用单循环链表作为数据结构
void Josephus(SingleLoopLinkList &singleLoopLinkList, int s, int m, int n)
{
    SingleLoopLinkListNode *ptr = singleLoopLinkList.head->link;
    SingleLoopLinkListNode *tmpPtr = singleLoopLinkList.head;
    int i, j;
    for (i = 1; i < s; i++)
    {
        ptr = ptr->link;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            tmpPtr = ptr;
            ptr = ptr->link;
            if (ptr == singleLoopLinkList.head)
            {
                tmpPtr = ptr;
                ptr = ptr->link;
            }
        }
        cout << ptr->data << " ";
        tmpPtr->link = ptr->link;
        delete ptr;
        ptr = tmpPtr->link;
    }
    cout << endl;
}
//采用双循环链表作为数据结构
void Josephus(DoubleLoopLinkList &doubleLoopLinkList, int s, int m, int n)
{
    DoubleLoopLinkListNode *ptr = doubleLoopLinkList.head->rightLink;
    DoubleLoopLinkListNode *tmpPtr = NULL;
    int i, j;
    for (i = 1; i < s; i++)
    {
        ptr = ptr->rightLink;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            if (ptr->rightLink != doubleLoopLinkList.head)
            {
                ptr = ptr->rightLink;
            }
            else
                ptr = doubleLoopLinkList.head->rightLink;
        }
        cout << ptr->data << " ";
        ptr->leftLink->rightLink = ptr->rightLink;
        ptr->rightLink->leftLink = ptr->leftLink;
        tmpPtr = ptr->rightLink;
        delete ptr;
        ptr = tmpPtr;
    }
    cout << endl;
}

//设计一个算法，求两个用有序链表表示的集合A和集合B的并，通过第3个用有序链表表示的集合C返回运算结果，A和B的原有内容保持不变。
void UnionSet(LinkList &setA, LinkList &setB, LinkList &setC)
{
}
//设计一个算法，求两个用有序链表表示的集合A和集合B的交，通过第3个用有序链表表示的集合C返回运算结果，A和B的原有内容保持不变。
void IntersectSet(LinkList &setA, LinkList &setB, LinkList &setC)
{
}
//设计一个算法，求两个用有序链表表示的集合A和集合B的差，通过第3个用有序链表表示的集合C返回运算结果，A和B的原有内容保持不变。
void DefferenceSet(LinkList &setA, LinkList &setB, LinkList &setC)
{
}
//若采用数组来存储一元多项式的系数，即用数组的第i个元素存放多项式的第i次幂项的系数，如对于一元多项式 $f(x) = 6x^6 + 7x^4 - 10x^2 + 5x +3$。设计两个算法，分别求一元多项式的和跟乘积。

//设计一个算法，输入一元多项式的系数跟指数，按照指数降幂的方式建立多项式链表。如果输入的指数与链表中已有的某一项的指数相等，则新的项不加入，并报告作废信息。整个输入序列以输入系数为0标志结束。

/*设对于一个一元多项式 $P(x) = a_{m-1}x^{e_{m-1}} + a_{m-2}x^{e_{m-2}} + \cdots + a_{0}x^{e_{0}}$ ，用表长为m的带有头结点的单链表表示为 $(t_{m-1} , t_{m-2} , \cdots , t_1, t_0)$ 。其中，m是多项式 $P(x)$ 中非0项的个数，每一个 $t_i(0 \leq t_i \leq m-1)$ 是 $P(x)$ 的一个非0项，各个项按指数 $e_i$ 递减顺序排列： $e_{m-1} \gt e_{m-2} \gt \cdots \gt e_0 \gt 0$ 。
    
    （1）. 设计一个一元多项式插入新项的算法Insert。该算法的功能是：如果多项式中没有与新项指数相等的项，则将此项插入到多项式链表的适当位置；如果多项式中已有与新项指数相同的项，则将它们合并。

    （2）. 利用（1）中的插入算法，设计一个实现一元多项式乘法的算法。*/

//设计一个算法，按照降幂的次序输出一个一元多项式。

//用带头结点的单链表表示一个一元多项式，链表中的结点按幂指数降序链接。设计一个算法，将表示一元多项式的单链表就地逆置，改为按幂指数升序链接。

//用带头结点的单链表表示一个一元多项式，试设计一个算法，计算多项式A在x处的值。

//类似用数组表示一元多项式，可用二维数组A表示二元多项式，数组元素A\[i]\[j]表示多项式中 $x^i$ 和 $y^j$ 的系数。试设计一个算法，把用二维数组表示的二元多项式以常规多项式的形式按升幂顺序输出。对于多项式的每一项 $c_kx^iy^j$ 可以打印成 $c_k$x^iy^j ，其中 $c_k$ ，i 和 j用实际值输出。当 $c_k$ ， i ， j 的值为1时，可以不显示 $c_k$ ，i ， j ，^ 。

//线性表相关算法测试
void testLinearListAlgorithms()
{
    SequenceList sequenceList;
    sequenceList.initList(20);
    for (int i = 0; i < 10; i++)
    {
        sequenceList.insert(i * i, i + 1);
    }
    sequenceList.print();
    //逆置线性表
    ReverseList(sequenceList);
    cout << "原地逆置线性表——逆置后的顺序表如下：" << endl;
    sequenceList.print();
    //删除线性表中的具有最小值的元素
    cout << "删除线性表中具有最小值元素：" << endl;
    ElementType deleteData;
    int flag = -1;
    flag = DeleteElementWithMinValue(sequenceList, deleteData);
    cout << "删除标志（1：成功；0：失败）：" << flag << "  ; 删除的值为：" << deleteData << " ；当前表长为：" << sequenceList.count << endl;
    sequenceList.print();
    //删除顺序表中指定位置的元素
    cout << "删除线性表中指定位置的元素：" << endl;
    flag = DeleteEmementByPosition(sequenceList, 5, deleteData);
    cout << "删除标志（1：成功；0：表空；-1：删除位置不合理）：" << flag << "  ; 删除的值为：" << deleteData << " ；当前表长为：" << sequenceList.count << endl;
    sequenceList.print();
    //向顺序表指定位置插入元素
    cout << "向顺序表指定位置插入元素：" << endl;
    flag = InsertElementByPosition(sequenceList, 5, 25);
    cout << "插入标志（1：成功；0：表空或表满；-1：插入失败）：" << flag << " ；当前表长为：" << sequenceList.count << endl;
    sequenceList.print();
    InsertElementByPosition(sequenceList, 2, 36);
    InsertElementByPosition(sequenceList, 4, 49);
    InsertElementByPosition(sequenceList, 6, 36);
    InsertElementByPosition(sequenceList, 8, 81);
    InsertElementByPosition(sequenceList, 10, 36);
    sequenceList.print();
    //删除顺序表中与给定元素值相等的所有元素
    RemoveAllValuesEqualGiveValue(sequenceList, 36);
    cout << "删除与36相等的所有元素后，顺序表元素为：" << endl;
    sequenceList.print();
    cout << "顺序表表长为：" << sequenceList.count << endl;
    //删除顺序表中元素位于给定范围的元素
    RemoveAllValuesInGiveRange(sequenceList, 20, 60);
    cout << "删除顺序表中元素大于20且小于60的元素后，顺序表元素为：" << endl;
    sequenceList.print();
    cout << "顺序表表长为：" << sequenceList.count << endl;
    SequenceList sequenceListA;
    sequenceListA.initList(20);
    for (int i = 0; i < 10; i++)
    {
        sequenceListA.insert(i + 1, i + 1);
    }
    //删除有序顺序表中元素介于给定范围的元素
    RemoveAllSequenceListValuesInGiveRange(sequenceListA, 2, 6);
    cout << "删除顺序表中元素大于2且小于6的元素后，顺序表元素为：" << endl;
    sequenceListA.print();
    cout << "顺序表表长为：" << sequenceListA.count << endl;
    //合并有序顺序表
    SequenceList sequenceListB;
    sequenceListB.initList(20);
    for (int i = 0; i < 10; i++)
    {
        sequenceListB.insert(3 * (i + 1), i + 1);
    }
    SequenceList mergeResult;
    mergeResult.initList(20);
    MergeSequenceList(sequenceListA, sequenceListB, mergeResult);
    cout << "两个有序 顺序表合并（假设合并后从小到大排列）后，元素为：" << endl;
    mergeResult.print();
    //顺序表去重
    sequenceListA.replace(3, 2);
    sequenceListA.replace(5, 7);
    sequenceListA.print();
    cout << "删除有序顺序表中重复的元素（删除顺序表B中值为30的元素，只保留一个）：" << endl;
    DeleteRepeatValuesFromSequenceList(sequenceListA);
    sequenceListA.print();
    //找出顺序表中的最值
    cout << "找出顺序表B中的最大值：" << endl;
    cout << "顺序表B的元素为：" << endl;
    sequenceListB.print();
    ElementType maxValue;
    ElementType minValue;
    FindMaximumValueAndMinimumValue(sequenceListB, maxValue, minValue);
    cout << "顺序表B中，最大值是：" << maxValue << " ；最小值是：" << minValue << endl;
    //根据除去最大公共前缀子串后的顺序表比较顺序表大小
    //注意，这里比较函数的验证需要把ElementType改为Char类型
    // SequenceList sequenceListA;
    // SequenceList sequenceListB;
    // sequenceListA.initList(10);
    // sequenceListB.initList(10);
    // sequenceListA.insert('b', 1);
    // sequenceListA.insert('e', 2);
    // sequenceListA.insert('i', 3);
    // sequenceListA.insert('j', 4);
    // sequenceListA.insert('i', 5);
    // sequenceListA.insert('n', 6);
    // sequenceListA.insert('g', 7);
    // sequenceListB.insert('b', 1);
    // sequenceListB.insert('e', 2);
    // sequenceListB.insert('i', 3);
    // sequenceListB.insert('f', 4);
    // sequenceListB.insert('a', 5);
    // sequenceListB.insert('n', 6);
    // sequenceListB.insert('g', 7);
    // cout << "字符顺序表A元素为：" << endl;
    // sequenceListA.print();
    // cout << "字符顺序表B元素为：" << endl;
    // sequenceListB.print();
    // char compareChar = CompareSequenceListWithSubList(sequenceListA, sequenceListB);
    // cout << "字符顺序表A与顺序表B的比较结果为：顺序表A" << compareChar << "顺序表B！" << endl;
}

#pragma endregion 线性表相关算法部分结束

#pragma region main函数部分

//main函数
int main()
{
    // testSequenceList(); //顺序表测试函数
    // testLinkList(); //单链表测试函数
    testLinearListAlgorithms(); //线性表相关算法测试函数
    return 0;
}

#pragma endregion main函数部分结束