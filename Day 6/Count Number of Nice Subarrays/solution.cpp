class Solution
{
public:
    int atmost(vector<int> &arr, int k)
    {
        int i = 0 , j = 0, ans = 0, odd = 0;
        while(j < arr.size())
        {
            if (arr[j] % 2)
            {
                odd++;
            }
           
            while (i <= j && odd > k)
            {
                if (arr[i] % 2)
                {
                    odd--;
                }
                i++;
            }
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};

/*
    Atmost 5 odd numbers can include subarrays with 0 , 1 , 2 ,3 , 4 , 5 odd numbers
    Atmost 4 odd numbers can include subarrays with 0 , 1 , 2 ,3 , 4  odd numbers
    
    Therefore if we substract the second from the first we get the number of subarrays with exactly 5 odd numbers
*/
