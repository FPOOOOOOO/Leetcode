#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
#include <set>
using namespace std;

struct point
{
    int x, y;
    bool right, left, up, down = false;
    int cal()
    {
        return right && left && up && down;
    }
};

point p[2001];

bool cmpx(const point &a, const point &b)
{
    return a.x < b.x;
}

bool cmpy(const point &a, const point &b)
{
    return a.y < b.y;
}

int main()
{
    int n;
    cin >> n;

    //printf("INPUT is: %d \n", n);

    unordered_map<int, unordered_map<int, int> > unmap_stars; // 坐标点的数量
    unordered_map<int, map<int, int> > halfmap_stars;
    map<int, map<int, int> > map_stars;

    set<pair<int, int> > SET1;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        //printf("X:%d Y:%d \n", x, y);
        // unmap_stars[x][y]++;
        // halfmap_stars[x][y]++;
        map_stars[x][y]++;
        SET1.insert({x, y});
    }

    int num1 = 0;

    num1 = SET1.count({1, 1});

    //num1 = map_stars.find(1); 
    //num2 = SET1.find(1);

    cout << num1;
    //cout << num2;
    //printf("Start to scan...... \n");

    // int cnt = 0;
    // for (auto it = map_stars.begin(); it != map_stars.end(); it++)
    // {


    //     cout << it->first << endl;
    //     for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
    //     {
    //         cout << it2->first << it2->second << endl;
    //     }
    // }

    // int ans = 0;
    // for (auto it = stars.begin(); it != stars.end(); it++) {
    //     int x = it->first;
    //     for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
    //         int y = it2->first;
    //         int cnt = it2->second;
    //         if (cnt < 4) continue; // 不足 4 个点的肯定不是幸运星
    //         int cnt_up = stars[x][y+1];
    //         int cnt_down = stars[x][y-1];
    //         int cnt_left = stars[x-1][y];
    //         int cnt_right = stars[x+1][y];
    //         if (cnt_up > 0 && cnt_down > 0 && cnt_left > 0 && cnt_right > 0) {
    //             ans++;
    //         }
    //     }
    // }

    // cout << ans << endl;
    return 0;
}
