#define pis pair<int,string>

class myComp {
  public:
    bool operator() (const pis &a, const pis &b) {
      if(a.first == b.first) return a.second < b.second;
      
      return a.first > b.first;
    }
};  


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        vector<pair<int,string>> temp;
        unordered_map<string,int> freq;
        priority_queue<pis,vector<pis>,myComp> pq;
        for(auto word: words) freq[word]++;
        for(auto it: freq)
        {
            pq.push({it.second,it.first});
            if(pq.size() > k)
            {                
                pq.pop();
            }  
        }

        while(pq.size())
        {
            temp.push_back(pq.top());
            pq.pop();
        }
        reverse(temp.begin(),temp.end());
        for(auto it : temp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};
