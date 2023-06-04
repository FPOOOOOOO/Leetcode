// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
// 4
// RWWW
// 1 2
// 2 3
// 2 4
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000000 + 7;

int main()
{
    long n;
    cin >> n;

    long result = 0;

    for(long i = 1; i <= n; i++){
        if(i % 2){
            result = (result + (i * (n - i + 1)) % MOD) % MOD;
        }else{
            result = (result + (i * (n - i + 1) / 2) % MOD) % MOD;
        }
    }

    cout << result << endl;
}