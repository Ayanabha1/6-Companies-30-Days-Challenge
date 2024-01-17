class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans = 0;
        ans += min(x,y)*4;
        ans += z*2;
        ans += (x > y || y > x) * 2;
        return ans;
    }
};
