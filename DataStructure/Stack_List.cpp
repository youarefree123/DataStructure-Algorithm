/*栈的链表实现，存放int类型数据，实现对应操作：
 	1:清空 void clear();
 	2:获取栈内元素个数 int size();
 	3:判空 bool isEmpty();
 	4:进栈 push();
 	5:出栈 pop();
 	6:取栈顶元素 top();
 	7:栈的初始化 init_Stack();
 	8:输出栈(自顶向下) put_stack();
 */

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <windows.h>

typedef struct node
{
	int data; //数据
	struct node* next; //指向后一个结点
}*Node;

typedef struct st{
	int num; //栈内元素个数
	Node Top; //栈顶
}*stack;


/*栈的初始化*/
stack init_Stack(){
	stack s = (stack)malloc(sizeof(struct st)); //动态分配内存
	s->num = 0;
	Node tmp = (Node)malloc(sizeof(struct node));
	tmp = NULL;
	s->Top = tmp;
	return s;
}

/*获取栈内元素个数*/
int size(stack s){
	return s->num;
}

/*判空*/
bool isEmpty(stack s){
	if(s->Top != NULL)
		return false;
	else
		return true;
}

/*进栈*/
void push(stack s ,int d){
	Node tmp = (Node)malloc(sizeof(struct node));
	tmp->data = d;
	tmp->next = s->Top; //新结点指向老的Top
	s->Top = tmp; //新结点成为新的Top
	s->num++;
}

/*出栈*/
void pop(stack s){
	if(s->Top == NULL) return;
	Node tmp = s->Top;
	s->Top = s->Top->next; 
	free(tmp); //释放内存
	if(s->num > 0) s->num--;
}

/*取栈顶元素*/
int top(stack s){
	return s->Top->data;
}

/*清空栈*/
void clear(stack s){
	while(!isEmpty(s)){
		pop(s);
	}
}


/*输出栈*/
void put_stack(stack s){
	printf("此时栈内元素自定向下为：");
	Node tmp = s->Top;
	while(tmp != NULL){
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
	printf("元素个数为：%d\n",size(s));
	printf("\n\n");
}

/*随机push或者pop一些数，并自动调用put_stack函数*/
void Auto_Machine(stack s){
	srand((unsigned)time(NULL));
	int nums = 5+rand()%10;
	while(nums--){
		int tmp = 1+rand()%100;
		int flag = 1+rand()%25;
		if(flag == 1){
			clear(s);
			printf("进行了clear操作\n\n");
		}
		
		else if(flag >= 2 && flag <= 4){
			pop(s);
			printf("进行了pop操作\n");
			put_stack(s);
		}
		else{
			push(s,tmp);
			printf("进行了push操作\n");
			put_stack(s);
		}
		Sleep(1000);
	}

}



int main()
{
	stack s = init_Stack();
	Auto_Machine(s);
	return 0;
}