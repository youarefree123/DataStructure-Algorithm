/*队列的链表实现，存放int类型数据，实现对应操作：
 	1:清空 void clear();
 	2:获取队列内元素个数 int size();
 	3:判空 bool isEmpty();
 	4:入队 push();   也可以叫enqueue()
 	5:出队 pop();    也可以叫dequeue()
 	6:取队首元素 get_front();
 	7:取队尾元素 get_rear();
 	8:队列的初始化 init_Queue();
 	8:输出队列 put_Queue();
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
	int num; //队列中元素个数
	Node front; //指向队首元素的指针
	Node rear; //指向队尾元素的指针
}*queue;


/*队列的初始化*/
queue init_Queue(){
	queue q = (queue)malloc(sizeof(struct st)); //动态分配内存
	q->num = 0;
	q->front = q->rear = NULL; //起初front和rear指向同一个位置,现在同时指向空
	return q;
}

/*获取栈内元素个数*/
int size(queue q){
	return q->num;
}

/*判空*/
bool isEmpty(queue q){
	if(q->front != NULL)
		return false;
	else
		return true;
}

/*入队列*/
void push(queue q ,int d){ 
	Node tmp = (Node)malloc(sizeof(struct node));
	tmp->data = d;
	tmp->next = NULL; //初始化新结点
	if(isEmpty(q)){ //如果一开始是一个空队列
		q->rear = tmp; //rear直接指向tmp结点	
		q->front = q->rear; //front 指向rear结点
	}
	else{
		q->rear->next = tmp; //队尾结点后面加上新结点
		q->rear = q->rear->next; //队尾结点向后挪
	}
	q->num++;
}

/*出队列*/
void pop(queue q){
	if(isEmpty(q)) return; //如果队列为空，直接返回
	Node tmp = q->front; //指针tmp指向老队首
	q->front = q->front->next; //front指向下一个
	free(tmp); //释放tmp指向的空间的内存
	if(q->num > 0) q->num--;	
}

/*取队首元素*/
int get_front(queue q){
	if(isEmpty(q)) return -1; //如果队列是空的，直接返回-1
	return q->front->data;
}

/*取队尾元素*/
int get_rear(queue q){
	if(isEmpty(q)) return -1;//如果队列是空的，直接返回-1
	return q->rear->data;
}

/*清空队列*/
void clear(queue q){
	while(!isEmpty(q)){
		pop(q);
	}
}


/*输出队列*/
void put_Queue(queue q){
	printf("此时队首元素为%d，队尾元素为%d.\n",get_front(q),get_rear(q));
	printf("队列中元素为：");
	Node tmp = q->front;
	while(tmp != NULL){
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
	printf("队列中元素个数为:%d",size(q));
	printf("\n\n");
}

/*随机push或者pop一些数，并自动调用put_Queue函数*/
void Auto_Machine(queue q){
	srand((unsigned)time(NULL));
	int nums = 5+rand()%10;
	while(nums--){
		int tmp = 1+rand()%100;
		int flag = 1+rand()%25;
		if(flag == 1){
			clear(q);
			printf("进行了clear操作\n\n");
		}
		else if(flag >= 2 && flag <= 4){
			pop(q);
			printf("进行了pop操作\n");
			put_Queue(q);
		}
		else{
			push(q,tmp);
			printf("进行了push操作\n");
			put_Queue(q);
		}
		Sleep(500);
	}

}



int main()
{
	queue q = init_Queue();
	Auto_Machine(q);
	return 0;
}