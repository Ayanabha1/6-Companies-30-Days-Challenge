class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> ageCnt(121,0) , ageSum(121,0);
        int sum = 0 , ans = 0;
        for(auto age: ages)
        {
            ageCnt[age]++;
        }
        for(int i = 15 ; i <= 120 ; i++)
        {
            int k = (i / 2) + 7;
            sum += ageCnt[i];
            ageSum[i] = sum;
            ans += ((ageSum[i] - ageSum[k] - 1) * ageCnt[i]);
        }
        return ans;
    }
};
