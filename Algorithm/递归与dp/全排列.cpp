#include <iostream>
#include <string>
using namespace std;

void permute(string str, int k) { //得到0~k-1之间的全排列
    if (k == str.size() - 1) {
        cout << str << endl;
    }
    else if (k >= str.size()) return;
    for (int i = k; i < str.size(); i++) { //排列第k位,并且排列完后复原
        swap(str[i], str[k]);
        permute(str, k + 1);
        swap(str[i], str[k]);
    }
}
void permute(string str) {
    if (str.empty()) return;
    permute(str, 0);
}
int main()
{
    string str = "abc";
    permute(str);
    system("pause");
    return 0;
}
