/*
 *利用荷兰国旗问题中的三层划分优化快排序，
 *当重复元素比较多的时候会加速很多
*/

#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

/*初始化一个数组*/

int* init_Arrary(int len){
	int* arr;
	arr = (int*)malloc(sizeof(int)*len);
	for(int i = 0 ; i < len ; i++){
		int tmp = 1+rand()%100;
		arr[i] = tmp;
	}
	return arr;
}

/*输出数组*/
void put_Arrary(int arr[],int len){
	for(int i = 0 ; i < len; i++)
		printf("%d ",arr[i]);
	printf("\n");
}

/*交换函数，或者用c++的 swap函数*/
void swap(int& a ,int& b){
	// a = a^b;
	// b = a^b;
	// a = a^b;
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
// /*寻找结点原来位置并返回，每一次partiton 都有一个位置就位*/
// vector<int> partition(int arr[] , int l , int r){
// 	int head = l+rand()%(r-l+1); //采用取随机数法
// 	swap(arr[r],arr[head]);
// 	int less = l-1;
// 	int more = r; //最后一个元素不参与划分
// 	while(l < more){
// 		if(arr[l] < arr[r])
// 			swap(arr[++less],arr[l++]); //将比head小的数都放到后面
// 		else if(arr[l] > arr[r]){
// 			swap(arr[--more],arr[l]);
// 		}
// 		else
// 			l++;
// 	}
// 	swap(arr[more],arr[r]); //将最后一个元素放到more左边界，这是最后的位置
// 	//此时less在小区域的有边界，more在大区域的左边界
// 	vector<int> v; 
// 	v.push_back(less+1);
// 	v.push_back(more);
// 	return v; //返回中甲区域的左右边界
// }
// /*快速排序主体部分*/
// void QuickSort(int arr[],int l ,int r){ //排序[l,h)的值
// 	if(l < r){
// 		vector<int> p ;
// 		p = partition(arr,l,r); //返回一个数组，包含序列中相等部分的左右边界
// 		QuickSort(arr,l,p[0]-1); //
// 		QuickSort(arr,p[1]+1,r);
// 	}	
// }


vector<int> partition(int arr[], int L ,int R){
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
	vector<int> v;
	v.push_back(less+1);
	v.push_back(more); //此时more位置就是对比项，
	return v;
}

void QuickSort(int arr[] ,int L, int R){
	if(L < R){ //如果左右划分超过一个元素
		vector<int> v = partition(arr,L,R);
		QuickSort(arr,L,v[0]-1);//递归左
		QuickSort(arr,v[0]+1,R);//递归右
	}	
}
int main(int argc, char const *argv[])
{
	int i = 10;
	while(i--){
		srand((unsigned)time(NULL));
		int len = 5+rand()%20; //随机数组长度
		int* arr = init_Arrary(len); //随机生成一个数组
		printf("unsorted: ");
		put_Arrary(arr,len);
		printf("sorted: ");
		QuickSort(arr,0,len-1); //数组排序
		put_Arrary(arr,len);
		Sleep(800);
		printf("\n\n");
	}
	return 0;
}