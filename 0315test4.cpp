// 数对是数学中一个重要的概念，类似于计算机中的pair，数对的性质如下：
// 每个数对(x,y)包含两个实数元素x,y，描述一对数之间的关系。两个数对比大小将先比较第一个数的大小，如果相同再比较第二个数的大小。
// 现在，有n个数（两两可能相同），他们之间两两将会形成n^2个数对（自己和自己也会形成数对）。我们希望知道，第k小的数对是哪一对数，并输出这一对。
// 输入描述
// 第一行包含两个数n,k 
// 接下来一行n个整数，空格隔开。
// 输出描述
// 输出第k小的数对。格式如(x,y)，其中x为数对中第一个数，y为数对中第二个数

// 样例输入
// 3 4
// 3 1 2
// 样例输出
// (2,1)
// 提示
// n≤100000,1≤k≤n^2，这n个数在int范围内[-2147483648,2147483647]
// 样例解释
// 数对一共有9个，分别是： (3,3)(3,1)(3,2)(1,3)(1,1)(1,2)(2,3)(2,1)(2,2) 
// 按从小到大的排序后：(1,1)(1,2)(1,3)(2,1)(2,2)(2,3)(3,1)(3,2)(3,3)
// 第4个为(2,1)

#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int x, y;

    map<int, int> MAP;
    set<int> SET;

    for(int i = 0; i < n; i++){
        int come;
        cin >> come;
        //SET.insert(come);
        MAP[come]++;
    }

    int unrepeat = MAP.size();
    int zhengshu = k / unrepeat;
    int yushu = k % unrepeat;

    int cnt = 0;

    for(auto it = MAP.begin(); it !=MAP.end(); it++){
        
        if(cnt == zhengshu){
            x = it->first;
        }
        if(cnt == yushu - 1){
            y = it->first;
        }
        cnt++;
    }
    cout << '(' << x << ',' << y << ')' << endl;

}

// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>

// using namespace std;

// int main() {
//     int n, k;
//     cin >> n >> k;

//     vector<int> nums(n);
//     for (int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }

//     sort(nums.begin(), nums.end()); // 将vector排序

//     set<pair<int, int>> pairs; // 存储数对的set容器

//     // 枚举所有数对
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             pairs.insert({nums[i], nums[j]}); // 将数对加入set容器
//         }
//     }

//     // 找到第k小的数对并输出
//     int cnt = 0; // 计数器
//     for (auto p : pairs) {
//         cnt++;
//         if (cnt == k) {
//             cout << "(" << p.first << "," << p.second << ")" << endl;
//             break;
//         }
//     }

//     return 0;
// }
