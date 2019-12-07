/* 
 * BT init_tree(); //初始化一个二叉树
 * void insert(); //插入结点
 * Position Find_Max(BT); //找到最大值
 * Position Find_(BT); //找到最大值
 * void PreorderTraversal_1(BT) //递归版先序遍历
 * void PreorderTraversal_2(BT) //迭代版先序遍历
 * void InorderTraversal_1(BT) //递归版中序遍历
 * void InorderTraversal_2(BT) //迭代版中序遍历
 * void PostorderTraversal_1(BT) //递归版后序遍历
 * void postorderTraversal_2(BT) //迭代版后序遍历
 * void LevelorderTraversal(BT) //层序遍历
 * int tree_deep_1(BT) // 求二叉树深度(迭代版本)
 * 
 */


#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;


typedef struct node
{
	int data;
	struct node* lchild; //左孩子
	struct node* rchild; //右孩子
}*BT;

typedef BT NODE;
typedef BT Position;

/*求二叉树深度,迭代版本*/
int tree_deep_1(BT bt){
	if(bt == NULL)
		return 0 ; 
	int left = tree_deep_1(bt->lchild);
	int right = tree_deep_1(bt->rchild);
	return left <= right ? right+1 : left+1;  
} 


/*找到树中最大元素*/
Position Find_Max(BT bt){
	if(bt != NULL){
		while(bt->rchild != NULL){
			bt = bt->rchild;
		}
	}
	return bt;
}

/*找到树中最小元素*/
Position Find_Min(BT bt){ //
	NODE tmp = bt;
	if(tmp != NULL){
		while(tmp->lchild != NULL){
			tmp = tmp->lchild;
		}
	}
	return tmp;
}

/*插入树结点*/
BT insert(BT bt , int d){
	if(bt == NULL){
		bt = (BT)malloc(sizeof(struct node));
		bt->data = d;
		bt->lchild = NULL;
		bt->rchild = NULL;

	}
	else{
		if(bt->data < d)
			bt->rchild = insert(bt->rchild,d);
		else
			bt->lchild = insert(bt->lchild,d);
	}
	return bt;
}


/*初始化一个二叉树*/
BT init_tree(){
	BT bt = NULL;
	int tmp[] = {5,3,7,2,4,6,8,1};
	for(int i = 0; i < 8 ; i++){
		bt = insert(bt,tmp[i]);
	}
	return bt;
}

 /*递归版先序遍历*/
void PreorderTraversal_1(BT bt){
	if(bt != NULL){
		printf("%d ",bt->data);
		PreorderTraversal_1(bt->lchild);
		PreorderTraversal_1(bt->rchild);
	}
	return ; 
}


 /*迭代版先序遍历：利用栈结构*/
void PreorderTraversal_2(BT bt){
	stack<BT> s;
	if(bt != NULL){
		s.push(bt);
		while(!s.empty()){
			NODE tmp = s.top();
			s.pop();
			printf("%d ",tmp->data);
			if(tmp->rchild != NULL)
				s.push(tmp->rchild);
			if(tmp->lchild != NULL)
				s.push(tmp->lchild);
		}
	}
}

 /*递归版中序遍历*/
void InorderTraversal_1(BT bt){
	if(bt != NULL){
		InorderTraversal_1(bt->lchild);
		printf("%d ",bt->data);
		InorderTraversal_1(bt->rchild);
	}
}

 /*迭代版中序遍历,利用栈结构*/
void InorderTraversal_2(BT bt){
	stack<BT> s;
	while(true){
		while(bt != NULL){
			s.push(bt);
			bt = bt->lchild;
		}
		if(s.empty()) return;
		bt = s.top();
		s.pop();
		printf("%d ",bt->data);
		bt = bt->rchild;
	}
	
}



 /*递归版后序遍历*/
void PostorderTraversal_1(BT bt){
	if(bt != NULL){
		PostorderTraversal_1(bt->lchild);
		PostorderTraversal_1(bt->rchild);
		printf("%d ",bt->data);
	}	
}

 /*迭代版后序遍历：利用栈结构，并记录最后一次访问的结点*/
void PostorderTraversal_2(BT bt){
	stack<BT> s;
	NODE last = NULL; //记录最后一次访问的结点
	while(bt != NULL || !s.empty()){
		while(bt != NULL){
			s.push(bt);
			bt = bt->lchild;
		}
			bt = s.top();
			if(bt->rchild == NULL || bt->rchild == last){ //如果此时没有右结点或者右结点是已经访问过的了
				printf("%d ",bt->data);
				s.pop();
				last = bt; //更新最后一次访问的结点
				bt = NULL; // 表示不需要转向，继续弹栈
			}
			else{
				bt = bt->rchild;
			}
		
	}
}


/*层序遍历：利用队列实现*/
void LevelorderTraversal(BT bt){
	queue<BT> q;
	if(bt != NULL)
		q.push(bt);
	while(!q.empty()){
		printf("%d ",q.front()->data);
		if(q.front()->lchild != NULL)
			q.push(q.front()->lchild);
		if(q.front()->rchild != NULL)
			q.push(q.front()->rchild);
		q.pop();
	}
	
} 




int main(int argc, char const *argv[])
{

	BT bt = init_tree();
	printf("递归先序遍历：");
	PreorderTraversal_1(bt);
	printf("\n");
	printf("迭代先序遍历：");
	PreorderTraversal_2(bt);
	printf("\n");
	printf("递归中序遍历：");
	InorderTraversal_1(bt);
	printf("\n");
	printf("迭代中序遍历：");
	InorderTraversal_2(bt);
	printf("\n");
	printf("递归后序遍历：");
	PostorderTraversal_1(bt);
	printf("\n");
	printf("迭代后序遍历：");
	PostorderTraversal_2(bt);
	printf("\n");
	printf("层序遍历：");
	LevelorderTraversal(bt);
	printf("\n");
	printf("该树深度为：%d\n",tree_deep_1(bt));
	return 0;
}