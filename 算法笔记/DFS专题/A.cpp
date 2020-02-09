#include "bits/stdc++.h"
using namespace std;
//考虑死胡同和拐点
int Stack[10]; //一个栈
int check[11]; //检查数是否已经用过
int n; 

void dfs(int index){ //考虑过index个值了
    if(index == n){ //死胡同
   	for(int i = 0 ; i < n ; i++){
   		printf("%d ",Stack[i]);;
   	}
   	printf("\n");
   	return;
   }

   //岔路口
   for(int i = 1 ; i <= n ; i++){
   	if(check[i] == 0){
   		Stack[index] = i;
   		check[i] = 1;
   		dfs(index+1);
   		check[i] = 0; //释放栈顶元素
   	}
   }
}



int main(int argc, char const *argv[])
{
	cin>>n;
	dfs(0);
	return 0;
}


