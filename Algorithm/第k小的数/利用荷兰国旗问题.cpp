#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

//复杂度通过概率计算得到O(N) , [O(N^2) 到 O(N)]
const int N = 1e5;
int q[N];
pair<int,int> partition(int arr[], int L ,int R){
	//返回中间区域的左右边界
	int head = L+rand()%(R-L);
	swap(arr[R],arr[head]);
	int less = L-1; //小于区域的右边界
	int more = R; //大于区域的左边界，其中arr[R]不参与下面的循环，作为对比项
	while(L < more){ //如果遍历没有碰到more的右边界
		if(arr[L] < arr[R]){ //如果该位置元素小于对比项
			swap(arr[++less],arr[L++]); //扩展less范围，同时L往前推进
		}
		else if(arr[L] > arr[R])
			swap(arr[--more],arr[L]); //扩展more范围，但是交换过来的元素无法判断大小，所以不能直接++
		else
			L++; //扩展中间区域的范围
	}
	swap(arr[more],arr[R]); //交换过后more位置就是原来的对比项
	return make_pair(less+1,more);
	// vector<int> v;
	// v.push_back(less+1);
	// v.push_back(more); //此时more位置就是对比项，
	// return v;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>q[i];
	}
	int k;
	cin>>k;
	int ans = -1;
    pair<int,int> v = partition(q,0,n-1);
   	while(ans == -1){
   		if(k >= v.first+1 && k <= v.second+1)
   			ans = q[v.first];
   		else{
   			if(k < v.first+1){
   				v = partition(q,0,v.first);
   			}
   			else if(k > v.second+1){
   				v = partition(q,v.second,n-1);
   			}
   		}
   	}
   	cout<<ans;
	return 0;
}