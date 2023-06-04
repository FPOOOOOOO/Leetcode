// 有这么一段伪代码
// input a,b,m,x
// while true:
//   x=(a*x+b)%m
//   print(x)
// end while
// 输出的x由于是在取模意义下的，所以会出现循环。
// 比如，a=2, b=1, m=5, x=2的时候，输出的序列将会如下：
// 0,1,3,2,0,1,3,2,0,1,3,2....
// 其中：0,1,3,2 称为最短的循环节。
// 现在给定a,b,m,x的值，请你计算最短循环节的长度。

// 输入描述
// 输入4个数，a,b,m,x
// 输出描述
// 输出一个数，最短循环节的长度
// 2 1 5 2
// 4

#include <iostream>
#include <set>
using namespace std;

int main(){
    int a, b, m, x;
    cin >> a >> b >> m >> x;

    set<int> map;

    x = (a * x + b) % m;

    int count = 0;
    while(true){
        x = (a * x + b) % m;
        if(map.count(x)){
            cout << count;
            return 0;
        }
        map.insert(x);
        count++;
    }

}

//int 不行，用long可以全部通过