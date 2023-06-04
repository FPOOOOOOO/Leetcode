// ����һ�ö�������������ö������ж��ٸ��ڵ������Ըýڵ�Ϊ������������������?
// ���Ƕ���һ�������������������ҽ���ÿһ��Ľڵ��������ﵽ�����ֵ(���޷�����һ������½ڵ�)
// ��һ������һ��������n������ڵ����������������n�У���i��������������li��ri������i�Žڵ������Ӻ��Ҷ��ӡ���ע�⣬���һ���ڵ�û�������/�Ҷ��ӣ����Ӧ��li��riΪ-1��

#include <iostream>
#include <set>
#include <vector>
 
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    //TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    //TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// struct TreeNode{
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x): val(x),left(NULL), right(NULL){}
// };

bool isFull(TreeNode* root, int& depth){
    if(!root){
        depth = 0;
        return true;
    }
    
    int left_depth, right_depth;
    bool left_full = isFull(root->left, left_depth);
    bool right_full = isFull(root->right, right_depth);

    depth = max(left_depth, right_depth) + 1;
    return left_full && right_full && left_depth == right_depth;
}

int dfs(TreeNode* root){
    if(!root) return 0;
    
    int depth;
    if(isFull(root, depth)){
        return 1 + dfs(root->left) + dfs(root->right);
    }else{
        return dfs(root->left) + dfs(root->right);
    }

}

int main(){
    int n;
    cin >> n;

    vector<TreeNode*> nodes(n+1);

    for(int i = 1; i <=n; i++){
        nodes[i] = new TreeNode(i);
    }

    for(int i = 1; i <= n; i++){
        int left, right;
        cin >> left >> right;
        if(left != -1){
            nodes[i]->left = nodes[left];
        }
        if(right != -1){
            nodes[i]->right = nodes[right];
        }
    }


    int result = dfs(nodes[1]);

    cout << result << endl;

    return 0;
}