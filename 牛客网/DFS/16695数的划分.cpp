#include <bits/stdc++.h>
using namespace std;

int key[7];
int n,k;
int remaining; //剩余量
int ans = 0;

void dfs(int index , int re){ //考虑第index位，剩余量为re
	if(index > k && re != 0)
		return;
	if(index > k && re == 0){ //已经考虑到第n位并且剩余量为0
		ans++;
		return;
	}

	for(int i = key[index-1] ; i <= re; i++){ //以字典序排列
		re -= i;
		key[index] = i;
		dfs(index+1,re);
		re += i;
	}
}

int main(int argc, char const *argv[])
{
	key[0] = 1; //特化
	cin>>n>>k;
	remaining = n;
	dfs(1,remaining);
	cout<<ans<<endl;
	return 0;
}
