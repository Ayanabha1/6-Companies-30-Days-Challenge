class Solution {
public:

    bool isWithinOneHour(int t1 , int t2)
    {
        if(t2 <= t1 + 99)
        {
            return true;
        }
        return false;
    }

    vector<string> findHighAccessEmployees(vector<vector<string>>& at) {
        unordered_map<string,vector<int>> times;
        vector<string> ans;
        for(auto it : at)
        {
            times[it[0]].push_back(stoi(it[1]));
        }
        
        for(auto emp : times)
        {
            sort(emp.second.begin(),emp.second.end());
            bool highAccessEmp = false;
            for(int i = 0 ; i < emp.second.size() ; i++)
            {
                if(i + 2 >= emp.second.size())
                {
                    break;
                }
                if(isWithinOneHour(emp.second[i] , emp.second[i+2]))
                {
                    highAccessEmp = true;
                    break;
                }
            }
            if(highAccessEmp)
            {
                ans.push_back(emp.first);
            }
        }
        return ans;
    }
};
