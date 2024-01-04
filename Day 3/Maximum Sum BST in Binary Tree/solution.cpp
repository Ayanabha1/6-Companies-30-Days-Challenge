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

class NodeVal {
    public:
    int minNode , maxNode , sum;
    NodeVal(int a , int b , int c)
    {
        minNode = a , maxNode = b , sum = c;
    }
};


class Solution {
public:
    int maxSum = 0;
    NodeVal *solve(TreeNode *node)
    {
        if(!node)
        {
            return new NodeVal(INT_MAX,INT_MIN,0);
        }
        auto left = solve(node->left);
        auto right = solve(node->right);

        if(!left || !right)
        {
            return NULL;
        }
        if(node->val <= left->maxNode || node->val >= right->minNode)
        {
            return NULL;
        }
        
        maxSum = max(maxSum,left->sum + right->sum + node->val);
        int minNode = min(node->val,left->minNode);
        int maxNode = max(node->val,right->maxNode);
        return new NodeVal(minNode,maxNode,left->sum + right->sum + node->val);
    }

    int maxSumBST(TreeNode* root) {
        solve(root); 
        return maxSum;  
    }
};
