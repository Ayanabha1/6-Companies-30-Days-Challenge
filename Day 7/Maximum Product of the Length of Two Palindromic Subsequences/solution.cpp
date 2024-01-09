class Solution {
public:
    bool isPalindrome(string s)
    {
        string temp = s;
        reverse(temp.begin() , temp.end());
        return s == temp;
    }

    void solve(int i , int &ans , string s , string &s1 , string &s2)
    {
        if(i == s.size())
        {
            if(isPalindrome(s1) && isPalindrome(s2))
            {
                ans = max(ans , (int)(s1.size() * s2.size()));
            }
            return;
        }

        s1 += s[i];
        solve(i+1,ans,s,s1,s2);
        s1.pop_back();

        s2 += s[i];
        solve(i+1,ans,s,s1,s2);
        s2.pop_back();

        solve(i+1,ans,s,s1,s2);
    }

    int maxProduct(string s) {
        int ans = 0;
        string s1 = "" , s2 = "";
        solve(0,ans,s,s1,s2);
        return ans;
    }
};
