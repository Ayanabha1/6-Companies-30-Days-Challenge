class Solution {
public:
    int wordCount(vector<string>& st, vector<string>& tar) {
        int ans = 0;
        unordered_set<int> hashes;
        for(auto word: st)
        {
            int hash = 0;
            for(auto ch : word)
            {
                hash |= (1 << (ch-'a'));
            }
            hashes.insert(hash);
        }

        for(auto word : tar)
        {
            int hash = 0;
            for(auto ch : word)
            {
                hash |= (1 << (ch-'a'));
            }
            for(int i = 0 ; i < 26 ; i++)
            {
                if(hash & (1 << i))
                {
                    int hash_temp = hash;
                    hash_temp ^= (1 << i);
                    if(hashes.find(hash_temp) != hashes.end())
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
