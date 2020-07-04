/*单链表：
    线性表的链式存储又称单链表；
    头指针：头指针用来表示一个单链表，头指针为NULL时表示链表为空。
    头结点：为了方便操作，在单链表的第一个结点之前附加一个结点，称之为头结点，头结点只包含指针域。
    单链表的特点是：对于链表，逻辑上相邻的元素其物理存储不要求相邻，即链表中的元素是离散分布在存储单元中的。因此链表是非随机存取的存储结构。
                在链表中，每个结点的指针都指向其逻辑顺序的后一个元素的地址。                    
    下面是以单链表的 C++ 实现 
*/

#include <iostream>
using namespace std;

typedef int ElementType;

struct ListNode
{
    ElementType data;
    ListNode *next;
};

struct LinkList
{
    ListNode *head;
    ListNode *tail;
    int count;
    void create();
    void insertFront(ElementType element);
    void insertBack(ElementType element);
    void removeElement(ElementType element);
    void deleteElement(int index);
    void find();
    void update();
    void getLength();
    void print();
};

void LinkList::create()
{
    head = new ListNode;
    head->next = nullptr;
    tail == NULL;
    count = 0;
}

void LinkList::insertFront(ElementType element)
{
    ListNode *list_node = new ListNode;
    list_node->data = element;
    list_node->next = head->next;
    head->next = list_node;
    if (count == 0)
        tail = list_node;
    count++;
}

void LinkList::insertBack(ElementType element)
{
    ListNode *list_node = new ListNode;
    list_node->data = element;
    list_node->next = nullptr;
    if (tail != NULL)
    {
        tail->next = list_node;
        tail = list_node;
        count++;
    }
    else
    {
        head->next = list_node;
        tail = list_node;
        count++;
    }
}

void LinkList::deleteElement(ElementType element)
{
    ListNode *list_node = head->next;
    if (list_node->data == element)
    {
    }
}

void LinkList::print()
{
    ListNode *ptr = head;
    while (ptr->next!= nullptr)
    {
        cout << ptr->next->data << endl;
        ptr = ptr->next;
    }
    delete ptr;
}

int main()
{
    LinkList L;
    L.create();
    L.insertFront(1);
    L.insertBack(100);
    L.print();
    return 0;
}
