#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int g[17][17];
int book[17][17];
vector<pii> v;
int n,m;
int startx,starty,endx,endy;
int flag = 0;

void dfs(int row,int col){
	if(row == endx && col == endy){
		flag = 1;
		for(int i = 0; i < (int)v.size()-1;i++){
			printf("(%d,%d)->",v[i].first,v[i].second);
		}
		printf("(%d,%d)\n",v[v.size()-1].first,v[v.size()-1].second);
		return;
	}

	for(int i = -1; i <= 1; i++){
		for(int j = -1; j <= 1; j++){
			if((i-j)!=0 && (i+j)!=0 && book[row+i][col+j] != 1 && g[row+i][col+j] != 0){
				book[row+i][col+j] = 1;
				v.push_back(make_pair(row+i,col+j));
				dfs(row+i,col+j);
				book[row+i][col+j] = 0;
				v.pop_back();
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d",&g[i][j]);
		}
	}

	cin>>startx>>starty;
	cin>>endx>>endy;
	v.push_back(make_pair(startx,starty));
	book[startx][starty] = 1;
	dfs(startx,starty);
	book[startx][starty] = 0;
	if(flag == 0){
		cout<<"-1"<<endl;
	}
	return 0;
}