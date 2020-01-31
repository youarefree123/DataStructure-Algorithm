
# 快速幂的模板题
&emsp;&emsp;[测试平台](https://www.acwing.com/problem/content/91/)

代码：
```c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
  ll a,b,p; // a^b mod p
  scanf("%lld %lld %lld",&a,&b,&p);
  ll ans = 1;
  while(b>0){ //如果幂次没有到0
  	if(b%2 == 1){
  		ans = a*ans%p;
  	}
  	a = a*a % p;
  	b = b>>1; //b除二
  }
	ans = ans%p; //最后的ans需要再次取余
	printf("%lld\n",ans);
}

```

[测试代码](https://github.com/youarefree123/DataStructure-Algorithm/blob/master/Algorithm/%E5%85%A8%E6%8E%92%E5%88%97/%E5%85%A8%E6%8E%92%E5%88%97.cpp)