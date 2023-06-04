#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n;
struct point {
    int x, y;
    bool l, r, u, d;  // left right up down �ĸ�����
    point() {
        x = y = 0;
        l = r = u = d = false;
    }
    int cal() {
        return l && r && u && d;
    }
};


point p[2005];  // ���������

bool cmpx(const point &a, const point &b){
    return a.x < b.x;
}

bool cmpy(const point &a, const point &b){
    return a.y < b.y;
}

int main()
{
    // input
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    sort(p, p+n, cmpx);
    set<int> Set;
    // ����X���С�������ұ���������õ��y�Ѿ����ڣ����жϸ�������leftΪtrue
    for (int i = 0; i < n; i++) {
        if (Set.find(p[i].y) != Set.end()) {
            p[i].l = true;
        }
        Set.insert(p[i].y);
    }
    Set.clear();

    // ����X���С�����ҵ������������õ��y�Ѿ����ڣ����жϸ�������rightΪtrue

    for (int i = n - 1; i >= 0; i--) {
        if (Set.find(p[i].y) != Set.end()) {
            p[i].r = true;
        }
        Set.insert(p[i].y);
    }
    Set.clear();

    sort(p, p+n, cmpy);
    for (int i = 0; i < n; i++){
        if (Set.find(p[i].x) != Set.end()) {
            p[i].d = true;
        }
        Set.insert(p[i].x);
    }
    Set.clear();

    for (int i = n - 1; i >= 0; i--) {
        if (Set.find(p[i].x) != Set.end()) {
            p[i].u = true;
        }
        Set.insert(p[i].x);
    }
    Set.clear();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += p[i].cal();
    }
    cout << ans << endl;

    return 0;
}
