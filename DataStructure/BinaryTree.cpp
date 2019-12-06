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
 * int tree_deep(BT) // 求二叉树深度
 * 
 */


#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;


typedef struct node
{
	int data;
	struct node* lchild; //左孩子
	struct node* rchild; //右孩子
}*BT;

typedef BT NODE;
typedef BT Position;

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
		while(tmp->rchild != NULL){
			tmp = tmp->rchild;
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
	for(int i = 0 ; i < 10 ; i++){
		int tmp = i+1;
		bt = insert(bt,tmp);
		
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

 /*递归版中序遍历*/
void InorderTraversal_1(BT bt){
	if(bt != NULL){
		InorderTraversal_1(bt->lchild);
		printf("%d ",bt->data);
		InorderTraversal_1(bt->rchild);
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
	printf("先序遍历：");
	PreorderTraversal_1(bt);
	printf("\n");
	printf("中序遍历：");
	InorderTraversal_1(bt);
	printf("\n");
	printf("后序遍历：");
	PostorderTraversal_1(bt);
	printf("\n");
	printf("层序遍历：");
	LevelorderTraversal(bt);
	printf("\n");
	return 0;
}