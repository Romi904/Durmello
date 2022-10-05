class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, INT_MIN, INT_MAX);
    }
    
    bool isBST(TreeNode* root, long long minVal, long long maxVal) {
        if(root == NULL) return true;
        if(root->val >= maxVal || root->val <= minVal) return false;
        return isBST(root->left, minVal, root->val) && isBST(root->right, root->val, maxVal);
    }
    
};