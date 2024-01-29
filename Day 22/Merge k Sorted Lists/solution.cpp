/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)      
        {
            return NULL;
        }
        return helper(0,lists.size()-1,lists);
    }

    ListNode *helper(int l , int r , vector<ListNode*> &lists)
    {
        if(l == r)
        {
            return lists[l];
        }
        if (l + 1 == r) {
            return merge(lists[l], lists[r]);
        }
        int m = l + (r-l)/2;
        ListNode *left = helper(l,m,lists);
        ListNode *right = helper(m+1,r,lists);
        return merge(left,right);
    }

    ListNode *merge(ListNode *l1 , ListNode *l2)
    {
        ListNode *merged = new ListNode(0);
        ListNode *curr = merged;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                curr->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else
            {
                curr->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        return merged->next;
    }
};
