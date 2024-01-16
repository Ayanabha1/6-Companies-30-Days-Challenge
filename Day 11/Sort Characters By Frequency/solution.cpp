class Solution {
    static bool comp(vector<int> &a , vector<int> &b)
    {
        return a[1] > b[1];
    }

public:


    string frequencySort(string s) {
        vector<vector<int>> freq(256,vector<int>(2,0));
        for(auto ch : s)
        {
            if(freq[ch][0] == 0)
            {
                freq[ch][0] = (int)ch;
            }
            freq[ch][1]++;
        }

        sort(freq.begin() , freq.end() , comp);
        string ans = "";
        for(int i = 0 ; i < freq.size() ; i++)
        {
            if(freq[i][1] == 0) continue;
            ans.append(freq[i][1],(char)freq[i][0]);
            
        }   
        return ans;
    }
};

