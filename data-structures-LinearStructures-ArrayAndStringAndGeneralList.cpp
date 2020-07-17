// 线性表——数组和字符串完整代码

#include <iostream>
#include <cstring>

using namespace std;

typedef int ElementType;

const int MAX_SIZE = 10;

#pragma region 字符串开始

struct String
{
private:
    char *data;
    int count;
    int MAX_SIZE;

public:
    String() : data(), count(), MAX_SIZE()
    {
        data = new char[MAX_SIZE];
        count = 0;
        MAX_SIZE = MAX_SIZE;
    }
    String(int size)
    {
        data = new char[size];
        count = 0;
        MAX_SIZE = size;
    }
    int length();                      //获取字符串长度
    char &operator[](const int index); //操作符[]重载
    void operator=(char const *str);   //操作符=重载

    friend istream &operator>>(istream &in, String str)
    {
        for (int i = 0; i < str.count; i++)
        {
            in >> str.data[i];
        }
        return in;
    }

    friend ostream &operator<<(ostream &out, String str)
    {
        for (int i = 0; i < str.count; i++)
        {
            out << str[i];
        }
        return out;
    }
};

//重载[]操作符
char &String::operator[](const int index)
{
    return this->data[index];
}

//重载=操作符
void String::operator=(char const *str)
{
    int size = 0;
    while (true)
    {
        if (str[size] == '\0')
            break;
        else
            size++;
    }
    if (this->MAX_SIZE < size + 1)
    {
        this->data = new char[size + 1];
        this->MAX_SIZE = size + 1;
    }
    this->count = 0;
    while (true)
    {
        if (str[this->count] == '\0')
            break;
        else
        {
            this->data[this->count] = str[this->count];
            this->count++;
        }
    }
}

//获取字符串长度
int String::length()
{
    return this->count;
}

//字符串测试
void testString()
{
    String str;
    str = "hello world!";
    cout << str << endl;
}

#pragma endregion 字符串结束

#pragma region 数组，字符串相关算法开始

#pragma region 数组相关算法开始

/*设有一个整数序列 $（e_1,e_2,\cdots,e_n）$ 存放在一维数A\[size]中的前n个数组
    元素的位置。设计一个算法，将这个序列原地逆置，即将数组的前n个原址内容置换为 
    $（e_n,e_{n-1},\cdots,e_1）$ 。*/
void ReverseArray(int *arr, int length)
{
    if (length == 0)
        return;
    int tmp = 0;
    for (int i = 1; i <= length / 2; i++)
    {
        tmp = arr[i - 1];
        arr[i - 1] = arr[length - i];
        arr[length - i] = tmp;
    }
}

/*假设数组A\[n]中有多个0元素，编写一个算法，将A中所有非0元素依次移到数组A的前端
    A\[i] $（0 \leq i \leq n-1）$ 。*/
void MoveToNonzeroElementToFront(int *arr, int length)
{
    int index = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] != 0)
        {
            if (i != index)
            {
                arr[index] = arr[i];
                arr[i] = 0;
            }
            index++;
        }
    }
}

/*在数组A\[n]中有n个不同的元素，编写一个算法，将A中所有数值在1到n之间的整数从小
    到大排序后从0号位置起连续存入数组B\[n]中，函数返回这些整数的个数。要求算法的时间
    复杂度为O(n)。*/
void Rearrange(int *arrA, int *arrB, int length, int &count)
{
    count = 0;
    int index = 0;
    for (int i = 0; i < length; i++)
    {
        arrB[i] = 0;
    }
    for (int i = 0; i < length; i++)
    {
        if (arrA[i] >= 1 && arrA[i] <= length)
        {
            arrB[arrA[i] - 1] = arrA[i];
            count++;
        }
    }
    for (int i = 0; i < length; i++)
    {
        if (arrB[i])
        {
            if (i != index)
            {
                arrB[index] = arrB[i];
            }
            index++;
        }
    }
}

/*编写一个算法，将 一个有n个非0元素的整数一维数组A\[n]拆分为两个一维数组，使得A
    中大于0的元素存放在数组B中，小于0的元素存放在数组C中。*/
void SplitArray(int *arrA, int *arrB, int *arrC, int lengthA, int &countB, int &countC)
{
    countB = 0;
    countC = 0;
    for (int i = 0; i < lengthA; i++)
    {
        if (arrA[i] > 0)
        {
            arrB[countB] = arrA[i];
            countB++;
        }
        else
        {
            arrB[countC] = arrA[i];
            countC++;
        }
    }
}

/*给定一个一维数组A\[n]，称A中连续相等的整数构成的子序列为平台。编写一个算法，求
    出并返回A中最长平台的长度和起始地址（下标，索引，从0开始）。*/
void GetMaxLongSubSequence(int *arr, int length, int &startIndex, int &subSequenceLength)
{
    startIndex = 0;
    subSequenceLength = 0;
    int i = 0;
    int k = 0;
    int t = 0;
    while (i < length)
    {
        k = 1;
        i++;
        while (i < length && arr[i - 1] == arr[i])
        {
            k++;
            i++;
        }
        if (k > subSequenceLength)
        {
            subSequenceLength = k;
            startIndex = t;
        }
        t = i;
    }
}

/*已知一维数组A\[m+n]中依次存放着两个表 $（a_1,a_2,\cdots,a_n）$ 和 
    $（b_1,b_2,\cdots,b_n）$ 。编写一个算法，将数组中两个表的位置互换，即将
    $（b_1,b_2,\cdots,b_n）$ 放在 $（a_1,a_2,\cdots,a_n）$ 前面。*/
void ExchangeArraySequence(int *arr, int m, int n)
{
    int tmp = m + n;
    int p = m;
    int k = tmp % p;
    int i = 0;
    int j = 0;
    while (k != 0)
    {
        tmp = p;
        p = k;
        k = tmp % p;
    }
    for (k = 0; k < p; k++)
    {
        tmp = arr[k];
        i = k;
        j = (i + m) % (m + n);
        while (j != k)
        {
            arr[i] = arr[j];
            i = j;
            i = (j + m) % (m + n);
        }
        arr[i] = tmp;
    }
}

/*若矩阵 $A_{m \times n}$ 中的某一组元素A\[i]\[j]是第i行中的最小值，同时又是
    第j列的最小值，则称此元素为该矩阵的一个鞍点。假设以二维数组存放矩阵，试设计
    一个算法，找出该矩阵中鞍点在二维数组中的位置（若鞍点存在时），并给出该算法的
    时间复杂度。*/
void LocateSaddlePoint(int **arr, int m, int n)
{
    int min;
    int i;
    int j;
    int k;
    int flag;
    for (i = 0; i < m; i++)
    {
        min = 0;
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] < arr[i][min])
                min = j;
        }
        flag = 1;
        for (k = 0; k < m; k++)
        {
            if (arr[i][min] < arr[k][min])
                flag = 0;
        }
        if (flag == 1)
        {
            cout << "Saddle Point Is :(" << i << "," << min << "),Value=" << arr[i][min] << endl;
        }
    }
}

/*设整数数组B\[m+1]\[n+1]的数据在行，列方向上都是按从小到大的顺序排列，且整型变
    量x中的数据在B中存在。试设计一个算法，找出一对满足B\[i]\[j]==x的i,j的值，同
    时要求比较次数不超过m + n。*/
void FindValueEqualGiveValue(int **arr, int m, int n, int value, int &i, int &j)
{
    i = 0;
    i = n;
    while (arr[i][j] != value)
    {
        if (arr[i][j] < value)
            i++;
        else
            j--;
    }
}

/*对于一个n阶方阵，试编写一个算法，通过行变换使其按每行元素的平均值递增的顺序排列。*/
void Arrange(int **arr, int n)
{
    int sum[n];
    int add[n];
    int i, j, k, p, tmp;
    for (i = 0; i < n; i++)
    {
        sum[i] = 0;
        add[i] = i;
        for (j = 0; j < n; j++)
        {
            sum[i] = sum[i] + arr[i][j];
        }
    }
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (sum[j] < sum[k])
                k = j;
        }
        if (i != k)
        {
            tmp = sum[i];
            sum[i] = sum[k];
            sum[k] = tmp;
            tmp = add[i];
            add[i] = add[k];
            add[k] = tmp;
        }
    }
    for (i = 0; i == add[i]; i++)
        k = add[i];
    p = i;
    for (j = 0; i < n; j++)
    {
        sum[j] = arr[i][j];
    }
    while (k != p)
    {
        for (j = 0; j < n; j++)
        {
            arr[i][j] = arr[k][j];
        }
        i = k;
        k = add[k];
    }
    for (j = 0; j < n; j++)
    {
        arr[i][j] = sum[j];
    }
}

//拉丁方阵是轮回方阵的一种。试编写一个算法，构造n阶拉丁方阵。
void LatinMatrix(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j + 1 < n)
                arr[i][j] = i + j + 1;
            else
                arr[i][j] = i + j + 1 - n;
        }
    }
}

/*试编写一个算法，将自然数 $1 ~ n^2 $ 按“蛇形”填入 $n \times n$ 的矩阵中
    （蛇形矩阵）。*/
void FillNaturalNumberInSnakeMatrix(int **arr, int n)
{
    int m = 1;
    int row = 0;
    int col = 0;
    int j = 0;
    int i = 0;
    for (int k = 0; k < 2 * n - 1; k++)
    {
        if (k <= n)
            j = k;
        else
            j = 2 * n - k;
        for (i = 0; i < j; i++)
        {
            if (k <= n)
            {
                if (k % 2)
                {
                    row = k + i - 1;
                    col = i;
                }
                else
                {
                    row = i;
                    col = k - i - 1;
                }
            }
            else
            {
                row = k + i - n;
                col = k - row - 1;
            }
            arr[row][col] = m;
            m++;
        }
    }
}

/*试编写一个算法，将自然数 $1 ~ n^2 $ 按“螺旋形”填入 $n \times n$ 的矩阵中
    （螺旋矩阵）。*/
void FillNaturalNumberInSpiralMatrix(int **arr, int n)
{
    int i = 0;
    int j = 0;
    int flag = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    i = 0;
    j = 0;
    for (int m = 1; m < n * n; m++)
    {
        arr[i][j] = m;
        if (flag = 0)
        {
            if (i + 1 < n && arr[i + 1][j] == 0)
                i++;
            else
            {
                j++;
                flag = 1;
            }
        }
        if (flag = 1)
        {
            if (j + 1 < n && arr[i][j + 1] == 0)
                j++;
            else
            {
                i--;
                flag = 2;
            }
        }
        if (flag == 2)
        {
            if (i - 1 > 0 && arr[i - 1][j] == 0)
                i--;
            else
            {
                j--;
                flag = 3;
            }
        }
        if (flag == 3)
        {
            if (j - 1 > 0 && arr[i][j - 1] == 0)
                j--;
            else
            {
                i++;
                flag = 0;
            }
        }
    }
}

#pragma endregion 数组相关算法结束

#pragma region 字符串相关算法开始

//设计一个算法，统计字符串中各个不同字符出现的频度。
void GetFrequency(string str, char ch[], int freq[], int &k)
{
    if (str.length() == 0)
        return;
    ch[0] = str[0];
    freq[0] = 1;
    int tmp = 1;
    for (int i = 1; i < str.length(); i++)
    {
        ch[i] = 0;
    }
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 0; j < tmp && ch[j] != str[i]; j++)
        {
            if (j == tmp)
            {
                ch[tmp] = str[i];
                ch[tmp]++;
                tmp++;
            }
            else
                ch[j]++;
        }
    }
}

/*所谓回文串，是指从前往后读和从后往前倒着都都一样的不含空白字符的
    字符串。设计一个算法，判断一个字符串是不是回文串。*/
bool IsPalindrome(string str)
{
    int i = 0;
    int j = str.length() - 1;
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

//设计一个递归算法，将整数字符串转换为整数。
int ConvertToNumber(string str, int start, int finish)
{
    if (start > finish)
        return -1;
    if (start == finish)
        return str[finish] - '0';
    return ConvertToNumber(str, start, finish - 1) * 10 + str[finish] - '0';
}

//设有两个字符串A，B。设计一个算法，找出A中第一个不在B中出现的字符。
bool AFindFistCharWithoutAppear(string str1, string str2, char &ch)
{
    bool flag = true;
    int i;
    for (i = 0; i < str1.length(); i++)
    {
        flag = true;
        for (int j = 0; j < str2.length(); j++)
        {
            if (str1[i] == str2[j])
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        ch = str1[i];
    }
    return flag;
}

#pragma endregion 字符串相关算法结束

#pragma endregion 数组，字符串相关算法结束

//main函数
int main()
{
    testString();
    return 0;
}