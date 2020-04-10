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
void swap(int arr[], int a , int b){
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}


void heapInsert(int arr[] , int index){
	while(arr[index] > arr[(index-1)/2]){ //如过新加的堆元素比他的父节点大
		swap(arr,index,(index-1)/2);
		index = (index - 1)/2;
	}
}

void heapify(int arr[] ,int index , int heapSize){//对当前结点进行下滤，使其恢复成堆结构
	int left = index*2+1; //左孩子
	while(left < heapSize){ //如果存在左孩子
		int largest = left+1 < heapSize && arr[left+1] > arr[left]
				  ? left+1
				  : left;
		largest =  arr[largest] > arr[index] ? largest : index;
		if(largest == index) //如果index本身就是最大的，不需要交换
			break;  
		swap(arr,largest,index); //否则将index和最大的孩子交换
		index = largest; //交换后原index值来到了largest的位置
		left = index*2+1; //左孩子

	}

}

void heapSort(int arr[],int heapSize){ //堆排序
	if(arr == NULL || heapSize < 2){
		return; //如果数组不合法，直接结束
	}
	for(int i = 0; i < heapSize; i++){
		heapInsert(arr,i); //构建0~i上的大根堆
	}
	swap(arr,0,--heapSize); //将堆首和堆尾部交换位置，此时找出最大值，放在最后，从此不再进行过滤	
	while(heapSize > 0){ //每次交换过后下滤一次，恢复堆结构
		heapify(arr,0,heapSize);
		swap(arr,0,--heapSize); //一直到将所有堆元素都置换过一遍
	}
	
}

// void heapInsert(int arr[] , int index){ //如果这个结点存放的数比父结点都大，就需要调整
// 	while(arr[index] > arr[(index-1)/2]){
// 		swap(arr,index,(index-1)/2);
// 		index = (index-1)/2;
// 	}
// }


// //调整成大根堆
// void heapify(int arr[] , int index, int heapSize){
// 	int left = index*2 + 1; //左孩子
// 	while(left < heapSize){ //如果没有越界
// 		int largest = left + 1 < heapSize && arr[left + 1] > arr[left]
// 		? left + 1
// 		: left; //选择左右孩子之间最大的那个下标
// 		largest = arr[largest] > arr[index] ? largest : index;
// 		if(largest == index) //如果最大的那个下标就是index本身，他就不用下滤
// 			break;
// 		swap(arr,largest,index); //否则就和最大的孩子交换
// 		index = largest; //index现在的位置就是原来largest的位置
// 		left = index*2 + 1; //继续往下滤，循环往复
// 	}
// }

// void heapSort(int arr[],int heapSize){ //堆排序
// 	if(arr == NULL || heapSize < 2){
// 		return ;
// 	}
// 	for(int i = 0; i < heapSize; i++){ //在数组的0~i区间建立堆
// 		heapInsert(arr,i); //0~i
// 	}
// 	swap(arr,0,--heapSize); //将堆顶和最后一位交换
// 	while(heapSize > 0){ //每一次循环，都能找到堆的最大值，然后放在最后面
// 		heapify(arr,0,heapSize); //调整堆结构
// 		swap(arr,0,--heapSize); //继续替换
// 	}
// }






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
		heapSort(arr,len); //数组排序
		put_Arrary(arr,len);
		Sleep(1000);
		printf("\n\n");
	}
	
	return 0;
}