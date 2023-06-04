// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
// 平衡字符串 cnt "a" = cnt "b" + cnt "c"
// 将一个字符串，变成平衡字符串的最少操作,输入保证偶数
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    long n;
    n = s.size();
    long cnta = 0;
    long cntb = 0;
    long cntc = 0;
    long result = 0;

    for (long i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            cnta++;
        if (s[i] == 'b')
            cntb++;
        if (s[i] == 'c')
            cntc++;
    }

    if (cntb + cntc > cnta)
    {
        result = (cntb + cntc - cnta) / 2;
    }else if(cntb + cntc == cnta){
        result = 0;
    }else if(cntb + cntc < cnta){
        result = (cnta - cntb - cntc) / 2;
    }

    cout << result << endl;
}