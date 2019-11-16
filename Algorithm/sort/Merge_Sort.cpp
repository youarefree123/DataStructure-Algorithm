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

/*合并函数：将两个有序数组合并成一个有序数组*/
void Merge(int* arr ,int l , int mid, int h){
	int lenA = mid-l; //第一个数组长度
	int lenB = h-mid; //第二个数组长度
	int* A = arr+l; //指向第一段数组第一个元素的指针
	int* B = arr+mid; //指向第二段数组第一个元素的指针
	int tmp[lenA];//备份第一段数组
	for(int i = 0 ; i < lenA ; i++){
		tmp[i] = A[i];
	}

	for(int i = 0 , j = 0 , k = 0;  (j < lenA) || (k < lenB);){
		if((j < lenA) && ((k >= lenB) || tmp[j] <= B[k])) A[i++] = tmp[j++]; 
		if((k < lenB) && ((j >= lenA) || B[k] < tmp[j])) A[i++] = B[k++]; 
	}
}




/*归并排序代码主体*/
void MergeSort(int* arr , int l , int h){
	if(h-l < 2) return; //递归基，如果是单元素区间就return
	int mid = (h+l)>>1; //找到中间元素
	MergeSort(arr,l,mid); //分割数组 ，范围是[l,mid)
	MergeSort(arr,mid,h); //分割数组 ，范围是[mid,hi)

	Merge(arr,l,mid,h); //合并上两个数组
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
		MergeSort(arr,0,len); //数组排序
		put_Arrary(arr,len);
		Sleep(1000);
		printf("\n\n");
	}
	
	return 0;
}