
/*
 *牛客
 *遍历每一层，每一层都做一次直方图的底边，可以遍历所有直方图，然后跑一边最大直方图
 *时间复杂度O(N*M)
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int q[N];
stack<long long> st; //单调栈 
int n,m;
int left = -1;
int cur;
long long maxm = 0;

long long getLineMax(){
	for(int i = 0; i < m; i++){
		while(!st.empty() &&q[i] <= q[st.top()]){
		//如果非空并且cur小于等于栈顶
		int cur = st.top(); //当前结算的值
		st.pop();
		int left = st.empty()?-1: st.top();//左边界
		maxm = max(maxm,(long long)(i-left-1)*q[cur]);
	}
	st.push(i); //满足单调栈条件，或者栈是空，，或者完成操作，直接压入
	}
	while(!st.empty()){ //将剩下来的的元素弹出
		int cur = st.top();
		st.pop();
		int left = st.empty() ? -1 : st.top();
		maxm = max(maxm,(long long)(m-left-1)*q[cur]); //右边没有比他小的了，直接从右边界开始算
	}
	return maxm;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	int tmp = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0;j < m; j++){ //每一层遍历，遍历完以后跑一次最大直方图
			if(i != 0){
				scanf("%d",&tmp);
				q[j] = tmp == 0 ? 0:q[j]+1;
			}
			else
				scanf("%d",&q[j]);
		}
		// for(int i = 0; i < m ;i++)
		// 	cout<<q[i]<<" ";
		// cout<<endl;
		maxm = max(maxm,getLineMax()); //每次都跑一遍,得到以该层为底的所有直方图中的最大的
	}
	cout<<maxm<<endl;
	return 0;
}

