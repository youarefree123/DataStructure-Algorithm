#include <bits/stdc++.h>
using namespace std;

void printAllSub(string str, int i, string res){
	if(i == (int)str.size()){
		cout<<res<<endl;
		return;
	}
	printAllSub(str,i+1,res);
	printAllSub(str,i+1,res+str[i]);
}


int main(int argc, char const *argv[])
{
	printAllSub("123",0,"");
	return 0;
}