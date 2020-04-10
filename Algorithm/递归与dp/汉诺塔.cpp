//汉诺塔问题移动过程
//N:1~N的问题 ， 从from杆到to杆，中间借助 help杆 
#include <bits/stdc++.h>
using namespace std;

void process(int N, string from, string to, string help){
	if (N == 1) //如果规模到了1，直接从from到to
	{
		cout<<"Move 1 from "<<from<<" to "<<to<<endl;
	}
	else{
		process(N-1,from,help,to); //通过to杆将n-1移动到help
	    cout<<"Move "<<N<<" from "<<from<<" to "<<to<<endl;//将第n位置移动到to杆
	    process(N-1,help,to,from); 
	}
}

int main(int argc, char const *argv[])
{
	process(3,"zuo","you","zhong");
	return 0;
}