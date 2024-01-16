class Solution {
public:
    int equalSubstring(string s, string t, int mc) {
        int ans = 0;
        int i = 0 , j = 0;
        while(j < s.size())
        {
            if(mc >= 0 && j < s.size())
            {
                mc -= abs(s[j] - t[j]);
                if(mc >= 0)
                {
                    ans = max(ans,j-i+1);
                }
                j++;
            }
            if(mc < 0 && i <= j)
            {
                mc += abs(s[i] - t[i]);
                i++;
            }
        }
        return ans;
    }
};
