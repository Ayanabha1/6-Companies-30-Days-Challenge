class Solution {
 

public:

    bool checkAllSeatsVacant(vector<int> &seats , vector<int> query)
    {
        for(auto seat : query)
        {
            if(seats[seat] == 1)
            {
                return false;
            }
        }
        return true;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& arr) {
        int ans = 0;
        sort(arr.begin(),arr.end());

        
        // Case: above this row , every seat is vacant
        int firstRow = arr[0][0];
        int topEmptyRows = firstRow - 1;
        ans += (topEmptyRows * 2);

        for(int i = 0 ; i < arr.size() ; i++)
        {
            if(i > 0)
            {
                int gap = arr[i][0] - arr[i-1][0] - 1;
                ans += (gap * 2);
            }
            vector<int> seats(10,0); // seats[i] = 0 -> means ith seat is vacant
            int j = i;
            while(j < arr.size() && arr[i][0] == arr[j][0])
            {
                seats[arr[j][1] - 1] = 1; // seats[i] = 1 -> means ith seat is not vacant
                j++;
            }
            i = j - 1;
            bool leftSplitVacant = checkAllSeatsVacant(seats,{1,2,3,4});
            bool rightSplitVacant = checkAllSeatsVacant(seats,{5,6,7,8});
            bool middleVacant = checkAllSeatsVacant(seats,{3,4,5,6});

            if(leftSplitVacant && rightSplitVacant)
            {
                ans += 2;
            }
            else if(leftSplitVacant || rightSplitVacant || middleVacant)
            {
                ans += 1;
            }
            
        }

        // Case: below this row , every seat is vacant
        int lastRow = arr[arr.size()-1][0];
        int lastEmptyRows = n - lastRow;
        ans += (lastEmptyRows * 2);


        return ans;
    }
};
