/*https://www.luogu.com.cn/problem/P3375*/
#include <iostream>
#include <string>
#define endl "\n"

using namespace std;

const int N = 1e6 + 5;
int Next[N];
int MaxL[N];
void getNext(string sub) {
    int len = sub.size() - 1;
    Next[1] = 0;
    int i = 1, j = 0;
    while (i <= len) {//为了方便求MaxL数组，多求一位next（next与最后一个字符无关，而MaxL等于next左移-1）
        if (j == 0 || sub[i] == sub[j]) {
            Next[++i] = ++j;
        } else {
            j = Next[j];
        }
    }
}

void KMP_all(string s, string sub, int slen, int sublen) {
    int i = 1, j = 1;
    while (i <= slen) {
        if (j == 0 || s[i] == sub[j]) {
            if(j==sublen){//匹配完成一个后，输出位置然后继续回溯往后匹配
                cout<<i-sublen+1<<endl;
                j=Next[j];
                continue;
            }
            i++;
            j++;
        } else {
            j = Next[j];
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = " ";
    string sub = " ";
    string t;
    cin >> t;
    int slen = t.size();
    s.append(t);
    cin >> t;
    int sublen = t.size();
    sub.append(t);
    getNext(sub);
    KMP_all(s,sub,slen,sublen);
    //由next求MaxL
    for (int i = 1; i <= sublen; i++) {
        MaxL[i] = Next[i + 1] - 1;
    }
    for (int i = 1; i <= sublen; i++) {
        cout << MaxL[i] << " ";
    }

    return 0;
}