#define pb push_back

class Solution {
public:

    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        vector<string> strs = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        ans.pb("");
        for(int i = 0 ; i < digits.size() ; i++)
        {
            vector<string> temp;
            int digit = digits[i] - '0';
            for(char ch : strs[digit])
            {
                for(auto el : ans)
                {
                    temp.pb(el + ch);
                }
            }
            ans = temp;
        }
        return ans;
    }
};

