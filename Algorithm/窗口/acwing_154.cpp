#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
int n; int k;
int q[N];
deque<int> dq1,dq2;
vector<int> maxm ,minm;

void getMaxArr(){
	int l = -1;
	int flag = 0;
	for(int r = -1 ;r < n-1;){
       if(++flag < k){
       	r++;
           while(!dq1.empty() && q[r] > q[dq1.back()]){
           		dq1.pop_back();
           }
           dq1.push_back(r);
           if(flag == k)
           		maxm.push_back(q[dq1.front()]); //存下前端队列的首部
       }
       else{
       	r++;
       	while(!dq1.empty() && q[dq1.back()] < q[r]){
           		dq1.pop_back();
           }
           dq1.push_back(r);
        maxm.push_back(q[dq1.front()]); //存下前端队列的首部
        l++;
       	if(dq1.front() == l) dq1.pop_front();
       }
	}
}


void getMinArr(){
	int l = -1;
	int flag = 0;
	for(int r = -1 ;r < n-1;){
       if(++flag < k){
       	r++;
           while(!dq2.empty() && q[r] < q[dq2.back()]){
           		dq2.pop_back();
           }
           dq2.push_back(r);
           if(flag == k)
           		minm.push_back(q[dq2.front()]); //存下前端队列的首部
       }
       else{
       	r++;
       	while(!dq2.empty() && q[r] < q[dq2.back()]){
           		dq2.pop_back();
           }
           dq2.push_back(r);
        minm.push_back(q[dq2.front()]); //存下前端队列的首部
        l++;
       	if(dq2.front() == l) dq2.pop_front();
       }
	}
}

int main(int argc, char const *argv[])
{
	
	cin>>n>>k;
	for(int i = 0; i < n; i++)
		scanf("%d",&q[i]);
	getMaxArr();
	getMinArr();
	for(int it : minm){
		cout<<it<<" ";
	}
	cout<<endl;
	for(int it : maxm){
		cout<<it<<" ";
	}
	cout<<endl;
	return 0;
}