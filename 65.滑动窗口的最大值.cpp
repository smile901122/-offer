class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int> index;
        if(num.size() >= size && size > 0){
        	//处理第一个滑窗
            for(int i = 0; i < size; ++i){
                while(!index.empty() && num[i] >= num[index.back()])
                    index.pop_back();
                index.push_back(i);
            }   
            res.push_back(num[index.front()]);
            //处理后续的滑窗
            for(int i = size; i < num.size(); ++i){
                while(!index.empty() && num[i] > num[index.back()])
                    index.pop_back();
                //若该元素已经从窗中滑出，则应该删除
                if(!index.empty() && index.front() <= i - size)
                    index.pop_front();
                index.push_back(i);
            	res.push_back(num[index.front()]);
            }
        }
        return res;
    }
};
