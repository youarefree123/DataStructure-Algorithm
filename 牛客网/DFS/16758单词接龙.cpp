#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;
 
int n,num;
string w[25];//记录单词 
int use[25];//用来记录单词 
int ans=0,now=1;//ans记录龙的长度，now省略头子母
void dfs(int k){
    ans=max(ans,now);
    for(int i=1;i<=n;i++){//依次遍历每个单词 
        if(use[i]<2){
            for(int j=0;j<w[k].length();j++){//判断如果首字母相同那么就比较 
                if(w[i][0]==w[k][j]){
                    int l1=j;
                    int l2=0;
                    while(w[i][l2]==w[k][l1] && l1<w[k].length()){//逐一比较到词尾 
                        l1++;
                        l2++;
                    }
                    if(l1>=w[k].length()){//如果比较完成 
                        now+=w[i].length()-l2;//新的单词减去与上个单词重合的长度 
                        use[i]++; 
                        dfs(i);//以这个单词为新的节点搜索
                        now-=w[i].length()-l2;
                        use[i]--; 
                    }
                }
            }
        }
    }
} 
void in(){
    for(int i=0;i<25;i++){
        use[i]=0;
    }
}
int main()
{
    in(); 
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    cin>>w[0];//把头子母看作一个单词 
    dfs(0);
    printf("%d",ans);
    return 0;
}