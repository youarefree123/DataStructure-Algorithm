/*插入排序C语言实现,并随机生成测试样例*/
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



/*插入排序主体部分*/
void insertionSort(int arr[],int l ,int h){ //排序[l,h)的值
	for(int i = l+1 ; i < h ; i++){
		int j = i-1;
		int key = arr[i]; //寻找位置
		while(l<=j && key < arr[j]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
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
		insertionSort(arr,0,len); //数组排序
		put_Arrary(arr,len);
		Sleep(1000);
		printf("\n\n");
	}
	
	return 0;
}