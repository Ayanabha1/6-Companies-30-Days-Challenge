class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        int num = 1;
        stack<int> st;
        string ans = "";
        for(auto ch : S)
        {
            if(ch == 'D')
            {
                st.push(num++);
            }
            else
            {
                st.push(num);
                num++;
                while(st.size())
                {
                    ans.push_back(st.top() + '0');
                    st.pop();
                }
            }
        }
        st.push(num);
        while(st.size())
        {
            ans.push_back(st.top() + '0');
            st.pop();
        }
        
        return ans;
    }
};
