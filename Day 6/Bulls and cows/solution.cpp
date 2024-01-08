class Solution {
public:
    void decreaseFreq(unordered_map<char, int>& map, char ch) {
        map[ch]--;
        if (map[ch] <= 0) 
        {
            map.erase(ch);
        }
    }

    string getHint(string s, string g) {
        unordered_map<char, int> map;
        for (auto it : s)
        {
            map[it]++;
        }
        int cows = 0, bulls = 0;

        // Find bulls
        for (int i = 0; i < g.size(); i++) {
            if (s[i] == g[i]) {
                bulls++;
                decreaseFreq(map,s[i]);
            }
        }

        // Find cows
        for(int i = 0 ; i < g.size() ; i++)
        {
            if(s[i] == g[i])
            {
                continue;
            }
            if(map.find(g[i]) != map.end())
            {
                cows++;
                decreaseFreq(map,g[i]);
            }
        }
        string ans = "";
        ans += to_string(bulls);
        ans += 'A';
        ans += to_string(cows);
        ans += 'B';

        return ans;
    }
};

/*
    Very easy just count the bull first and decrement the frequency of the character and then just count the cows.
    Use an unordered map to store the frequencies
*/
