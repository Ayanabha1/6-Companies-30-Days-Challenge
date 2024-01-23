class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int contentChild = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int i = 0;
        for(int j = 0 ; j < g.size() ; j++)
        {
            while(i < s.size() && s[i] < g[j])
            {
                i++;
            }
            if(i == s.size())
            {
                break;
            }
            contentChild++;
            i++;
        }
        
        return contentChild;
    }   
};


// s -> 1 3 3 4
//        i  
// g -> 2 5 6
//      j
