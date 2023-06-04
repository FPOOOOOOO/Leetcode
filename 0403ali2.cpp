class UF{
public:
    UF(int n):parent_(vector<int>(n,-1)){}
    int Find(int x) {
        if (parent_[x] < 0) {
            return x;
        } else {
            auto root = Find(parent_[x]);
            parent_[x] = root;
            return root;
        }
    }
    void Union(int x, int y) {
        int rootX = Find(x);
        int rootY = Find(y);
        if (parent_[rootX] < parent_[rootY]) {
            auto size = parent_[rootY];
            parent_[rootY] = rootX;
            parent_[rootX] += size;
        }else {
            auto size = parent_[rootX];
            parent_[rootX] = rootY;
            parent_[rootY] += size;
        }
    }
    int depth(int x) {
        return -parent_[x];
    }

    vector<int> parent_;
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        //calculate size of each island
        auto len = grid.size();
        UF uf(len*len);
        int maxSize = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (grid[i][j] == 0) continue;
                else {
                    if (i+1 < len && grid[i+1][j]) {
                        if (uf.Find(i*len+j) != uf.Find(i*len+j+len)) {
                            uf.Union(i*len+j,i*len+j+len);
                        }
                    }
                    if (j+1 < len && grid[i][j+1]) {
                        if (uf.Find(i*len+j) != uf.Find(i*len+j+1)) {
                            uf.Union(i*len+j,i*len+j+1);
                        }
                    }
                    maxSize = max(maxSize,uf.depth(uf.Find(i*len+j)));
                }
            }
        }
        
        //iterate through non-island node to find the maximum size
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (grid[i][j] == 1) continue;
                else {
                    set<pair<int,int>> root_val;
                    if (i+1 < len && grid[i+1][j]) {
                        auto first = uf.Find(i*len+j+len);
                        auto second = uf.depth(first);
                        root_val.insert(make_pair(first,second));
                    }
                    if (i-1 < len && grid[i-1][j]) {
                        auto first = uf.Find(i*len+j-len);
                        auto second = uf.depth(first);
                        root_val.insert(make_pair(first,second));
                    }
                    if (j+1 < len && grid[i][j+1]) {
                        auto first = uf.Find(i*len+j+1);
                        auto second = uf.depth(first);
                        root_val.insert(make_pair(first,second));
                    }
                    if (j-1 < len && grid[i][j-1]) {
                        auto first = uf.Find(i*len+j-1);
                        auto second = uf.depth(first);
                        root_val.insert(make_pair(first,second));
                    }
                    auto curr = std::accumulate(root_val.begin(), root_val.end(), 0,[](int &cur,const pair<int,int> &val){
                        cur += val.second;
                        return cur;
                    });
                    maxSize = max(maxSize,curr+1);
                }
            }
        }
        return maxSize;
    }
};