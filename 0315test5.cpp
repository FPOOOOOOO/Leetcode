// ��үү�ĳ������ڴ��ۻ���У�
// Ŀǰ�������ļ�����һ��k����һ��ȥ��������Ʒ�����ڴ��ۻ���Ⱥܴ�ÿ����ֻ��ȥ����һ�Σ�������һ����Ķ����۸��ǲ������Ƶġ�
// ��үү�ĳ�����Ʒ��Ϊ���ࣺA���B����Ʒ��������һ���������Ʒ�к���A����Ʒ����ô�����������Ʒ������˵�һ����Ʒ��ۡ����һ���������Ʒ��ֻ��B����Ʒ����ô�������Ʒ�����ۡ�
// ���Ǽƻ�Ҫ��n����Ʒ�����ڽ���n����Ʒ����Ϣ���㣬���������η���kλ���˱ȽϺ��㡣

// ��������
// ��һ������������n,k��������Ʒ���������˵�������
// ������n�У�ÿ����������u,v����һ����Ʒ��u������Ʒ�ļ۸�v������Ʒ�����ࡣ���vΪ1��������ΪA����Ʒ�����vΪ2��������ΪB����Ʒ��
// 1<=n,k<=1000,1<=u<=1000000��v��{1,2}
// �������
// ���һ��һ��С������ʾ����Ҫ�����ٵ�Ǯ����������λС�������

// ��������
// 5 2
// 10 1
// 2 2
// 5 2
// 8 1
// 9 1
// �������
// 28.00
// ��ʾ
// �������ͣ�
// ��һ����ֻ���һ����Ʒ���ڶ�������ʣ�µ���Ʒ��
// ��һ������������A����Ʒ������˵���Ʒ��ۣ�����5Ԫ
// �ڶ���������Ҳ����A����Ʒ������˵���Ʒ��ۣ�����23Ԫ����Ʒ����ۣ�
// ���򷨲�Ψһ��

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
    } // ��ʼ��

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