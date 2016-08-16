class Solution {
public:
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (input.size() == 0 || input.size() < k || k <= 0)
            return {};
        int pos = partion(input, 0, input.size() - 1);
        while (pos != k - 1)
        {
            if (pos > k - 1)
                pos = partion(input, 0, pos - 1);
            else
                pos = partion(input, pos + 1, input.size() - 1);
        }
        //将前k个数复制到res中并返回
        for(int i = 0; i < k; ++i){
            res.push_back(input[i]);
        }
        return res;
    }
    
private:
    int partion(vector<int>& input, int begin, int end)
    {
        int key = input[begin];
        int l = begin + 1;
        int r = end;
        while (l <= r)
        {
            while (l <= r && input[r] > key)    --r;
            while (l <= r && input[l] <= key)   ++l;
            if(l < r)   swap(input[l++], input[r--]);
        }
        swap(input[begin], input[r]);
        return r;
    }
};
