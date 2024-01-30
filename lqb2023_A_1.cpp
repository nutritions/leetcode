// 给定 L, R，问 L ≤ x ≤ R 中有多少个数 x 满足存在整数 y,z 使得 x = y^2 − z^2
#include <iostream>
using namespace std;
int main()
{
    int L, R;
    cin >> L>> R;
    int cnt=0;
    //必须是奇数或者4的倍数
    for(int i=L;i<=R;i++){
        if(i%4==0||i%2==1){
            cnt++;
        }
    }

    
    cout<<cnt;
    return 0;
}