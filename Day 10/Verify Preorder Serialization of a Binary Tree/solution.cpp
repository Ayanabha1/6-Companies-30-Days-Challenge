class Solution {
public:

    int getNextIndex(int i , string s)
    {
        while(i < s.size() && s[i] >= '0' && s[i] <= '9') i++;
        return i;
    }

    bool isValidSerialization(string s) {
        if(s.size() == 1 && s[0] == '#')
        {
            return true;
        }
        if(s[0] == '#')
        {
            return false;
        }

        int expNodes = 2;
        int i = getNextIndex(0,s);

        for( ; i < s.size() ; i++)
        {
            if(expNodes <= 0)
            {
                return false;
            }
            if(s[i] == ',') continue;
            if(s[i] == '#')
            {
                expNodes--;
            }
            else
            {
                // expNodes = expNodes - 1 + 2 = expNodes + 1
                expNodes++;
                i = getNextIndex(i,s) - 1;
            }
        }
        
        return (expNodes == 0);
    }
};
