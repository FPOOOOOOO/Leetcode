// ��������ѧ��һ����Ҫ�ĸ�������ڼ�����е�pair�����Ե��������£�
// ÿ������(x,y)��������ʵ��Ԫ��x,y������һ����֮��Ĺ�ϵ���������Աȴ�С���ȱȽϵ�һ�����Ĵ�С�������ͬ�ٱȽϵڶ������Ĵ�С��
// ���ڣ���n����������������ͬ��������֮�����������γ�n^2�����ԣ��Լ����Լ�Ҳ���γ����ԣ�������ϣ��֪������kС����������һ�������������һ�ԡ�
// ��������
// ��һ�а���������n,k 
// ������һ��n���������ո������
// �������
// �����kС�����ԡ���ʽ��(x,y)������xΪ�����е�һ������yΪ�����еڶ�����

// ��������
// 3 4
// 3 1 2
// �������
// (2,1)
// ��ʾ
// n��100000,1��k��n^2����n������int��Χ��[-2147483648,2147483647]
// ��������
// ����һ����9�����ֱ��ǣ� (3,3)(3,1)(3,2)(1,3)(1,1)(1,2)(2,3)(2,1)(2,2) 
// ����С����������(1,1)(1,2)(1,3)(2,1)(2,2)(2,3)(3,1)(3,2)(3,3)
// ��4��Ϊ(2,1)

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

//     sort(nums.begin(), nums.end()); // ��vector����

//     set<pair<int, int>> pairs; // �洢���Ե�set����

//     // ö����������
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             pairs.insert({nums[i], nums[j]}); // �����Լ���set����
//         }
//     }

//     // �ҵ���kС�����Բ����
//     int cnt = 0; // ������
//     for (auto p : pairs) {
//         cnt++;
//         if (cnt == k) {
//             cout << "(" << p.first << "," << p.second << ")" << endl;
//             break;
//         }
//     }

//     return 0;
// }
