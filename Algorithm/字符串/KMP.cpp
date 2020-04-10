#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <time.h>

using namespace std;


typedef int Position; //位置 

/*
int* buidNext(char* P){ //构造next表 未改进版
	int m = strlen(P) ; // 模式串串长
	Position j = 0; //“主”串指针
	int* N = (int*)malloc(sizeof(int)*(m));
	int t = N[0] = -1; //通配符，哨兵
	while(j < m-1){
		if(t < 0 || P[j] == P[t]){
			t++; j++;
			N[j] = t; // 可改进
		}
		else t = N[t];
	}   
	return N;
}
*/

int* buidNext(char* P){ //构造next表 ，改进版
	int m = strlen(P);
	Position j = 0; 
	int* N = (int*)malloc(sizeof(int)*m);
	int t = N[0] = -1;
	while( j < m-1){
		if(t < 0 || P[j] == P[t]){
			j++; t++;
			N[j] = (P[j] !=P[t])? t:N[t];
		}
		else
			t = N[t];
	}
	return N;
}


Position match(char* P ,char* T){ //KMP算法,P是模式串，T是主串
	int* next = buidNext(P); //构造next表
	//putNext(next);
	int n = (int)strlen(T);//主串长度
	Position i = 0 ; //主串指针
	int m = (int)strlen(P); //模式串指长度
	Position j = 0 ; //模式串指针
	while((j < m)&&(i < n)){ //强条件，一旦两个串的其中一个遍历完，另一个就没有再遍历的必要，循环便终止
		if((j<0) || (P[j] == T[i])){ //若匹配，或P已移出最左侧
			i++ ; j++; //转到下个字符
		}
		else 
			j = next[j]; //模式串按照既定的位置右移
	}
	delete[] next;
	return i-j; //返回主串中最先与模式串匹配的首位置
 }






char* buildArray(){//用于构造主串
	char Transform[2] = {'0','1'}; 
	int *t = (int*)malloc(sizeof(int)*50);
	char *a = (char*)malloc(sizeof(char)*50);
	// int* t = new int[50];
	// char* a = new char[50];
	srand((unsigned)time(NULL));
	for(int i = 0 ; i < 50 ; i++){
		t[i] = rand()%2;
	}

	for(int  i = 0; i < 50 ; i++){
		a[i] = Transform[t[i]];
	}
	return a;
	
}

void putArray(char *a){
	int i = 0;
	while(i < 50){printf("%c ",a[i]); i++;}
	printf("\n");
}



int main(int argc, char const *argv[])
{
	char *T = buildArray();
	printf("主串为：\n");
	putArray(T);

	char *P = "01011";
	printf("模式串为：\n");
	printf("%s\n",P);

	printf("匹配的位置为:\n");
	printf("%d\n",match(P,T));

	delete[] T;
	return 0;
}
