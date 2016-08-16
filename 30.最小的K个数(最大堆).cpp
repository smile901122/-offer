class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int n = input.size();
        if(n <= 0 || n < k) return vector<int>();
         
        vector<int> res(input.begin(), input.begin() + k);
        //建堆
        make_heap(res.begin(), res.end());
         
        for(int i = k; i < n; ++i)
        {
            if(input[i] < res[0])
            {
                //先pop,然后在容器中删除
                pop_heap(res.begin(), res.end());
                res.pop_back();
                //先在容器中加入，再push
                res.push_back(input[i]);
                push_heap(res.begin(), res.end());
            }
        }
        //使其从小到大输出
        //sort_heap(res.begin(), res.end());
        return res;
         
    }
};
