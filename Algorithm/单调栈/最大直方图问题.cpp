/*
 *acwing 131
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int q[N];
stack<long long> st; //单调栈 
int n;
int left = -1;
int cur;
long long maxm = 0;
int main(int argc, char const *argv[])
{
	while(scanf("%d",&n) != EOF && n != 0){
		for(int i = 0; i < n; i++){
			scanf("%d",&q[i]);
		}
		for(int i = 0; i < n; i++){
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
		maxm = max(maxm,(long long)(n-left-1)*q[cur]); //右边没有比他小的了，直接从右边界开始算
	}
	cout<<maxm<<endl;
	maxm = 0;
	}
	return 0;
}

