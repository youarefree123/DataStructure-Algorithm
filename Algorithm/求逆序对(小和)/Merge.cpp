//利用归并排序求解序列中的逆序对

#include <bits/stdc++.h>
using namespace std;
template<class T> //模板
int getArrLen(T& arr){
	return ((int)sizeof(arr)/(int)sizeof(arr[0]));
}
int Merge(int arr[], int l, int mid, int r){
	int len = r-l+1;
	int help[len]; //临时数组
	int p1 = l;
	int p2 = mid+1;
	int i = 0;
	int XiaoHe = 0;
	int Nixu = 0;
	while(p1 <= mid && p2 <= r){
		XiaoHe += arr[p1] < arr[p2] ? (r-p2+1)*arr[p1] : 0; //计算小和
		Nixu += arr[p1] > arr[p2] ? (mid-p1+1):0; //计算逆序对
		help[i++] = arr[p1] < arr[p2]? arr[p1++]:arr[p2++]; 
	}
	//两个有且只有一个会越界,下面两个循环只会执行一个
	while(p1 <= mid){
		help[i++] = arr[p1++];
	}
	while(p2 <= r){
		help[i++] = arr[p2++];
	}
	// 将临时数组help 复制到原数组
	for(int i = 0; i < len; i++){
		arr[l+i] = help[i]; //重要：关注左边的局部是在整体的哪个位置
	}
	// return XiaoHe;
	return Nixu;

}

int MergeSort(int arr[] , int l, int r){
	if(l == r) //如果左右指向同一个元素，返回
		return 0;
	int mid = l + ((r-l)>>1);
	// MergeSort(arr,l,mid);
	// MergeSort(arr,mid+1,r);
	// Merge(arr,l,mid,r);

	return(MergeSort(arr,l,mid)
		   +MergeSort(arr,mid+1,r)
		   +Merge(arr,l,mid,r)); //得到左侧部分产生的小和(或者逆序对)+右侧部分产生的+merge的时候产生的

}

int main(int argc, char const *argv[])
{	int arr[] = {10,2,9,8,5,3,2,6,7,3};
	 // cout<<"小和："<<MergeSort(arr,0,getArrLen(arr)-1)<<endl;
	 cout<<"逆序对："<<MergeSort(arr,0,getArrLen(arr)-1)<<endl;
	for(int i : arr){
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}
