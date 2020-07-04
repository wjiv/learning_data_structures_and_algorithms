/*单链表：
    线性表的链式存储又称单链表；
    头指针：头指针用来表示一个单链表，头指针为NULL时表示链表为空。
    头结点：为了方便操作，在单链表的第一个结点之前附加一个结点，称之为头结点，头结点只包含指针域。
    单链表的特点是：对于链表，逻辑上相邻的元素其物理存储不要求相邻，即链表中的元素是离散分布在存储单元中的。因此链表是非随机存取的存储结构。
                在链表中，每个结点的指针都指向其逻辑顺序的后一个元素的地址。                    
    下面是以顺序表的 C++ 实现 
*/

#include <iostream>
using namespace std;

typedef int ElementType;

struct ListNode
{
    ElementType data;
    ListNode *next;
};

struct LinkList{
    ListNode *head;
    void create();
    void insertFront();
    void insertBack();
    void deleteElement();
    void find();
    void update();
    void getLength();
};

int main()
{
    return 0;
}