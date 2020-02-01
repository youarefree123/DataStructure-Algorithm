#include <bits/stdc++.h>
using namespace std;
int check[21];
int Stack[21];
int n,r;

void dfs(int index){ //已经考虑到前index个位置了
	if(index == r){
		for(int i = 0; i < index; i++){
			printf("%d ",Stack[i]);
		}
		printf("\n");
		return;
	}

	for(int i = 1; i <= n; i++){
		if(check[i] != 1 && Stack[index-1] < i){
			Stack[index] = i;
			check[i] = 1;
			dfs(index+1);
			check[i] = 0;
		}
	}
}  


int main(int argc, char const *argv[])
{
	cin>>n>>r;
	dfs(0);
	return 0;
}