/*顺序表：
    线性表的顺序存储又称顺序表；
    顺序表的特点是：逻辑上相邻元素其物理存储也相邻，即顺序表表中元素的逻辑顺序与其物理顺序相同。
                   顺序表的主要特点是随机访问（访问也称读写），对于查找和更新元素，只要给出索引，即可在O(1)的时间复杂度内找到指定元素位置。
                   顺序表插入跟删除操作需要移动大量元素，因此其时间复杂度为：O(n)。
    下面是以顺序表的 C++ 实现 
*/

#include <iostream>
const int INIT_SIZE = 100;
using namespace std;

typedef int ElementType;

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
    void update(ElementType e);                  //跟新顺序表中元素
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
    count == 0;
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
}

// // 根据元素返回所在位置
// int SequenceList::find(ElementType element)
// {
//     int index = -1;
//     for (int i = 0; i < count; i++)
//     {
//         if (data[i] == element)
//             index = i + 1;
//     }
//     return index;
// }

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

//main函数

int main()
{
    test();
    return 0;
}