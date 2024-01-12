/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<int> solve(TreeNode *node , int st , int &ans)
    {
        if(!node)
        {
            // {level,node}
            return {0,0};
        }
        auto left = solve(node->left,st,ans);
        auto right = solve(node->right,st,ans);
        if(node->val == st)
        {
            ans = max(ans,max(left[0],right[0]));
            return {1,st};
        }
        if(left[1] == st || right[1] == st)
        {
            ans = max(ans,left[0] + right[0]);
            return {(left[1] == st) ? (left[0] + 1) : (right[0] + 1) , st};
        }
        return {1 + max(left[0],right[0]) , node->val};
    }

    int amountOfTime(TreeNode* root, int start) {
        int ans = 0;
        solve(root,start,ans);
        return ans;
    }
};
