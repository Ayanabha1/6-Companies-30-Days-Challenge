class Solution {
public:
    vector<vector<int>> rects;
    vector<int> weights;
    void assignWeight(vector<int> r)
    {
        int area = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
        weights.push_back(area + (weights.empty() ? 0 : weights.back()));
    }
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        for(auto el : rects) assignWeight(el);
    }
    vector<int> pick() {
        int randW = rand() % weights.back();
        auto randPos = upper_bound(weights.begin(),weights.end(),randW);
        int randIdx = randPos - weights.begin();
        vector<int> randomRect = rects[randIdx];
        int randX = rand() % (randomRect[2] - randomRect[0] + 1) + randomRect[0]; 
        int randY = rand() % (randomRect[3] - randomRect[1] + 1) + randomRect[1]; 
        return {randX,randY};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
