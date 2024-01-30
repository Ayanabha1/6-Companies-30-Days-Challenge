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

    vector<int> solve(TreeNode *root , int distance , int &ans)
    {
        if(!root)
        {
            return {};
        }
        if(!root->left && !root->right)
        {
            return {1};
        }
        vector<int> left = solve(root->left,distance,ans);
        vector<int> right = solve(root->right,distance,ans);
        vector<int> arr;
        for(int i = 0 ; i < left.size() ; i++)
        {
            for(int j = 0 ; j < right.size() ; j++)
            {
                if(left[i] + right[j] <= distance)
                {
                    ans++;
                }
            }
        }

        for(auto it: left) arr.push_back(it + 1);
        for(auto it: right) arr.push_back(it + 1);
        return arr;
    }

    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        solve(root,distance,ans);
        return ans;
    }
};
