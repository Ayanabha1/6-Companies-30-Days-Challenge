class Solution {
public:
    vector<int> getOccurrences(string s , string p)
    {
        vector<int> ans;
        for(int i = 0 ; i <= s.size() - p.size() ; i++)
        {
            string temp = s.substr(i,p.size());
            if(temp == p)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        if(a.size() > s.size() || b.size() > s.size())
        {
            return {};
        }
        vector<int> a_ind = getOccurrences(s,a);
        vector<int> b_ind = getOccurrences(s,b);
        vector<int> ans;
        int i = 0 , j = 0;
        while(i < a_ind.size() && j < b_ind.size())
        {
            if(abs(a_ind[i] - b_ind[j]) <= k)
            {
                ans.push_back(a_ind[i]);
                i++;
            }
            else if(a_ind[i] > b_ind[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};
