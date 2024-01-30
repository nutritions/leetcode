/*
小蓝有一个长度均为 n 且仅由数字字符 0 ∼ 9 组成的字符串，下标从 0 到 n − 1，
你可以将其视作是一个具有 n 位的十进制数字 num，小蓝可以从 num 中选出一段连续的子串并将子串进行反转，
最多反转一次。小蓝想要将选出的子串进行反转后再放入原位置处得到的新的数字 numnew 满足条件 numnew < num，
请你帮他计算下一共有多少种不同的子串选择方案，只要两个子串在 num 中的位置不完全相同我们就视作是不同的方案。
注意，我们允许前导零的存在，即数字的最高位可以是 0 ，这是合法的。

输入格式：输入一行包含一个长度为 n 的字符串表示 num（仅包含数字字符 0 ∼ 9），
从左至右下标依次为 0 ∼ n − 1。

输出格式：输出一行包含一个整数表示答案。
*/
#include<iostream>
#include<string>
using namespace std;
string s;
int ans=0;
void check(int l,int r){
    if(s[l]>s[r]){
        ans++;
        //cout<<l<<" "<<r<<endl;
    }else if(s[l]==s[r]){
        if(l<r)
            check(++l,--r);
    }else{
        return;
    }
}
int main(){
    cin>>s;
    int n=s.size();
    //cout<<n<<endl;
    for(int l=0;l<n-1;l++){
        for(int r=n-1;r>l;r--){
            check(l,r);
        }
    }
    cout<<ans<<endl;
    

    
    return 0;
}