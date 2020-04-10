#include <bits/stdc++.h>
using namespace std;
int matrix[4][4];
int end = 3;

//暴力枚举：复杂度很高
int walk(int i ,int j){
	if(i == end && j == end){//到达目的地
		return matrix[i][j];
	}
	if(i == end){ //往下走到尽头
		return matrix[i][j]+walk(i,j+1); //往右走
	}
	if(j == end){// 往右走到尽头
		return matrix[i][j]+walk(i+1,j);
	}
	//否则就是正常情况
	int right = walk(i,j+1); //往右
	int down = walk(i+1,j); //往下
	return matrix[i][j] + min(right,down); 
}

