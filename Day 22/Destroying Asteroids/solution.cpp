class Solution {
public:
    int mod = 1E9 + 7;
    bool asteroidsDestroyed(int mass, vector<int>& arr) {
        sort(arr.begin(),arr.end());
        long  __mass = mass;
        for(auto it: arr)
        {
            if(it > __mass)
            {
                return false;
            }
            __mass += it;
        }
        return true;
    }
};
