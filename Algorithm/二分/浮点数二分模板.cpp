#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	double x;
	cin>>x;
	double l = 0,r =x;
	while(r-l > 1e-8){ //一般比精度高两位小数
		double mid = (l+r) /2;
		if(mid*mid >= x) r = mid;
		else l = mid;
	}
	printf("%lf\n",l);
	return 0;
}
