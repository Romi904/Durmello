#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        return 1+max(left,right);
    }
};
int main()
{
    Solution s;
    TreeNode *root = new TreeNode(5);
    TreeNode *n1 = new TreeNode(4);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(7);
    TreeNode *n4 = new TreeNode(1);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    int depth = s.maxDepth(root);
    cout<<"Depth of the binary tree : "<<depth<<endl;
    return 0;    
}
