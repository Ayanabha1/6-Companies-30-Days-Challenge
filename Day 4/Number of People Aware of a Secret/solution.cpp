class Solution {
public:
    int mod = 1E9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int day = 2;
        long long ans = 1 , cnt = 0;
        queue<vector<long long>> starts , stops;
        starts.push({1+delay,1});
        stops.push({1+forget,1});

        while(day <= n)
        {
            if(!stops.empty() && day == stops.front()[0])
            {
                auto front = stops.front();
                cnt = (cnt - (front[1]) + mod) % mod;
                ans = (ans - (front[1]) + mod) % mod;
                stops.pop(); 
            }
            if(!starts.empty() && day == starts.front()[0])
            {
                auto front = starts.front();
                cnt += front[1];
                cnt %= mod;
                starts.pop();
            }
            ans += cnt;
            ans %= mod;
            if(cnt)
            {
                starts.push({day + delay , cnt});
                stops.push({day + forget , cnt});
            }
            day++;
        }
        ans %= mod;
        return ans;
    }
};
