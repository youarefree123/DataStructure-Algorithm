// 莫里斯遍历(morris traversal) ，额外空间复杂度O(1)
//线索二叉树
//细节： 如果当前节点有左孩子，找到该左子树的最右节点，如果该节点的右孩子
//指向为空，则将其指向该节点（即父节点）如果该节点指向父节点，将该节点指向空，并
//遍历父节点的左孩子
//可以直接有序 ！？ (二叉树节点满足左小右大的情况时)
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
	int data;
	node* left;
	node* right;

}*Node;

Node newnode(int v){
	Node n = new node;
	n->data = v;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void insert(Node &root ,int v){ //注意：因为构造新结点我单独写了一个函数，所以需要返回root的引用
	if(root == NULL){
		root = newnode(v);
		return;
	}
	if(v < root->data){
		insert(root->left,v);
	}
	else{
		insert(root->right,v);
	}
}

void morrisIn(Node &head){
	if(head == NULL)
		return;
	Node cur1 = head;
	Node cur2 = NULL;
	while(cur1 != NULL){
		cur2 = cur1->left; //一直往左走
		if(cur2 != NULL){
			while(cur2->right != NULL && cur2->right != cur1){
				cur2 = cur2->right; //找到当前节点的最右节点
				
			}
			if(cur2->right == NULL){ //如果为空，指向父节点
				cur2->right = cur1;
				cur1 = cur1->left;
				continue;
			}
			else{
				cur2->right = NULL; //如果指向父节点，则指向空
			}
		}
		cout<<cur1->data<<" ";
		cur1 = cur1->right; //左孩子为空（遍历过了）则遍历右边
	}
	cout<<endl;
}

// void pre(Node root){
// 	if(root == NULL)
// 		return;
// 	cout<<root->data<<" ";
// 	pre(root->left);
// 	pre(root->right);
// }

int main(int argc, char const *argv[])
{
	int tmp;
	Node bt = NULL;
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>tmp;
		insert(bt,tmp);
	}
	morrisIn(bt);
	return 0;
}