// 熊爷爷的超市正在打折活动当中！
// 目前，你和你的家里人一共k个人一起去买生活用品。由于打折活动力度很大，每个人只能去付款一次，但是这一次买的东西价格是不做限制的。
// 熊爷爷的超市物品分为两类：A类和B类物品，活动是如果一个人买的商品中含有A类物品，那么他买的所有物品中最便宜的一件物品半价。如果一个人买的商品中只有B类物品，那么他买的物品不打折。
// 你们计划要买n个物品，现在将这n个物品的信息给你，请你计算如何分配k位家人比较合算。

// 输入描述
// 第一行有两个整数n,k，代表物品的数量和人的数量。
// 接下来n行，每行两个整数u,v描述一个物品。u代表物品的价格，v代表商品的种类。如果v为1，代表其为A类商品。如果v为2，代表其为B类商品。
// 1<=n,k<=1000,1<=u<=1000000，v∈{1,2}
// 输出描述
// 输出一行一个小数，表示所需要的最少的钱数。保留两位小数输出。

// 样例输入
// 5 2
// 10 1
// 2 2
// 5 2
// 8 1
// 9 1
// 样例输出
// 28.00
// 提示
// 样例解释：
// 第一个人只买第一个物品，第二个人买剩下的物品。
// 第一个人由于买了A类物品，最便宜的物品半价，付款5元
// 第二个人由于也买了A类物品，最便宜的物品半价，付款23元（物品二半价）
// （买法不唯一）

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct ITEM
{
    int price, type;
};

bool cmp1(const ITEM &a, const ITEM &b)
{
    return a.price > b.price;
}

bool cmp2(const ITEM &a, const ITEM &b)
{
    return a.price < b.price;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ITEM> A, B;
    for (int i = 0; i < n; i++)
    {
        int price, type;
        ITEM temp;
        cin >> price >> type;
        temp.price = price;
        temp.type = type;
        if (type == 1)
        {
            A.push_back(temp);
        }
        else
        {
            //B.push_back({price, type});
            B.push_back(temp);
        }
    } // 初始化

    sort(A.begin(), A.end(), cmp1);
    sort(B.begin(), B.end(), cmp2);

    double ans = 0;
    int cnt = 0;
    int MIN = INT32_MAX;
    for (int i = 0; i < A.size(); i++)
    {
        if (cnt < k - 1)
        {
            ans += A[i].price * 0.5;
            cnt++;
        }
        else
        {
            ans += A[i].price;
            MIN = min(MIN, A[i].price);
        }
    }

    for (int i = 0; i < B.size(); i++)
    {
        ans += B[i].price;
        MIN = min(MIN, B[i].price);
    }

    if(MIN != INT32_MAX) ans -= MIN * 0.5;

    cout << fixed << setprecision(2) << ans << endl;

    return 0;
}