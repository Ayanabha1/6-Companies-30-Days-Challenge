class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int sumSize = 0 , wordCnt = words.size();
        for(int i = 0 ; i < words.size() ; i++)
        {
            sumSize += words[i].size();
            reverse(words[i].begin(),words[i].end());
        }
        sort(words.begin(),words.end());
        for(int i = 0 ; i < words.size() - 1 ; i++)
        {
            if(words[i] == words[i+1].substr(0,words[i].size()))
            {
                sumSize -= words[i].size();
                wordCnt--;
            }
        }
        
        return (sumSize + wordCnt);
    }
};
