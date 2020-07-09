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

        答：如果一个集合中每个元素都有且仅有一个直接前驱，有且仅有一个直接后继，它不是线性表，因为不满足线性表的逻辑结构特点。循环链表是一种存储结构，而线性表是逻辑结构，因此，循环链表不是线性表。

2. 如果一个元素集合中有一个元素仅有一个直接后继而没有直接前驱，另一个元素只有一个直接前驱而没有直接后继，其他元素都仅有一个直接前驱和直接后继，但其中各个元素可能数据类型不同，该元素集合是线性表吗？

        答：该元素集合是线性表。对于不同的类型的元素可以使用Union来构造定义，保相同存储空间大小即可。

3. 如果有n个（n$\geq$0）元素的序列构成一个表，且每个数据元素有不可再分的数据元素，又有可再分的子表，它是线性表吗？如果不是，它又是什么表？什么条件下才能称为线性表？

        答：它不是线性表，而是广义表，仅当表中所有元素都为不可能再分的数据元素时才称为线性表。

4. 如果一个一维整数数组有n个数据元素，它是线性表吗？二维数组可视为一维数组的一维数组，那么二维数组是线性表吗？为什么？

        答：数组由于其特殊性，可以认为是逻辑结构，也可以认为是存储结构。因此，一维数组是线性表。二维数组不是线性表，因为二维数组在逻辑上最多有两个直接前驱和两个直接后继。

5. 可以为线性表定义查找，插入，删除等操作吗？如何实现？

        答：可以为线性表定义这些操作，实现方式依赖于线性表采用何种存储结构来实现。

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

//main函数
int main(){
    test();
    return 0;
}
```

#### 疑难解答

1. 线性表的顺序存储表示是一维数组吗？

        答：顺序表的实现采用了一维数组，但二者之间是有区别的：

            1. 一维数组跟顺序表都是可以随机存储的，但顺序表各个元素之间是相继存放的，而一维数组中，元素可以不相继存放。
            
            2. 一维数组只能存放元素，而顺序表可以在其上定义和实现操作。

            3. 顺序表长度是可变的，而一维数组一经分配，长度便不再改变。  

2. 顺序表可以扩充吗？如果想要扩充，应该采用何种结构？

        答：采用静态分配数组的顺序表是不可以扩充的。若想要扩充，则顺序表实现时，数组需要动态分配。在扩充时，只需要重新分配数组空间即可。

3. 线性表的每一个数据元素是否必须相同？为什么？

        答：线性表的每一个表元素占据的空间一般要求相同，对于要求每个元素类型不同，可以使用联合类型（Union）来定义顺序表的数据元素类型。

4. 对于动态分配的顺序表A，可否用SequenceList A定义后直接使用？

        答：不能直接使用，采用动态分配的顺序表，在声明变量后，必须对顺序表进行初始化操作，为顺序表分配存储空间，并置空后才能使用。

#### 相关算法

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
    return 1; //1表示删除成功
}
```

4. 设计一个算法，向顺序表中第i个位置插入一个新的元素x，如果i不合理则显示错误信息并退出运行。

- **C++编码实现**：

```C++
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
```

5. 设计一个算法，从顺序表中删除具有给定值x的所有元素。

- **C++编码实现**：

```C++

```

6. 设计一个算法，从顺序表中删除其值在给定值s与t（s $\leq$ t）之间的所有元素，如果顺序表为空，则显示错误信息并退出运行。

- **C++编码实现**：

```C++

```

7. 设计一个算法，从有序顺序表中删除其值在给定值s与t（s $\leq$ t）之间的所有元素，如果顺序表为空，则显示错误信息并退出运行。


- **C++编码实现**：

```C++

```

8. 设计一个算法，将两个有序顺序表合并成一个新的有序顺序表并由函数返回结果顺序表。

- **C++编码实现**：

```C++

```

9. 设计一个算法，从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不相同。

- **C++编码实现**：

```C++

```

10. 设计一个算法，以不多于 3n/2的平均比较次数，在一个有n个整数的顺序表A中找出具有最大值和最小值的整数。

- **C++编码实现**：

```C++

```

11. 设$A=(a_1,a_2,\cdots,a_{n-1},a_n)$和$B=(b_1,b_2,\cdots,b_{n-1},b_n)$均为顺序表，$A^{'}$和$B^{'}$分别是除去最大公共前缀子串后的子表。如A=('b','e','i','j','i','n','g')，B=('b','e','i','f','a','n','g')，则两者的最大公共前缀为'b','e','i'，在两个顺序表中除去最大公共前缀的子表分别为A'=('j','i','n','g')，B'=('f','a','n','g')。若A'=B'=空表，则A=B；若A'=空表且B'$\neq$空表，或两者均不空且A'的第一个元素值小于B'的第一个元素的值，则A$\lt$B，否则A$\gt$B。设计一个算法根据上述方法比较A和B的大小。

- **C++编码实现**：

```C++

```

### 线性表的链式存储——单链表

#### 单链表的定义

**线性表的链式存储称为单链表**。

#### 单链表的特点

- 