// #include <bits/stdc++.h>
// using namespace std;

// struct Node
// {
// 	int data; //并查集的每个结点
// };
// map<Node, Node> fatherMap; //key:child value:father
// map<Node,int> sizeMap;//每个结点他所在的集合有多少结点

// bool operator!=(const Node& a, const Node& b){
// 	return a.data!= b.data;
// }

// void makeSets(vector<Node> v){
// 	fatherMap.clear();
// 	sizeMap.clear();
// 	for(Node it : v){
// 		fatherMap[it] = *it; //标记一下
// 		sizeMap[it] = 1;
// 	}
// }
 
// Node findHead(Node node){ //找寻父节点,并扁平化
// 	Node father = fatherMap.find(node).second;
// 	if(father != node)
// 		father = findHead(father); //递归查找父节点
// 	fatherMap[node] = father; //更新node结点的父节点
// 	return father; //father作为返回值更新一路上所有的结点
// }

// bool isSameSet(Node a, Node b){ //查操作
// 	return !(findHead(a) != findHead(b));
// }
// void Union(Node a, Node b){ //并操作
// 	if(a == NULL ||  b == NULL)
// 		return;
// 	Node aHead = findHead(a);
// 	Node bHead = findHead(b);
// 	if(aHead != bHead){ //如果两个节点不在同一集合
// 		int aSetsize = sizeMap.find(a).second;
// 		int bSetsize = sizeMap.find(b).second;
// 		if(aSetsize <= bSetsize){ //大的合并小的
// 			fatherMap[aHead] = bHead;
// 			sizeMap[bHead] = aSetsize+bSetsize;
// 		}
// 		else{
// 			fatherMap[bHead] = aHead;
// 			sizeMap[aHead] = aSetsize+bSetsize;
// 		}
// 	}

// }


#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

struct Node {
	int data;		// whatever type u want
	Node(int x) : data(x) { } //构造函数
	Node() : data(0) { } //构造函数
	friend bool operator!=(const Node &a, const Node &b) { return (a.data != b.data); }
	friend bool operator==(const Node &a, const Node &b) { return (a.data == b.data); }
	friend bool operator<(const Node &a, const Node &b) { return (a.data < b.data); }
};

class UnionFindSet {
public:
	UnionFindSet(const vector<Node> &Nodes) {
		makeSet(Nodes);	// 注意：不应有重复的node
	}

	bool isInSameSet(const Node &a, const Node &b) {
		return (findRootUnRecur(a) == findRootUnRecur(b));
	}

	void Union(const Node &a, const Node &b) {
		Node rootA = findRootUnRecur(a);
		Node rootB = findRootUnRecur(b);
		if (rootA != rootB) {
			int sizeA = sizeMap[rootA];
			int sizeB = sizeMap[rootB];
			if (sizeA <= sizeB) {
				fatherMap[rootA] = rootB;
				sizeMap[rootB] = (sizeA + sizeB);
			}
			else {
				fatherMap[rootB] = rootA;
				sizeMap[rootA] = (sizeA + sizeB);
			}
		}
	}

private:
	void makeSet(const vector<Node> &Nodes) {
		fatherMap.clear();
		sizeMap.clear();
		for (auto node : Nodes) {
			fatherMap[node] = node;
			sizeMap[node] = 1;
		}
	}

	Node findRootRecur(Node node) { //递归版找根节点
		Node father = fatherMap[node];
		if (father != node) {
			father = findRootRecur(father);
		}
		fatherMap[node] = father;
		return father;
	}

	Node findRootUnRecur(Node node) { //非递归版找根节点
		stack<Node> stk;
		Node cur = node;
		Node parent = fatherMap[cur];
		while (cur != parent) {
			stk.push(cur);
			cur = parent;
			parent = fatherMap[cur];
		}
		while (!stk.empty()) {
			fatherMap[stk.top()] = parent;
			stk.pop();
		}
		return parent;
	}

	map<Node, Node> fatherMap; // key ：child， value ：parent
	map<Node, int> sizeMap;	// key ：当前结点， value ：当前结点所在的集合一共有多少个结点
};

int main() {
	const int N = 5;
	vector<Node> Nodes = { Node(1), Node(2), Node(3), Node(4), Node(5) };
	UnionFindSet disjoin_set(Nodes);

	int a, b, cnt = 0;
	cout << "开始查询：请输入元素A和元素B：";
	while (cin >> a >> b) {
		if (disjoin_set.isInSameSet(a, b))
			cout << "元素a - " << a << ", 元素b - " << b << "：在同一个集合中\n";
		else
			cout << "元素a - " << a << ", 元素b - " << b << "：不在同一个集合中\n";
		if (cnt++ > 2)
			break;
		cout << "\n开始查询：请输入元素A和元素B：";
	}

	cnt = 0;
	cout << "\n开始合并：请输入合并元素A和元素B：";
	while (cin >> a >> b) {
		disjoin_set.Union(a, b);
		cout << "元素a - " << a << ", 元素b - " << b << "：所在集合已合并\n";
		if (cnt++ > 1)
			break;
		cout << "\n开始合并：请输入元素A和元素B：";
	}

	cnt = 0;
	cout << "\n开始查询：请输入元素A和元素B：";
	while (cin >> a >> b) {
		if (disjoin_set.isInSameSet(a, b))
			cout << "元素a - " << a << ", 元素b - " << b << "：在同一个集合中\n";
		else
			cout << "元素a - " << a << ", 元素b - " << b << "：不在同一个集合中\n";
		if (cnt++ > 3)
			break;
		cout << "\n开始查询：请输入元素A和元素B：";
	}

	return 0;
}
