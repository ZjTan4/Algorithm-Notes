/*
1-2 链表的反转(2018/9/22(Sa-3))
下面所给的是链表节点的结构，你的任务是写一个函数将链表反转。
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(){
            val=0;
            next=NULL;
        }
        ListNode(int x) : val(x), next(NULL) {}
        ~ListNode(){}
    };
*/
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() {
		val = 0;
		next = NULL;
	}
	ListNode(int x) : val(x), next(NULL) {}
	~ListNode() {}
};
void clear(ListNode *head)
{
	if (head == nullptr)return;
	ListNode *ptr = head;
	ListNode *pre = head;
	while (ptr != nullptr)
	{
		if (ptr->next == nullptr)
		{
			delete ptr;
			return;
		}
		else
		{
			ptr = ptr->next;
			delete pre;
			pre = ptr;
		}
	}
}
ListNode* reverseList(ListNode* head)
{
	int count = 0;
	ListNode *ptr = head;
	while (ptr!=nullptr)
	{
		count++;
		ptr = ptr->next;
	}
	ptr = head;
	int *result = new int[count];
	for (int i = 0; i < count; i++)
	{
		result[i] = ptr->val;
		ptr = ptr->next;
	}
	ListNode *newHead = new ListNode(result[count - 1]);
	ptr = newHead;
	for (int i = count-2; i >= 0 ; i--)
	{
		ListNode *temp = new ListNode(result[i]);
		ptr->next = temp;
		ptr = ptr->next;
	}
	clear(head);
	delete[] result;
	return newHead;
}

int main()
{
	ListNode *head = new ListNode(0);
	ListNode *p1 = head->next = new ListNode(1);
	for (int i = 0; i < 10; i++)
	{
		ListNode *ptr = new ListNode(i + 2);
		p1->next = ptr;
		p1 = p1->next;
	}
	ListNode *newHead = reverseList(head);
	p1 = newHead;
	while (p1 != NULL)
	{
		cout << p1->val << endl;
		p1 = p1->next;
	}
	clear(newHead);
}