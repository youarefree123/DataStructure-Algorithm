#include <bits/stdc++.h>
using namespace std;
std::vector<string> v;

bool cmp(string a, string b){
	for(int i = 0 ; i < (int)min(a.size(),b.size()); i++){
		if(a[i] > b[i])
			return true;
		else if(a[i] < b[i])
			return false;
	}
	if(a.size() < b.size()){ //选择b
		return b[0] >= b[b.size()-1];
			
	}
	else if(a.size() > b.size()){ //选择a
		return a[0] <= a[a.size()-1];
	}	
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		string tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i = 0; i < (int)v.size(); i++){
		cout<<v[i];
	}
	return 0;
}
