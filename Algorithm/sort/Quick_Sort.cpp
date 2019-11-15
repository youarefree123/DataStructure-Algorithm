/*快速排序C语言实现,并随机生成测试样例*/
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <windows.h>


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
void swap(int* a , int* b){
	int tmp = *a ;
	*a = *b;
	*b = tmp;
}

/*寻找结点原来位置并返回，每一次partiton 都有一个位置就位*/
int partition(int arr[] , int l , int h){
	int head = l+rand()%(h-l+1); //采用取随机数法
	swap(&arr[l],&arr[head]);
	int ans = arr[l];
	while(l < h){ //退出条件
		while(l < h && arr[h] > ans) h--; //注意： l<h 这个条件必须放在前面，否则会出现数组越界
		arr[l] = arr[h];
		while(l < h && arr[l] <= ans) l++; //注意： l<h 这个条件必须放在前面，否则会出现数组越界
		arr[h] = arr[l];
	}
	arr[l] = ans;
	return l;
}


/*快速排序主体部分*/
void QuickSort(int arr[],int l ,int h){ //排序[l,h)的值
	if(h-l < 2) return; //递归基， 如果两个值差值只有1说明只有一个元素了
	int poi = partition(arr,l,h-1); //在[l,h-1]之间找到分割点
	QuickSort(arr,l,poi); //不断分治
	QuickSort(arr,poi+1,h);
	
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
		QuickSort(arr,0,len); //数组排序
		put_Arrary(arr,len);
		Sleep(1000);
		printf("\n\n");
	}
	
	return 0;
}