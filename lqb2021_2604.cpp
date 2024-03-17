/*https://www.dotcpp.com/oj/problem2604.html*/
#include<iostream>
using namespace std;

#define endl "\n"
const int N=101;
const int sumN=100005;
//dp[i][j]表示，用前i个砝码可以表示j重量
bool dp[N][sumN];
int w[N];
int sum;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        sum+=w[i];
    }
    dp[0][0]=1;//动态规划初始条件
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            dp[i][j]=dp[i-1][j]||dp[i-1][j+w[i]]||dp[i-1][abs(j-w[i])];
        }
    }
    int ans=0;
    for(int i=1;i<=sum;i++){//遍历所有重量，可以达成则++
        if(dp[n][i]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}