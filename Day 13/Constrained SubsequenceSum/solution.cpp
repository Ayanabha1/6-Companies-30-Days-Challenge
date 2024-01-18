class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> temp = nums;
        priority_queue<pair<int,int>> pq;
        pq.push({temp[0],0});
        int ans = temp[0];
        for(int i = 1 ; i < temp.size() ; i++)
        {
            while(!pq.empty() && (i - pq.top().second > k))
            {
                pq.pop();
            }
            temp[i] = max(temp[i],temp[i] + pq.top().first);
            pq.push({temp[i],i});

            ans = max(ans,temp[i]);
        }
        return ans;
    }
};
