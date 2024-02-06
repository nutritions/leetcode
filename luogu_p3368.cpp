/*https://www.luogu.com.cn/problem/P3368*/
//单点查询和区间修改
//主要难点在区间修改这里，如果还是逐个单点修改，容易超时，
//只要求查单点，所以采用差分(当前比前一项大多少)的方法,这样只需要修改两端
#include<iostream>
#include<vector>
using namespace std;

#define endl "\n"
#define ll long long 
const  int N=5*5e5+5;
int n,m;
vector<ll> sum(N);//差分的部分区间区间和
vector<ll> arr(N);

ll lowbit(ll x){
    return x&-x;
}
//单点修改差分
void update(ll x,ll k){
    while(x<=n){
        sum[x]+=k;
        x+=lowbit(x);
    }
}

//差分前缀和
ll queryPreSum(ll x){
    ll pre_sum=0;
    while(x){
        pre_sum+=sum[x];
        x-=lowbit(x);
    }
    return pre_sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){

        cin>>arr[i];
    
    }
    int op,x;
    while(m--){
        cin>>op>>x;
        if(op==1){
            int y,k;
            cin>>y>>k;
            update(x,k);//修改区间开始比前一项大k
            update(y+1,-k);//区间末尾比后一项小k
        }else{
            cout<<arr[x]+queryPreSum(x)<<endl;//原始数据加上变化的差分
        }
    }
    return 0;
}