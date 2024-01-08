class Solution {
public:

    int minMoves2(vector<int>& nums) {
        int n = nums.size() , moves = 0;
        sort(nums.begin(),nums.end());
        int mid = nums[(n-1)/2];
        for(auto el : nums)
        {
            moves += abs(el-mid);
        }
        return moves;
    }
    
};

/* 
    Approach:
    Find the median and make every element equal to that
*/
