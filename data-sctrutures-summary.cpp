/*数据结构绪论常见算法实现：*/
#include <iostream>
#include <cmath>
using namespace std;

//递推计算阶乘
double RecursiveCalculateFactorial(double x)
{
    float s = 1.0;
    float t = 1.0;
    int n = 1;
    while (fabs(t) > 1e-6)
    {
        t = t * x / n;
        s = s + t;
        n++;
    }
    return s;
}

//“百钱买百鸡”问题
void HundredChickensWithHundredDollars()
{
    for (int x = 0; x <= 100; x++)
    {
        for (int y = 0; y <= 100; y++)
        {
            for (int z = 0; z <= 100; z++)
            {
                if (x + y + z == 100 && 5 * x + 3 * y + z / 3 == 100)
                {
                    cout << "公鸡数：" << x << " ；母鸡数：" << y << " ；小鸡数：" << z << endl;
                }
            }
        }
    }
}

//递归正向打印数组元素
void PrintArrayElementsForwardRecursively(int *arr, int length, int index)
{
    if (index >= length)
        return;
    if (index != 0)
        cout << " ";
    else
        cout << endl;
    cout << arr[index];
    PrintArrayElementsForwardRecursively(arr, length, index + 1);
}

//递归反向打印数组元素
void PrintArrayElementsBackwardRecursively(int *arr, int length, int index)
{
    if (index >= length)
        return;
    PrintArrayElementsBackwardRecursively(arr, length, index + 1);
    if (index != length - 1)
        cout << " ";
    else
        cout << endl;
    cout << arr[index];
}

//main函数
int main()
{
    cout << RecursiveCalculateFactorial(1) << endl;

    HundredChickensWithHundredDollars();

    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    PrintArrayElementsForwardRecursively(arr, 10, 0);

    PrintArrayElementsBackwardRecursively(arr, 10, 0);

    return 0;
}