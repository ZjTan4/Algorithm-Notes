/*
4-2 Intersection of two linked list
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A: a1 → a2 →c1 → c2 → c3
B: b1 → b2 → b3→c1 → c2 → c3

begin to intersect at node c1.

Notes:

If the two linked lists have no intersection at all, return null. The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure. Your code should preferably run in O(n) time and use only O(1) memory.
链表结构体定义在linkNode.h中，你只需要实现函数getIntersectionNode，
该函数的声明如下，参数为两个链表的头指针，返回值为相交处的第一个节点指针。
linkNode *getIntersectionNode(linkNode *headA, linkNode *headB);

*/
#include<iostream>

using namespace std;

 struct linkNode {
     int val;
     linkNode *next;
     linkNode(int x) : val(x), next(NULL) {}
 };

// O(n^2) method
/*
linkNode *getIntersectionNode(linkNode *headA, linkNode *headB)
{
	linkNode *ptr_a = headA;
	linkNode *ptr_b = headB;
	while (ptr_a !=NULL)
	{
    ptr_b=headB;
		while (ptr_b != NULL)
		{
			if (ptr_a==ptr_b)
			{
				return ptr_a;
			}
			ptr_b = ptr_b->next;
		}
		ptr_a = ptr_a->next;
	}
	return nullptr;
}
*/

// O(n) method
linkNode *getIntersectionNode(linkNode *headA, linkNode *headB)
{
    linkNode* ptr_a = headA;
    linkNode* ptr_b = headB;
    int count_A = 0;
    int count_B = 0;

    while(ptr_a != nullptr)
    {
        count_A++;
        ptr_a = ptr_a->next;
    }
    ptr_a = headA;

    while(ptr_b != nullptr)
    {
        count_B++;
        ptr_b = ptr_b->next;
    }
    ptr_b = headB;

    if(count_A < count_B)
    {
        int delta = count_B - count_A;
        for(int i=0;i < delta; i++)
        {
            ptr_b = ptr_b->next;
        }
    }
    else
    {
        int delta = count_A - count_B;
        for(int i=0;i < delta; i++)
        {
            ptr_a = ptr_a->next;
        }
    }

    while(ptr_a != nullptr)
    {
        if(ptr_a == ptr_b)return ptr_a;
        ptr_a = ptr_a->next;
        ptr_b = ptr_b->next;
    }

    return nullptr;
}