class DataStream {
public:

    int consecVal = 0 , val , k;
    DataStream(int value, int k) {
        val = value;
        this->k = k;
    }
    
    bool consec(int num) {
        if(num == val)
        {
            consecVal++;
        }
        else
        {
            consecVal = 0;
        }
        if(consecVal >= k)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

