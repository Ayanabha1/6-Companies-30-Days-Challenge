class Solution {
public:
    int countCollisions(string s) {
        int i = 0 , j = s.size() - 1 , ans = 0;   
        while(i < s.size() && s[i] == 'L')
        {
            i++;
        }
        while(j >= 0 && s[j] == 'R')
        {
            j--;
        }
        
        for(int k = i ; k <= j ; k++)
        {
            if(s[k] != 'S')
            {
                ans++;
            }
        }
        return ans;
    }
};
