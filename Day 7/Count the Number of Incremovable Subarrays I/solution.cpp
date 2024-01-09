class Solution {
public:
    // Coded by Ayanabha Misra
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            for(int j = i ; j < nums.size() ; j++)
            {
                if(i - 1 >= 0 && j + 1 < nums.size() && nums[i-1] >= nums[j + 1])
                {
                    continue;
                }
                int flag = true;
                int x = i - 1 , y = nums.size() - 1;
                while(x - 1 >= 0)
                {
                    if(nums[x - 1] >= nums[x]) 
                    {
                        flag = false;
                        break;
                    }
                    x--;
                }
                while(y - 1 > j)
                {
                    if(nums[y - 1] >= nums[y]) 
                    {
                        flag = false;
                        break;
                    }
                    y--;
                }
                if(flag) ans++;
                
            }
        }
        return ans;
    }
};
