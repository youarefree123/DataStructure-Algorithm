//Manacher算法：求最长回文长度
#include <bits/stdc++.h>
using namespace std;
const int maxm = 3e6;
char s[maxm],str[maxm];
int len1,len2,p[maxm],ans;

void init() //双倍字符串
{
	str[0] = '$';
	str[1] = '#';
	for(int i = 0 ; i < len1; i++){
		str[i*2+2] = s[i];
		str[i*2+3] = '#';
	}
	str[len2] = '*';
	len2 = len1*2+2;
}

void manacher(){
	int id = 0,mx = 0;
	for(int i = 1; i < len2; i++){
		if(mx > i) p[i] = min(p[2*id-i],mx-i); 
		//如果对称点没超过边界就是就和对称点一样，否则要取到边界，
		//再暴力匹配mx后面的部分
		else p[i] = 1; //否则最大回文长度起始是1
		for(; str[i+p[i]] == str[i-p[i]]; p[i]++); //暴力匹配
		if(p[i] + i > mx){
			mx = p[i]+i; //更新右边界
			id = i; //更新最长子串中心
		}
	}
}

int main(int argc, char const *argv[])
{
	// while(scanf("%s",s)!= EOF){
	// 	len1 = strlen(s);
	// 	init();
	// 	int ans = manacher();
	// 	cout<<ans-1<<endl; //两倍的回文半径 2*p[i]-1

	// }
	int cnt = 1;
	while(scanf("%s",s) != EOF){
		if(s[0] == 'E' && s[1] == 'N' && s[2] == 'D')
			break;
		len1 = strlen(s);
		init();
		manacher();
		ans = 0;
		for(int i = 0 ; i < len2; i++){
			ans = max(ans,p[i]);
		}
		cout<<"Case "<<cnt++<<": "<<ans-1<<endl;
		
	}
	return 0;
}