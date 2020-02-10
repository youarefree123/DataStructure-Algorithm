#include<bits/stdc++.h>
using namespace std;
const int MAXM = 100001;
struct Node{
  int a;
  int b;
  double key;
};
bool cmp(Node a, Node b){
	return a.key > b.key;
}
vector<Node> item;
int T; //数据组数
int n,v; //n个物品，体积v;

void put(){
	for(int i = 0; i < (int)item.size(); i++){
		cout<<endl<<item[i].a<<" "<<item[i].b;
	}
}
int main(int argc, char const *argv[])
{
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&v);
		int tmp1,tmp2;
		for(int i = 0; i < n; i++){
			Node tmp;
			scanf("%d%d",&tmp1,&tmp2);
			tmp.a = tmp1;
			tmp.b = tmp2;
			tmp.key = ( 1.0 *tmp.b ) / tmp.a;
			item.push_back(tmp);
		}
		
		sort(item.begin(),item.end(),cmp);
		// put();
		int nums = n;
		while(nums > 0){
			int i;
			for(i = 0; i < (int)item.size() ;i++){
				if(item[i].a <= v){ //可以放得下
					v = v - item[i].a + item[i].b;
					item.erase(item.begin()+i);
					//put();
					nums--;
					break;
				}
				if(i  == (int)item.size()-1)
					nums = -1;	
			}
		}
		if(nums == 0)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}