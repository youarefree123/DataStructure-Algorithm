#include <bits/stdc++.h>
using namespace std;

//严格O(N) bfprt(arr,k)// 
//划分五个数一组，每组排序，将每组中位数拿出组成新数组,不断递归直到不足五个数，
//再求出新数组的中位数
//得到一个中位数，将该数作为中间划分，进行partition
 
const int N = 1000005;  
   
int a[N];  


int findMedian(int a[] , int l , int r)
{
    int i , index;
    for(i=l,index=0 ; i+4<=r ; i+=5,index++){
        sort(a+l , a+l+5);
        swap(a[l+index] , a[i+2]);
    }
    if(i<=r){
        sort(a+i , a+r+1);
        swap(a[l+index] , a[i+(r-i+1)/2]);
        index++;
    }
    if(index == 1) return a[l];
    else return findMedian(a , l , l+index-1);
}
//以p位置上的数字作为基准点划分，返回的i是最后基准点所在的位置
int partion(int a[] , int l , int r , int p)
{
    swap(a[p] , a[l]);
    int i=l , j=r , pivot= a[i];
    while(i<j){
        while(i<j && a[j]>=pivot) j--;
        if(i<j) a[i] = a[j];
        while(i<j && a[i]<=pivot) i++;
        if(i<j) a[j] = a[i];
    }
    a[i] = pivot;
    return i;
}   
//在a数组的[l,r]区间内找到第k小的数字
int findKthMin(int a[] , int l , int r , int k)
{
    // int median = findMedian(a , l , r);
    int p = partion(a , l , r , l);
    int len = p-l+1;
    if(len == k) return a[p];
    else if(len>k) return findKthMin(a,l,p-1,k);
    else return findKthMin(a,p+1,r,k-len);
}
   
int main()  
{  
    int n, k;  
    while(~scanf("%d", &n)){   
        for(int i = 0; i < n; i++)  
            scanf("%d", &a[i]);  
        scanf("%d", &k);
        int ret = findKthMin(a,0,n-1,k);
        //for(int i=0 ; i<n ; i++)
        printf("%d\n", ret);  
    }
    return 0;  
} 