#include <bits/stdc++.h>
using namespace std;
//找中序的后继
struct Node
{
	Node* Parent;
	int data;
	Node* left;
	Node* right;
};

Node getSuccessorNode(Node node){ //找后继
	if(node == NULL)
		return node;
	if(node->right != NULL){
		return get
	}
}