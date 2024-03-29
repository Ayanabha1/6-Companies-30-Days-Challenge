class Solution {
public:

     bool check(long long d1, long long d2, long long uc1, long long uc2, long long x) {
        long long A = x / d1;
        long long A_ = x - A;  
        long long B = x / d2;	
        long long B_ = x - B;	
        long long AIB = x / lcm(d1, d2); 
        long long AuB = A + B - AIB;	
        long long AIB_ = x - (AuB);	

        if(A_ >= uc1 && B_ >= uc2 && (A_ + B_ - AIB_ >= uc1 + uc2))
        {
            return true;
        }

        return false;
    }

    int minimizeSet(int d1, int d2, int u1, int u2) {
        long long lo = 1, hi = 1e17;
        while (hi > lo + 1) {
            long long mid = (lo + hi) >> 1;
            if (check(d1, d2, u1, u2, mid)) hi = mid;
            else lo = mid;
        }
        return hi;
    }

   
};
