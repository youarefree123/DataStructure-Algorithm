#include <bits/stdc++.h>
using namespace std;

template<class T> //模板
int getLen(T& arr){
	return ((int)sizeof(arr)/(int)sizeof(arr[0]));
}

void swap(int& a ,int& b){
	// a = a^b;
	// b = a^b;
	// a = a^b;

	int tmp;
	tmp = a;
	a = b;
	b = tmp;

}



void partition(int arr[] ,int L ,int R,int num){
	int less = L-1;
	int more = R+1;
	int cur = L;
	while(cur < more){
		if(arr[cur] < num)
			swap(arr[++less],arr[cur++]); //拿小于区域后一位的数 ，每次cur都会往后推进
		else if(arr[cur] > num)
			swap(arr[--more],arr[cur]); //拿大于区域前一位的数，每次cur拿回的数都是未知大小的，所以不能推进
		else
			cur++;
	}
	// for(int i = 0; i < 10; i++){
	// 	cout<<arr[i]<<" ";
	// }
	return;
	// int a[] = {less+1,more-1};
	// return a; //返回左右
}


int main(int argc, char const *argv[])
{
	int arr[] = {10,9,8,7,6,7,4,8,2,1};
	partition(arr,0,getLen(arr)-1,6);
	for(int i : arr){
		cout<<i<<" ";
	}
	return 0;
}
