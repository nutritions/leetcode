/*https://www.luogu.com.cn/problem/P3811*/
//求乘法逆元，利用费马小定理转换为快速幂取模
//乘法逆元：ax=1(mod p),a和x互为乘法逆元（模意义下的倒数）
//费马小定理：p为素数，a,p互质，则a^(p-1)=1(mod p)
//综上，x=a^(p-2)

#include<iostream>
using namespace std;
typedef long long ll;
#define endl "\n"

int n,p;

//任何一个整数可以写成2的幂之和，例如105=1+8+32+64
//所以要求7^105次方，也就可以求7^1*7^8*7^32*7^64
//也就是只需要求7的2的幂的次幂即可，每次平方即可计算得到
int quickpow(ll a,int b,int p){
    int ans=1;
    while(b){
        if(b&1){//b模2，判断最后一位是否为1
            ans=ans*a%p;//最后一位是1，则说明对应的次幂需要乘上
        }
        a=a*a%p;//计算对应的次幂
        b=b>>1;//判断完去掉最后一位，继续
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cout<<quickpow(i,p-2,p)<<endl;
    }
    return 0;

}