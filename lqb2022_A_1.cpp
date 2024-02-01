/*
给定 n 个整数 a1, a2, · · · , an ，求它们两两相乘再相加的和，即 
S = a1 · a2 + a1 · a3 
+ · · · + a1 · an + a2 · a3 + · · · 
+ an-2 · an-1 + an-2 · an + an-1 · an.

输入格式：输入的第一行包含一个整数 n 。 第二行包含 n 个整数 a1, a2, · · · an。

输出格式：输出一个整数 S，表示所求的和。请使用合适的数据类型进行运算
*/

//因式分解，计算后缀
#include<iostream>
#define  ll long long
using namespace std;

ll suf=0;//a_i后缀和
ll sum=0;//a_i之后相乘的答案
int n;
int a;

int main(){
    cin>>n;
    cin>>suf;
    for(int i=0;i<n-1;i++){
        cin>>a;
        sum+=a*suf;
        suf+=a;
        

    }

    cout<<sum<<endl;
    system("pause");
    return 0;
}