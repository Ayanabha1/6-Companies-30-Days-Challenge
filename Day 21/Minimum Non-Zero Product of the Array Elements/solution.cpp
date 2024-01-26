class Solution {
public:
    int mod = 1e9 + 7;

    long long expon(long long a , long long b)
    {
        long long ans = 1; 
 
        while (b > 0) {    
            if (b & 1)
            {
                ans = ((ans % mod) * (a % mod))%mod;
            }
            
            b = b / 2; 
            a = ((a % mod) * (a) % mod) % mod; 
        }
        return (ans % mod);
    }


    int minNonZeroProduct(int p) {
        long long maxProd = 0;
        maxProd = (((long long ) 1) << p) - 1;

        long long secondMax = maxProd - 1;
        secondMax = secondMax % mod;

        long long exp = maxProd / 2;
        secondMax = secondMax % mod;

        secondMax = expon(secondMax , exp);
        maxProd = ((maxProd % mod) * (secondMax % mod) % mod);
        return (maxProd % mod); 
    }
};
