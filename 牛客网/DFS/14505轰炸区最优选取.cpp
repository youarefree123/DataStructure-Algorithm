#include <bits/stdc++.h>
using namespace std;

int g[51][51];
int n,k;
int maxm = 0;
int book[51][51];

void dfs(int x, int y){
	if(x+k > n || y+k > n)
		return;
	if(book[x][y])
		return;
	int tmp = 0;
	book[x][y] = 1;
	for(int i = x; i < x+k ; i++){
		for(int j = y; j < y+k; j++){
			tmp += g[i][j];
		}
	}
	if(tmp > maxm)
		maxm = tmp;

	dfs(x+1,y);
	dfs(x,y+1);
	dfs(x+1,y+1);

}

int main(int argc, char const *argv[])
{
	while(scanf("%d%d",&n,&k)){
		for(int i = 0; i < n ; i++){
			for (int j = 0; j < n; ++j)
			{
				scanf("%d",&g[i][j]);
			}
		}
		dfs(0,0);
		printf("%d\n",maxm);
		maxm = -1;
		memset(book,0,sizeof(book));
}
	
	return 0;
}
