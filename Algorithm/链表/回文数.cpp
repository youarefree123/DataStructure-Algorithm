/*
 *判断是不是回文数，涉及到了反转链表
 */


#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char value;
	Node* next;
};

//初始化一个链表，用到了随机数
Node* init_List(){
	Node* L = (Node*)malloc(sizeof(Node));//头节点初始化
	Node* ss = L;//用于操纵的指针
	L->next = NULL;
	srand((unsigned)time(NULL));
	int n = 3+rand()%22;
	for(int i = 0; i < n; i++){
		Node* T = (Node*)malloc(sizeof(Node));//头节点初始化
		T->value = i+1; //录入数据
		T->next = NULL; //初始化结点
		ss->next = T; 
		ss = ss->next; //将新结点插入到链表最后
	}
	return L;
}

void insert(Node* L,int data){
	Node* p = L;
	while(p->next != NULL){
		p = p->next;
	}
	Node* ss = new Node;
	ss->value = data;
	ss->next = NULL;
	p->next = ss;
}

void put_List(Node* L){
	Node* s = L;
	while(s->next != NULL){
		printf("%d ",s->next->value);
		s = s->next;
	}
	printf("\n");
}

bool isPalindrome(Node* head){ //不带头节点链表
	if(head == NULL || head->next == NULL){ //如果是空结点或者结点后为空
		return true;
	}
	Node* n1 = head; //快指针
	Node* n2 = head; //慢指针
	while(n2->next != NULL && n2->next->next != NULL){ //保证快指针后面两位都存在
		n1 = n1->next; // n1->mid
		n2 = n2->next->next; // n2->end
	} 
	n2 = n1->next; //n2 指向中间值的下一位
	n1->next = NULL; //mid尾部接上NULL
	Node* n3 = NULL; //临时变量
	while(n2 != NULL){ //后半部分链表反转
		n3 = n2->next;
		n2->next = n1; //为了以后可以还原链表，否则可以直接为空
		n1 = n2; //n1 move
		n2 = n3; //n2 move
	}
	n3 = n1; // n3拿到链表尾部结点,用作最后复原链表
	n2 = head; //n2拿到头部
	bool res = true;
	while(n1 != NULL && n2 != NULL){ //比对
		if(n1->value != n2->value){
			res = false;
			break;
		}
		n1 = n1->next;
		n2 = n2->next;
	}
	n1 = n3->next; //n1拿到反转链表的最后一位
	while(n1 != NULL){ //复原链表
		n2 = n1->next;
		n1->next = n3;
		n3 = n1;
		n1 = n2;
	}
	return res;
}


int main(int argc, char const *argv[])
{
	Node* L = new Node;
	L ->next = NULL;
	insert(L,1);
	insert(L,2);
	insert(L,2);
	insert(L,1);
	put_List(L);
	cout<<isPalindrome(L->next);
	return 0;
}