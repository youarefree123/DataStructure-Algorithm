#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int num; //目标数
    vector<char> path; //达到该状态的步骤
};
queue<Node> qu; //bfs队列
int op_a(int n) {//操作A（上下行互换）
    int low = n % 10000;
    int high = n / 10000;
    return low * 10000 + high;
}

int op_b(int n) {//操作B（每次以行循环右移一个）
    int low = n % 10000;
    int high = n / 10000;
    int h = high % 10;
    high = h * 1000 + high / 10;
    int l = low % 10;
    low = l * 1000 + low / 10;
    return high * 10000 + low;
}

int op_c(int n) {//操作C（中间四小块顺时针转一格）
    int a[8];
    for (int i = 0; i < 8; i++) {
        a[7-i] = n % 10;
        n = n / 10;
    }
    int ans =   a[0] * 10000000 +
                a[5] * 1000000 +
                a[1] * 100000 +
                a[3] * 10000 +
                a[4] * 1000 +
                a[6] * 100 +
                a[2] * 10 +
                a[7];
    return ans;
}

Node bfs(int end){ //传入参数为最终目标数
    Node front; //初始状态
    front.num = 12348765;
    qu.push(front);
    while(!qu.empty()){
        front = qu.front();
        qu.pop();
        //依次进行三种操作 
        Node tmp1 = front;
        tmp1.num = op_a(front.num);
        tmp1.path.push_back('A');
        if (tmp1.num == end) {
            return tmp1;//如果得到目标状态则返回 
        }
        else {
            qu.push(tmp1);
        }

        Node tmp2 = front;
        tmp2.num = op_b(front.num);
        tmp2.path.push_back('B');
        if (tmp2.num == end) {
            return tmp2;//如果得到目标状态则返回 
        }
        else {
            qu.push(tmp2);
        }

        Node tmp3 = front;
        tmp3.num = op_c(front.num);
        tmp3.path.push_back('C');
        if (tmp3.num == end) {
            return tmp3;//如果得到目标状态则返回 
        }
        else {
            qu.push(tmp3);
        }
    }
}


int main(int argc, char const *argv[])
{
    int tmp;
    int end = 0;
    for(int i = 0; i < 4; i++){ //输入目标数
        cin>>tmp;
        end = 10*end + tmp;
    }
    int a[4];
    for(int i = 0; i < 4; i++){
        cin>>a[i];
    }
    for(int i = 3 ; i >= 0; i--){
        end = 10*end + a[i];
    }
    
    Node node = bfs(end);
    cout<<node.path.size()<<endl;
    int limit = 0;
    for(int i = 0; i < (int)node.path.size(); i++){
        if(limit < 60){
            cout<<node.path[i];
            limit++;
        }
        else{
            cout<<endl<<node.path[i];
            limit = 0;
        }
    }
    return 0;
}