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
void HundredChickensWithHundredDollars(int cockPrice, int henPrice, int chickPrice, int &cockNum, int &henNum, int &chickNum)
{
    for (cockNum = 0; cockNum <= 100; cockNum++)
    {
        for (henNum = 0; henNum <= 100; henNum++)
        {
            for (chickNum = 0; chickNum <= 100; chickNum++)
            {
                if (cockNum + henNum + chickNum == 100 && cockPrice * cockNum + henPrice * henNum + chickPrice * chickNum == 100)
                    break;
            }
        }
    }
}

//递归正向打印数组元素
void PrintArrayElementsForwardRecursively(int *arr, int length, int index)
{
    if (index >= length)
        return;
    cout << arr[index] << endl;
    PrintArrayElementsForwardRecursively(arr, length, index + 1);
}

//递归反向打印数组元素
void PrintArrayElementsBackwardRecursively(int *arr, int length, int index)
{
    if (index >= length)
        return;
    PrintArrayElementsBackwardRecursively(arr, length, index + 1);
    cout << arr[index] << endl;
}

//main函数
int main()
{
    cout << RecursiveCalculateFactorial(1) << endl;
    int cockNum = 0;
    int henNum = 0;
    int chickNum = 0;
    HundredChickensWithHundredDollars(5, 3, 1 / 3, cockNum, henNum, chickNum);
    cout << cockNum << " " << henNum << " " << chickNum << endl;
    return 0;
}