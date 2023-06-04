// 给定一棵二又树，试求这棵二叉树有多少个节点满足以该节点为根的子树是满二叉树?
// 我们定义一棵树是满二叉树，当且仅当每一层的节点数量都达到了最大值(即无法在这一层添加新节点)
// 第一行输入一个正整数n，代表节点的数量。接下来的n行，第i行输入两个整数li和ri，代表i号节点的左儿子和右儿子。请注意，如果一个节点没有左儿子/右儿子，则对应的li和ri为-1。

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