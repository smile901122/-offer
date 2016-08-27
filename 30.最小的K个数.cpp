class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
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
        
        vector<int> res(input.begin(), input.begin() + k);
        return res;
    }
    
private:
    int partion(vector<int>& input, int begin, int end)
    {
        int key = input[begin];
        while (begin < end)
        {
            while (begin < end && input[end] >= key)	--end;
            input[begin] = input[end];
            while (begin < end && input[begin] < key)	++begin;
            input[end] = input[begin];
        }
        input[begin] = key;
        return begin;
    }
};
