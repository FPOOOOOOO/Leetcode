#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n;
struct point {
    int x, y;
    bool l, r, u, d;  // left right up down 四个方向
    point() {
        x = y = 0;
        l = r = u = d = false;
    }
    int cal() {
        return l && r && u && d;
    }
};


point p[2005];  // 保存坐标点

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
    // 排序按X轴从小到大，左到右遍历，如果该点的y已经存在，则判断该坐标点的left为true
    for (int i = 0; i < n; i++) {
        if (Set.find(p[i].y) != Set.end()) {
            p[i].l = true;
        }
        Set.insert(p[i].y);
    }
    Set.clear();

    // 排序按X轴从小到大，右到左遍历，如果该点的y已经存在，则判断该坐标点的right为true

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
