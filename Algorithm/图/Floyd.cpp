#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int n, m; //点，边
int mp[maxn][maxn];
//dp[k][i][j] :经过 1~k ， i到j的最短路
//dp[k][i][j] = min(dp[k-1][i][j] ,dp[k-1][i][K]+dp[k-1][k][j])
//表示要不要经过k点，一条是不经过k点，直接到达的边，一条是经过k的两条小边相加
//只和k有关,所以可以直接省下k

void Floyd(){
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n ; i++)
			for(int j = 0; j < n; j++)
				mp[i][j] = min(mp[i][j],mp[i][k]+ mp[k][j]);
}

int main()
{
	while(scanf("%d%d",&n,&m) != EOF){
		for(int i = 0 ; i < n; i++)
			for(int j = 0; j < n; j++)
				if(i == j)mp[i][j] = 0;//自己代价为0
				else mp[i][j] = 1e9; //其余都不可达
		for(int i = 1; i <= m ; i++){
		int x,y,z; //点x到点y, 距离为z
		scanf("%d%d%d",&x,&y,&z);
		mp[x][y] = min(z,mp[x][y]);
		mp[y][x] = min(z,mp[y][x]);
	}
	Floyd();
	int s,t; //起点，终点
	scanf("%d%d",&s,&t);
	
	if(mp[s][t] == 1e9)
		cout<<"-1"<<endl;
	else
		cout<<mp[s][t]<<endl;
	}
	return 0;
}