/*https://www.luogu.com.cn/problem/P3865*/
//ST表求RMQ问题
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define endl "\n"
const int N=1e5+5;
int f_max[N][22];//f[i][j]表示从i开始长度为2^j的区间最大值
int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //预处理
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>f_max[i][0];
    }
    for(int j=1;j<=20;j++){//枚举长度
        for(int i=1;i+(1<<j)-1<=n;i++){//枚举起始位置
            f_max[i][j]=max(f_max[i][j-1],f_max[i+(1<<(j-1))][j-1]);//注意位运算优先级比较低，需要加上括号
        }
    }
    //查询
    int l,r;
    while(m--){
        cin>>l>>r;
        int k=log2(r-l+1);//将区间长度分为两个2^k长度的区间进行查询，中间可以重合
        cout<<max(f_max[l][k],f_max[r-(1<<k)+1][k])<<endl;
    }
    return 0;
}