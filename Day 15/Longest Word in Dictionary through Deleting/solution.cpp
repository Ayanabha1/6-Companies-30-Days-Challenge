class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for(auto word : dictionary)
        {
            if(word.size() > s.size() || word.size() < ans.size())
            {
                continue;
            }
            int i = 0 , j = 0;
            while(j < s.size())
            {
                if(word[i] == s[j])
                {
                    i++;
                }
                j++;
            }
            if(i == word.size())
            {
                if(word.size() > ans.size())
                {
                    ans = word;
                }
                else if(word.size() == ans.size())
                {
                    ans = (ans < word) ? ans : word;
                }
            }
        }
        return ans;
    }
};
