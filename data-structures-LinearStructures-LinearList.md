## 线性表

### 线性表的定义

**线性表**：n个数据元素的有限序列称为线性表。记作$L=(a_1,a_2,a_3,\cdots ,a_n)$ 。其中，$L$ 是表名，$a_i$ 为表中的结点。n表示数据元素的个数，也称表长。当n=0是，表为空。

### 线性表的特点

- 每个结点数据元素类型都相同，且占有相同得分存储空间；

- 表中的每个元素排列有其先后次序；

- 除第一个元素外，每一个元素都有一个直接前驱（元素）；

- 除最后一个元素外，每一个元素都有一个直接后继（元素）。

### 线性表的操作

- **初始化**：将线性表置为空表；

- **求表长**：统计线性表中元素的个数；

- **查找元素**：按值查找返回所查找元素的索引位置，按下标查找返回对应下标元素的值；

- **插入元素**：在指定位置向线性表中插入元素；

- **删除元素**：删除线性表中指定位置的元素；

- **遍历**：按一定顺序遍历打印出线性表中的所有元素。

- **判空**：判断线性表是否为空表；

- **$\cdots$**

#### 疑难解答

1. 如果一个集合中每个元素都有且仅有一个直接前驱，有且仅有一个直接后继，它是线性表吗？循环链表是线性表吗？

>答：如果一个集合中每个元素都有且仅有一个直接前驱，有且仅有一个直接后继，它不是线性表，因为不满足线性表的逻辑结构特点。循环链表是一种存储结构，而线性表是逻辑结构，因此，循环链表不是线性表。

2. 如果一个元素集合中有一个元素仅有一个直接后继而没有直接前驱，另一个元素只有一个直接前驱而没有直接后继，其他元素都仅有一个直接前驱和直接后继，但其中各个元素可能数据类型不同，该元素集合是线性表吗？

>答：该元素集合是线性表。对于不同的类型的元素可以使用Union来构造定义，保相同存储空间大小即可。

3. 如果有n个（n$\geq$0）元素的序列构成一个表，且每个数据元素有不可再分的数据元素，又有可再分的子表，它是线性表吗？如果不是，它又是什么表？什么条件下才能称为线性表？

>答：它不是线性表，而是广义表，仅当表中所有元素都为不可能再分的数据元素时才称为线性表。

4. 如果一个一维整数数组有n个数据元素，它是线性表吗？二维数组可视为一维数组的一维数组，那么二维数组是线性表吗？为什么？

>答：数组由于其特殊性，可以认为是逻辑结构，也可以认为是存储结构。因此，一维数组是线性表。二维数组不是线性表，因为二维数组在逻辑上最多有两个直接前驱和两个直接后继。

5. 可以为线性表定义查找，插入，删除等操作吗？如何实现？

>答：可以为线性表定义这些操作，实现方式依赖于线性表采用何种存储结构来实现。

### 线性表的顺序存储——顺序表

#### 顺序表的定义

**线性表的顺序存储称为顺序表。**

#### 顺序表的特点

- 逻辑上相邻的两个元素，其物理位置也相邻；

- 顺序表往往借助数组来实现，顺序表的第一个元素在数组中对应的下标索引是0；

- 顺表是一种可随机存取的存储结构。这意味着可以根据元素相对线性表的第一个元素的位置或者元素的下标索引直接访问该元素。

#### 顺序表的实现

- **C++编码实现**：

```C++

#include <iostream>
using namespace std;

// 公共变量
const int INIT_SIZE = 100;
typedef int ElementType;

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

//main函数
int main(){
    testSequenceList();
    return 0;
}
```

#### 疑难解答

1. 线性表的顺序存储表示是一维数组吗？

>答：顺序表的实现采用了一维数组，但二者之间是有区别的：
>
>    1. 一维数组跟顺序表都是可以随机存储的，但顺序表各个元素之间是相继存放的，而一维数组中，元素可以不相继存放。
>            
>    2. 一维数组只能存放元素，而顺序表可以在其上定义和实现操作。
>
>    3. 顺序表长度是可变的，而一维数组一经分配，长度便不再改变。  

2. 顺序表可以扩充吗？如果想要扩充，应该采用何种结构？

> 答：采用静态分配数组的顺序表是不可以扩充的。若想要扩充，则顺序表实现时，数组需要动态分配。在扩充时，只需要重新分配数组空间即可。

3. 线性表的每一个数据元素是否必须相同？为什么？

>答：线性表的每一个表元素占据的空间一般要求相同，对于要求每个元素类型不同，可以使用联合类型（Union）来定义顺序表的数据元素类型。

4. 对于动态分配的顺序表A，可否用SequenceList A定义后直接使用？

>答：不能直接使用，采用动态分配的顺序表，在声明变量后，必须对顺序表进行初始化操作，为顺序表分配存储空间，并置空后才能使用。

#### 顺序表相关算法

1. 设有一个线性表（$e_1，e_2，\cdots ，e_{n-1}，e_n$）。设计一个算法，将这个线性表原地逆置，即将顺序表的前n个原址内容置换为（$e_n，e_{n-1}，\cdots ，e_2，e_1$）。

- **C++编码实现**：

```C++
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
```

2. 设计一个算法，从顺序表中删除具有最小值的元素，并由函数返回被删元素的值。空出的位置由表中最后一个元素填补，若顺序表为空则显示错误信息并结束运行。

- **C++编码实现**：

```C++
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
```

3. 设计一个算法，从顺序表中删除第position个元素并由函数返回被删元素的值，如果position不合理或者表为空，则显示错误信息并退出运行。

- **C++编码实现**：

```C++
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
```

4. 设计一个算法，向顺序表中第i个位置插入一个新的元素x，如果i不合理则显示错误信息并退出运行。

- **C++编码实现**：

```C++
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
```

5. 设计一个算法，从顺序表中删除具有给定值x的所有元素。

- **C++编码实现**：

```C++
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
```

6. 设计一个算法，从顺序表中删除其值在给定值s与t（s $\leq$ t）之间的所有元素，如果顺序表为空，则显示错误信息并退出运行。

- **C++编码实现**：

```C++
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
```

7. 设计一个算法，从有序顺序表中删除其值在给定值s与t（s $\leq$ t）之间的所有元素，如果顺序表为空，则显示错误信息并退出运行。


- **C++编码实现**：

```C++
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
```

8. 设计一个算法，将两个有序顺序表合并成一个新的有序顺序表并由函数返回结果顺序表。

- **C++编码实现**：

```C++
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
```

9. 设计一个算法，从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不相同。

- **C++编码实现**：

```C++
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
```

10. 设计一个算法，以不多于 3n/2的平均比较次数，在一个有n个整数的顺序表A中找出具有最大值和最小值的整数。

- **C++编码实现**：

```C++
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

```

11. 设$A=(a_1,a_2,\cdots,a_{n-1},a_n)$和$B=(b_1,b_2,\cdots,b_{n-1},b_n)$均为顺序表，$A^{'}$和$B^{'}$分别是除去最大公共前缀子串后的子表。如A=('b','e','i','j','i','n','g')，B=('b','e','i','f','a','n','g')，则两者的最大公共前缀为'b','e','i'，在两个顺序表中除去最大公共前缀的子表分别为A'=('j','i','n','g')，B'=('f','a','n','g')。若A'=B'=空表，则A=B；若A'=空表且B'$\neq$空表，或两者均不空且A'的第一个元素值小于B'的第一个元素的值，则A$\lt$B，否则A$\gt$B。设计一个算法根据上述方法比较A和B的大小。

- **C++编码实现**：

```C++
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
```

### 线性表的链式存储——单链表

#### 单链表的定义

**线性表的链式存储称为单链表**。

#### 单链表的特点

- 链表中每个结点所占用的存储空间是连续的，但结点之间的物理位置可以连续也可以不连续。

- 链表结点物理存储不要求连续，一般采用指针来表示各个结点之间的逻辑关系。

- 在单链表上，各个节点的访问只能是顺序访问。

- 为了实现统一跟方便管理，一般引入头结点。头结点只存放下一个结点的地址，不存放数据元素，但可以在头结点记录其他信息，比如表长等。

- 链表尾结点指针域为空（NULL或null_ptr），表示单链表收尾。单链表为空时头结点指针域为空，头结点即为尾结点。

#### 链表动态内存分配和回收

- 在C语言中，一般采用 **stdlib.h** 头文件下的 **malloc()** 函数来为链表结点分配内存。该函数的调用格式为：**ListNode \* node = (ListNode \*)malloc(sizeof(ListNode))** 。结点内存释放，一般使用 **free(node)** 函数。

- 在C++语言中，可以采用 **new** 关键字来为结点分配内存。其格式为：**ListNode \* node = new ListNode** 。结点内存释放，使用 **delete node** 语句即可。 

#### 单链表的实现

- **C++编码实现**：

```C++
#include <iostream>
using namespace std;

// 公共变量
const int INIT_SIZE = 100;
typedef int ElementType;

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

//main函数
int main(){
    testLinkList();
    return 0;
}
```

#### 疑难解答

1. **想要以O(1)的时间代价存取第i个表元素，线性表应采用顺序表还是单链表？**

>答：顺序表示具有随机存取元素的特点，因此，想要在O(1)的时间代价内完成线性表元素的访问，可以使用线性表的顺序存储——顺序表来实现线性表。

2. **在何种场合选用顺序表？何种场合选用链表？**

>答：事先无法预估线性表的大小，或者需要进行频繁插入和删除操作时，线性表的实现采用链式存储会便于线性表的扩充和降低插入，删除操作的时间开销。当线性表需要进行频繁的查找和存取操作时，采用顺序表结构可以提高查找或存取的速度。

3. **为了统一空链表和非空链表，简化链表的插入和删除操作，不必特殊考虑在首结点处的处理，需要给链表增加什么？**

>答：需要给链表增加头结点。

4. **链表的定义是一个递归的定义，其递归性体现在什么地方？如何利用链表的递归性解决问题？**

>答：链表是通过链表结点借助指针顺序链接而成的。从结构定义来看，链表指针通过链表结点定义，链表结点又是由链表指针来定义的，这种循环的递归定义决定了链表是一种递归结构。从链表的使用来看，一个链表指针指向链表的一个结点，通过链表指针可以访问该链表；链表结点的指针域又指向下一个链表的结点（可以看作一个新的链表，可以为空），通过指针的递归方式可以逐个访问链表的各个结点，直到链表结点指针域为空（链表为空）时为止。通过链表的递归关系，可以将处理n个结点的链表问题转化为处理n-1个结点的链表问题，以此类推，最终转化为处理一个结点的链表问题，从而逐步缩小访问范围，降低问题的难度。

5. **链表结点只能通过链表的表头指针才能访问，如果一个结点失去了指向它的指针，将会产生什么后果？如何在插入或删除操作中避免这种后果？**

>答：一个链表结点如果失去了指向它的指针，则该结点所在的内存单元将会无法访问，存在放在该处的链表结点也将无法访问，该存储空间无法回收，成为无用单元，即所谓的“内存泄露”。内存泄漏会导致程序在某些函数（模块）中分配的内存空间，在该函数（模块）执行结束后，占用的内存空间无法被系统回收，如果内存泄漏越来越多，会导致程序最后无内存空间可用，程序崩溃。在C/C++这种不提供垃圾回收（GC）机制的编程语言中，最忌讳内存泄漏，在编程过程中，申请的内存空间一定要在使用完毕后主动释放，确保不造成内存泄漏。在链表的插入操作中，要确保先修改插入结点的指针域，指向要插入位置的后一结点，在修改前一结点的指针域，使其指向插入结点。在链表的删除操作中，需要先用临时变量保存删除结点，在修改删除结点的前后指针，最后还要使用free()函数或者delete关键字将删除的结点内存空间释放掉。为了确保链表结点不是去指向它的指针，插入跟删除操作中修改指针指向的语句一般都是不能随意调换位置的。

6. **若p是链表指针，在链表中顺序查找不能使用p++，这是为什么？**

>答：若链表的各个节点都是存放在连续的内存单元，则完全可以使用p++来访问下一个结点。但实际上，链表的各个结点在在内存中存放不一定是连续的，因此，使用p++访问的地址，访问到的不一定是链表的结点地址。因此，在顺序访问链表结点时，要让p指向p逻辑上的下一个结点，即使用p=p->next来指向p结点逻辑上的下一个结点。

#### 顺序表相关算法

**C++语言编码实现**

1. 设计一个算法，在带头结点的单链表中寻找第i($i \geq 1$)。若找到，则返回第i个结点的地址；若找不到，则返回NULL。

- **C++语言编码实现**：

```C++

```

2. 设计一个算法，在带头结点的单链表中确定值最大的结点。

- **C++语言编码实现**：

```C++

```

3. 设计一个算法，统计带头结点的单链表中具有给定值x的所有元素数。

- **C++语言编码实现**：

```C++

```

4. 设计一个算法，根据一维数组A\[n]建立一个带头结点的单链表，使单链表中各个元素的次序与A\[n]中各元素的次序相同，要求该程序的时间复杂度为O(n)。

- **C++语言编码实现**：

```C++

```

5. 设计一个算法，在非递减有序的带头结点的单链表中删除值相同的多余结点。

- **C++语言编码实现**：

```C++

```

6. 已知L为不带头结点的单链表的表头指针，链表中存储的都是整型数据，试写出下列运算的递归算法：

    (1). 求链表中的最大整数；

    (2). 求链表结点的个数;

    (3). 求链表所有元素的平均值。

- **C++语言编码实现**：

```C++

```

7. 设ha和hb分别是两个带头结点的非递减有序单链表的表头指针，设计一个算法，将这个两个有序链表合并成一个非递增的单链表。要求结果链表仍使用原来两个链表的存储空间，不另外占用其他的存储空间。表中允许出现重复的数据。

- **C++语言编码实现**：

```C++

```

8. 设有一个表头指针为h的单链表。设计一个算法，通过一次遍历，将链表中的所有结点的指针的链接方向逆转。

- **C++语言编码实现**：

```C++

```

9. 设在一个带头结点的单链表中所有元素结点的数据值按递增顺序排列，设计一个算法，删除所有大于min且小于max的元素结点（若存在）。

- **C++语言编码实现**：

```C++

```

10. 根据一个结点数据为整型的单链表创建两个单链表，使得第一个单链表中包含原单链表中所有数值为奇数的结点，第二个单链表中包含原单链表中所有数据为偶数的结点，原有单链表保持不变。

- **C++语言编码实现**：

```C++

```

11. 已知一个带头结点的单链表中包含3类字符（数字字符，字母字符和其他字符），设计一个算法，构造3个新的单链表，使得每个单链表中只包含同一类字符。要求使用原来的空间，表头结点可以另辟空间。

- **C++语言编码实现**：

```C++

```

### 理解线性表存储结构的要点

1. 顺序表的表元素是相继存放的，元素之间没有间隔。顺序表一般采用数组来实现，但一维数组并不等同于顺序表，两者最主要的区别是顺序表位置从1开始，而一维数组是从0开始，且一维数组元素存放不要求相继，即两个元素之间可以允许有多个空位。

2. 带头结点的单链表从头结点开始，若表空，则头结点指针域为空。单链表最后一个结点称为尾结点，尾结点指针域始终为空指针。当单链表为空时，头结点与尾结点重合。

3. 从元素访问的方式来看，顺序表一个从前往后或从后往前顺序访问，也可以根据索引位置直接访问。单链表只能从头结点依次顺序访问（存取）。

4. 从元素物理存储顺序来看，顺序表逻辑上相邻的两个元素，其物理位置也相邻，单链表逻辑上相邻的两个元素，其物理位置不要求相邻。

5. 从存储空间利用率来看，若定义存储密度=表中数据元素占用的存储空间/分配给表的总空间，则顺序表的存储密度为1，而单链表的存储密度小于1。这是因为单链表每个结点不仅存放数据元素，还包括表述逻辑关系的指针。

6. 从查找速度来看，单链表只能根据头结点一次逐个访问每个结点，而顺序表支持随机存储。因此，查找效率，顺序表要比单链表要高。

7. 从插入跟删除操作来看，顺序表插入时，需要为移动其他元素的位置，为插入位置的元素腾出空位，才能执行插入操作。删除操作时，当元素被删除后，要移动删除位置的元素将空位补齐，保证顺序表元素之间的相继存放特点。而单链表的插入跟删除只需要修改插入跟删除位置的结点指针即可。因此，插入跟删除操作，单链表速度要比顺序表快。

8. 从表的灵活性来看。顺序表若采用静态分配内从的方法，则当顺序表占满后，无法再进行插入元素的操作。采用动态分配存储空间的顺序表，在顺序表满时，可以再重新分配内存空间，达到顺序表扩容的目的。但是，扩容过程中，需要移动大量元素，操作效率较低。而单链表的结点空间只在需要的时候才申请，且每个结点的存储不要求物理位置相邻，因此，理论上，只要内从空间无限，单链表的长度也是无限的。

### 线性链表的其他变形

#### 单循环链表

1. **单循环链表的定义**：单循环链表是指单链表的最后一个结点（尾结点）指向头结点（第一个结点）。

2. **单循环链表的结构定义**：

```C++
typedef int ElementType;

// 与单链表结构一致，只是最后一个结点指针再为NULL(null_ptr)，而是指向头结点
struct CircleListNode{
    ElementType data;
    CircleListNode * next;
};
```

3. **单循环链表的特点**：

    - 在单循环链表上可以周而复始地访问所有结点；

    - 在做链表合并和分裂时，如果不是必须从头结点开始，则可以直接在链表指针处合并，时间复杂度可达到O(1)。

#### 双向链表

1. **双向链表的定义**：双向链表是指链表的每个结点包含两个指针域，分别指向它的前驱结点跟后继结点。双向链表可同时在两个方向上遍历元素。

2. **双向链表的结构定义**：

```C++
typedef int ElementType;

struct CircleListNode{
    ElementType data;
    CircleListNode * leftLink;
    CircleListNode * rightLink;
};
```

3. **双向链表的特点**：

    - 从某个结点出发可以访问直接前驱结点或直接后继结点，其时间复杂度为O(1)；

    - 查找第i个结点，向第i个结点插入元素或者删除第i个结点，都要区分从哪个方向；

    - 双向循环链表，修改指针要同时考虑前驱环链和后继环链上的修改；

    - 某个结点的直接前驱的直接后继，或该结点的直接后继的直接前驱结点即为该结点本身。

#### 静态链表

1. **静态链表的定义**：静态链表是指借助数组来描述线性表的链式存储结构。

2. **静态链表的结构定义**：

```C++
const int DefaultSize = 128;
typedef int ElementType;

struct StaticListNode{
    ElementType data;
    StaticListNode *next;
};

typedef StaticListLinkNode StaticLinkList[DefaultSize];
```

3. **静态链表的特点**：

    - 静态链表采用一维数组存储链表元素，每个数组元素表示链表的一个结点，包括数据域跟指针域；

    - 链表结点地址用数组元素的下标来表示。因此结点的后继指针域存放的是数组元素的下标；

    - 静态链表的最后一个元素结点的指针域中用“-1”来表示链表结尾。最后一个元素结点的指针域中存放“0”表示头结点。

    - 静态链表的头结点在0号下标的数组元素位置，其他结点从1号数组元素位置开始存放；

    - 存取静态链表A的第i个结点的元素的某个域，用A\[i].data或A\[i].next。如果想进入第i个结点的下一个结点，用i=A\[i].next即可。

#### 疑难解答

1. **判断一个带头结点的单循环链表L是否为空，应采用何种语句？判断一个不带头结点的循环链表是否为空，应采用何种语句？**

>答：带头结点的单循环链表，判空可用：L->next == L 语句；不带头结点的循环链表判空可用：L == NULL 语句。

2. **想以O(1)的时间代价将两个链表连起来，可采用何种链表结构？**

>答：采用单循环链表结构。设两个单链表的表头指针为分别为L1，L2，则连接的语句为：
>
>LinkNode *p = L2->next;
>l2->next = l1->next;
>L1->next = p;

3. **想要以O(1)的时间代价访问第i个表元素的直接前驱/直接后继，应采用何种链表结构？**

>答：应采用双向链表结构。

4. **想要以O(1)的时间代价删除链表指针p所指的结点，可采用何种链表结构？**

>答：可以采用单循环链表或者带头结点或者循环的双向链表。
>单循环链表实现语句为：
>q = p -> next;
>p -> data = q -> data;
>p -> next = q -> next;
>delete q;
>带头结点或者循环双向链表实现语句为：
>p -> lLink -> rLink = p -> rLink;
>p -> rLink -> lLink = p -> lLink;
>delete p;

5. **线性表的特征是除了第一个元素其他的每个元素都有唯一一个直接前驱，除最后一个元素外，每个元素都有唯一一个直接后继。而单循环链表的每个元素都有直接前驱和直接后继，双向循环链表的每个元素都有一个直接前驱和直接后继，它们还是线性表吗？**

>答：线性表是逻辑结构，而单循环链表和双向循环链表都是存储结构，是线性表的特殊存储方式。线性结构跟逻辑结构属于不同层次的范畴。因此，单循环链表跟循环双向链表都不是线性表.

6. **在数据移动代价比较高的场合,使用静态链表是否更节省时间?**

>答:相比较顺序表,使用静态链表更节省时间.

#### 单循环链表，双向链表，静态链表的相关算法

1. 设计一个算法,将一个带头结点的单循环链表中所有结点的链接方向逆转。

- **C++语言编码实现**：

```C++

```

2. 设有一个带头结点的非空双向循环链表L，指针p指向链表中第一个元素值为x的结点，设计一个算法，从链表中删除*p结点。

- **C++语言编码实现**：

```C++

```

3. 设计一个算法，逆转带头结点的双向循环链表中所有结点的链接方向。

- **C++语言编码实现**：

```C++

```

4. 设计一个算法，改造一个带头结点的双向链表，所有结点的原有次序保持在各结点的rLink域中，而lLink域把所有结点按照其值从小到大的顺序链接起来。

- **C++语言编码实现**：

```C++

```

5. 设以带头结点的双向循环链表表示线性表L=（$a_1,a_2,\cdots ,a_{n-1},a_n$）。设计一个时间复杂度为O(n)的算法，将L改造为L=（$a_1,a_3,\cdots ,a_n, \cdots ,a_4,a_2$）。

- **C++语言编码实现**：

```C++

```

6. 设计一个实现下属要求的Locate运算函数。设有一个带头结点双向链表L，每个结点有4个数据成员：指向前驱结点的指针lLink，指向后继节点的指针rLink，存放数据的成员data和访问频度frequency。所有结点的frequency初始时都为0。每当在链表上进行一次Locate(x)操作时，令元素值x结点的访问频度frequency加1，并将该结点前移，链接到与它的访问频度相等的结点后面，使得链表中所有结点保持按访问品读递减的顺序排列，以使频繁访问的结点总是靠近表头。

- **C++语言编码实现**：

```C++

```

### 线性表的应用

#### 用线性表表示集合

#### 用线性表实现一元多项式

#### 疑难解答

1. **整数集合，字符集合和字符串集合都有顺序吗？它们如何相互比较？**

>答：整数集合，字符集合和字符串集合都有一个自然的线性顺序。整数可以根据其值大小直接比较。字符跟字符串可以根据其对应的内码（ASCII）进行比较大小。

2. **指针集合有顺序吗？**

>答：指针集合有顺序。一般指针集合是存放在一个线性序列中，根据这些指针在序列中的位置，它们有一个线性顺序。对于按照非线性（如树或图）方式组合的指针集合，可以根据某种遍历算法将它们转化为一种线性顺序。

3. **用（01）向量实现集合的适用范围是什么？**

>答：（01）向量实现集合可适用于又穷集合。当集合元素的个数n不太大时，可以将一个线性序列中的集合元素按照元素名次映射到（01）向量上去。

4. **用有序链表实现集合的适用范围是什么？**

>答：有序链表实现的集合，集合元素的个数可以增长。理论上只要内存容量足够多（无限），集合元素也可以足够多（无限）。

5. **为什么一元多项式常采用链表方式存储？**

>答：因为一元多项式的非0系数项经过运算可能系数可能会变成0，当出现0系数项时，需要在结果多项式中添加或删除一些项。利用链表存储多项式，由于链表结点的新增跟删除非常简单，在O(1)的时间代价内就可完成插入或删除的相关操作，因此采用链表方式存储一元多项式，效率比较高。

#### 线性表的应用相关算法

1. 设n个人围坐在圆桌周围，现在从第s个人开始报数，报到第m个人让他出局；然后从出局者的下一个人开始从新报数，数到第m个人，再让他出局....如此反复，直到所有的人全部出局为止。对于任意给定的n,s,m,求出这n个人的出局序列。以n=9,s=1,m=5为例验证。

    （1）. 若用整数序列1，2，3，...，n表示顺序围坐在圆桌周围的人，设计一个算法用一维数组表示作为求解过程中使用的数据结构，解决上述问题。

    （2）. 采用带头结点的单循环链表作为求解过程中使用的数据结构，设计一个算法，解决上述问题。

    （3）. 采用带头结点的双向循环链表作为求解过程中使用的数据结构，设计一个算法，解决上述问题。

- **C++语言编码实现**：

```C++

```

2. 设计一个算法，求两个用（01）向量表示的集合A和集合B的并，通过第3个用（01）向量表示的集合C返回运算结果，A和B的原有内容保持不变。

- **C++语言编码实现**：

```C++

```

3. 设计一个算法，求两个用（01）向量表示的集合A和集合B的交，通过第3个用（01）向量表示的集合C返回运算结果，A和B的原有内容保持不变。

- **C++语言编码实现**：

```C++

```

4. 设计一个算法，求两个用（01）向量表示的集合A和集合B的差，通过第3个用（01）向量表示的集合C返回运算结果，A和B的原有内容保持不变。

- **C++语言编码实现**：

```C++

```

5. 设计一个算法，求两个用有序链表表示的集合A和集合B的并，通过第3个用有序链表表示的集合C返回运算结果，A和B的原有内容保持不变。

- **C++语言编码实现**：

```C++

```

6. 设计一个算法，求两个用有序链表表示的集合A和集合B的交，通过第3个用有序链表表示的集合C返回运算结果，A和B的原有内容保持不变。

- **C++语言编码实现**：

```C++

```

7. 设计一个算法，求两个用有序链表表示的集合A和集合B的差，通过第3个用有序链表表示的集合C返回运算结果，A和B的原有内容保持不变。

- **C++语言编码实现**：

```C++

```

8. 若采用数组来存储一元多项式的系数，即用数组的第i个元素存放多项式的第i次幂项的系数，如对于一元多项式 $f(x) = 6x^6 + 7x^4 - 10x^2 + 5x +3$。设计两个算法，分别求一元多项式的和跟乘积。

- **C++语言编码实现**：

```C++

```

9. 设计一个算法，输入一元多项式的系数跟指数，按照指数降幂的方式建立多项式链表。如果输入的指数与链表中已有的某一项的指数相等，则新的项不加入，并报告作废信息。整个输入序列以输入系数为0标志结束。

- **C++语言编码实现**：

```C++

```

10. 设对于一个一元多项式 $P(x) = a_{m-1}x^{e_{m-1}} + a_{m-2}x^{e_{m-2}} + \cdots + a_{0}x^{e_{0}}$ ，用表长为m的带有头结点的单链表表示为 $(t_{m-1} , t_{m-2} , \cdots , t_1, t_0)$ 。其中，m是多项式 $P(x)$ 中非0项的个数，每一个 $t_i(0 \leq t_i \leq m-1)$ 是 $P(x)$ 的一个非0项，各个项按指数 $e_i$ 递减顺序排列： $e_{m-1} \gt e_{m-2} \gt \cdots \gt e_0 \gt 0$ 。
    
    （1）. 设计一个一元多项式插入新项的算法Insert。该算法的功能是：如果多项式中没有与新项指数相等的项，则将此项插入到多项式链表的适当位置；如果多项式中已有与新项指数相同的项，则将它们合并。

    （2）. 利用（1）中的插入算法，设计一个实现一元多项式乘法的算法。

- **C++语言编码实现**：

```C++

```

11. 设计一个算法，按照降幂的次序输出一个一元多项式。

- **C++语言编码实现**：

```C++

```

12. 用带头结点的单链表表示一个一元多项式，链表中的结点按幂指数降序链接。设计一个算法，将表示一元多项式的单链表就地逆置，改为按幂指数升序链接。

- **C++语言编码实现**：

```C++

```

13. 用带头结点的单链表表示一个一元多项式，试设计一个算法，计算多项式A在x处的值。

- **C++语言编码实现**：

```C++

```

14. 类似用数组表示一元多项式，可用二维数组A表示二元多项式，数组元素A\[i]\[j]表示多项式中 $x^i$ 和 $y^j$ 的系数。试设计一个算法，把用二维数组表示的二元多项式以常规多项式的形式按升幂顺序输出。对于多项式的每一项 $c_kx^iy^j$ 可以打印成 $c_k$x^iy^j ，其中 $c_k$ ，i 和 j用实际值输出。当 $c_k$ ， i ， j 的值为1时，可以不显示 $c_k$ ，i ， j ，^ 。

- **C++语言编码实现**：

```C++

```