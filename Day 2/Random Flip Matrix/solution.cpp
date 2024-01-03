class Solution {
public:
    int cnt = 0;
    int m,n;
    unordered_set<int> flipped;
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        cnt = m * n;
    }
    
    vector<int> flip() {
        if(flipped.size() == cnt) 
        {
            return {};
        }
        int randomInd = rand() % cnt;
        while(flipped.count(randomInd))
        {
            randomInd++;
            randomInd = randomInd % cnt;
        }
        flipped.insert(randomInd);
        return {randomInd / n , randomInd % n};

    }
    
    void reset() {
        flipped = {};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
