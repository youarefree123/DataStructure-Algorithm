#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n,m;
int q[N];

int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++) scanf("%d",&q[i]);
	while(m--){
		int x = 0;
		scanf("%d",&x);
		int l = 0; int r = n-1;
		while(l < r){ // 先找开始位
			int mid = (l+r)>>1;
			if(q[mid] >= x) r = mid;
			else l = mid+1;
		}
		if(q[l] != x)cout<<"-1 -1"<<endl; //可能该数是比自己小的中最大的那个数 
		else{
			cout<<l<<" ";
			int l = 0,r = n-1;
			while(l < r){
				int mid = (r+l+1)>>1;
				if(q[mid] <= x) l = mid;
				else r = mid -1;
			}
			cout<<l<<endl;
		}
	}
	return 0;
}
