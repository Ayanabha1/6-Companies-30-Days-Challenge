class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<vector<int>> stones;
        int alice = 0 , bob = 0 , sum = 0;
        for(int i = 0 ; i < aliceValues.size() ; i++)
        {
            stones.push_back({aliceValues[i] + bobValues[i] , aliceValues[i] , bobValues[i]});
        }
        sort(stones.begin(),stones.end());

        for(int i = 0 ; i < stones.size() ; i++)
        {
            alice += i % 2 ? 0 : stones[stones.size() - i - 1][1];
            bob += i % 2 ? stones[stones.size() - i - 1][2] : 0;
        }
        if(alice > bob)
        {
            return 1;
        }
        else if(alice < bob)
        {
            return -1;
        }
        return 0;
    }
};
