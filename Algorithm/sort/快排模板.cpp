//快排模板
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n;
int q[N];

void quick_sort(int q[] ,int l, int r){
	if(l >= r)return;
	int x = q[l+rand()%(r-l)]; //不能取到r的位置，会造成j的越界
	int i = l-1; int j = r+1; //虚拟边界
	while(i < j){
		do i++; while(q[i] < x); //找到小于x的位置
		do j--; while(q[j] > x); //找到大于x的位置
		if(i < j) swap(q[i],q[j]);//如果i < j交换两个数的位置i
	}
	quick_sort(q,l,j);
	quick_sort(q,j+1,r);
}

int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i = 0 ; i < n; i++){
		scanf("%d",&q[i]);
	}
	quick_sort(q,0,n-1);
	for(int i = 0; i < n; i++){
		printf("%d ",q[i]);
	}
	return 0;
}

void sort_w(){ //库函数
	sort(q,q+n);
}