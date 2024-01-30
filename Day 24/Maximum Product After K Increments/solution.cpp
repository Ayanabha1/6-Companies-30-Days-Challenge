class Solution {
public:

    int mod = 1E9 + 7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it : nums) pq.push(it);
        int temp = k; 
        long product = 1;
        while(k)
        {
            int top = pq.top();
            pq.pop();
            pq.push(top + 1);
            k--;
        }
        while(!pq.empty())
        {
            product = (product * pq.top()) % mod;
            // product %= mod;
            pq.pop();
        }
        return product;
    }
};
