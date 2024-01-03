class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        // code here
        int missing, repeating;
        for (int i = 0; i < n; i++)
        {
            int ind = abs(arr[i]);
            if (arr[ind - 1] < 0)
            {
                repeating = abs(arr[i]);
            }
            else
            {
                arr[ind - 1] *= -1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                missing = i + 1;
            }
        }
        return {repeating, missing};
    }
};
