#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* lChild;
	node* rChild;

};
typedef struct node *Node;


node* newnode(int v){
	node* n = new node;
	n->data = v;
	n->lChild = NULL;
	n->rChild = NULL;
	return n;
}

void Search(node* root ,int x ,int newData){ //查找结点，并替换
	if(root == NULL)
		return;
	if(root->data == x){
		root->data = newData;
		return;
	}
	Search(root->lChild,x,newData);
	Search(root->rChild,x,newData);
}

void insert(node* &root ,int v){ //注意：因为构造新结点我单独写了一个函数，所以需要返回root的引用
	if(root == NULL){
		root = newnode(v);
		return;
	}
	if(v < root->data){
		insert(root->lChild,v);
	}
	else{
		insert(root->rChild,v);
	}
}

void pre(node* root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	pre(root->lChild);
	pre(root->rChild);
}




int main(int argc, char const *argv[])
{
	int tmp;
	node* bt = NULL;
	for(int i = 0; i < 10; i++){
		cin>>tmp;
		insert(bt,tmp);
	}
	pre(bt);
	return 0;
}
