/*
小蓝正在一个瓜摊上买瓜。瓜摊上共有 n 个瓜，每个瓜的重量为 Ai 。
小蓝刀功了得，他可以把任何瓜劈成完全等重的两份，不过每个瓜只能劈一刀。
小蓝希望买到的瓜的重量的和恰好为 m 。
请问小蓝至少要劈多少个瓜才能买到重量恰好为 m 的瓜。如果无论怎样小蓝都无法得到总重恰好为 m 的瓜，请输出 −1 。

输入格式：输入的第一行包含两个整数 n, m，用一个空格分隔，分别表示瓜的个数和小蓝想买到的瓜的总重量。
第二行包含 n 个整数 Ai，相邻整数之间使用一个空格分隔，分别表示每个瓜的重量。

输出格式：输出一行包含一个整数表示答案。
*/
#include<iostream>
#include<algorithm>
#define MAX 30
using namespace std;
int n,m;
int ans=0x3f3f3f3f;
long weight[MAX];
long long suf[MAX+1];
//对于每一个瓜，可选：
//不选择，重量不变，切次数不变
//选择但不切，重量加上去，切次数不变
//选择并且切，重量一半加上去，切次数加1
//最终满足条件：sum_w=m,cut尽可能小
void DFS(int pos,long long sum_w,int cut){//层数、总重量、切割次数
    if(sum_w==m){
        ans=min(ans,cut);
        return;//当前DFS路径没有继续搜的必要了
    }
    if(pos>=n||cut>=ans||sum_w>m){
        return;
    }
    DFS(pos+1,sum_w+weight[pos],cut);
   
    DFS(pos+1,sum_w+weight[pos]/2,cut+1);
    
    DFS(pos+1,sum_w,cut);
}

int main(){
    
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    cin>>n>>m;
    //重量可能为奇数，采用的long long，所以全部翻倍处理
    m=m*2;
    for(int i=0;i<n;i++){
        cin>>weight[i];
        weight[i]*=2;
    }
    
    //sort(weight,weight+n,greater<int>());
    //for(int i=n-1;i>=0;i--) suf[i] = suf[i+1]+weight[i];
    DFS(0,0,0);
    
    if(ans==0x3f3f3f3f){
        cout<<-1;
    }else{
        cout<<ans;
    }



     system("pause");
     return 0;
}