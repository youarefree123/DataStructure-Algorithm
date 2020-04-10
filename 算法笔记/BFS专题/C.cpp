#include <bits/stdc++.h>
using namespace std;
struct matrix
{
	int status[3][3];

};

map<matrix, int> M; //用来判断是否存在该种状态
int ending[3][3];
int starting[3][3];

int main(int argc, char const *argv[])
{
	
	for (int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; i++){
			scanf("%d",&starting[i][j]);
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; i++){
			scanf("%d",&ending[i][j]);
		}
	}

	matrix mm;
	mm.status = starting;

	return 0;
}
